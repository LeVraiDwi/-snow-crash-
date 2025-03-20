On trouve 2 fichier token et un binaire level09:
    dans token on a: f4kmm6p|=�p�n��DB�Du{��

Le bianire
    ./level09 12345 => 13579
    ./level09 abcd => aceg
on vois que l'exe prend la chaine et ajoute la position de chaque caractaire au caractaire.

On cherche donc a creer un exe qui soustrait sa position a chaque caractaire.
    cf: main.c
Apres on copie dans tmp:
    scp -P 2222 ./main.c level09@127.0.0.1:/tmp/
On compile dans /tmp et on se place dans tmp pour executer le binaire avec la valeur de token:
    cat token | xargs ./a.out
on obtient le mot de passe de flag09 => getflag finis.
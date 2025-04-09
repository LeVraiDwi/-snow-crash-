Dans ce flag on ne trouve aucun fichier suspect:
On decide donc de s' attaquer a getflag:
En decompilant get flag on constate plusieur chose differente:
    1- il y a plus le commentaire qui indique que on ne doit pas decompiler le fichier getflag n' est plus localhost
    2- Il y a la meme fonction ft_des() que dans le flag 13
    3- La fonction est appeler avec un argument different en fonction de uid de l' utilisateur
Il faut donc mainteant trouver le bonne argument a passer a la fonction ft_des():
    grace a la commande:
```
id flag14    
```
On trouve que l'uid de l'utilisateur flag14 est 3014
Il faut donc chercher dans le code de getflag l'argument utiliser dans ft_des() quand le uid est de 3014 -> 0xbc6
On trouve l'argument "g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|"
On peut donc utiliser le programme du flag13 avec comme argment la s tring trouver plus tot
on obtient:
7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
notre flag et mot de passe du user flag14
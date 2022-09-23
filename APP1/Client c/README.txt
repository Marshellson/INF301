Quickstart :
============

Pour démarrer la présentation d'AppoLab, commencez par compiler le tout:
> make

Puis lancez le programme d'introduction.
> ./client-introduction

et suivez les consignes :-)



Liste des fichiers :
====================

client-introduction.c
  => à lancer initialement pour découvrir AppoLab

client-tutoriel.c
  => sera utilisé pendant le tutoriel

client-interactif.c
  => à utiliser plus tard, si besoin de se connecter à nouveau de manière 
     interactive avec AppoLab sans avoir à re-programmer à partir de 
     client-tutoriel.

client.h
  => interface de la librairie de communication avec AppoLab.
     À NE PAS MODIFIER !! (sauf si vous voulez changer les couleurs d'affichage)

client.c
  => librairie de communication avec AppoLab. À NE PAS MODIFIER !!
     (mais vous pouvez aller regarder dedans si vous osez... :-)

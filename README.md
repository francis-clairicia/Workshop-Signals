# Workshop - Signaux

C'est quoi, des signaux ?
-------------------------
Pour faire simple, ce sont des informations envoyées par le kernel à un programme.

Elles ont toutes un but initial : Arrêter le dit programme.

Exemple: `SIGSEGV` (Segmentation Fault)

Lesquels sont-ils?
------------------
Les principaux à retenir :
- `SIGINT` : Signal envoyé lors d'un CTRL+C
- `SIGABRT` : Interruption abrupte d'un processus
- `SIGSEGV` : Mauvaise manipulation de mémoire
- `SIGKILL`/`SIGSTOP` : Arrête votre programme sans préavis
- `SIGTERM` : Arrête le programme également, mais peut être catch

[signal(7)](https://man7.org/linux/man-pages/man7/signal.7.html) pour connaître les autres.

Que faire avec ?
----------------
- Gérer `SIGINT` pour agir lors d'un CTRL+C (ex: arrêter une boucle)
- S'occuper des signaux pour les processus enfants (fork)
- Faire 2 programmes communiquer entre eux (coucou le Navy)

Il n'est pas obligé d'interagir avec les signaux, mais de nouvelles possibilités s'offrent à vous.

Comment s'en servir ?
---------------------
Les fonctions à connaître :
- [signal(2)](https://man7.org/linux/man-pages/man2/signal.2.html)/[sigaction(2)](https://man7.org/linux/man-pages/man2/sigaction.2.html): Modifie le comportement d'un programme à la réception d'un signal
- [kill(2)](https://man7.org/linux/man-pages/man2/kill.2.html): Envoie un signal un processus spécifique
- [raise(3)](https://man7.org/linux/man-pages/man3/raise.3.html): Envoie un signal à son propre processus (`kill(getpid())`)
- [pause(2)](https://man7.org/linux/man-pages/man2/pause.2.html): Attend qu'un signal soit reçu

En bonus:
- [abort(3)](https://man7.org/linux/man-pages/man3/abort.3.html): Envoie `SIGABRT` à son propre processus, et stoppe obligatoirement le processus

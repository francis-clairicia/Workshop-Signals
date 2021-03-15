/*
** EPITECH PROJECT, 2021
** Workshop_Signals
** File description:
** kill
*/

#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int kill(pid_t pid, int sig);

/*
Exercice 4:

Y'a un programme qui n'arrête pas de tourner quand on le lance.
On me dit à chaque fois d'aller dans htop, sauf que j'y connais rien.

Tu veux pas faire un p'tit programme qui va envoyer le signal le plus puissant
à ce fichu process ?

Fonction à utiliser: kill(2)
*/

int main(int ac, char const * const *av)
{
    if (ac == 1) {
        fprintf(stderr, "Il faut un PID en paramètre.\n");
        fprintf(stderr, "(Un conseil, ne mets jamais ni 0, ni 1, ni -1 dans un kill())\n");
        fprintf(stderr, "(surtout si c'est pour envoyer SIGKILL)\n");
        fprintf(stderr, "(Je t'aurais prévenu)\n");
        return 84;
    }

    pid_t pid = atoi(av[1]);

    /* Utilisation de kill */
    return 0;
}
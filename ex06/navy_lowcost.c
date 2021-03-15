/*
** EPITECH PROJECT, 2021
** Workshop_Signals
** File description:
** navy_lowcost
*/

/* Ce truc c'est pour que VS Code ne vous embête pas :) */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int kill(pid_t pid, int sig);

int pause(void);

/*
Exercice 6:

Maintenant que vous avez pu manipuler les fonctions de bases pour les signaux,
pourquoi pas passer à la pratique ?

L'exercice consiste à envoyer un nombre avec des signaux à un autre process,

Allez ça ne devrait pas te faire peur, tu t'es bien tapé le Navy donc tu es
forgé :)

Plus sérieusement, une partie du code est déjà présent afin que tu ne sois pas
perdu.

Tu dois te servir de SIGUSR1 et SIGUSR2 pour faire communiquer tes processus

Il y a 2 façons de voir pour envoyer un nombre N:
- Envoyer N fois SIGUSR1 et envoyer SIGUSR2 pour dire qu'on a fini
- Envoyer en binaire le nombre N en envoyant des 0 et des 1 successivement
  en considérant SIGUSR1 comme étant un 0 et SIGUSR2 un 1.

Choisis ce avec quoi tu es le plus à l'aise
(Bizarrement j'ai l'impression que tout le monde va prendre l'option 1...
Naaan ça doit être mon imagination ! Enfin j'espère...)

Fonctions à utiliser:
- kill(2)
- pause(2)
- sigaction(2)
*/

static int GLOBAL_SIGNUM = 0;

unsigned int get_number_from_process(void)
{
    unsigned int nb = 0;

    /* Utilisation de pause() */
    return nb;
}

void send_number_to_process(pid_t recieving_pid, unsigned int nb)
{
    /* Utilisation de kill() */
}

/* Ta fonction handler avec sigaction comme d'habitude */

int main(int ac, char const * const *av)
{
    /* Utilisation de sigaction sur SIGUSR1 et SIGUSR2 */
    /* Là tu sais faire maintenant ! Ou au pire CTRL+C/CTRL+V */

    if (ac == 1) {
        /* Il sera le receveur */
        printf("Je veux un nombre entre 0 et l'infini !\n");
        printf("Pour l'envoyer c'est là-dessus: %d\n", getpid());
        printf("Eh j'ai reçu le nombre %u\n", get_number_from_process());
    } else if (ac == 3) {
        /* Il sera l'envoyeur */
        pid_t pid = atoi(av[1]);
        unsigned int nb = atoi(av[2]);
        printf("J'envoie le nombre %u au processus n°%d\n", nb, pid);
        send_number_to_process(pid, nb);
    } else {
        fprintf(stderr, "Erreur d'arguments\n");
    }
    return 0;
}
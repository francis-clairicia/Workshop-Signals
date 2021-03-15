/*
** EPITECH PROJECT, 2021
** Workshop_Signals
** File description:
** sigaction
*/

/* Ce truc c'est pour que VS Code ne vous embête pas :) */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include <sys/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>

static bool GLOBAL_LOOP = false;

/*
Exercice 3:

Dans les exercices précédents, on se contentait juste de gérer un signal
sans trop en savoir plus.

Maintenant on voudrait avoir des informations supplémentaires
quant à son envoi.

Ici on veut afficher le PID (process ID) du processus qui nous a envoyé
ce signal.

Modifie le code ci-dessous pour y parvenir

Fonction à utiliser : sigaction(2)
*/

/* Tu as une fonction à créer ici. */
/*
Bon allez cette fois-ci je t'aide un peu
Là ta fonction doit prendre 3 arguments:
    1) Celui des 2 premières fonctions
    2) Une structure un peu particulière
    3) Un pointeur qui ne nous sera pas utile
*/
void sigint_handler(int sig, siginfo_t *info, void *ucontext)
{
    printf("%d\n", info->si_pid);
    GLOBAL_LOOP = false;
}

int main(void)
{
    struct sigaction action;

    action.sa_flags = SA_SIGINFO; // On veut des informations supplémentaires
    sigemptyset(&action.sa_mask); // Pas de masque à appliquer aux signaux

    /* On utilise sa_sigaction si on a donné comme flag SA_SIGINFO */
    /* Sinon, ce sera sa_handler */
    /* Tu comprends bien que ce ne sera pas le même prototype de fonction */
    /* Mais alors c'est quoi ? */
    /* (Oui j'l'ai déjà un peu spoil mais c'était si évident ? :) ) */
    action.sa_sigaction = sigint_handler;

    /* Utilisation de sigaction */
    sigaction(SIGINT, &action, NULL);

    GLOBAL_LOOP = true;
    while (GLOBAL_LOOP == true) {
        continue;
    }
    printf("Je vais m'arrêter correctement.\n");
    return 0;
}
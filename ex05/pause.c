/*
** EPITECH PROJECT, 2021
** Workshop_Signals
** File description:
** pause
*/

#include <sys/types.h>
#include <stdio.h>
#include <signal.h>

int pause(void);

/*
Exercice 5:

Bon ok, ce n'en est pas vraiment un.
En même temps la fonction consiste à attendre n'importe quel signal,
je suppose qu'on a pas besoin de te faire un dessin.

La seule chose à savoir en + dessus est que si une fonction handler est créée
avec signal() ou sigaction(), alors cette fonction sera obligatoirement
appelée AVANT la fin de pause()
*/

int main(void)
{
    pause();
    /* Donc normalement ici votre fonction a déjà été appelée. */
}
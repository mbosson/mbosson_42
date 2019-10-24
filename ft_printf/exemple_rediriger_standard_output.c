#include <sys/wait.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>
// ----------->> FONCTION QUI RECUPERE LA SORTIE STANDARD D'UNE COMMANDE UNIX DANS UNE CHAINE DE CARACTERE <<----------- \\


char *redirection_sortie_standard();
char buf, sortie[10000];
char *redirection_sortie(char *commande, char *option)
{
    int tube[2];
    pid_t cpid;
    int i = 0;

    if (pipe(tube) == -1)
    {
        perror("Le pipe n'a pas fonctionn�");
        exit(EXIT_FAILURE); // quitte le programme si le pipe n'est pas cr��
    }
    cpid = fork();
    if (cpid == -1)
    {
        perror("Le fork n'a pas fonctionn�");
        exit(EXIT_FAILURE); // quitte le programme si le fork n'as pas fonctionn�
    }
    if (cpid != 0)
    {    /* Le pere est lecteur sur le tube */
        close(tube[1]);          /* Fermeture du cot� �criture non utilis� par le pere */

        /* cette boucle while permet de lire les caract�res pr�sent sur le cot� lecture du tube et les stocker dans la chaine sortie */
        while (read(tube[0], &buf, 1) > 0)
        {
            sortie[i] = buf; // rempli la chaine sortie caract�re par caract�re
            i++;
            sortie[i] = '\0'; // indique la fin de la chaine de caract�re
        }
        close(tube[0]); // fermeture du cot� lecture du tube une fois la lecture une fois que la fonction read a renvoy� 0 : EOF, la lecture termin�e
        return sortie; // la fonction retourne la chaine qui contient le contenu de la sortie standard
        exit(EXIT_SUCCESS);
    }
    else
    {                             /* Le fils �crit dans le tube  */
        close(tube[0]);          /* Fermeture du cot� lecture non utilis� par le fil */
        dup2(tube[1], 1);     /* */
        execlp(commande, commande, option, (char *)NULL);
        close(tube[1]);          /* Le pere lecteur verra un "EOF" ce qui permet la synchronisation */
        wait(NULL);                /* Attendre que le fils se termine */
        exit(EXIT_SUCCESS);
    }
}

int main( int argc, char ** argv )
{
    char *resultat;

    printf("Bonjour \n");
    char *cmd = "ps";
    char *opt = "-e";
    resultat = redirection_sortie(cmd, opt); // resultat doit stocker la sortie standard, autrement dit l'affichage de la commande "ps" avec pour argument "-e"

    /* ---> ce printf s'affiche <--- */
    printf("le resultat est : %s \n", resultat);

    // celui ci �galement :
    printf("Bla bla \n");
    return 0;
}

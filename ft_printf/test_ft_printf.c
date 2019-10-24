#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int ft_printf(const char *str, ...);

void    test1(void)
{
    int i = 0;
    int compt;
    char buffer1[100];
    char buffer2[100];
    char err_buffer1[100];
    char err_buffer2[100];
    int true_return_value;
    int cpy_return_value;
    char str[] = "%%";
    int error = 0;

    //TRUE
    /*true_return_value = snprintf(buffer1, 100, str);
    compt = 0;
    while ((i = read(1, buffer1, 1)) > 0)
        compt += i;
    buffer1[compt] = 0;
    compt = 0;
    while ((i = read(2, err_buffer1, 1)) > 0)
        compt += i;
    err_buffer1[compt] = 0;*/

    //CPY
    printf("COPY : test|");
    cpy_return_value = printf(str);
    printf("|test\n");
    compt = 0;
    /*while ((i = read(1, buffer2, 1)) >= 0)
        compt += i;
    buffer2[compt] = 0;
    compt = 0;
    while ((i = read(2, err_buffer2, 1)) > 0)
        compt += i;
    err_buffer2[compt] = 0;*/

    //TEST
    /*if (true_return_value != cpy_return_value)
    {
        printf ("DIFF return value for [%s]\n", str);
        printf("TRUE : %d", true_return_value);
        printf("COPY : %d", cpy_return_value);
        error = 1;
    }
    if (strcmp(buffer1, buffer2) != 0)
    {
        printf ("DIFF standard output for [%s]\n", str);
        printf("TRUE : %s\n", buffer1);
        printf("COPY : %s\n", buffer2);
        error = 1;
    }
    if (strcmp(err_buffer1, err_buffer2) != 0)
    {
        printf ("DIFF error output for [%s]\n", str);
        printf("TRUE : %s\n", err_buffer1);
        printf("COPY : %s\n", err_buffer2);
        error = 1;
    }
    if (error == 0)
        printf("OK for [%s]\n", str);*/

    /*printf("TRUE : %d\nCOPY : %d\nTRUE STD : %s\nCOPY STD : %s\n", true_return_value, cpy_return_value, buffer1, buffer2);
    printf("TRUE ERR : %s\nCOPY ERR : %s\n", err_buffer1, err_buffer2);*/
    //printf("|%s|\n", buffer1);
    #include <stdio.h>
    int nbLus = fscanf( stdin, "%d", &i) ;
    fprintf(stdin, "5");
    if(nbLus != 1)
    {
        // erreur : on n’a pas pu lire un entier
        fprintf(stderr, "Erreur : lecture entier impossible !") ;
        return 1 ; // sortie du programme
    }
        fprintf(stdout, "valeur lue %d\n", i) ;
    return 0 ;
}

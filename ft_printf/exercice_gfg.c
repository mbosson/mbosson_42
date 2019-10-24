/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: abourbou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 16:45:57 by abourbou     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 17:53:49 by abourbou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

/* pipe[0] = lecture
 * pipe[1] = ecriture*/

char	buffer[200];
char	buff_ret [200];

int		main(int argc, char **argv)
{
	int		p1[2];
	int		p2[2];
	int		pid;
	int		i;
	char	str[] = "www.geeks";

	char	car_buf;
	(void)argc;

	if (pipe(p1) < 0)
	{
		printf("echec de pipe\n");
		return (0);
	}
	if (pipe(p2) < 0)
	{
		printf("echec du deuxieme pipe\n");
		return (0);
	}
	if ((pid = fork()) == -1)
	{
		printf("echec de fork\n");
		return (0);
	}
	if (pid > 0) //c'est le process parent P1 qui envoie la string a P2
	{
		close (p1[0]); //fermeture lecture car useless
		i = 0;
		while (argv[1][i])
			i++;
		//printf("argv[1] : %s\n", argv[1]);
		write (p1[1], argv[1], i);

		close (p1[1]);
		//printf("P1 attends que P2 lui renvoie\n");
		if (wait(0) == -1) //attente de la lecture par le process fils
		{
			printf("echec de wait : pas de retour du processus fils\n");
			return (0);
		}
		//printf("fin attente\n");
	}
	else	//c'est le process fils P2 qui recoit et envoie le tout concatener
	{
		close (p1[1]);
		//printf("je suis le fils!\n");
		i = 0;
		while(read(p1[0], &car_buf, 1) > 0)
		{
			buffer[i] = car_buf;
			i++;	
		}
		buffer[i] = 0;
		//printf("buffer : %s\n", buffer);
		close(p1[0]);
	}
	(void)str;
	if (pid == 0) //maintenant ecriture de P2 dans P1
	{
		i = 0;
		close(p2[0]);
		while (str[i])
			i++;
		write(p2[1], str, i);
		//printf("test\n");
		i = 0;
		while (buffer[i])
			i++;
		write(p2[1], buffer, i);
		
		close (p2[1]);		
	}
	if (pid) 
	{
		close(p2[1]);
		i = 0;
		while (read(p2[0], &car_buf, 1) > 0)
		{
			buff_ret[i] = car_buf;
			i++;
		}
		buff_ret[i] = 0;
		write(1, buff_ret, i);
		write(1, "\n", 1);
		close (p2[0]);
	}
	//printf("test : %d\n", pid);
	return (0);	
}

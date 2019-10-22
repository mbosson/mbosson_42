/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 13:10:50 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 18:22:06 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int main(void)
{
	char	chemin[3];
	int		bug;

	bug = 0;
	print("Ce jeux est un jeux à choix multiples. Vos choix et vos actes auront des consequences, et vous en etes le seul responsable. ");
	print("Lorsque qu'un choix se presente a vous, rentrez le chiffre correspondant et appuyez sur Entree");
	choice(chemin, 3, 2, "Avez vous bien compris ? Oui (1) / Non (2)");
	if (chemin[0] == '2')
	{
		print("Tant pis");
		return (0);
	}
	print("Tres bien, nous allons pouvoir commencer");
	reveil(chemin, bug);
	return (0);
}

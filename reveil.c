/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reveil.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 15:31:15 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 18:18:16 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int reveil(void)
{
	print("Vous vous réveillez dans une pièce confinée, des traces de menottes sur le bras");
	print("Vous ne vous souvenez pas qui vous êtes, ni pourquoi vous êtes là, mais il semblerait qu’on vous ai emmené ici");
	print("Vous sortez et arriver dans une pièce légèrement plus grande. Il fait chaud et froid à la fois.");
	print("Vous voyez une silhouette au centre de la pièce et décidez de vous en approcher.");
	print("Au fur et à mesure que vous vous rapprochez, l’odeur devient de plus en plus nauséabondes");
	print("Des lors que vous vous tenez à quelque mètres de la silhouette, celle ci se relève, laissant apparaitre sa face putride de gobelin !");
	print("Le gobelin vous fait face, vetu d'habits en tissus, legerement dechire");
	choice(3, 3, "Que voulez vous faire ? (1) Lui foncer dessus  / (2) Lui lancer une boule de feu / (3) Prendre votre dague en main");
	if (chemin[0] == '1')
	{
		print("Le gobelin vous empalle avec son épée rouillé, tout simplement. Mourrir aussi vite, faut vraiment être con..");
		life = 0;
	}
	if (chemin[0] == '2')
	{
		print("Une étrange énergie survient en vous et le creu de vos mains expluse une boule enflamée de la taille d'un ballon de football.");
		print("Les vêtements du gobelin s'enflamment et, dans sa panique, il vous fonce dessus. Votre robe s'enflamme à son tour et votre peau fusionne avec elle");
		print("Dans un mauvais Marvel, vous seriez devenu un super-hero, mais là vous etes juste mort..");
		life = 0;
	}
	if (chemin[0] == '3')
		print("Vous vous saisissez de votre dague et le gobelin vous fonce dessus.");
	return (1);
}

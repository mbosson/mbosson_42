/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reveil.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbosson <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 15:31:15 by mbosson      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/21 17:27:11 by mbosson     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "header.h"

int reveil(char *chemin, int bug)
{
	print("Vous vous réveillez dans une pièce confinée, des traces de menottes sur le bras");
	print("Vous ne vous souvenez pas qui vous êtes, ni pourquoi vous êtes là, mais il semblerait qu’on vous ai emmené ici");
	print("Vous sortez et arriver dans une pièce légèrement plus grande. Il fait chaud et froid à la fois.");
	print("Vous voyez une silhouette au centre de la pièce et décidez de vous en approcher.");
	print("Au fur et à mesure que vous vous rapprochez, l’odeur devient de plus en plus nauséabondes");
	print("Des lors que vous vous tenez à quelque mètres de la silhouette, celle ci se relève, laissant apparaitre sa face putride de gobelin !");
	print("Le gobelin vous fait face, vetu d'habits en tissus, legerement dechire");
	bug = choice(chemin, 3, 3, "Que voulez vous faire ? (1) Lui foncer dessus  / (2) Lui lancer une boule de feu / (3) Prendre votre dague en main");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbs_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeulema <jmeulema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:42:28 by jmeulema          #+#    #+#             */
/*   Updated: 2022/12/23 11:52:01 by jmeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10  // nombre de nombres à générer
#define X 0   // borne inférieure de l'intervalle
#define Y 1000 // borne supérieure de l'intervalle

// Cette fonction génère et affiche une liste de N nombres différents compris entre X et Y
void generer_liste_nombres(int n, int x, int y)
{
  int nombres[y - x + 1]; // tableau pour stocker les nombres compris entre X et Y
  int i;
  srand(time(NULL)); // initialisation de la graine du générateur de nombres aléatoires

  // Remplissage du tableau avec tous les nombres compris entre X et Y
  for (i = 0; i < y - x + 1; i++) 
  {
    nombres[i] = x + i;
  }

  // Mélange aléatoire des éléments du tableau
  for (i = y - x; i > 0; i--) {
    int j = rand() % (i + 1);
    int tmp = nombres[i];
    nombres[i] = nombres[j];
    nombres[j] = tmp;
  }

  // Affichage des N premiers éléments du tableau mélangé
  for (i = 0; i < n; i++) {
    printf("%d ", nombres[i]);
  }
}

int main()
{
  generer_liste_nombres(500, 0, 1000);
  printf("\n");
  return 0;
}
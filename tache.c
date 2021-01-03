#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tache.h"
void alermante(int jour,int mois,int annee)
{
 tache2 c;
 FILE *f=NULL,*g=NULL;
 g=fopen("alermante.txt","w"); 
 f=fopen("temperature.txt","r");
 if(f==NULL)
  return;
 else
 {
  while(fscanf(f, "%d %d %d %d %f\n",&c.id,&c.jour,&c.mois,&c.annee,&c.valeur)!=EOF)
  {
   if(c.jour == jour && c.mois== mois && c.annee == annee )
{
   if(c.valeur<7 || c.valeur>11 )
    {
     if(g==NULL)
      {
       return;
      }
     else
      {
       fprintf(g,"%d %f\n",c.id,c.valeur);
      }
    }	
	
  }
 }
  fclose(f);
  fclose(g);
 }
}


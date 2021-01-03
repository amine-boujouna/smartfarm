#ifdef HAVE_CONFIG_H_
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum{
        ENOM,
        EREFERENCE,
        ETYPE,
        EEMPLACEMENT,
     };

void ajoutercapteur(capteur p)
{
FILE *f;
	f=fopen("capteur.txt","a+");
	if(f!=NULL)
	{
	fprintf(f,"%s %s %s %s\n",p.nom,p.reference,p.type,p.emplacement);
	fclose(f);
	}
}





void affichercapteur(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter	iter;
GtkListStore *store;
FILE *f;
char nom[50];
char reference[50];
char type[50];
char emplacement[50];
store=NULL;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("reference", renderer, "text",EREFERENCE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("emplacement", renderer, "text",EEMPLACEMENT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	store=gtk_list_store_new (4, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("capteur.txt", "r");
	if(f==NULL)
	{
return;
	}
	else
	{ 	
	f = fopen("capteur.txt","a+");
		while(fscanf(f,"%s %s %s %s \n",nom,reference,type,emplacement)!=EOF)
		{
		gtk_list_store_append (store, &iter);
		gtk_list_store_set (store, &iter,ENOM, nom,EREFERENCE,reference,ETYPE,type,EEMPLACEMENT, emplacement, -1);
		}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}
}



void modifiercapteur(capteur p,char nom[20])
{
capteur p1;

FILE*f;
FILE*m;

	f=fopen("capteur.txt","r");
	m=fopen("modifier.txt","a+");
	//if (f!=NULL)
	//{
		while(fscanf(f,"%s %s %s %s \n",p1.nom,p1.reference,p1.type,p1.emplacement)!=EOF)
		{
			if ((strcmp(nom,p1.nom)!=0))
   			 fprintf(m," %s %s %s %s  \n",p1.nom,p1.reference,p1.type,p1.emplacement);}
			//
//else
			fprintf(m,"%s %s %s %s \n",nom,p.reference,p.type,p.emplacement);
		//}
	//}
	fclose(f);
	fclose(m);
	remove("capteur.txt");
	rename("modifier.txt","capteur.txt");
}

void supprimercapteur(char nom[50])
{
capteur p;
//char nom[50];
char reference[50];
char type[50];
char emplacement[50];
FILE *f,*f1;
f=fopen("capteur.txt","r");
f1=fopen("tmp.txt","w");
//if ((f!=NULL)&&(f1!=NULL))
//{
//return;
//}
//else {
while(fscanf(f,"%s %s %s %s\n",p.nom,p.reference,p.type,p.emplacement)!=EOF)
{
        if(strcmp(p.nom,nom)!=0)
//||strcmp(p.reference,reference)!=0||        strcmp(p.type,type)!=0||strcmp(p.emplacement,emplacement)!=0)

fprintf(f1,"%s %s %s %s",p.nom,p.reference,p.type,p.emplacement);
}

fclose(f);
fclose(f1);

remove("capteur.txt");
rename("tmp.txt","capteur.txt");

}






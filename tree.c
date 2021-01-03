#ifdef HAVE_CONFIG_H_
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "callbacks.h"
#include <gtk/gtk.h>

enum{
        id_c,
        valeur_c,
     };
void afficheralermente(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter	iter;
GtkListStore *store;
FILE *f;
char id[50];
char valeur[50];
int id1;
float valeur1;
store=NULL;

	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("identifiant", renderer, "text",id_c, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("valeur", renderer, "text",valeur_c, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	
	store=gtk_list_store_new (2, G_TYPE_STRING, G_TYPE_STRING);
	f=fopen("alermante.txt", "r");
	if(f==NULL)
	{
return;
	}
	else
	{ 	
		while(fscanf(f,"%d %f\n",&id1,&valeur1)!=EOF)
		{
		sprintf(id,"%d",id1);
	        sprintf(valeur,"%.2f",valeur1);
		gtk_list_store_append (store, &iter);
		gtk_list_store_set (store, &iter,id_c, id,valeur_c,valeur,-1);
		}
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
	g_object_unref (store);
	}
}
}


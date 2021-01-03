#include <gtk/gtk.h> 
typedef struct{
char nom[20];
char reference[20];
char type[20];
char emplacement[20];
}capteur;

void ajoutercapteur(capteur p);
void  affichercapteur(GtkWidget *liste);
void modifiercapteur(capteur p,char nom[20]);
void supprimercapteur(char nom[50]);

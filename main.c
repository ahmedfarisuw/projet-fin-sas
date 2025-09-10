#include <stdio.h>
#include <string.h>

#define MAX_JOUEURS 100

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    int numeroMaillot;
    char poste[50];
    int age;
    int buts;
    char dateInscription[50];
    char statut[50];
} joueur;

joueur equipe[MAX_JOUEURS];
int nombreJoueurs = 0;
int ajoutID = 1;
void ajouterJoueur() {
    if (nombreJoueurs >= MAX_JOUEURS) {
        printf("⚠ Impossible d'ajouter plus de joueurs !\n");
        return;
    }

    joueur j;
    j.id = ajoutID++;

    printf("\n--- Ajouter un joueur ---\n");
    printf("Nom : ");
    scanf("%s", j.nom);
    printf("Prenom : ");
    scanf("%s", j.prenom);
    printf("Numero de maillot : ");
    scanf("%d", &j.numeroMaillot);
    printf("Poste (gardien/defenseur/milieu/attaquant) : ");
    scanf("%s", j.poste);
    printf("Age : ");
    scanf("%d", &j.age);
    printf("Nombre de buts : ");
    scanf("%d", &j.buts);
    printf("Statut (titulaire/remplacant) : ");
    scanf("%s", j.statut);

    equipe[nombreJoueurs++] = j;
    printf("✅ Joueur ajoute avec succes ! ID = %d\n", j.id);
}
void ajouterPlusieursJoueurs() {
    int n;
    printf("\nCombien de joueurs voulez-vous ajouter ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ajouterJoueur();
    }
}
void afficherjoueurs(){
    int choix;
    joueur j ;
    if(nombreJoueurs==0){
         while (choix != 0);
    printf("\n----------listes des joueurs----------\n");
    for(int i=0;i<nombreJoueurs;i++){
        j=equipe[i];
        printf("ID:%d|%s%s|Maillot:%d|poste:%d|age:%d|buts:%d|statut:%s\n",j.id,j.nom,j.prenom,j.numeroMaillot,j.poste,j.age,j.buts,j.statut);
    }
        printf("Aucun joueur dans équipe.\n");
        return;
    }
}

int main() {
    int choix;
    

    do {
        printf("\n===== MENU =====\n");
        printf("1. Ajouter un joueur\n");
        printf("2. Ajouter plusieurs joueurs\n");
        printf("3.Afficher joueurs\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterJoueur(); break;
            case 2: ajouterPlusieursJoueurs(); break;
            case 3: afficherjoueurs();break;
            case 0: printf("👋 Au revoir !\n"); break;
            default: printf("⚠ Choix invalide.\n");
        }
    
    return 0;
    }}

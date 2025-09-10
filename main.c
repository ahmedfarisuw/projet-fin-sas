#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct {
    int id;
    char nom[30];
    char prenom[30];
    int numeroMaillot;
    char poste[20];
    int age;
    int buts;
    char statut[15];
} Joueur;

Joueur equipe[MAX];
int nbJoueurs = 0;
int nextId = 1;
void ajouterJoueur() {
    if (nbJoueurs >= MAX) {
        printf("⚠ L'équipe est pleine!\n");
        return;
    }

    Joueur j;
    j.id = nextId++;

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

    getDate(j.dateInscription);

    printf("Statut (titulaire/remplacant) : ");
    scanf("%s", j.statut);

    equipe[nbJoueurs++] = j;
    printf("✅ Joueur ajoute avec succes !\n");
}
void ajouterPlusieurs() {
    int n;
    printf("Combien de joueurs voulez-vous ajouter ? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\n--- Ajout joueur %d ---\n", i + 1);
        ajouterJoueur();
    }
}
void afficherJoueurs() {
    if (nbJoueurs == 0) {
        printf("⚠ Aucun joueur dans l'equipe.\n");
        
        return;
    }
    printf("\n--- Liste des joueurs ---\n");
    for (int i = 0; i < nbJoueurs; i++) {
        Joueur j = equipe[i];
        printf("ID:%d | %s %s | Maillot:%d | Poste:%s | Age:%d | Buts:%d | Date:%s | Statut:%s\n",
               j.id, j.nom, j.prenom, j.numeroMaillot, j.poste, j.age, j.buts, j.dateInscription, j.statut);
    }
}
void rechercherParId() {
    int id;
    printf("Entrez ID du joueur : ");
    scanf("%d", &id);

    for (int i = 0; i < nbJoueurs; i++) {
        if (equipe[i].id == id) {
            printf("Trouve: %s %s, Age:%d, Buts:%d\n",
                   equipe[i].nom, equipe[i].prenom, equipe[i].age, equipe[i].buts);
            return;
        }
    }
    printf("⚠ Joueur non trouve.\n");
}
void rechercherParNom() {
    char nom[30];
    printf("Entrez le nom du joueur : ");
    scanf("%s", nom);

    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(equipe[i].nom, nom) == 0) {
            printf("Trouve: ID:%d %s %s, Age:%d, Buts:%d\n",
                   equipe[i].id, equipe[i].nom, equipe[i].prenom, equipe[i].age, equipe[i].buts);
            return;
        }
    }
    printf("⚠ Joueur non trouve.\n");
}
void modifierJoueur() {
    int id;
    printf("Entrez ID du joueur a modifier : ");
    scanf("%d", &id);

    for (int i = 0; i < nbJoueurs; i++) {
        if (equipe[i].id == id) {
            int choix;
            printf("1. Modifier poste\n2. Modifier age\n3. Modifier buts\nChoix : ");
            scanf("%d", &choix);

            if (choix == 1) {
                printf("Nouveau poste : ");
                scanf("%s", equipe[i].poste);
            } else if (choix == 2) {
                printf("Nouvel age : ");
                scanf("%d", &equipe[i].age);
            } else if (choix == 3) {
                printf("Nouveaux buts : ");
                scanf("%d", &equipe[i].buts);
            }
            printf("✅ Modification effectuee.\n");
            return;
        }
    }
    printf("⚠ Joueur non trouve.\n");
}


void supprimerJoueur() {
    int id;
    printf("Entrez ID du joueur a supprimer : ");
    scanf("%d", &id);

    for (int i = 0; i < nbJoueurs; i++) {
        if (equipe[i].id == id) {
            for (int j = i; j < nbJoueurs - 1; j++) {
                equipe[j] = equipe[j + 1];
            }
            nbJoueurs--;
            printf("✅ Joueur supprime.\n");
            return;
        }
    }
    printf("⚠ Joueur non trouve.\n");
}

void statistiques() {
    if (nbJoueurs == 0) {
        printf("⚠ Aucun joueur.\n");
        return;
    }

    printf("Nombre total de joueurs : %d\n", nbJoueurs);

    int sommeAges = 0;
    int maxButs = -1, minAge = 200, maxAge = 0;
    int idMaxButs = 0, idMinAge = 0, idMaxAge = 0;

    for (int i = 0; i < nbJoueurs; i++) {
        sommeAges += equipe[i].age;

        if (equipe[i].buts > maxButs) {
            maxButs = equipe[i].buts;
            idMaxButs = i;
        }

        if (equipe[i].age < minAge) {
            minAge = equipe[i].age;
            idMinAge = i;
        }

        if (equipe[i].age > maxAge) {
            maxAge = equipe[i].age;
            idMaxAge = i;
        }
    }

    printf("Age moyen : %.2f\n", (float)sommeAges / nbJoueurs);
    printf("Meilleur buteur : %s %s (%d buts)\n", equipe[idMaxButs].nom, equipe[idMaxButs].prenom, equipe[idMaxButs].buts);
    printf("Le plus jeune : %s %s (%d ans)\n", equipe[idMinAge].nom, equipe[idMinAge].prenom, equipe[idMinAge].age);
    printf("Le plus age : %s %s (%d ans)\n", equipe[idMaxAge].nom, equipe[idMaxAge].prenom, equipe[idMaxAge].age);
}
int main() {
    int choix;
    do {
        printf("\n--- Menu Gestion Equipe ---\n");
        printf("1. Ajouter un joueur\n");
        printf("2. Ajouter plusieurs joueurs\n");
        printf("3. Afficher tous les joueurs\n");
        printf("4. Rechercher par ID\n");
        printf("5. Rechercher par Nom\n");
        printf("6. Modifier un joueur\n");
        printf("7. Supprimer un joueur\n");
        printf("8. Statistiques\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterJoueur(); break;
            case 2: ajouterPlusieurs(); break;
            case 3: afficherJoueurs(); break;
            case 4: rechercherParId(); break;
            case 5: rechercherParNom(); break;
            case 6: modifierJoueur(); break;
            case 7: supprimerJoueur(); break;
            case 8: statistiques(); break;
            case 0: printf("👋 Au revoir!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}

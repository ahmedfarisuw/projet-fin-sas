#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


void ajouterUnJoueur() {
    if (nbJoueurs >= MAX) {
        printf("⚠ Limite atteinte, impossible d'ajouter plus de joueurs.\n");
        return;
    }


    Joueur j;
    j.id = nextId++;

    printf("Nom : ");
    scanf("%29s", j.nom);

    printf("Prenom : ");
    scanf("%29s", j.prenom);

    printf("Numero de maillot : ");
    scanf("%d", &j.numeroMaillot);

    printf("entrer le poste:");
    scanf("%s", j.poste);

    printf("Age : ");
    scanf("%d", &j.age);

    printf("Nombre de buts : ");
    scanf("%d", &j.buts);

    printf("Statut (titulaire/remplacant) : ");
    scanf("%14s", j.statut);

    equipe[nbJoueurs++] = j;
    printf("Joueur ajoute avec succes !\n");
}
void choisirPoste() {
    int choix;

    printf("=== Choisissez un poste ===\n");
    printf("1. Gardien\n");
    printf("2. Milieu\n");
    printf("3. Défense\n");
    printf("4. Attaque\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            printf("Vous avez choisi : Gardien\n");
            break;
        case 2:
            printf("Vous avez choisi : Milieu\n");
            break;
        case 3:
            printf("Vous avez choisi : Défense\n");
            break;
        case 4:
            printf("Vous avez choisi : Attaque\n");
            break;
        default:
            printf("Choix invalide, veuillez entrer un nombre entre 1 et 4.\n");
            break;
    }
}
void ajouterPlusieursJoueurs() {
    int n;
    printf("Combien de joueurs voulez-vous ajouter ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n--- Ajout du joueur %d ---\n", i + 1);
        ajouterUnJoueur();
    }
}
void afficherJoueurs() {
    if (nbJoueurs == 0) {
        printf("⚠ Aucun joueur dans l'equipe.\n");
        
        return;
    }
    printf("  \n||-----------------------Liste des joueurs----------------------------------------\n||");
    for (int i = 0; i < nbJoueurs; i++) {
        Joueur j = equipe[i];
        printf("||ID:%d | nom: %s| prenom: %s | Maillot:%d | Poste: %s | Age:%d | Buts:%d |  Statut:%s||\n",
               j.id, j.nom, j.prenom, j.numeroMaillot,j.poste, j.age, j.buts,j.statut);
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
            printf("Modification effectuee.\n");
            return;
        }
    }
    printf("Joueur non trouve.\n");
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
            printf("Joueur supprime.\n");
            return;
        }
    }
    printf("Joueur non trouve.\n");
}

void statistiques() {
    if (nbJoueurs == 0) {
        printf("Aucun joueur.\n");
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
void sousMenurecherche(){
    int choix;
    do{
        printf("\n------sous-Menu recherche joueur ------\n");
        printf("1.rechercher par id.\n");
        printf("2.rechercher par nom.\n");
        printf("3.Retour au menu principal.\n");
        printf("votre choix:");
        scanf("%d",&choix);
        switch (choix){
        case 1:
            rechercherParId();
            break;
        case 2:
        rechercherParNom();
        break;
        case 3:
                printf("Retour au menu principal...\n");
                break;
        
        default:
         printf("Choix invalide, reessayez.\n");
        
        }
    }while(choix!=3);
}
void sousMenuAjout() {
    int choix;
    do {
        printf("\n--- Sous-Menu Ajouter Joueur ---\n");
        printf("1. Ajouter un seul joueur\n");
        printf("2. Ajouter plusieurs joueurs\n");
        printf("3. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterUnJoueur();
                break;
            case 2:
                ajouterPlusieursJoueurs();
                break;
            case 3:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide, reessayez.\n");
        }
    } while (choix != 3);
}
void trierParNom(Joueur tab[], int n) {
    Joueur temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(tab[i].nom, tab[j].nom) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}
void trierParAge(Joueur tab[], int n) {
    Joueur temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tab[i].age > tab[j].age) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}
void trierParPoste(Joueur tab[], int n) {
    Joueur temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(tab[i].poste, tab[j].poste) > 0) {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}
void sousMenuaffichage() {
    int choix;
    do {
        printf("\n--- Sous-Menu Afficher un joueur  ---\n");
        printf("1. Afficher par ordre alphabétique\n");
        printf("2. afficher par ordre age \n");
        printf("3. afficher les joueurs  par poste \n");
        printf("4. Retour au menu principal\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                trierParNom(equipe, nbJoueurs);
                afficherJoueurs();
                break;
            case 2:
                trierParAge(equipe, nbJoueurs);
                afficherJoueurs();
                break;
                case 3:
               trierParPoste(equipe, nbJoueurs);
               afficherJoueurs();
                break;
            case 4:
                printf("Retour au menu principal...\n");
                break;
            default:
                printf("Choix invalide, reessayez.\n");
        }
    } while (choix != 4);
}
int main() {
    int choix;
    do {
        printf("\n--- Menu Gestion Equipe ---\n");
        printf("1. Ajout des joueurs\n");
        printf("2. Affichage des joueurs\n");
        printf("3. Recherche des joueurs \n");
        printf("4. Modifier un joueur\n");
        printf("5. Supprimer un joueur\n");
        printf("6. Statistiques\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: sousMenuAjout() ; break;
            case 2: sousMenuaffichage(); break;
            case 3: sousMenurecherche(); break;
            case 4: modifierJoueur(); break;
            case 5: supprimerJoueur(); break;
            case 6: statistiques(); break;
            case 0: printf("👋 Au revoir!\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
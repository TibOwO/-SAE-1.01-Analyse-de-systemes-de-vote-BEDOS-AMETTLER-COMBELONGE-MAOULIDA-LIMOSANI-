// Bibliothèques
#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

// Espace de code
using namespace std;

// déclaration des variables
    int nbrParticipants = 0;             // Init. du compteur de participants/votants

    int jeu1, jeu2, jeu3, jeu4 = 0;      // Init. des compteurs de vote pour chaque jeu

    vector<string> nomJeux(4);           // Init. tableau avec le nom des jeux

    bool aff1, aff2, aff3, aff4 = false; // Init. variable pour gerer les égalités
    
//FONCTIONS 

//-- Liste les jeux presents dans le fichier input.txt --
void ListeJeu(string ligneLu, char delimiter)
{
    stringstream ss(ligneLu);           // Init. variable "ss" de type stringstream qui a pour option "ligneLu", passé en paramètre de la fonction "ListeJeu"
    string jeu;                         // Init. variable "jeu" de type string
    while (!ss.eof())                   // La boucle tourne tant que le programme n'est pas arrivé a lafin de la ligne lu (LigneLu)
    {
        getline(ss, jeu, delimiter);    // Entre ss en entrée standard et stock une string dans la variable jeux jusqu'a un delimiter passé en paramètre
        cout << jeu << endl;            // affiche la string stocké dans la variable jeu
    }
}

//-- Affiche les jeux recupérés précedement avec ListeJeu() dans le fichier de sortie --
void affichJeux(){
    cout << "Les quatre jeu sont : " << endl;   // Affiche une première phrase
    string ligneJeu;                            // Init. variable ligneJeu de type string
    for (int i = 0; i < 4; i++)                 // Boucle "for", lit la ligne, et enregistre la string lorsque que le curseur arrive au delimiter, 4 foix
    {
        cin >> ligneJeu;                        // enregistre la ligne dns la variable "ligneJeu"
        ListeJeu(ligneJeu, ' ');                // appel la fonction ListeJeu avec comme paramètre la ligneJeu et le delimiter
        nomJeux[i] = ligneJeu;                  // une fois les 4 jeux séparé, ils sont enregistré dans un tableau "nomJeux"
    }
}

//-- Comptabilise les voix de chaque votant et les enregistres dans les variables coorespondantes
void CompteVote(){
    while (cin.eof() == false)              // boucle "while", tant que la boucle n'est pas arrive a la fin du fichier, la boucle continue.
    {
        string ligneLue;                    // Init. variable ligneLue de type string
        cin >> ligneLue;                    // ligne suivante du fichier rentrée dans la variable ligneLue
        if (ligneLue == "1")                // Condition "if", si ligneLue vaut "1", alors ...
        {
            ++jeu1;                         // +1 a la variable jeu1
        }

        else if (ligneLue == "2")           // Condition "else if", sinon si ligneLue vaut "2", alors ...
        {
            ++jeu2;                         // +1 à la variable jeu2
        }

        else if (ligneLue == "3")           // Condition "else if", sinon si ligneLue vaut "3", alors ...
        {
            ++jeu3;                         // +1 à la variable jeu3
        }

        else if (ligneLue == "4")           // Condition "else if", sinon si ligneLue vaut "4", alors ...
        {
            ++jeu4;                         // +1 à la variable jeu4
        }

        else                                // Condition "else", sinon (si aucune des condition n'est verifiée) faire...
        {
            ++nbrParticipants;              // +1 a la variable nbrParticipants
        }
    }
    nbrParticipants = nbrParticipants / 2;  // On divise le nombre de nbrParticipants car le compteur compte le nom ET prenom du votants.
}

// -- Affiche les votes optenue pour chaque jeux --
void affichResultat(){
    cout << "Resultat final : " << endl                             // Affiche "Resultat final : " avec un retour a la ligne
         << endl                                                    // second retour a la ligne pour la mise en forme
         << nomJeux[0] << " = " << jeu1 << endl                     // Affichage du premier jeu du tableau "nomJeu" avec son score et un retour a la ligne
         << nomJeux[1] << " = " << jeu2 << endl                     // Affichage du second jeu du tableau "nomJeu" avec son score et un retour a la ligne
         << nomJeux[2] << " = " << jeu3 << endl                     // Affichage du troisième jeu du tableau "nomJeu" avec son score et un retour a la ligne
         << nomJeux[3] << " = " << jeu4 << endl                     // Affichage du quatrième jeu du tableau "nomJeu" avec son score et un retour a la ligne
         << "Nombre de participant = " << nbrParticipants << endl   // Affichege du nombre de participants et un retour a la ligne
         << endl;                                                   // second retour a la ligne pour la mise en forme
}

// -- Tri les jeux en fonction des vote reçu, du plus grand au plus petit --
vector<int> CalculGagnant(int jeu1, int jeu2, int jeu3, int jeu4)
{
    vector<int> tab(4);                         // Init. tableau d'entier comportant jusqu'à 4 valeur
    tab[0] = jeu1;                              // la place 0 du tableau est jeu1
    tab[1] = jeu2;                              // la place 1 du tableau est jeu2
    tab[2] = jeu3;                              // la place 2 du tableau est jeu3
    tab[3] = jeu4;                              // la place 3 du tableau est jeu4
    sort(tab.begin(), tab.end(), greater<>());  // Tri l'entièreté du tableau du plus grand au plus petit
    return tab;                                 // retourne le tableau trié
}

// -- Affiche le classement des jeux, du premier au dernier --
void affichGagnant(vector<int> tab){
    for (int i = 0; i <= tab.size() - 1; ++i)               // Boucle for, 
    {
        if (i == 0)
        {
            cout << i + 1 << "er, ";
        }
        else
        {
            cout << i + 1 << "ème, ";
        }

        if (tab[i] == jeu1 && aff1 == false)
        {

            cout << nomJeux[0];
            aff1 = true;
        }

        else if (tab[i] == jeu2 && aff2 == false)
        {
            cout << nomJeux[1];
            aff2 = true;
        }

        else if (tab[i] == jeu3 && aff3 == false)
        {
            cout << nomJeux[2];
            aff3 = true;
        }

        else if (tab[i] == jeu4 && aff4 == false)
        {
            cout << nomJeux[3];
            aff4 = true;
        }
        cout << " avec un score de : " << tab[i] << endl;
    }
}


int main()
{
    //-- Affiche les jeux recupérés précedement avec ListeJeu() dans le fichier de sortie --
    affichJeux();

    //-- Comptabilise les voix de chaque votant et les enregistres dans les variables coorespondantes
    CompteVote();

    // -- Affiche votes optenue pour chaque jeux --
    affichResultat();

    // -- Tri les jeux en fonction des vote reçu, du plus grand au plus petit --
    vector<int> tab = CalculGagnant(jeu1, jeu2, jeu3, jeu4);
    
    // -- Affiche le classement des jeux, du premier au dernier --
    affichGagnant(tab);
}

/*
Fichier: DresseurApprenti.cpp
Auteur(s): 
Date de creation: 
Date de modification: 
*/
#include "DresseurApprenti.h"

// todo:
// Faire l'initialisation de tout les attributs
DresseurApprenti::DresseurApprenti(const string& nom, const string & nomObjetMagique, int bonus, float tauxEchec )
{
    
}

// todo
// méthode de la classe dérivée
void DresseurApprenti::utiliserObjetMagique(shared_ptr<Creature> creature) {
    
    
    // todo:
    // 1. Permettre l'affichage decrivant comme quoi l'objet courant
    // (DresseurApprenti) est en train d'utiliser son objet magique.
    // (voir affichage)

    
    // bonusApprenti
    int bonusApprenti = static_cast <int> (this->obtenirObjetMagique().obtenirBonus()*(100-tauxEchec_)/100);
    
    // 2. Normalement, un bonus était ajouter à deux moments:
    
    // creature->modifierPointDeVie(creature->obtenirPointDeVie() +
    // objetMagique_.obtenirBonus());
    
    // On veut desormais que ce soit le bonusApprenti qui soit ajoute
    // a la place de objetMagique_.obtenirBonus()
    
    // indice 1: Il s'agit d'une nouvelle implementation de la
    // methode utiliserObjetMagique. Par contre, elle est extremement
    // similaire a celle de la classe de base a quelque details
    // pres. Reutilisez le code de la methode utiliserObjetMagique de la
    // classe de base.
    
    // indice 2: Fiez-vous au test sur les objets magiques
    
    
}

float DresseurApprenti::obtenirTauxEchec() const{ return tauxEchec_;}

 void DresseurApprenti::modifierTauxEchec(float tx ) { tauxEchec_ = tx;}

// todo:
// 1. Fait l'affichage des informations du dresseur
// ( vous devez reutiliser la methode de la classe parent )
// 2. Faire l'affichage du taux d'echec de la creature
// ( fiez-vous a l'affichage )
ostream& operator<<(ostream& os, const DresseurApprenti& dresseur) {
    return os;
}


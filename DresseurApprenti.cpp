/*
Fichier: DresseurApprenti.cpp
Auteur(s): 
Date de creation: 
Date de modification: 
*/
#include "DresseurApprenti.h"

// todo: DONE
// Faire l'initialisation de tout les attributs DONE
DresseurApprenti::DresseurApprenti(const string& nom, const string& nomObjetMagique, int bonus, float tauxEchec) :Dresseur(nom, nomObjetMagique, bonus)
{
    tauxEchec_ = tauxEchec;
}

// todo DONE
// méthode de la classe dérivée
void DresseurApprenti::utiliserObjetMagique(shared_ptr<Creature> creature) {
    
    
    // todo:
    // 1. Permettre l'affichage decrivant comme quoi l'objet courant DONE
    // (DresseurApprenti) est en train d'utiliser son objet magique.
    // (voir affichage)
    cout << this->nom_ << " utilise son objet magique de dresseur apprenti" << endl;
    
    // bonusApprenti
    int bonusApprenti = static_cast <int> (this->obtenirObjetMagique().obtenirBonus()*(100-tauxEchec_)/100);
    
    // 2. Normalement, un bonus était ajouter à deux moments:
    
    // creature->modifierPointDeVie(creature->obtenirPointDeVie() +
    // objetMagique_.obtenirBonus());
    
    // On veut desormais que ce soit le bonusApprenti qui soit ajoute
    // a la place de objetMagique_.obtenirBonus()
    if ((creature->obtenirPointDeVieTotal() - creature->obtenirPointDeVie()) >= objetMagique_.obtenirBonus()) {
        creature->modifierPointDeVie(creature->obtenirPointDeVie() + bonusApprenti);
    }
    else {
        creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());
    }
    if ((creature->obtenirEnergieTotale() - creature->obtenirEnergie()) > objetMagique_.obtenirBonus())
    {
        creature->modifierEnergie(creature->obtenirEnergie() + bonusApprenti);
    }
    else {
        creature->modifierEnergie(creature->obtenirEnergieTotale());
    }
    // indice 1: Il s'agit d'une nouvelle implementation de la
    // methode utiliserObjetMagique. Par contre, elle est extremement
    // similaire a celle de la classe de base a quelque details
    // pres. Reutilisez le code de la methode utiliserObjetMagique de la
    // classe de base.
    
    // indice 2: Fiez-vous au test sur les objets magiques
    
    
}

float DresseurApprenti::obtenirTauxEchec() const{ return tauxEchec_;}

 void DresseurApprenti::modifierTauxEchec(float tx ) { tauxEchec_ = tx;}

// todo: DONE
// 1. Fait l'affichage des informations du dresseur
// ( vous devez reutiliser la methode de la classe parent )
// 2. Faire l'affichage du taux d'echec de la creature
// ( fiez-vous a l'affichage )
ostream& operator<<(ostream& os, const DresseurApprenti& dresseur) {
    
    
   //Dresseur& refDresseur = const_cast<DresseurApprenti&>(dresseur);
   //dresseur = static_cast<DresseurApprenti&>(refDresseur);
   //os << static_cast<DresseurApprenti&>(refDresseur);
    os << dresseur.nom_ << " possede " << dresseur.creatures_.size() << " creature(s):" << endl;
    for (shared_ptr<Creature> c : dresseur.creatures_) {

        // todo:
        // Verifier s'il s'agit d'une creature magique
        if (dynamic_cast<CreatureMagique*>(c.get())) {
            // S'il s'agit bien d'une creature magique,
                    // afficher "Creature magique:"
            cout << "Creature magique: " << endl;
        }
        else {
            // Si c'est une CreatureExperience, faite
            // l'affichage de "Creature d'experience:"
            cout << "Creature d'experience: " << endl;
        }

        os << *c << endl;
        os << dresseur.nom_ << " possede l'objet suivant: " << endl;
        os << dresseur.objetMagique_;
    }

    os << "et a un taux d'echec de " << dresseur.obtenirTauxEchec() << endl;
    return os;
}


#include "CreatureExperience.h"

// todo: DONE
// Faire l'initialisation de tout les attributs
CreatureExperience::CreatureExperience(const string& nom) :Creature(nom), forceExperience_(0) {}
    //nom_ = nom; 
    //this.nom_ = nom; //proposition chargee td
//implementation apres ":"


// todo: DONE VERIFIED
// Faire l'initialisation de tout les attributs
CreatureExperience::CreatureExperience(const string& nom, unsigned int attaque, unsigned int defense, unsigned int pointDeVie, unsigned int energie, Pouvoir pouvoir, unsigned int forceExp):Creature(nom, attaque, defense, pointDeVie, energie, pouvoir), forceExperience_(forceExp){}
//implementation apres ":"

// todo: DONE
// Faire l'initialisation de tout les attributs
CreatureExperience::CreatureExperience(const Creature& creature, unsigned int forceExp):Creature(creature), forceExperience_(forceExp){}
//implementation apres ":"


// todo:
// Faire l'initialisation de tout les attributs
CreatureExperience::CreatureExperience(const CreatureExperience& creature):Creature(creature), forceExperience_(creature.obtenirForceExperience()) {}
//implementation apres ":"



// todo
// Faire la surcharge de l'opérateur = de maniere a ce que
// les attributs de la creatureExperience puisse etre copie
// dans l'objet courant.
CreatureExperience& CreatureExperience::operator= (const CreatureExperience &  creature)
{
    if (this != &creature) {
        Creature::operator=(creature);
        forceExperience_ = creature.obtenirForceExperience();
    }
	   return *this;
}

// todo
// energie de creatureExperience est additionné à la forceExperience
// l'attaque rate 1 fois sur 10
void CreatureExperience::attaquer(Creature& creature)
{
    // todo
    // 1. Modifier l'energie de l'objet courant pour qu'elle
    // devienne: (l'energie courante + la force Experience)
    
    
    // todo
    // 2. La méthode attaquer de la classe de base avait une
    // chance sur 6 de ne pas fonctionner. Dans cette classe
    // la creature a de l'experience. Ses attaques ne
    // fonctionnent pas uniquement 1 fois sur 10.
    // Son attaque ne fonctionnera pas si tentative est 5.
    
    // indice 1: Il s'agit d'une nouvelle implementation de la
    // methode attaquer. Par contre, elle est extremement
    // similaire a celle de la classe de base a quelque details
    // pres. Reutilisez le code de la methode attaquer de la
    // classe de base.
    
    // indice 2: Fiez-vous au test sur les attaques

    if (energie_ >= pouvoir_->obtenirEnergieNecessaire()) {
        if (creature.obtenirPointDeVie() >= 0) {

            int degat = 0;

            int degatPotentiel = static_cast<int>(pouvoir_->obtenirNombreDeDegat()) * (static_cast<int>(attaque_) / 2);

            // Determiner la defense restante de la creature
            int defenseRestante = static_cast<int>(creature.obtenirDefense()) - degatPotentiel;
            
            if (defenseRestante < 0)
            {
                degat = -defenseRestante;
                creature.modifierDefense(0);
            }
            else {
                creature.modifierDefense(defenseRestante);
            }

            // L'attaque rate une fois sur 6
            int tentative = rand() % 10;

            if (tentative != 5) {

                std::cout << nom_ << " lance " << pouvoir_->obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;

                if (degat > creature.obtenirPointDeVie()) {
                    creature.modifierPointDeVie(0);
                    int xp = experienceGagnee(creature);

                    cout << nom_ << " a gagne " << xp << " XP" << endl << endl;
                }
                else {
                    creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
                }

                cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
                energie_ -= pouvoir_->obtenirEnergieNecessaire();
            }
            else {
                std::cout << "Attaque " << pouvoir_->obtenirNom() << " a echouee" << endl;
            }
        }
        else {
            std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << endl;
        }
    }
    else
    {
        cout << this->obtenirNom() << " n'as plus assez d'énergie pour se battre" << endl;
    }
    
}
// todo DONE VERIFIED
// Se fier à l'affichage des tests->
// devrait dire que la creature {nom de la creature}
// est une creature d'experience et devrait afficher
// sa force experience.
void CreatureExperience::afficher() const
{
    cout << "Creature Experience";
}

// todo DONE VERIFIED
// Se fier à l'affichage des tests->
// 1. devrait utiliser la méthode afficher de l'objet courant
// 2. devrait faire appel à la surcharge de l'operateur <<
// de la classe parent.
std::ostream& operator<<(std::ostream & os, const CreatureExperience& creature)
{
    creature.afficher();
    os << static_cast<Creature>(creature);
	return os;
}

// todo
// doit retourner l'attribut forceExperience_ de l'objet courant
unsigned int CreatureExperience::obtenirExperience () const
{
    return this->forceExperience_;
}

unsigned int CreatureExperience::obtenirForceExperience() const
{
	return forceExperience_;
}

void CreatureExperience::modifierForceExperience(unsigned int forceExperience)
{
	forceExperience_ = forceExperience;
}

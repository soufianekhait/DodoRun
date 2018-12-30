#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf ;

void afficheTitre(RenderWindow &fenetre);
void afficheMenu(RenderWindow &fenetre);
void afficheRegle(RenderWindow &fenetre);
void afficheRoute(RenderWindow &fenetre);
void afficheFin(RenderWindow &fenetre, int &score);
void afficheCredit(RenderWindow &fenetre, int score);


#endif // FONCTION_H_INCLUDED

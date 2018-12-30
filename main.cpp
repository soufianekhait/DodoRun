#include <SFML/Graphics.hpp>
#include <time.h>
#include "fonction.h"
#define LARGEUR_FENETRE 1800
#define HAUTEUR_FENETRE 1080
#define PAUSE 50
#define MAX_NOMBRE_DE_MENU 5
#define POLICE "angrybirds-regular.ttf"
using namespace sf;

int main()
{
    RenderWindow fenetre(VideoMode(LARGEUR_FENETRE,HAUTEUR_FENETRE), "DODO RUN");

    // afficheTitre
    while (fenetre.isOpen())
    {
        fenetre.clear(Color(255,230,104));
        afficheTitre(fenetre);
    }

    return 0;
}

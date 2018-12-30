#include "Menu.h"
using namespace sf;

Menu::Menu(float LARGEUR_FENETRE, float HAUTEUR_FENETRE)
{
	if (!font.loadFromFile("angrybirds-regular.ttf"))
		printf("Pb de chargement de police!");

    menu[0].setFont(font);
    menu[0].setString("Dodo Run");
    menu[0].setCharacterSize(110);
    menu[0].setColor(Color(4,137,177));
    //center titre
    FloatRect titre = menu[0].getLocalBounds();
    menu[0].setOrigin(titre.left + titre.width/2.3f, titre.top + titre.height/2.0f);
    menu[0].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/4.5f));

    menu[1].setFont(font);
    menu[1].setString("Score :");
    menu[1].setCharacterSize(50);
    menu[1].setColor(Color(4,137,177));
    //center score
    FloatRect score = menu[1].getLocalBounds();
    menu[1].setOrigin(score.left + score.width/2.3f, score.top + score.height/2.0f);
    menu[1].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/2.6f));


	menu[2].setFont(font);
	menu[2].setColor(Color(4,137,177));
    menu[2].setCharacterSize(50);
	menu[2].setString("Credits");
//	menu[0].setPosition(Vector2f(LARGEUR_FENETRE / 2, HAUTEUR_FENETRE / (MAX_NOMBRE_DE_MENU + 1) * 1));
    //Position
    FloatRect credits = menu[2].getLocalBounds();
    menu[2].setOrigin(credits.width/2.3f, credits.height/2.0f);
    menu[2].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/1.9f));

	menu[3].setFont(font);
	menu[3].setColor(Color(4,137,177));
	menu[3].setCharacterSize(50);
	menu[3].setString("Retourner au Menu");
    //menu[1].setPosition(Vector2f(LARGEUR_FENETRE / 2, HAUTEUR_FENETRE / (MAX_NOMBRE_DE_MENU + 1) * 2));
	//Position
    FloatRect retour = menu[3].getLocalBounds();
    menu[3].setOrigin(retour.width/2.3f, retour.height/2.0f);
    menu[3].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/1.62f));

	menu[4].setFont(font);
	menu[4].setColor(Color(4,137,177));
	menu[4].setCharacterSize(50);
	menu[4].setString("Quitter");
    //menu[2].setPosition(Vector2f(LARGEUR_FENETRE / 2, HAUTEUR_FENETRE / (MAX_NOMBRE_DE_MENU + 1) * 3));
	//Position
    FloatRect quitter = menu[4].getLocalBounds();
    menu[4].setOrigin(quitter.width/2.3f, quitter.height/2.0f);
    menu[4].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/1.4f));

	ElementsSelect = 0;
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow &fenetre)
{
	for (int i=0; i < MAX_NOMBRE_DE_MENU; i++)
	{
		fenetre.draw(menu[i]);
	}
}

void Menu::BougeEnHaut()
{
	if (ElementsSelect - 3 >= 0)
	{
		menu[ElementsSelect].setColor(Color(4,137,177));
		ElementsSelect--;
		menu[ElementsSelect].setColor(Color::Red);
	}
}

void Menu::BougeEnBas()
{
	if (ElementsSelect + 1 < MAX_NOMBRE_DE_MENU)
	{
		menu[ElementsSelect].setColor(Color(4,137,177));
		ElementsSelect++;
		menu[ElementsSelect].setColor(Color::Red);
	}
}

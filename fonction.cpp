#include <SFML/Graphics.hpp>
#include "fonction.h"
#include <string.h>
#include <time.h>
#define LARGEUR_FENETRE 1800
#define HAUTEUR_FENETRE 1080
#define PAUSE 50
#define POLICE "angrybirds-regular.ttf"
#define MAX_NOMBRE_DE_MENU 5
#include <SFML/Audio.hpp>

using namespace sf;


/**************************************************************/


void afficheDodo(RenderWindow &fenetre)
{
    Texture dodoRunT;
        if (!dodoRunT.loadFromFile("dodoRun.png")) //image à remplacer par image dodo
            printf("Erreur de chargement\n");

        Sprite dodoRunS;
        dodoRunS.setTexture(dodoRunT);
        dodoRunS.scale(2,2);
        FloatRect dodoRunRect = dodoRunS.getLocalBounds();
        dodoRunS.setOrigin(0, dodoRunRect.height);


int i = 0;
        while (i<960-(960/8))
        {
            dodoRunS.setTextureRect(IntRect(i, 0, 960/8 , 100));
            dodoRunS.setPosition(0, 540);
            fenetre.clear(Color(255,230,104));
            fenetre.draw(dodoRunS);

            fenetre.display();
            i = i + (960/8);
            sleep(milliseconds(PAUSE));

        }
}


/*************************************************************/


void afficheTitre(RenderWindow &fenetre)
{
Texture dodoTitreTexture;
        if (!dodoTitreTexture.loadFromFile("protoDodo.png"))
            printf("Erreur de chargement\n");

        Sprite dodoTitreSprite(dodoTitreTexture);

        Font font;
        if(!font.loadFromFile(POLICE))
         printf("bug");

        Text titre;
        Text quitter;
        Text lancer;

        titre.setFont(font);
        titre.setString("Dodo Run");
        titre.setCharacterSize(100);
        titre.setColor(Color(4, 137, 177));
        titre.setStyle(Text::Bold);

        quitter.setFont(font);
        quitter.setString("Pour quitter :\nappuyez sur Q");
        quitter.setCharacterSize(50);
        quitter.setColor(Color(4, 137, 177));

        lancer.setFont(font);
        lancer.setString("Pour lancer le jeu : \nappuyez sur entrée");
        lancer.setCharacterSize(50);
        lancer.setColor(Color(4, 137, 177));

        FloatRect quitRect = quitter.getLocalBounds();
        quitter.setOrigin(quitRect.width/2,quitRect.height/2);
        quitter.setPosition(Vector2f(LARGEUR_FENETRE/3,HAUTEUR_FENETRE/1.5));

        FloatRect lanceRect = lancer.getLocalBounds();
        lancer.setOrigin(lanceRect.width/2,lanceRect.height/2);
        lancer.setPosition(Vector2f(LARGEUR_FENETRE/1.5,HAUTEUR_FENETRE/1.5));

        FloatRect titreRect = titre.getLocalBounds();
        titre.setOrigin(titreRect.width/2,titreRect.height/2);
        titre.setPosition(Vector2f(LARGEUR_FENETRE/2,HAUTEUR_FENETRE/2));


        FloatRect dodoRect = dodoTitreSprite.getLocalBounds();
        dodoTitreSprite.setOrigin(dodoRect.width/2, dodoRect.height/2);
        dodoTitreSprite.setPosition(LARGEUR_FENETRE/2, HAUTEUR_FENETRE/3);


        fenetre.draw(titre);
        fenetre.draw(dodoTitreSprite);
        fenetre.draw(quitter);
        fenetre.draw(lancer);


        Event event;
        int posX = 0;
        int posY = 540;


        while (fenetre.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                fenetre.close();
            }
            else if(event.type == Event::KeyPressed)
            {
                if(event.key.code == Keyboard::Q  )
                {
                    fenetre.close();
                }
                if(event.key.code == Keyboard::Up && posY>330)
                {
                    posY-=216;
                }
                if(event.key.code == Keyboard::Down && posY<756)
                {
                    posY+=216;
                }
                if(event.key.code == Keyboard::Return  )
                {
                    afficheMenu(fenetre);
                }
            }
        }

        fenetre.display();
}


/**********************************************************/


void afficheFin(RenderWindow &fenetre, int &score)
{

    char sscore[30];
    char resultat[30];
    score=score-1;
    int ElementsSelect;
	Font font;
	Text menu[MAX_NOMBRE_DE_MENU];
    if (!font.loadFromFile(POLICE))
		printf("Pb de chargement de police!");

    menu[0].setFont(font);
    menu[0].setString("Dodo Run");
    menu[0].setCharacterSize(110);
    menu[0].setColor(Color(4,137,177));
    FloatRect titre = menu[0].getLocalBounds();
    menu[0].setOrigin(titre.left + titre.width/2.3f, titre.top + titre.height/2.0f);
    menu[0].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/4.5f));

    menu[1].setFont(font);
    sprintf(resultat,"Score : ");
    sprintf(sscore,"%i points",score);
    strcat(resultat,sscore);
    menu[1].setString(resultat);
    menu[1].setCharacterSize(50);
    menu[1].setColor(Color(4,137,177));
    //center score
    FloatRect scoreRect = menu[1].getLocalBounds();
    menu[1].setOrigin(scoreRect.left + scoreRect.width/2.3f, scoreRect.top + scoreRect.height/2.0f);
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
	menu[3].setString("Retourner au menu");
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


	fenetre.setMouseCursorVisible(false);

	while (fenetre.isOpen())
	{
		Event event;

		while (fenetre.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyPressed:
				switch (event.key.code)
				{if(ElementsSelect==3)
				case Keyboard::Up:
					if (ElementsSelect - 3 >= 0)
	{
		menu[ElementsSelect].setColor(Color(4,137,177));
		ElementsSelect--;
		menu[ElementsSelect].setColor(Color::Red);
	}
					break;

				case Keyboard::Down:
					if ((ElementsSelect + 1 < MAX_NOMBRE_DE_MENU))
	{
		menu[ElementsSelect].setColor(Color(4,137,177));
		ElementsSelect++;
		menu[ElementsSelect].setColor(Color::Red);
        menu[1].setColor(Color(187, 143, 206));
	}
					break;

				case Keyboard::Return:
					if(ElementsSelect==2)
                        afficheCredit(fenetre, score);
					if(ElementsSelect==3)
                        afficheMenu(fenetre);
					if(ElementsSelect==4)
						fenetre.close();


				break;
			case Event::Closed:
				fenetre.close();

				break;

			}
		}
fenetre.clear(Color(255,230,104));
		for (int i=0; i < MAX_NOMBRE_DE_MENU; i++)
	{

		fenetre.draw(menu[i]);
	}

		fenetre.display();
	}
}

}


/*********************************************************/


void afficheRoute(RenderWindow &fenetre){



srand(time(NULL));



    fenetre.setFramerateLimit(30); //images par seconde pour l'anim du dodo
    int typeObstacle;
    int obstacleX = LARGEUR_FENETRE;
    int obstacleY;
    int piste;

    //définition du score texte-----------------------

    SoundBuffer boingBuffer;
    if (!boingBuffer.loadFromFile("SF-hopping.wav"))
        {
            printf("Erreur de chargement de boing\n");
        }

    Sound boingSound;

    Music music;
    if (!music.openFromFile("star_wars_cantina.wav"))
        printf("Erreur music\n");
    music.play();
    music.setPlayingOffset(seconds(0.3));


    Text text;
    Font font;
    int score=0;
    if(!font.loadFromFile(POLICE))
    {
        printf("Erreur de chargement de la police\n");
    }
    text.setFont(font);
    text.setColor(Color(255, 255, 255));
    text.setCharacterSize(75);
    FloatRect affiche = text.getLocalBounds();
    text.setOrigin(affiche.width/2.3f, affiche.height/2.0f);
    text.setPosition(Vector2f(LARGEUR_FENETRE/7.7f, HAUTEUR_FENETRE/15.5f));

    char sscore[30];
    char resultat[200];

    //définition de l'image du dodo qui court----------------

    int posX = 0;
    int posY = 540;
    Texture dodoRunT;
    if (!dodoRunT.loadFromFile("dodoRun.png")) //image à remplacer par image dodo
        printf("Erreur de chargement\n");

    Sprite dodoRunS;
    dodoRunS.setTexture(dodoRunT);
    dodoRunS.scale(2,2);
    FloatRect dodoRunRect = dodoRunS.getLocalBounds();
    dodoRunS.setOrigin(0, dodoRunRect.height);
    //----------------------------------------------------------
    //définition obstacle--------------------------------



    // définition route-------------------------------

    RectangleShape rect1(Vector2f(LARGEUR_FENETRE,HAUTEUR_FENETRE/5));
    rect1.setFillColor(Color(4, 137, 177));
    rect1.setOutlineThickness(2);
    rect1.setOutlineColor(Color(0, 0, 0));
    rect1.setPosition(0,0);

    RectangleShape rect2(Vector2f(LARGEUR_FENETRE,HAUTEUR_FENETRE/5));
    rect2.setFillColor(Color(255,230,104));
    rect2.setOutlineThickness(2);
    rect2.setOutlineColor(Color(0, 0, 0));
    rect2.setPosition(0,216);

    RectangleShape rect3(Vector2f(LARGEUR_FENETRE,HAUTEUR_FENETRE/5));
    rect3.setFillColor(Color(255,230,104));
    rect3.setOutlineThickness(2);
    rect3.setOutlineColor(Color(0, 0, 0));
    rect3.setPosition(0,432);

    RectangleShape rect4(Vector2f(LARGEUR_FENETRE,HAUTEUR_FENETRE/5));
    rect4.setFillColor(Color(255,230,104));
    rect4.setOutlineThickness(2);
    rect4.setOutlineColor(Color(0, 0, 0));
    rect4.setPosition(0,648);

    RectangleShape rect5(Vector2f(LARGEUR_FENETRE,HAUTEUR_FENETRE/5));
    rect5.setFillColor(Color(4, 137, 177));
    rect5.setOutlineThickness(2);
    rect5.setOutlineColor(Color(0, 0, 0));
    rect5.setPosition(0,864);


    int frameCounter = 0;
    int imageDodo = 0;
    dodoRunS.setTextureRect(IntRect(imageDodo*(960/8), 0, 960/8, 100));

    while (fenetre.isOpen())
    {

            dodoRunS.setPosition(0, posY);

            obstacleX=LARGEUR_FENETRE;

            typeObstacle = ((rand() % 2)+1);
            piste = (rand() % 3) + 1;


            while(obstacleX>-600)
            {
        Event event;
    while (fenetre.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            fenetre.close();
        }
        else if(event.type == Event::KeyPressed)
        {
            if(event.key.code == Keyboard::Q )
            {
                music.stop();
                afficheFin(fenetre,score);
            }
            if(event.key.code == Keyboard::Up && posY>330)
            {
                posY-=216;
            }
            if(event.key.code == Keyboard::Down && posY<756)
            {
                posY+=216;
            }
        }

    }
        fenetre.clear(Color(255,230,104));
        frameCounter++;
        frameCounter%=60;

        dodoRunS.setPosition(0, posY);

        // ======================================== LOGIQUE ========================================





                if(frameCounter%1 == 0)
                {
                    dodoRunS.setTextureRect(IntRect(imageDodo*(960/8), 0, 960/8, 100));
                    imageDodo++;
                    imageDodo%=8;
                }


                Texture obstacleT;

                switch(typeObstacle)
                {
                case 1:

                    if (!obstacleT.loadFromFile("dune.png"))
                        printf("Erreur de chargement\n");

                    break;

                case 2:

                    if (!obstacleT.loadFromFile("rocher.png"))
                        printf("Erreur de chargement\n");
                    break ;

                default:
                    printf("Erreur random\n");
                    break;

                }
                Sprite obstacleS;
                obstacleS.setTexture(obstacleT);
                obstacleS.scale(2,2);
                FloatRect obstacleRect = obstacleS.getLocalBounds();
                obstacleS.setOrigin(0, obstacleRect.height);


                // choix affichage de la piste------------------------------

                switch(piste)
                {
                case 1:
                    obstacleY=324;
                    break;
                case 2:
                    obstacleY=540;
                    break;
                case 3:
                    obstacleY=756;
                    break;

                default:
                    printf("Erreur random\n");
                    break;

                }

                int pas=75;

                if (score>100 && score<=200)
                    pas=100;
                if (score>200 && score<=400)
                    pas=120;
                if (score>400 && score<=800)
                    pas=150;
                if (score>800 && score<=1600)
                    pas=180;
                if (score>1600 && score<=3200)
                    pas=200;
                if (score>3200 && score<=6400)
                    pas=225;
                if (score>6400)
                    pas=300;

                obstacleX = obstacleX-pas;
                obstacleS.setPosition(obstacleX, obstacleY);
                score++;
                sprintf(resultat,"Score : ");
                sprintf(sscore,"%i",score);
                strcat(resultat,sscore);
                text.setString(resultat);



                if (posX==obstacleX && posY==obstacleY)
                {
                    music.stop();
                    boingSound.setBuffer(boingBuffer);
                    boingSound.play();
                    sleep(milliseconds(200));

                    afficheFin(fenetre,score);
                }

                else
                {
                  fenetre.draw(rect1);
                fenetre.draw(rect2);
                fenetre.draw(rect3);
                fenetre.draw(rect4);
                fenetre.draw(rect5);
                fenetre.draw(text);
                fenetre.draw(obstacleS);
                fenetre.draw(dodoRunS);
                fenetre.display();
                }

            }

    }

}


/***********************************************************************/


void afficheMenu(RenderWindow &fenetre){


    int ElementsSelect;
	Font font;
	Text menu[MAX_NOMBRE_DE_MENU];
    if (!font.loadFromFile(POLICE))
		printf("Pb de chargement de police!");

    menu[0].setFont(font);
    menu[0].setString("Dodo Run");
    menu[0].setCharacterSize(110);
    menu[0].setColor(Color(4,137,177));
    FloatRect titre = menu[0].getLocalBounds();
    menu[0].setOrigin(titre.left + titre.width/2.3f, titre.top + titre.height/2.0f);
    menu[0].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/4.5f));

    menu[1].setFont(font);
    menu[1].setString("Menu :");
    menu[1].setCharacterSize(50);
    menu[1].setColor(Color(4,137,177));
    //center score
    FloatRect score = menu[1].getLocalBounds();
    menu[1].setOrigin(score.left + score.width/2.3f, score.top + score.height/2.0f);
    menu[1].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/2.6f));


	menu[2].setFont(font);
	menu[2].setColor(Color(4,137,177));
    menu[2].setCharacterSize(50);
	menu[2].setString("Jouer");
//	menu[0].setPosition(Vector2f(LARGEUR_FENETRE / 2, HAUTEUR_FENETRE / (MAX_NOMBRE_DE_MENU + 1) * 1));
    //Position
    FloatRect credits = menu[2].getLocalBounds();
    menu[2].setOrigin(credits.width/2.3f, credits.height/2.0f);
    menu[2].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/1.9f));

	menu[3].setFont(font);
	menu[3].setColor(Color(4,137,177));
	menu[3].setCharacterSize(50);
	menu[3].setString("Instructions");
    //menu[1].setPosition(Vector2f(LARGEUR_FENETRE / 2, HAUTEUR_FENETRE / (MAX_NOMBRE_DE_MENU + 1) * 2));
	//Position
    FloatRect retour = menu[3].getLocalBounds();
    menu[3].setOrigin(retour.width/2.3f, retour.height/2.0f);
    menu[3].setPosition(Vector2f(LARGEUR_FENETRE/2.0f, HAUTEUR_FENETRE/1.62f));

	ElementsSelect = 0;


	fenetre.setMouseCursorVisible(false);

	while (fenetre.isOpen())
	{
		Event event;

		while (fenetre.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::KeyPressed:
				switch (event.key.code)
				{if(ElementsSelect==3)
				case Keyboard::Up:
					if (ElementsSelect - 3 >= 0)
	{
		menu[ElementsSelect].setColor(Color(4,137,177));
		ElementsSelect--;
		menu[ElementsSelect].setColor(Color::Red);
	}
					break;


				case Keyboard::Q:

				       fenetre.close() ;
				        break;



				case Keyboard::Down:
					if ((ElementsSelect + 2 < MAX_NOMBRE_DE_MENU))
	{
		menu[ElementsSelect].setColor(Color(4,137,177));
		ElementsSelect++;
		menu[ElementsSelect].setColor(Color::Red);
        menu[1].setColor(Color(187, 143, 206));
	}
					break;

				case Keyboard::Return:
					if(ElementsSelect==2)
						afficheRoute(fenetre);
					if(ElementsSelect==3)
						afficheRegle(fenetre);





				break;
			case Event::Closed:
				fenetre.close();

				break;

			}
		}
fenetre.clear(Color(255,230,104));
		for (int i=0; i < MAX_NOMBRE_DE_MENU; i++)
	{

		fenetre.draw(menu[i]);
	}

		fenetre.display();
	}
}
}


/*************************************************************************************************************************************************/


void afficheCredit(RenderWindow &fenetre, int score){

    Text titre;
    Text retour;
    Text prog;
    Text dessin;
    Text credit;
    Font font;

    if(!font.loadFromFile(POLICE))
        printf("Erreur de chargement de la police\n");

    titre.setFont(font);
    titre.setString("Credits :");
    titre.setCharacterSize(100);
    titre.setColor(Color(4, 137, 177));
    titre.setStyle(Text::Bold);
    FloatRect titreRect = titre.getLocalBounds();
    titre.setOrigin(titreRect.width/2,titreRect.height/2);
    titre.setPosition(Vector2f(LARGEUR_FENETRE/2,150));


    credit.setFont(font);
    credit.setString("Ce jeu est réalisé par :\n\nSoufiane KHAIT\nPierre REMY\nSebastien SALERO-GIANDINA\nManon THIVANT\n\nRouli");
    credit.setCharacterSize(55);
    credit.setColor(Color(4,137,177));
    FloatRect creditRect = credit.getLocalBounds();
    credit.setOrigin(creditRect.width/2,creditRect.height/2);
    credit.setPosition(Vector2f(LARGEUR_FENETRE/2,550));

    prog.setFont(font);
    prog.setString("Programmation :");
    prog.setCharacterSize(50);
    prog.setColor(Color(187, 143, 206));
    FloatRect progRect = prog.getLocalBounds();
    prog.setOrigin(progRect.width/1.0,progRect.height/2);
    prog.setPosition(Vector2f(LARGEUR_FENETRE/3.5f, HAUTEUR_FENETRE/2.0f));

    dessin.setFont(font);
    dessin.setString("Dessin :");
    dessin.setCharacterSize(50);
    dessin.setColor(Color(187, 143, 206));
    FloatRect dessRect = dessin.getLocalBounds();
    dessin.setOrigin(dessRect.width/1.0,dessRect.height/2);
    dessin.setPosition(Vector2f(LARGEUR_FENETRE/3.5f, HAUTEUR_FENETRE/1.40f));


    retour.setFont(font);
    retour.setString("Appuyer R pour retour");
    retour.setColor(Color(4,137,177));
    retour.setCharacterSize(65);
    FloatRect choix1Rect = retour.getLocalBounds();
    retour.setPosition(Vector2f((LARGEUR_FENETRE/5)-(choix1Rect.width/2),900));
    Event evenement;

   while (fenetre.isOpen())
    {

        while (fenetre.pollEvent(evenement))
        {

            switch (evenement.type)
            {

            case Event::Closed:
                fenetre.close();
                break;

            case Event::KeyPressed:
				switch (evenement.key.code)
				{
				    case Keyboard::R:
				        {
				        system("cls");
				        afficheFin(fenetre, score);
				        }
				        break;
				}

            }

    retour.setColor(Color(4,137,177));
    fenetre.clear(Color(255, 230, 104));
    fenetre.draw(titre);
    fenetre.draw(retour);
    fenetre.draw(prog);
    fenetre.draw(dessin);
    fenetre.draw(credit);
    fenetre.display();
        }
    }
    system("pause");
}


/*************************************************************************************************************************************************/


void afficheRegle(RenderWindow &fenetre){

    Text titre;
    Text choix1;
    Text choix2;
    Text regle;
    Font font;

    if(!font.loadFromFile(POLICE))
        printf("Erreur de chargement de la police\n");

    titre.setFont(font);
    titre.setString("Regles :");
    titre.setCharacterSize(100);
    titre.setColor(Color(4, 137, 177));
    FloatRect titreRect = titre.getLocalBounds();
    titre.setOrigin(titreRect.width/2,titreRect.height/2);
    titre.setPosition(Vector2f(LARGEUR_FENETRE/2,150));


    regle.setFont(font);
    regle.setString("Le but du jeu est de courir le plus longtemps possible\nen évitant les obstacles.\nLe jeu se termine lorsque vous vous heurtez\nà un obstacle.\nPour éviter ce genre d'incident, vous pouvez vous diriger\nsur trois voies à l'aide des flèches directionnelles.\n");
    regle.setCharacterSize(55);
    regle.setColor(Color(4,137,177));
    FloatRect regleRect = regle.getLocalBounds();
    regle.setOrigin(regleRect.width/2,regleRect.height/2);
    regle.setPosition(Vector2f(LARGEUR_FENETRE/2,550));


    choix1.setFont(font);
    choix1.setString("Appuyer R pour retour");
    choix1.setColor(Color(4,137,177));
    choix1.setCharacterSize(65);
    FloatRect choix1Rect = choix1.getLocalBounds();
    choix1.setPosition(Vector2f((LARGEUR_FENETRE/5)-(choix1Rect.width/2),900));
    Event evenement;

   while (fenetre.isOpen())
    {

        while (fenetre.pollEvent(evenement))
        {

            switch (evenement.type)
            {

            case Event::Closed:
                fenetre.close();
                break;

            case Event::KeyPressed:
				switch (evenement.key.code)
				{
				    case Keyboard::R:
				        {
				        system("cls");
				        afficheMenu(fenetre);
				        }
				        break;
				}

            }
            choix1.setColor(Color(4,137,177));
    fenetre.clear(Color(255, 230, 104));
    fenetre.draw(titre);
    fenetre.draw(choix1);
    fenetre.draw(regle);
    fenetre.display();
        }
    }
    system("pause");
}


/*******************************************************************************************/



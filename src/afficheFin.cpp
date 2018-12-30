//
//#include "afficheFin.h"
//#include "SFML/Graphics.hpp"
//#define LARGEUR_FENETRE 1920
//#define HAUTEUR_FENETRE 1080
//using namespace sf;
//
//void afficheFin(RenderWindow &fenetre)
//{
//
//    RenderWindow (VideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE), "FIN", Style::Fullscreen);
//    Menu menu(fenetre.getSize().x, fenetre.getSize().y);
//
//    fenetre.setMouseCursorVisible(false);
//
//
//    while (fenetre.isOpen())
//    {
//        Event event;
//
//        while (fenetre.pollEvent(event))
//        {
//            switch (event.type)
//            {
//            case Event::KeyReleased:
//                switch (event.key.code)
//                {
//                case Keyboard::Up:
//                    menu.BougeEnHaut();
//                    break;
//
//                case Keyboard::Down:
//                    menu.BougeEnBas();
//                    break;
//
//                case Keyboard::Return:
//                    switch (menu.GetPressedItem())
//                    {
//                    case 1:
////                        afficheScore();
//                        break;
//                    case 3:
//                        afficheTitre(fenetre);
//                        break;
//                    case 4:
//                        fenetre.close();
//                        break;
//                    }
//
//                    break;
//                }
//
//                break;
//            case Event::Closed:
//                fenetre.close();
//
//                break;
//
//            }
//        }
//
//        fenetre.clear(Color(255,230,104));
//        menu.draw(fenetre);
//        fenetre.display();
//    }
//}

#include <iostream>
#include <SFML/Graphics.hpp>
#include "player.h"



int main(){

    sf::RenderWindow window(sf::VideoMode (512, 512), "Okno"); //z blibl sfml funkcja renderWindow o nazwie window z konstruktorem
    //sf::videoMode zawierającym wielkosc okna oraz z nazwą okna
    sf::Texture playertexture;
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 512.0f));

    playertexture.loadFromFile("andy.png");

    Player player(&playerTexture, sf::Vector2u(4,5), 0.25f 0.64f);
    float deltaTime = 0.0f;
    sf::Clock clock;



    while (window.isOpen())//loop powodujący bycie otwartym okna
    {
        deltaTime = clock.restart().asSeconds();
        sf::Event evnt; //pollEvent wymaga sf::Event, nazywamy evnt bo event jest zarezerwowany
        while(window.pollEvent(evnt)) //
        {
           switch (evnt.type)
           {
           case sf::Event::Closed:
                window.close();
               break;
           
           default:
               break;
           }
        }
        player.Update(deltaTime);
        view.setCenter(player.GetPossition());
        window.clear();
        player.Draw(window);
        window.display();



    }









    return 0;


}
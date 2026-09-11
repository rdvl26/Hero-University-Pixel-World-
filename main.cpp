#include <iostream>
#include <string>
#include <memory>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "include/Jugador.hpp"
#include "include/Enemigos.hpp"
#include "include/Fondo.hpp"
#include "include/Enemigos.hpp"
#include "include/Plataformas.hpp"
#include "include/Llave.hpp"
#include "include/conversiones.hpp"
#include "include/DetectorDeColisiones.hpp"

int main (){

    sf::RenderWindow ventana(sf::VideoMode(1280,720), "Hero University");
    ventana.setFramerateLimit(90);
    ventana.setKeyRepeatEnabled(false); //Evita un input continuo en los eventos

    sf::Clock reloj;
    float dt; //Cambio del tiempo entre frame
    bool eventoSaltar = false;

    b2Vec2 gravedad(0.0, -9.81f);

    std::shared_ptr<b2World> mundo = std::make_shared<b2World>(gravedad);
    ContactListener listaContactos;
    mundo->SetContactListener(&listaContactos);

    Jugador player(640.0f,510.0f,"assets/JUGADOR.png",71,104,"Principal", mundo, &listaContactos, ventana.getSize().x, ventana.getSize().y);
    //posX, posY, rutaImagen, anchoImagen, AltoImagen, nombreJugador, mundoBox2D, verificadorDeContactos
    player.setAnchoSalto_setAltoSalto(76, 104.5); //Imagen del salto mas grande
    listaContactos.setSensor(player.getSensor()); //obtener el sensor de los pies
    Fondo fondos(mundo, ventana.getSize().x, ventana.getSize().y);

    while(ventana.isOpen()){
        dt = reloj.restart().asSeconds();
        eventoSaltar = false;
        sf::Event evento;
        while(ventana.pollEvent(evento)){ //procesar cada evento ocurrido
            if(evento.type == sf::Event::Closed) //Evento de cerrar la ventana
                ventana.close();
            if(evento.type == sf::Event::KeyPressed){
                if(evento.key.code == sf::Keyboard::W){
                    eventoSaltar = true;
                }
            }
        }

        mundo->Step(1.0f/60.0f,8,3);
        player.actualizar(ventana, dt, eventoSaltar);
        ventana.clear(sf::Color(51,153,255)); //Borrar el anterior FRAME y poner un fondo
        //Lo que dibujara en cada FRAME
        fondos.dibujarTodo(ventana);
        player.dibujarTodo(ventana);
        ventana.display(); //Dibujar nuevo FRAME
        
    }


    return 0;
}
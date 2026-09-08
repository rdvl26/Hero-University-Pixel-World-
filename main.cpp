#include <iostream>
#include <string>
#include <memory>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include "include/Jugador.hpp"
#include "include/Enemigos.hpp"
#include "include/cargarFondos.hpp"
#include "include/Fondo.hpp"
#include "include/Enemigos.hpp"
#include "include/Plataformas.hpp"
#include "include/Llave.hpp"
#include "include/conversiones.hpp"

int main (){

    sf::RenderWindow ventana(sf::VideoMode(1280,720), "Hero University");
    ventana.setFramerateLimit(90);
    sf::Clock reloj;
    float dt; //Cambio del tiempo entre frame

    b2Vec2 gravedad(0.0, -9.81);

    std::shared_ptr<b2World> mundo = std::make_shared<b2World>(gravedad);

    Jugador player(640.0f,510.0f,"assets/JUGADOR.png",71,104,"Principal", mundo);
    Fondo fondos(cargarFondo(), mundo);


    while(ventana.isOpen()){
        dt = reloj.restart().asSeconds();
        
        sf::Event evento;
        while(ventana.pollEvent(evento)){ //procesar cada evento ocurrido
            if(evento.type == sf::Event::Closed) //Evento de cerrar la ventana
                ventana.close();
        }

        mundo->Step(1.0f/60.0f,8,3);
        player.actualizar(ventana, dt);
        ventana.clear(sf::Color(51,153,255)); //Borrar el anterior FRAME y poner un fondo
        //Lo que dibujara en cada FRAME
        fondos.dibujarTodo(ventana);
        player.dibujarTodo(ventana);
        ventana.display(); //Dibujar nuevo FRAME
    }


    return 0;
}
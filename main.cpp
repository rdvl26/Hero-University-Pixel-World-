#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "include/Jugador.hpp"
#include "include/Enemigos.hpp"
#include "include/cargarFondos.hpp"
#include "include/Fondo.hpp"
#include "include/Enemigos.hpp"
#include "include/Plataformas.hpp"
#include "include/Llave.hpp"


using namespace std;


int main (){

    sf::RenderWindow ventana(sf::VideoMode(1280,720), "Hero University");
    ventana.setFramerateLimit(90);
    sf::Clock reloj;
    float dt; //Cambio del tiempo entre frame
    Jugador player(640.0f,485.0f,"assets/JUGADOR.png",71,104,"Principal");
    Fondo fondos(cargarFondo());

    while(ventana.isOpen()){
        dt = reloj.restart().asSeconds();
        
        sf::Event evento;
        while(ventana.pollEvent(evento)){ //procesar cada evento ocurrido
            if(evento.type == sf::Event::Closed) //Evento de cerrar la ventana
                ventana.close();
        }
        player.actualizar(ventana, dt);
        ventana.clear(sf::Color(51,153,255)); //Borrar el anterior FRAME y poner un fondo
        //Lo que dibujara en cada FRAME
        
        fondos.dibujarTodo(ventana);
        player.dibujarTodo(ventana);
        ventana.display(); //Dibujar nuevo FRAME
    }


    return 0;
}
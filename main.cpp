#include <iostream>
#include <string>
#include <memory>
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <sstream>

//.hpp
#include "include/Jugador.hpp"
#include "include/Enemigos.hpp"
#include "include/Fondo.hpp"
#include "include/Enemigos.hpp"
#include "include/Plataformas.hpp"
#include "include/Llave.hpp"
#include "include/conversiones.hpp"
#include "include/DetectorDeColisiones.hpp"
#include "include/ventanaError.hpp"

int main (){
    std::stringstream erroresSFML;
    sf::err().rdbuf(erroresSFML.rdbuf());   //Silenciar errores de sfml para que no salga en el terminal

    sf::RenderWindow ventana(sf::VideoMode(1280,720), "Hero University");
    ventana.setFramerateLimit(90);
    ventana.setKeyRepeatEnabled(false); //Evita un input continuo en los eventos

    sf::Clock reloj;
    float dt; //Cambio del tiempo entre frame
    bool eventoSaltar = false;

    b2Vec2 gravedad(0.0, -9.81f);

    std::shared_ptr<b2World> mundo = std::make_shared<b2World>(gravedad);
    FiltroColisiones filtroColisiones;
    ContactListener listaContactos;
    mundo->SetContactFilter(&filtroColisiones);
    mundo->SetContactListener(&listaContactos);

    Jugador player(640.0f,550.0f,"assets/JUGADOR.png",71,104, mundo, &listaContactos, ventana.getSize().x, ventana.getSize().y);
    Enemigos Enemigo1(940.0f, 485.0f, "assets/ENEMIGOS.png", 71, 104, mundo, ventana.getSize().x, ventana.getSize().y);
    Fondo fondos(mundo, ventana.getSize().x, ventana.getSize().y);

    try{
        VentanaError ventanaError("assets/alertas.jpeg", "assets/mrsmonster.ttf", 0.5f,0.5f);
          ventanaError.setPositionMensaje(425,85);
          ventanaError.setColorTexto(sf::Color::Red);
        if(!player.isOpen()){
            ventana.close();
            ventanaError.crearVentana(player.getMensajeError());
        }else{
            player.setAnchoSalto_setAltoSalto(76, 104.5); //Imagen del salto mas grande
            listaContactos.setSensor(player.getSensor()); //obtener el sensor de los pies
            filtroColisiones.setFiltroJugador(player.getCuerpo(), player.getHitbox());
        }

        if(!Enemigo1.isOpen()){
            ventana.close();
            ventanaError.crearVentana(Enemigo1.getMensajeError());
        }else{
            Enemigo1.setDistanciaObjetivo(300);
            Enemigo1.setDistanciaCombate(20);
            Enemigo1.setVelocidadAtaque(3);
            Enemigo1.setVelocidadPatrullaje(2);
            listaContactos.setHitBox(player.getHitbox(), Enemigo1.getHitbox());
            filtroColisiones.setFiltroEnemigo(Enemigo1.getCuerpo(), Enemigo1.getHitbox());

        }  

        if(!fondos.isCargadoLosArchivos()){
            ventana.close();
            ventanaError.crearVentana(fondos.getMensajeError());
        }
    

    }catch(std::runtime_error& e){
        abrirTerminal(e.what());
        ventana.close();
    }
   

  

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

       
        mundo->Step(1/60.0f,8,3);

        player.actualizar(dt, eventoSaltar);
        Enemigo1.actualizar(dt, false, player.getPosicionX(), player.getAncho(), player.getAlto());
      
        ventana.clear(sf::Color(51,153,255)); //Borrar el anterior FRAME y poner un fondo
        //Lo que dibujara en cada FRAME
        fondos.dibujarTodo(ventana);
        player.dibujarTodo(ventana);
        Enemigo1.dibujarTodo(ventana);
        ventana.display(); //Dibujar nuevo FRAME
        
    }


    return 0;
}
#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <box2d/box2d.h>
#include "Bot.hpp"
#include "MaquinaEstados.hpp"
#include "conversiones.hpp"

#include <iostream>
class Jugador : public Bot{

    protected:
        std::string nombre;
        sf::View vista;
        int centroVistaX, centroVistaY;
        int limiteDerecho; //Longitud del mapa en X.
        MaquinaEstados maquinaEstado;

        b2Body* cuerpoJugador;
        b2Vec2 vel;
        b2Vec2 pos;
        
    public:
        Jugador(float posicionX, float posicionY,std::string rutaImagen,float alto, float ancho , std::string nombre, std::shared_ptr<b2World> mundo);
        
        ~Jugador() override;
        
        void movimientoDer(sf::RenderWindow& ventana,float& dt) override;
        
        void movimientoIzq(sf::RenderWindow& ventana,float& dt) override;

        void quietoIzq(sf::RenderWindow& ventana,float dt);

        void quietoDer(sf::RenderWindow& ventana,float dt);

        void saltar(float posicionX, float posicionY);

        void interactuar(float posicionX, float posicionY);

        void actualizar(sf::RenderWindow& ventana, float dt);

        void dibujarTodo(sf::RenderWindow& ventana) override;

        std::string getNombre();

        friend class MaquinaEstados; //Maquina de estados tendrá acceso a los atributos privados
};

#endif
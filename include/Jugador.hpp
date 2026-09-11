#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <box2d/box2d.h>
#include "Bot.hpp"
#include "MaquinaEstados.hpp"
#include "conversiones.hpp"
#include "DetectorDeColisiones.hpp"

#include <iostream>
class Jugador : public Bot{

    protected:
        std::string nombre;
        //camara jugador
        sf::View vista;
        int centroVistaX, centroVistaY;
        int limiteDerecho; //Longitud del mapa en X.

        Conversiones conversion;

        //maquina de estados que decide el metodo a ejecutar
        MaquinaEstados maquinaEstado;
        //Detectar que está tocando el jugador

        b2Body* cuerpoJugador;
        b2Vec2 vel;
        b2Vec2 pos;
        b2Vec2 impulsoSalto;
        //Sensor que dirá si el jugador toca el suelo
        b2Fixture* sensorPies;
        float anchoFrameSalto, altoFrameSalto;
        ContactListener* listaColisiones;
    public:
        

        Jugador(float posicionX, float posicionY,std::string rutaImagen,float alto, float ancho , std::string nombre, std::shared_ptr<b2World> mundo, ContactListener* listaColisiones, float anchoVentana, float altoVentana);
        
        ~Jugador() override;
        
        void movimientoDer(sf::RenderWindow& ventana,float& dt) override;
        
        void movimientoIzq(sf::RenderWindow& ventana,float& dt) override;

        void quietoIzq(sf::RenderWindow& ventana,float& dt);

        void quietoDer(sf::RenderWindow& ventana,float& dt);

        void setAnchoSalto_setAltoSalto(float ancho, float alto);

        void iniciarSalto();

        void saltar(sf::RenderWindow& ventana, float& dt, float escalaX);

        void interactuar(float posicionX, float posicionY);

        void actualizar(sf::RenderWindow& ventana, float& dt, bool eventoSaltar);

        void dibujarTodo(sf::RenderWindow& ventana) override;

        b2Fixture* getSensor() ;

        std::string getNombre();

        float getVelocidadY();

        friend class MaquinaEstados; //Maquina de estados tendrá acceso a los atributos privados
};

#endif
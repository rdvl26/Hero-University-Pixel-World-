#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <box2d/box2d.h>
#include "Bot.hpp"
#include "conversiones.hpp"
#include "DetectorDeColisiones.hpp"

#include <iostream>



class Jugador : public Bot{

    public:

    enum class Estados{
            Quieto,
            CaminarIzq,
            CaminarDer,
            Salto,
            Agacharse,
            Combate
        };

    protected:
        std::string nombre;
        //camara jugador
        sf::View vista;
        int centroVistaX, centroVistaY;
        int limiteDerecho; //Longitud del mapa en X.
        Estados estadoActual;

        Conversiones conversion;

        //maquina de estados que decide el metodo a ejecutar
    
        //Detectar que está tocando el jugador

        b2Body* cuerpoJugador;
        b2Vec2 impulsoSalto;
        //Sensor que dirá si el jugador toca el suelo
        b2Fixture* sensorPies;
        float anchoFrameSalto, altoFrameSalto;
        float posRecorte = 0;
        ContactListener* listaColisiones;

        bool teclaW;
        bool teclaA;
        bool teclaS;
        bool teclaD;
        bool izq = false, der = true;
        bool estaEnSuelo = false;
        bool estaEnElAire = false;



    public:
        

        Jugador(float posicionX, float posicionY,std::string rutaImagen,float alto, float ancho , std::shared_ptr<b2World> mundo, ContactListener* listaColisiones, float anchoVentana, float altoVentana, std::string nombre = "player");
        
        ~Jugador() override;

        void movimientos(float& dt, bool derecha) override;
    
        void cambiarEstado(Estados nuevoEstado);

        Estados getEstado() const;

        void quieto(float& dt, bool derecha);

        void setAnchoSalto_setAltoSalto(float ancho, float alto);

        void iniciarSalto();

        void saltar(float& dt, float escalaX);

        void interactuar(float posicionX, float posicionY);

        void actualizar(float& dt, bool eventoSaltar);

        void dibujarTodo(sf::RenderWindow& ventana) override;

        b2Fixture* getSensor() ;

        std::string getNombre();

        float getVelocidadY();
        
};

#endif
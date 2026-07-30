#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Bot.hpp"

class Jugador : public Bot{

    protected:
        std::string nombre;

    public:
        Jugador(float posicionX, float posicionY,std::string rutaImagen,float alto, float ancho , std::string nombre);
        
        ~Jugador() override;
        
        void movimiento(sf::RenderWindow& ventana,float& dt);

        void saltar(float posicionX, float posicionY);

        void interactuar(float posicionX, float posicionY);

        std::string getNombre();

};

#endif
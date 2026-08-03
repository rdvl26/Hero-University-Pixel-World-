#ifndef BOT_HPP
#define BOT_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Diseño.hpp"


class Bot : public Diseño{

    protected:
        int vida;
        int daño;
        int velocidad;
        bool vivo;

        //Variables para animacion
        sf::IntRect recorte;
        float contador;
        int animacionX, animacionY;
        float altoFrame;
        float anchoFrame;
    public:
        
        Bot(float posicionX, float posicionY, std::string rutaImagen, float ancho, float alto );

        ~Bot() override;
        virtual void movimiento(sf::RenderWindow& ventana,float& dt);

        void combate();

        void recibioDaño();

        void estadosSuelo();

        int getVida();

        int setVida();

};

#endif
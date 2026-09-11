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
    public:
        
        Bot(float posicionX, float posicionY, std::string rutaImagen, float ancho, float alto );

        ~Bot() override;
        virtual void movimientoIzq(sf::RenderWindow& ventana,float& dt);
        virtual void movimientoDer(sf::RenderWindow& ventana,float& dt);

        void combate();

        void recibioDaño();

        void estadosSuelo();

        int getVida();

        void setVida(int vida);

};

#endif
#ifndef DISEÑO_HPP
#define DISEÑO_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

class Diseño{

    protected:
        float alto;
        float ancho;
        sf::Sprite sprite;
        sf::Texture textura;
        bool isOpen_Ventana = true;
        std::string mensajeError;
    
    public:
        Diseño(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto);

        virtual ~Diseño();
        
        float getPosicionX();
        
        float getPosicionY();

        float getAncho();

        float getAlto();

        std::string getMensajeError() const;

        bool isOpen() const;

        virtual void dibujarTodo(sf::RenderWindow& ventana);

};

#endif
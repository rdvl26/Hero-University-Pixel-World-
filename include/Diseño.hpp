#ifndef DISEÑO_HPP
#define DISEÑO_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Diseño{

    protected:
        float alto;
        float ancho;
        sf::Sprite sprite;
        sf::Texture textura;
    
    public:
        Diseño(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto);

        virtual ~Diseño();
        
        float getPosicionX();
        
        float getPosicionY();

        float getAncho();

        float getAlto();

        virtual void dibujarTodo(sf::RenderWindow& ventana);

};

#endif
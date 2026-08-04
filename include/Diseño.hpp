#ifndef DISEÑO_HPP
#define DISEÑO_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Diseño{

    protected:
        float posicionX;
        float posicionY;
        float alto;
        float ancho;
        sf::Sprite sprite;
        sf::Texture textura;
    
    public:
        Diseño(float posicionX, float posicionY,std::string rutaImagen, float alto, float ancho);

        virtual ~Diseño();
        
        float getPosicionX();
        
        float getPosicionY();

        virtual void dibujarTodo(sf::RenderWindow& ventana);

};

#endif
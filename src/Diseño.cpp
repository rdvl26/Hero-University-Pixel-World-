#include "../include/Diseño.hpp"

    Diseño::Diseño(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto): ancho(ancho),alto(alto){
            this->textura.loadFromFile(rutaImagen);
            sprite.setTexture(textura);
            sprite.setPosition(posicionX,posicionY);
        }

    Diseño::~Diseño(){
    
    }
    float Diseño::getPosicionX(){
            return sprite.getPosition().x;
        }
        
    float Diseño::getPosicionY(){
            return sprite.getPosition().y;
        }

    float Diseño::getAncho(){
        return ancho;
    }
    float Diseño::getAlto(){
        return alto;
    }

    void Diseño::dibujarTodo(sf::RenderWindow& ventana){
            ventana.draw(sprite);
        }
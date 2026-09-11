#include "../include/Diseño.hpp"

    Diseño::Diseño(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto): posicionX(posicionX),posicionY(posicionY),ancho(ancho),alto(alto){
            this->textura.loadFromFile(rutaImagen);
            sprite.setTexture(textura);
            sprite.setPosition(posicionX,posicionY);
        }

    Diseño::~Diseño(){
    
    }
    float Diseño::getPosicionX(){
            return posicionX;
        }
        
    float Diseño::getPosicionY(){
            return posicionY;
        }

    void Diseño::dibujarTodo(sf::RenderWindow& ventana){
            ventana.draw(sprite);
        }
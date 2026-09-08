#include "../include/Diseño.hpp"

    Diseño::Diseño(float posicionX, float posicionY,std::string rutaImagen, float alto, float ancho): posicionX(posicionX),posicionY(posicionY),alto(alto),ancho(ancho){
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
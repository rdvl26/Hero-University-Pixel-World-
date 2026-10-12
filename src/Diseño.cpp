#include "../include/Diseño.hpp"

    Diseño::Diseño(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto): ancho(ancho),alto(alto){
            
        try{
            if(!textura.loadFromFile(rutaImagen)){
                throw std::runtime_error("No se pudo cargar\n" + rutaImagen);
            }
                sprite.setTexture(textura);
                sprite.setPosition(posicionX,posicionY);
                isOpen_Ventana = true;
            }catch(std::runtime_error& e){
                isOpen_Ventana = false;
                mensajeError = e.what();
            }
        
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

    bool Diseño::isOpen() const{
        return isOpen_Ventana;
    }

    std::string Diseño::getMensajeError() const{
        return mensajeError;
    }

    void Diseño::dibujarTodo(sf::RenderWindow& ventana){
            ventana.draw(sprite);
        }
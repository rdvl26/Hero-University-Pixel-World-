#include "../include/Bot.hpp"
#include <SFML/Graphics.hpp>
#include <string>


     Bot::Bot(float posicionX, float posicionY, std::string rutaImagen, float ancho, float alto ) : Diseño(posicionX, posicionY, rutaImagen, ancho, alto){
            //Recorte inicial
            animacionX = 0;
            animacionY = 0;
            contador = 0; 
            anchoFrame = ancho;
            altoFrame = alto;
            recorte = sf::IntRect(animacionX,animacionY,anchoFrame,altoFrame);
            sprite.setTextureRect(recorte);
    }
    Bot::~Bot(){
        
    }
    
    void Bot::movimientoIzq(sf::RenderWindow& ventana,float& dt){
           
        }
    void Bot::movimientoDer(sf::RenderWindow& ventana,float& dt){
           
    }

    void Bot::combate(){

        } 

    void Bot::recibioDaño(){

        } 

    void Bot::estadosSuelo(){

        }

    int Bot::getVida(){
            return vida;
        }

    void Bot::setVida(int vida){
           this->vida = vida;
        }

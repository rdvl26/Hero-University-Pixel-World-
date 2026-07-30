#include "../include/Bot.hpp"
#include <SFML/Graphics.hpp>
#include <string>


     Bot::Bot(float posicionX, float posicionY, std::string rutaImagen, float ancho, float alto ) : Diseño(posicionX, posicionY, rutaImagen, alto, ancho){
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
    void Bot::movimiento(sf::RenderWindow& ventana,float& dt){
            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                    contador+=dt;
                    if(contador < 0.20){
                        recorte = sf::IntRect(animacionX = 0,animacionY = 0,anchoFrame,altoFrame);
                        sprite.setTextureRect(recorte);
                    }else if(contador < 0.33){
                        recorte = sf::IntRect(animacionX = anchoFrame,animacionY = 0,anchoFrame,altoFrame);
                        sprite.setTextureRect(recorte);
                        
                    }else if(contador < 0.46){
                        recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = 0,anchoFrame,altoFrame);
                        sprite.setTextureRect(recorte);
                        
                    }else if(contador < 0.59){
                        recorte = sf::IntRect(animacionX = anchoFrame*3,animacionY = 0,anchoFrame,altoFrame);
                        sprite.setTextureRect(recorte);

                    }else if(contador < 0.72){
                        recorte = sf::IntRect(animacionX = anchoFrame*4,animacionY = 0,anchoFrame,altoFrame);
                        sprite.setTextureRect(recorte);
                        
                    }else if(contador < 0.85){
                        recorte = sf::IntRect(animacionX = anchoFrame*5,animacionY = 0,anchoFrame,altoFrame);
                        sprite.setTextureRect(recorte);
                        contador = 0;
                    }
        
                    posicionX += 90*dt;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

                sprite.setOrigin(50,0);
                contador+=dt;
                if(contador < 0.20){
                    recorte = sf::IntRect(animacionX = 0,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.33){
                    recorte = sf::IntRect(animacionX = anchoFrame,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    
                }else if(contador < 0.46){
                    recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.59){
                    recorte = sf::IntRect(animacionX = anchoFrame*3,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.72){
                    recorte = sf::IntRect(animacionX = anchoFrame*4,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.85){
                    recorte = sf::IntRect(animacionX = anchoFrame*5,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    contador = 0;
                }
    
                posicionX -= 90*dt;
            }
    
    
            if (posicionX > 1280 - anchoFrame) {
                posicionX = 1280 - anchoFrame;
            }
            if (posicionX<0) {
                posicionX = 0;
            }
    
            sprite.setPosition(posicionX, posicionY);
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

        

    int Bot::setVida(){
            return vida;
        }

#include "../include/Jugador.hpp"
#include <SFML/Graphics.hpp>
#include <string>

Jugador::Jugador(float posicionX, float posicionY,std::string rutaImagen,float alto, float ancho , std::string nombre) :nombre(nombre), Bot(posicionX, posicionY, rutaImagen,alto,ancho){
            sprite.setScale(1.15f,1.15f);
            vista.setSize(1280,720);
            limiteDerecho = 3000;
}
Jugador::~Jugador(){
    
}

void Jugador::movimiento(sf::RenderWindow& ventana,float& dt){

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
    
    
            if (posicionX > limiteDerecho - anchoFrame) {
                posicionX = limiteDerecho - anchoFrame;
            }
            if (posicionX<0) {
                posicionX = 0;
            }
    
            sprite.setPosition(posicionX, posicionY);

            centroVistaX = sprite.getPosition().x;
            centroVistaY = sprite.getPosition().y - 125;

            if(centroVistaX < 640){
                centroVistaX = 640;
            }
            if(centroVistaX > limiteDerecho-640){
                centroVistaX = limiteDerecho-640;
            }
            vista.setCenter(centroVistaX,centroVistaY);
}

void Jugador::saltar(float posicionX, float posicionY){

}
void Jugador::interactuar(float posicionX, float posicionY){

}
void Jugador::dibujarTodo(sf::RenderWindow& ventana){
    Diseño::dibujarTodo(ventana);
    ventana.setView(vista);
}
std::string Jugador::getNombre(){
    return nombre;
}
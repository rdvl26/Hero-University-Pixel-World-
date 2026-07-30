#include "../include/Jugador.hpp"
#include <SFML/Graphics.hpp>
#include <string>

Jugador::Jugador(float posicionX, float posicionY,std::string rutaImagen,float alto, float ancho , std::string nombre) :nombre(nombre), Bot(posicionX, posicionY, rutaImagen,alto,ancho){
            sprite.setScale(1.15f,1.15f);
}
Jugador::~Jugador(){
    
}

void Jugador::movimiento(sf::RenderWindow& ventana,float& dt){
            Bot::movimiento(ventana, dt);
}

void Jugador::saltar(float posicionX, float posicionY){

}
void Jugador::interactuar(float posicionX, float posicionY){

}
std::string Jugador::getNombre(){
    return nombre;
}
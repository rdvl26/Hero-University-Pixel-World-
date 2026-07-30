#include "../include/Enemigos.hpp"

Enemigos::Enemigos(float posicionX, float posicionY,std::string rutaImagen, float alto, float ancho, int tipo, int vida) : Bot(posicionX, posicionY,rutaImagen, alto, ancho){

}
Enemigos::~Enemigos(){

}

bool Enemigos::estaVivo(){
        return vivo;
    }
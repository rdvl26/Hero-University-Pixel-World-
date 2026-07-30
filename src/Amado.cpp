#include "../include/Amado.hpp"

Amado::Amado( float posicionX, float posicionY,std::string rutaImagen, float alto, float ancho, std::string nombre) : Diseño(posicionX, posicionY, rutaImagen, alto, ancho){

}
Amado::~Amado(){
    
}

void Amado::pedirAyuda(){

}
        
void Amado::interactuar(){

}
        
void Amado::iniciarDialogo(){

}
        
void Amado::mostrarProductos(){

}
        
void Amado::vender(std::string producto){

}
        
void Amado::setEstado(std::string nuevoEstado){

}
        
int Amado::getEstado(){
    return estado;
}
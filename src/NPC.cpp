#include "../include/NPC.hpp"

NPC::NPC( float posicionX, float posicionY,std::string rutaImagen, float alto, float ancho, std::string nombre) : Diseño(posicionX, posicionY, rutaImagen, alto, ancho){

}
NPC::~NPC(){
    
}

void NPC::pedirAyuda(){

}
        
void NPC::interactuar(){

}
        
void NPC::iniciarDialogo(){

}
        
void NPC::mostrarProductos(){

}
        
void NPC::vender(std::string producto){

}
        
void NPC::setEstado(std::string nuevoEstado){

}
        
int NPC::getEstado(){
    return estado;
}
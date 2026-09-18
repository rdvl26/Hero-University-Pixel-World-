#include "../include/Enemigos.hpp"

Enemigos::Enemigos(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto, int tipo, int vida) : Bot(posicionX, posicionY,rutaImagen, alto, ancho){

    caminata = true;
    sprite.setScale(1.15f,1.15f);

}

Enemigos::~Enemigos(){

}

void Enemigos::Patrullaje(float &dt){
    velocidad=90;

    //Camina a la derecha
    if(caminata == true){
        
        contador+=dt;
        if(contador < 0.20){
            recorte = sf::IntRect(animacionX = 0,animacionY = 0,ancho,alto);// 1
            sprite.setTextureRect(recorte);
        }
        else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = ancho,animacionY = 0,ancho,alto);// 2
            sprite.setTextureRect(recorte);       
        }
        else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = ancho*2,animacionY = 0,ancho,alto);// 3
            sprite.setTextureRect(recorte);     
        }
        else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = 0,animacionY = alto,ancho,alto);// 4
            sprite.setTextureRect(recorte);         
        }
        else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = ancho,animacionY = alto,ancho,alto);// 5
            sprite.setTextureRect(recorte);       
        }
        else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = ancho*2,animacionY = alto,ancho,alto);// 6
            sprite.setTextureRect(recorte);     
        }
        else{
            contador=0; 
        }

        posicionX += velocidad*dt;
        sprite.setPosition(posicionX,posicionY);

        if(posicionX >= 1040){
            caminata=false;// cambiamos a falso para podercaminar a la izquierda
        }
        
    }

    //Camina a la izquierda      
    else{

        contador+=dt;
        if(contador < 0.20){
            recorte = sf::IntRect(animacionX = ancho,animacionY = 0,-ancho,alto);// 1
            sprite.setTextureRect(recorte);
        }
        else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = ancho*2,animacionY = 0,-ancho,alto);// 2
            sprite.setTextureRect(recorte);                
        }
        else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = ancho*3,animacionY = 0,-ancho,alto);// 3
            sprite.setTextureRect(recorte);         
        }
        else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = ancho,animacionY = alto,-ancho,alto);// 4
            sprite.setTextureRect(recorte);          
        }
        else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = ancho*2,animacionY = alto,-ancho,alto);// 5
            sprite.setTextureRect(recorte);         
        }
        else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = ancho*3,animacionY = alto,-ancho,alto);// 6
            sprite.setTextureRect(recorte);      
        }
        else if(contador < 0.98){
            contador=0; 
        }     



        posicionX -= velocidad*dt;
        sprite.setPosition(posicionX,posicionY);
        

        if(posicionX <= 840){
            caminata=true;
        }
    }
}




bool Enemigos::estaVivo(){
        return vivo;
    }
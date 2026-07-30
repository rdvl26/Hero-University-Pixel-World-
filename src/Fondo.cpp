#include "../include/Fondo.hpp"

Fondo::Fondo(std::vector<std::string> ruta){
        this->posX_suelo = 0;
        //Cargar fondos en la GPU
        for(auto& rect: ruta){
            cargarTexturaFondo.emplace_back();
            cargarTexturaFondo.back().loadFromFile(rect);
        }
        /*
        cielo.setTexture(cargarTexturaFondo[0]);
        cielo.setPosition(0,0);
        cielo.setScale(10.0f,.685f);
        */
}
void Fondo::suelo(){
        int i;
        for(i = 0; i < 20; i++){
            spritesSuelo.emplace_back(cargarTexturaFondo[1]);
            spritesSuelo[i].setScale(1.5f,1.5f);
        }
        for(i = 0; i < spritesSuelo.size(); i++){
            spritesSuelo[i].setPosition(posX_suelo + 192*i,posY_suelo);
            spritesSuelo[i].setScale(1.5f,1.5f);
        }

}
void Fondo::cielo(){
        int i;
        for(i = 0; i < 20; i++){
            spritesCielo.emplace_back(cargarTexturaFondo[0]);
        }
        for(i = 0; i < spritesCielo.size(); i++){
            spritesCielo[i].setScale(1.5f,1.5f);
            spritesCielo[i].setPosition(0 + 192*i,0);
            
        }
}
void Fondo::cargarMontañas(){

        montaña.setTexture(cargarTexturaFondo[2]);
        
        montaña.setScale(2.0f,2.0f);
        montaña.setPosition(0,0);
           

}
void Fondo::dibujarTodo(sf::RenderWindow& ventana){
        Fondo::suelo();
        Fondo::cielo();
        Fondo::cargarMontañas();
        
        int i;
        for(i = 0; i < spritesCielo.size(); i++){
            ventana.draw(spritesCielo[i]);
        }
        for(i = 0; i < spritesSuelo.size(); i++){
            ventana.draw(spritesSuelo[i]);
        }
        ventana.draw(montaña);
       
}



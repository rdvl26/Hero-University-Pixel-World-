#include "../include/Fondo.hpp"

Fondo::Fondo(std::vector<std::string> ruta){
        this->posX_suelo = 0;
        //Cargar fondos en la GPU
        for(auto& rect: ruta){
            cargarTexturaFondo.emplace_back();
            cargarTexturaFondo.back().loadFromFile(rect);
        }

       for(int i = 0; i < 20; i++){
        cielo.setTexture(cargarTexturaFondo[0]);
        cielo.setScale(1.5f,1.5f);
        cielo.setPosition(0+192*i,0);
        spritesCielo.push_back(cielo);
       }

       for(int i = 0; i < 20; i++){
            suelo.setTexture(cargarTexturaFondo[1]);
            suelo.setScale(1.5f,1.5f);
            suelo.setPosition(posX_suelo + 192*i,528);
            spritesSuelo.push_back(suelo);
       }
       montaña.setTexture(cargarTexturaFondo[2]);
       montaña.setScale(2.0f,2.0f);
       montaña.setPosition(0,0);
}

void Fondo::dibujarTodo(sf::RenderWindow& ventana){
        
        int i;
        for(i = 0; i < spritesCielo.size(); i++){
            ventana.draw(spritesCielo[i]);
        }
        for(i = 0; i < spritesSuelo.size(); i++){
            ventana.draw(spritesSuelo[i]);
        }
        ventana.draw(montaña);
       
}



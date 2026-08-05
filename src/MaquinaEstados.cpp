#include "../include/MaquinaEstados.hpp"
#include "../include/Jugador.hpp"
#include <iostream>

void MaquinaEstados::cambiarEstado(Estados nuevoEstado){
    if(estadoActual != nuevoEstado){
        estadoActual = nuevoEstado;
    }
}

void MaquinaEstados::actualizar(sf::RenderWindow& ventana, float dt){

    teclaW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    teclaA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    teclaS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    teclaD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    if(teclaA && !teclaD){
        cambiarEstado(Estados::CaminarIzq);
        izq = true;
        der = false;
    }else if(teclaD && !teclaA){
        cambiarEstado(Estados::CaminarDer);
        izq = false;
        der = true;
    }else{
        estadoActual = Estados::Quieto;
    }

    switch (estadoActual)
    {
  
    case Estados::CaminarIzq:
        jugador->movimientoIzq(ventana, dt);
        break;
    case Estados::CaminarDer:
        jugador->movimientoDer(ventana, dt);
        break;
    case Estados::Quieto:
        if(izq){
            jugador->quietoIzq(ventana, dt);
        }else{
            jugador->quietoDer(ventana,dt);
        }
        
        break;
    }
}
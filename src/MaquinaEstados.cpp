#include "../include/MaquinaEstados.hpp"
#include "../include/Jugador.hpp"


void MaquinaEstados::cambiarEstado(Estados nuevoEstado){
    if(estadoActual != nuevoEstado){
        estadoActual = nuevoEstado;
    }
}

void MaquinaEstados::actualizar(sf::RenderWindow& ventana, float dt, bool eventoSaltar){

    teclaW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    teclaA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    teclaS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    teclaD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    estaEnSuelo =  jugador->listaColisiones->tocaSuelo();
    if(eventoSaltar && estaEnSuelo){
            cambiarEstado(Estados::Salto);
            jugador->iniciarSalto();
    }else if(!estaEnSuelo || (estadoActual == Estados::Salto && jugador->getVelocidadY() > 0.5f)){
            cambiarEstado(Estados::Salto);
    }else if(estaEnSuelo){
            if(teclaA && !teclaD && estaEnSuelo){
            cambiarEstado(Estados::CaminarIzq);
            izq = true;
            der = false;
        }else if(teclaD && !teclaA && jugador->listaColisiones->tocaSuelo()){
            cambiarEstado(Estados::CaminarDer);
            izq = false;
            der = true;
        }else{
            estadoActual = Estados::Quieto;
        }
    }

    switch (estadoActual){
  
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
    case Estados::Salto:
        if(izq){
            jugador->saltar(ventana, dt, 1.025);
        }else{
            jugador->saltar(ventana,dt,0);
        }
        break;
    }
}
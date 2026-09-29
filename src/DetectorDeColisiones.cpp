#include "../include/DetectorDeColisiones.hpp"
#include <iostream>

    ContactListener::ContactListener(){
        numeroContactos = 0;
        sensorPies = nullptr;
    }

    void ContactListener::setSensor(b2Fixture* sensor){
        sensorPies = sensor;
    }

    void ContactListener::BeginContact(b2Contact* contact){
          
        if(sensorPies == contact->GetFixtureA() || sensorPies == contact->GetFixtureB()){
            //comprobar si el sensor de los pies detecta algo
            numeroContactos++;
        }

            
    }

    void ContactListener::EndContact(b2Contact* contact){
        
        if(sensorPies == contact->GetFixtureA() || sensorPies == contact->GetFixtureB()){
            //comprobar si el sensor de los pies detecta algo
            numeroContactos--;
        }
            
    }

    bool ContactListener::tocaSuelo() const{
            return numeroContactos > 0;
    }

    FiltroColisiones::FiltroColisiones(){
        jugador = nullptr;
        enemigo = nullptr;
        hitboxJugador = nullptr;
        hitboxEnemigo = nullptr;
    }

    void FiltroColisiones::setFiltroJugador(b2Body* jugador, b2Fixture* hitbox_jugador){
        this->jugador = jugador;
        this->hitboxJugador = hitbox_jugador;
    }
    void FiltroColisiones::setFiltroEnemigo(b2Body* enemigo, b2Fixture* hitbox_enemigo){
        this->enemigo = enemigo;
        this->hitboxEnemigo = hitbox_enemigo;
    }
     bool FiltroColisiones::ShouldCollide(b2Fixture* fixA, b2Fixture* fixB){
        b2Body* a = fixA->GetBody();
        b2Body* b = fixB->GetBody();

        if((a == jugador && b == enemigo) || a == enemigo && b == jugador){
            if((fixA == hitboxJugador && fixB == hitboxEnemigo) || (fixA == hitboxJugador && fixB == hitboxEnemigo)){
                std::cout << "Contacto\n";
                return true;
            }
        
            return false;
        }
        return true;
     }
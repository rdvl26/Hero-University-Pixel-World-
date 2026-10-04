#include "../include/DetectorDeColisiones.hpp"
#include <iostream>

    ContactListener::ContactListener(){
        numeroContactos = 0;
        sensorPies = nullptr;
        hitboxA = nullptr;
        hitboxB = nullptr;
        estanColisionandoHitBox = false;
    }

    void ContactListener::setSensor(b2Fixture* sensor){
        sensorPies = sensor;
    }

    void ContactListener::setHitBox(b2Fixture* fixA, b2Fixture* fixB){
        this->hitboxA = fixA;
        this->hitboxB = fixB;
    }

    void ContactListener::BeginContact(b2Contact* contact){
          
        if(sensorPies == contact->GetFixtureA() || sensorPies == contact->GetFixtureB()){
            //comprobar si el sensor de los pies detecta algo
            numeroContactos++;
        }

        if(hitboxA && hitboxB){
            if((hitboxA == contact->GetFixtureA() && hitboxB == contact->GetFixtureB()) || (hitboxB == contact->GetFixtureA() && hitboxA == contact->GetFixtureB())){
                estanColisionandoHitBox = true;
            }
        }

            
    }

    void ContactListener::EndContact(b2Contact* contact){
        
        if(sensorPies == contact->GetFixtureA() || sensorPies == contact->GetFixtureB()){
            //comprobar si el sensor de los pies detecta algo
            numeroContactos--;
        }

         if((hitboxA == contact->GetFixtureA() && hitboxB == contact->GetFixtureB()) || (hitboxB == contact->GetFixtureA() && hitboxA == contact->GetFixtureB())){
                estanColisionandoHitBox = false;
            }
            
    }

    bool ContactListener::tocaSuelo() const{
            return numeroContactos > 0;
    }

    std::string ContactListener::hitboxContact() const{
        if(estanColisionandoHitBox)
            return "Contacto\n";
        return "Sin contacto\n";
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
            if((fixA == hitboxJugador && fixB == hitboxEnemigo) || (fixA == hitboxEnemigo && fixB == hitboxJugador)){
                return true;
            }
        
            return false;
        }
        return true;
     }
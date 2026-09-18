#include "../include/DetectorDeColisiones.hpp"

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
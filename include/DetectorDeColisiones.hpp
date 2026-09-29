#ifndef DETECTORDECOLISIONES_HPP
#define DETECTORDECOLISIONES_HPP

#include <box2d/box2d.h>
#include <string>
#include <memory>

class ContactListener: public b2ContactListener{
    private:
        int numeroContactos;
        b2Fixture* sensorPies;
    public:

        ContactListener();
        
        void setSensor(b2Fixture* sensor);

        void BeginContact(b2Contact* contact) override;

        void EndContact(b2Contact* contact) override;

        bool tocaSuelo() const;
};

class FiltroColisiones : public b2ContactFilter{
    private:
    b2Body* jugador;
    b2Body* enemigo;

    b2Fixture* hitboxJugador;
    b2Fixture* hitboxEnemigo;
    public:

    FiltroColisiones();
    
    void setFiltroJugador(b2Body* jugador, b2Fixture* hitbox_jugador);
    void setFiltroEnemigo(b2Body* enemigo, b2Fixture* hitbox_enemigo);

    bool ShouldCollide(b2Fixture* fixA, b2Fixture* fixB) override;


};

#endif

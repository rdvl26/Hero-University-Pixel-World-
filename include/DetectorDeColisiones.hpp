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


#endif
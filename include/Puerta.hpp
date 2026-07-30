#ifndef PUERTA_HPP
#define PUERTA_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Diseño.hpp"
#include "Llave.hpp"

class Puerta : public Diseño{

    protected:
        bool abierta;

    public:
    Puerta();
    
    ~Puerta()override;
    
    void tieneLlave();
};

#endif
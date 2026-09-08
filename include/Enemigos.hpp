#ifndef ENEMIGOS_HPP
#define ENEMIGOS_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Bot.hpp"

class Enemigos : public Bot{

    protected:
        int tipo;

    public:
        Enemigos(float posicionX, float posicionY,std::string rutaImagen, float alto, float ancho, int tipo, int vida);
        ~Enemigos() override;

        bool estaVivo();

};

#endif
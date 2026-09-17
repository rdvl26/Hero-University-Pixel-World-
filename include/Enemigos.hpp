#ifndef ENEMIGOS_HPP
#define ENEMIGOS_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Bot.hpp"

class Enemigos : public Bot{

    protected:
        int tipo;
        bool Caminata=true;

    public:
        Enemigos(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto, int tipo, int vida);

        ~Enemigos() override;

        void Patrullaje(float &dt);

        bool estaVivo();

};

#endif
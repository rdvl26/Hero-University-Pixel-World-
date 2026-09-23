#ifndef ENEMIGOS_HPP
#define ENEMIGOS_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <box2d/box2d.h>
#include <memory>

#include "Bot.hpp"
#include "conversiones.hpp"

class Enemigos : public Bot{

    protected:
        int tipo;
        bool caminata;
        bool alerta;
        b2Body* cuerpoEnemigo;
        Conversiones conversiones;

    public:
        Enemigos(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto, int tipo, int vida , std::shared_ptr<b2World> mundo, float anchoVentana, float altoVentana);

        ~Enemigos() override;

        void movimientos(float &dt, float posObjetivo, float anchoObjetivo, float altoObjetivo , float distanciaClaveObjetivo = 10);

        bool estaVivo();

};

#endif
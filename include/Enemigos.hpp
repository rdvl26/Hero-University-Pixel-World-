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
        float posObjetivo, anchoObjetivo, altoObjetivo,distanciaClaveObjetivo;

    public:
        Enemigos(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto, int tipo, int vida , std::shared_ptr<b2World> mundo, float anchoVentana, float altoVentana);

        ~Enemigos() override;

        void movimientos(float &dt, bool derecha) override;

        bool estaVivo();

        void actualizar(float &dt, bool derecha, float posObjetivo,float anchoObjetivo,float altoObjetivo,float distanciaClaveObjetivo);

};

#endif
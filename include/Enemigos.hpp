#ifndef ENEMIGOS_HPP
#define ENEMIGOS_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <box2d/box2d.h>
#include <memory>
#include <cmath>

#include "Bot.hpp"
#include "conversiones.hpp"

class Enemigos : public Bot{

    protected:
        int tipo;
        bool caminata;
        bool alerta;
        float voltearSprite;
        int estadoFurioso;
        b2Body* cuerpoEnemigo;
        Conversiones conversiones;
        //atributos de deteccion y cobate
        float posObjetivo, anchoObjetivo, altoObjetivo,distanciaClaveObjetivo,distanciaX_total, distanciaX_absoluta;
        float distanciaCombate;
        bool atacando;
        bool animacionActiva;
        int velocidadAtaque;
        int velocidadPatrullaje;
        b2Fixture* hitbox;
        float desplazarHitbox;

    public:
        Enemigos(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto, std::shared_ptr<b2World> mundo, float anchoVentana, float altoVentana, int tipo = 1,  float desplazarHitbox = 0);

        ~Enemigos() override;

        void movimientos(float &dt, bool derecha) override;

        bool estaVivo();

        void setDistanciaObjetivo(float pixeles);

        void setDistanciaCombate(float px);

        void setVelocidadAtaque(int metrosPorSegundo);

        void setVelocidadPatrullaje(int metrosPorSegundo);


        void actualizar(float &dt, bool derecha, float posObjetivo,float anchoObjetivo,float altoObjetivo);

        void combate(float& contador, float& dt) override;

        b2Body* getCuerpo();
        b2Fixture* getHitbox();
};

#endif
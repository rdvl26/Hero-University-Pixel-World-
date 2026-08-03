#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Diseño.hpp"
#include "Jugador.hpp"
#include "Enemigos.hpp"

class Plataformas : public Diseño{
    public:
    Plataformas(float posicionX, float posicionY, std::string suelo, float alto, float ancho);

    ~Plataformas()override;
    void colision(/* "Jugador*, enemigos*" */);

    void destruir();

};

#endif
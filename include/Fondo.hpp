#ifndef FONDO_HPP
#define FONDO_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "conversiones.hpp"
#include "cargarFondos.hpp"
#include <memory>
#include <box2d/box2d.h>

class Fondo{
private:
    std::vector<std::shared_ptr<sf::Texture>> cargarTexturaFondo;
    std::vector<sf::Sprite> spritesSuelo;
    std::vector<sf::Sprite> spritesCielo;
    sf::Sprite cielo;
    sf::Sprite montaña;
    sf::Sprite suelo;
    int posX_suelo;
    float anchoSuelo;
    const int MosaicosSuelos = 20;
    const int posY_suelo = 528;
    b2Body* cuerpoSuelo = nullptr;
public:
    Fondo(std::vector<std::string> ruta, std::shared_ptr<b2World> mundo);
    void dibujarTodo(sf::RenderWindow& ventana);
};


#endif
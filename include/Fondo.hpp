#ifndef FONDO_HPP
#define FONDO_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "conversiones.hpp"
#include <memory>
#include <box2d/box2d.h>

class Fondo{
private:
    std::vector<std::string> rutafondos;
    std::vector<std::shared_ptr<sf::Texture>> cargarTexturaFondo;
    std::vector<sf::Sprite> spritesSuelo;
    std::vector<sf::Sprite> spritesCielo;
    std::vector<sf::Sprite> spritesMontañas;
    sf::FloatRect tamañoImagen_Cielo;
    sf::FloatRect tamañoImagen_Suelo;
    sf::Sprite cielo;
    sf::Sprite montaña;
    sf::Sprite suelo;
    int posX_suelo;
    float anchoImagen;
    float altoImagen;
    const int MosaicosSuelos = 20;
    const int posY_suelo = 528;
    b2Body* cuerpoSuelo = nullptr;
    Conversiones conversiones;
    
public:
    Fondo(std::shared_ptr<b2World> mundo, float anchoVentana, float alturaVentana);

    void cargarFondo();

    void dibujarTodo(sf::RenderWindow& ventana);
};


#endif
#ifndef FONDO_HPP
#define FONDO_HPP
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Fondo{
private:
    std::vector<sf::Texture> cargarTexturaFondo;
    std::vector<sf::Sprite> spritesSuelo;
    std::vector<sf::Sprite> spritesCielo;
    sf::Sprite montaña;
    int posX_suelo;
    const int posY_suelo = 528;
public:
    Fondo(std::vector<std::string> ruta);
    void suelo();
    void cielo();
    void cargarMontañas();
    void dibujarTodo(sf::RenderWindow& ventana);
};


#endif
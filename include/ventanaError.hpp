#ifndef VENTANAERROR_HPP
#define VENTANAERROR_HPP

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <memory>

void abrirTerminal(const std::string mensaje);

class VentanaError{
    private:
        std::unique_ptr<sf::RenderWindow> ventana;
        sf::Texture textura;
        sf::Sprite sprite;
        sf::Font fuente;
        sf::Text texto;
        std::string rutaImagen;
        std::string rutaFuente;
    public:
    VentanaError(const std::string ruta_Imagen_Error, const std::string ruta_FuenteDeTexto, float escalaX = 1, float escalaY = 1);

    void setPositionMensaje(float x, float y);

    void setColorTexto(sf::Color color);
      
    void crearVentana(const std::string mensaje_A_Mostrar);

};

#endif
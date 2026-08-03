#ifndef LLAVE_HPP
#define LLAVE_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Diseño.hpp"

class Llave : public Diseño{

    protected:
        bool recogida;

    public:
        Llave(float posicionX, float posicionY, std::string rutaImagen, float alto, float ancho);
    
        ~Llave() override;

        void interactuar();

        void setRecogida();

        void destruir();

};

#endif
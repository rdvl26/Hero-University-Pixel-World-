#ifndef AMADO_HPP
#define AMADO_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Diseño.hpp"

class Amado : public Diseño{

    protected:
        std::string nombre;
        int estado;

    public:
        Amado( float posicionX, float posicionY,std::string rutaImagen, float alto, float ancho, std::string nombre);

        ~Amado() override;
        
        void pedirAyuda();
        
        void interactuar();
        
        void iniciarDialogo();
        
        void mostrarProductos();
        
        void vender(std::string producto);
        
        void setEstado(std::string nuevoEstado);
        
        int getEstado();

};

#endif
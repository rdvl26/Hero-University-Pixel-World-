#ifndef NPC_HPP
#define NPC_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Diseño.hpp"

class NPC : public Diseño{

    protected:
        std::string nombre;
        int estado;

    public:
        NPC( float posicionX, float posicionY,std::string rutaImagen, float alto, float ancho, std::string nombre);

        ~NPC() override;
        
        void pedirAyuda();
        
        void interactuar();
        
        void iniciarDialogo();
        
        void mostrarProductos();
        
        void vender(std::string producto);
        
        void setEstado(std::string nuevoEstado);
        
        int getEstado();

};

#endif
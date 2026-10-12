 #include "../include/ventanaError.hpp"
 #include <iostream>
 
void abrirTerminal(const std::string mensaje){
    #ifdef _WIN32 //Si el sistema es Windows abre PowerShell
        std::string cmd = "start cmd /k echo " + mensaje;
        system(cmd.c_str());
    #elif __APPLE__ //Si el sistema es Apple, se abre su terminal
        std::string cmd = "osascript -e 'tell application \"Terminal\" to do script \"echo " 
                        + mensaje + "\"'";
        system(cmd.c_str());
    #elif __linux__ //Si el sistema es Linux se abre la terminal Gnome
        std::string cmd = "x-terminal-emulator -e bash -c \"echo '" + mensaje + "'; exec bash\"";
        system(cmd.c_str());
    #endif
}

 VentanaError::VentanaError(const std::string ruta_Imagen_Error, const std::string ruta_FuenteDeTexto, float escalaX, float escalaY) : rutaImagen(ruta_Imagen_Error), rutaFuente(ruta_FuenteDeTexto){
            if(!textura.loadFromFile(rutaImagen)){
                throw std::runtime_error("Error\n" + rutaImagen + "\nNo encontrado");
            }

            if(!fuente.loadFromFile(rutaFuente)){
                throw std::runtime_error("Error\n" + rutaFuente + "\nNo encontrado");
            }

            sprite.setTexture(textura);
            sprite.setScale(escalaX, escalaY);
            ventana = std::make_unique<sf::RenderWindow>(sf::VideoMode(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height), "ERROR");
            ventana->setFramerateLimit(60);
            texto.setFont(fuente);
            texto.setFillColor(sf::Color::Black);
            texto.setCharacterSize(20);
            

    }

 void VentanaError::setColorTexto(sf::Color color){
    texto.setFillColor(color);
 }
      
void VentanaError::crearVentana(const std::string mensaje_A_Mostrar){
        texto.setString(mensaje_A_Mostrar);
        
        if(ventana == nullptr)
            return;
    
        while(ventana->isOpen()){
            sf::Event evento;
            while(ventana->pollEvent(evento)){
                if(evento.type == sf::Event::Closed)
                    ventana->close();
            }

            ventana->clear();
            ventana->draw(sprite);
            ventana->draw(texto);
            ventana->display();
                
        }
    }

void VentanaError::setPositionMensaje(float x, float y){
        texto.setPosition(x, y);
    }
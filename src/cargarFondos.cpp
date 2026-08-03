#include "../include/cargarFondos.hpp"

std::vector<std::string> cargarFondo(){
    std::vector<std::string> rutafondos;
    rutafondos.reserve(2);
    rutafondos.emplace_back("assets/cielo.png");
    rutafondos.emplace_back("assets/piso.png");
    rutafondos.emplace_back("assets/montañas.png");
    return rutafondos;
}
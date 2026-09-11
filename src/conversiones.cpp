#include "../include/conversiones.hpp"

Conversiones::Conversiones(float alturaVentana, float anchoVentana): alturaVentana(alturaVentana), anchoVentana(anchoVentana){}

float Conversiones::box2d_sfml_x(float x_b2){
    return x_b2 * escala;
}
float Conversiones::box2d_sfml_y(float y_b2){
    return (alturaVentana - (y_b2 * escala));
}

float Conversiones::mitadAnchoBox2D(float anchoSFML){
    return (anchoSFML/2)/escala;
}
float Conversiones::mitadAltoBox2D(float altoSFML){
    return (altoSFML/2)/escala;
}
float Conversiones::centroX_box2D(float x_sfml, float anchoSFML){
    return (x_sfml + (anchoSFML/2))/escala;
}
float Conversiones::centroY_box2D(float y_sfml, float altoSFML){
    return (alturaVentana - (y_sfml + (altoSFML/2)))/escala;
}



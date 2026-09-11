#ifndef CONVERSIONES_HPP
#define CONVERSIONES_HPP

#include <string>

class Conversiones{
    private:

        const float escala = 30.0f; // 1m son 30 px
        float alturaVentana = 720;
        float anchoVentana = 1280;

    public:
        Conversiones(float alturaVentana, float anchoVentana);
            //Para actualizar posiciones a SFML
        float box2d_sfml_x(float x_b2);
        float box2d_sfml_y(float y_b2);
        //Para establecer la forma en Box2D
        float mitadAnchoBox2D(float anchoSFML);
        float mitadAltoBox2D(float altoSFML);
        //Para posicionar en Box2D
        float centroX_box2D(float x_sfml, float anchoSFML);
        float centroY_box2D(float y_sfml, float altoSFML);
        float getEscala(){
            return escala;
        }



};





#endif
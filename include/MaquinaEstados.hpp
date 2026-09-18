#ifndef MAQUINASESTADOS_HPP
#define MAQUINASESTADOS_HPP
#include <SFML/Graphics.hpp>
#include <string>


    class Jugador;

    enum class Estados{
        Quieto,
        CaminarIzq,
        CaminarDer,
        Salto,
        Agacharse,
        Combate
    };

    class MaquinaEstados{
        private:
        Jugador* jugador; //Apuntará al mismo jugador
        Estados estadoActual = Estados::Quieto;
        bool teclaW;
        bool teclaA;
        bool teclaS;
        bool teclaD;
        bool izq = false, der = true;
        bool estaEnSuelo = false;
        bool estaEnElAire = false;

        public:
        MaquinaEstados(Jugador* j): jugador(j){}

        void cambiarEstado(Estados nuevoEstado);

        Estados getEstado() const;

        void actualizar(sf::RenderWindow& ventana, float dt, bool eventoSaltar);



    };
#endif
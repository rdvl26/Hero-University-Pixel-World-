#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;



//######CLASE PADRE######
class Diseño{

    protected:
        float posicionX;
        float posicionY;
        sf::Sprite sprite;
        sf:: Texture textura;
    
    public:
        Diseño(float posicionX, float posicionY /* "sprite *Diseño" */ ){

        }

        float getPosicionX(){
            return posicionX;
        }
        
        float getPosicionY(){
            return posicionY;
        }

        void SincronizarSprite(){
            sprite.setPosition(posicionX, posicionY);
        }

        void dibujarTodo(sf::RenderWindow& ventana){

        
        }

};

//######CLASE HIJA 1######

class Bot : public Diseño{

    protected:
        int vida;
        int daño;
        int velocidad;

    public:
        Bot(float posicionX, float posicionY /* "sprite *Diseño" */ ) : Diseño(posicionX, posicionY /* "sprite *Diseño" */ ){

        }

        void movimiento(float posX, float posY){

        }

        void combate(){

        } 

        void daño(){

        } 

        void estadosSuelo(){

        }

        int getVida(){

        }

        string getNombre(){

        }

        int setVida(){

        }

};

//######CLASE HIJA 1.1######
class Jugador : public Bot{

    protected:
        string nombre;

    public:
        Jugador(float posicionX, float posicionY, string nombre) : Bot(posicionX, posicionY){

        }

        void saltar(float posicionX, float posicionY){

        }

        void interactuar(float posicionX, float posicionY){

        }

};

//######CLASE HIJA 1.2######
class Enemigos : public Bot{

    protected:
        int tipo;

    public:
        Enemigos(float posicionX, float posicionY, int tipo, int vida) : Bot(posicionX, posicionY){

        }
    
    bool estaVivo(){

    }

};

//######CLASE HIJA 2######
class Amado : public Diseño{

    protected:
        string nombre;
        int estado;

    public:
        Amado( float posicionX, float posicionY, string nombre) : Diseño(posicionX, posicionY /* "sprite *Diseño" */ ){

        }

        void pedirAyuda(){

        }
        
        void interactuar(){

        }
        
        void iniciarDialogo(){


        }
        
        void mostrarProductos(){

        }
        
        void vender(string producto){

        }
        
        void setEstado(string nuevoEstado){

        }
        
        int getEstado(){

        }
        
        void sincronizarSprite(){

        }

};

//######CLASE HIJA 3######
class Llave : public Diseño{

    protected:
        bool recogida;

    public:
        Llave(float posicionX, float posicionY) : Diseño(posicionX, posicionY /* "sprite *Diseño" */ ){

        }
    

        void interactuar(){

        }

        void setRecogida(){

        }

        void destruir(){

        }

};

//######CLASE HIJA 4######
class Puerta : public Diseño{

    protected:
        bool abierta;

    public:    
    void tieneLlave(/* "*Llave" */){

    }    
};

//CLASE HIJA 5######
class Plataformas : public Diseño{

    public:
    Plataformas(float posicionX, float posicionY) : Diseño(posicionX, posicionY /* "sprite *Diseño" */ ){
 
    }

    void colision(/* "Jugador*, enemigos*" */){
        
        }

    void destruir(){

    }

};




int main (){




    return 0;
}
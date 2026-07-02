#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;



//######CLASE PADRE######
class Diseño{

    protected:
        float posicionX;
        float posicionY;
        float alto;
        float ancho;
        sf::Sprite sprite;
        sf:: Texture textura;
    
    public:
        Diseño(float posicionX, float posicionY,string rutaImagen, float alto, float ancho){
            this->textura.loadFromFile(rutaImagen);
            sprite.setTexture(textura);
            sprite.setPosition(posicionX,posicionY);
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
            ventana.draw(sprite);
        }

};

//######CLASE HIJA 1######

class Bot : public Diseño{

    protected:
        int vida;
        int daño;
        int velocidad;
        bool vivo;

    public:
        Bot(float posicionX, float posicionY, string rutaImagen, float alto, float ancho ) : Diseño(posicionX, posicionY, rutaImagen, alto, ancho){
            sf::IntRect recorte(0,0,alto,ancho);
            sprite.setTextureRect(recorte);
        }

        void movimiento(float posX, float posY){

        }

        void combate(){

        } 

        void recibioDaño(){

        } 

        void estadosSuelo(){

        }

        int getVida(){
            return vida;
        }

        

        int setVida(){
            return vida;
        }

};

//######CLASE HIJA 1.1######
class Jugador : public Bot{

    protected:
        string nombre;

    public:
        Jugador(float posicionX, float posicionY,string rutaImagen,float alto, float ancho , string nombre) :nombre(nombre), Bot(posicionX, posicionY, rutaImagen,alto,ancho){
            
        }

        void saltar(float posicionX, float posicionY){

        }

        void interactuar(float posicionX, float posicionY){

        }
        string getNombre(){
            return nombre;
        }

};

//######CLASE HIJA 1.2######
class Enemigos : public Bot{

    protected:
        int tipo;

    public:
        Enemigos(float posicionX, float posicionY,string rutaImagen, float alto, float ancho, int tipo, int vida) : Bot(posicionX, posicionY,rutaImagen, alto, ancho){

        }
    
    bool estaVivo(){
        return vivo;
    }

};

//######CLASE HIJA 2######
class Amado : public Diseño{

    protected:
        string nombre;
        int estado;

    public:
        Amado( float posicionX, float posicionY,string rutaImagen, float alto, float ancho, string nombre) : Diseño(posicionX, posicionY, rutaImagen, alto, ancho){

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
            return estado;
        }
        
        void sincronizarSprite(){

        }

};

//######CLASE HIJA 3######
class Llave : public Diseño{

    protected:
        bool recogida;

    public:
        Llave(float posicionX, float posicionY, string rutaImagen, float alto, float ancho) : Diseño(posicionX, posicionY, rutaImagen, alto, ancho){

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
    Plataformas(float posicionX, float posicionY, string rutaImagen, float alto, float ancho) : Diseño(posicionX, posicionY, rutaImagen, alto, ancho){
 
    }

    void colision(/* "Jugador*, enemigos*" */){
        
        }

    void destruir(){

    }

};




int main (){

    sf::RenderWindow ventana(sf::VideoMode(1280,720), "Hero University");
    ventana.setFramerateLimit(90);

    Jugador player(640.0f,500.0f,"Recursos/Jugador.png",65,100,"Principal");

    while(ventana.isOpen()){
        sf::Event evento;
        while(ventana.pollEvent(evento)){ //procesar cada evento ocurrido
            if(evento.type == sf::Event::Closed) //Evento de cerrar la ventana
                ventana.close();
        }


        ventana.clear(sf::Color::Black); //Borrar el anterior FRAME y poner un fondo
            //Lo que dibujara en cada FRAME
        player.dibujarTodo(ventana);
        ventana.display(); //Dibujar nuevo FRAME
    }


    return 0;
}
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
        sf::Texture textura;
    
    public:
        Diseño(float posicionX, float posicionY,string rutaImagen, float alto, float ancho): posicionX(posicionX),posicionY(posicionY),alto(alto),ancho(ancho){
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
//Este metodo no hace nada
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

        //Variables para animacion
        sf::IntRect recorte;
        int frameActual;
        int espaciado;
        float contador;
        float temporizador;
        int animacionX, animacionY;
        float altoFrame;
        float anchoFrame;
        bool voltearSprite;
        

    public:
        Bot(float posicionX, float posicionY, string rutaImagen, float ancho, float alto ) : Diseño(posicionX, posicionY, rutaImagen, alto, ancho){
            //Recorte inicial
            animacionX = 0;
            animacionY = 0;
            contador = 0; 
            anchoFrame = ancho;
            altoFrame = alto;
            recorte = sf::IntRect(animacionX,animacionY,anchoFrame,altoFrame);
            sprite.setTextureRect(recorte);
            voltearSprite = false;
        }
        void movimiento(sf::RenderWindow& ventana,float& dt){
            if(voltearSprite){
                voltearSprite = false;
                sprite.setScale(1.0f,1.0f);
            }
           
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                contador+=dt;
                if(contador < 0.20){
                    recorte = sf::IntRect(animacionX = 0,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.60){
                    recorte = sf::IntRect(animacionX = anchoFrame,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    
                }else if(contador < 1.00){
                    recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 1.40){
                    recorte = sf::IntRect(animacionX = 0,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 1.80){
                    recorte = sf::IntRect(animacionX = anchoFrame,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 2.20){
                    recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    contador = 0;
                }
    
                posicionX += 100*dt;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

                if(!voltearSprite)
                    sprite.setScale(-1.0f,1.0f); //Volteado el sprite
                sprite.setOrigin(50,0);
                voltearSprite = true;
                contador+=dt;
                if(contador < 0.20){
                    recorte = sf::IntRect(animacionX = 0,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.60){
                    recorte = sf::IntRect(animacionX = anchoFrame,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    
                }else if(contador < 1.00){
                    recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 1.40){
                    recorte = sf::IntRect(animacionX = 0,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 1.80){
                    recorte = sf::IntRect(animacionX = anchoFrame,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 2.20){
                    recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    contador = 0;
                }
    
                posicionX -= 100*dt;
            }
    
    
            if (posicionX > 1280 - anchoFrame) {
                posicionX = 1280 - anchoFrame;
            }
            if (posicionX<0) {
                posicionX = 0;
            }
    
            sprite.setPosition(posicionX, posicionY);
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

        void movimiento(sf::RenderWindow& ventana,float& dt){
            Bot::movimiento(ventana, dt);
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
    sf::Clock reloj;
    float dt; //Cambio del tiempo entre frame
    Jugador player(640.0f,500.0f,"Recursos/Jugador.png",71,104,"Principal");

    while(ventana.isOpen()){
        dt = reloj.restart().asSeconds();
        
        sf::Event evento;
        while(ventana.pollEvent(evento)){ //procesar cada evento ocurrido
            if(evento.type == sf::Event::Closed) //Evento de cerrar la ventana
                ventana.close();
        }


        ventana.clear(sf::Color::Green); //Borrar el anterior FRAME y poner un fondo
            //Lo que dibujara en cada FRAME
        player.dibujarTodo(ventana);
        player.movimiento(ventana,dt);
        ventana.display(); //Dibujar nuevo FRAME
    }


    return 0;
}
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
        float contador;
        int animacionX, animacionY;
        float altoFrame;
        float anchoFrame;
        

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
        }
        void movimiento(sf::RenderWindow& ventana,float& dt){
           
           if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                contador+=dt;
                if(contador < 0.20){
                    recorte = sf::IntRect(animacionX = 0,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.33){
                    recorte = sf::IntRect(animacionX = anchoFrame,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    
                }else if(contador < 0.46){
                    recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.59){
                    recorte = sf::IntRect(animacionX = anchoFrame*3,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.72){
                    recorte = sf::IntRect(animacionX = anchoFrame*4,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.85){
                    recorte = sf::IntRect(animacionX = anchoFrame*5,animacionY = 0,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    contador = 0;
                }
    
                posicionX += 100*dt;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

                sprite.setOrigin(50,0);
                contador+=dt;
                if(contador < 0.20){
                    recorte = sf::IntRect(animacionX = 0,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.33){
                    recorte = sf::IntRect(animacionX = anchoFrame,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                    
                }else if(contador < 0.46){
                    recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.59){
                    recorte = sf::IntRect(animacionX = anchoFrame*3,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.72){
                    recorte = sf::IntRect(animacionX = anchoFrame*4,animacionY = altoFrame,anchoFrame,altoFrame);
                    sprite.setTextureRect(recorte);
                }else if(contador < 0.85){
                    recorte = sf::IntRect(animacionX = anchoFrame*5,animacionY = altoFrame,anchoFrame,altoFrame);
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

class Fondo{
private:
    vector<sf::Texture> cargarTexturaFondo;
    vector<sf::Sprite> spritesSuelo;
    sf::Sprite cielo;
    int posX;
    const int posY = 600;
public:
    Fondo(vector<string> ruta){
        this->posX = 0;
        //Cargar fondos en la GPU
        for(auto& rect: ruta){
            cargarTexturaFondo.emplace_back();
            cargarTexturaFondo.back().loadFromFile(rect);
        }
        cielo.setTexture(cargarTexturaFondo[0]);
        cielo.setPosition(0,0);
        cielo.setScale(10.0f,4.685f);
    }
    void suelo(){
        int i;
        for(i = 0; i < 20; i++){
            spritesSuelo.emplace_back(cargarTexturaFondo[1]);
        }
        for(i = 0; i < spritesSuelo.size(); i++){
            spritesSuelo[i].setPosition(posX + 128*i,posY);
            spritesSuelo[i].setScale(1.0f,1.0f);
        }
    }
    void dibujarTodo(sf::RenderWindow& ventana){
        for(int i = 0; i < spritesSuelo.size(); i++){
            ventana.draw(spritesSuelo[i]);
        }
        ventana.draw(cielo);
    }
};
class Plataformas : public Diseño{
    public:
    Plataformas(float posicionX, float posicionY, string suelo, float alto, float ancho) : Diseño(posicionX, posicionY, suelo, alto, ancho){
    }

    void colision(/* "Jugador*, enemigos*" */){
        
        }

    void destruir(){

    }

};

vector<string> cargarFondo(){
    vector<string> rutafondos;
    rutafondos.reserve(2);
    rutafondos.emplace_back("Aplicacion/Recursos/cielo.png");
    rutafondos.emplace_back("Aplicacion/Recursos/piso.png");
    return rutafondos;
}


int main (){

    sf::RenderWindow ventana(sf::VideoMode(1280,720), "Hero University");
    ventana.setFramerateLimit(90);
    sf::Clock reloj;
    float dt; //Cambio del tiempo entre frame
    Jugador player(640.0f,550.0f,"Aplicacion/Recursos/JUGADOR.png",71,104,"Principal");
    Fondo fondos(cargarFondo());

    while(ventana.isOpen()){
        dt = reloj.restart().asSeconds();
        
        sf::Event evento;
        while(ventana.pollEvent(evento)){ //procesar cada evento ocurrido
            if(evento.type == sf::Event::Closed) //Evento de cerrar la ventana
                ventana.close();
        }


        ventana.clear(sf::Color(51,153,255)); //Borrar el anterior FRAME y poner un fondo
        //Lo que dibujara en cada FRAME
        fondos.suelo();
        fondos.dibujarTodo(ventana);
        player.dibujarTodo(ventana);
        player.movimiento(ventana,dt);
        
        ventana.display(); //Dibujar nuevo FRAME
    }


    return 0;
}
#include "../include/Enemigos.hpp"

Enemigos::Enemigos(float posicionX, float posicionY,std::string rutaImagen, float ancho, float alto, std::shared_ptr<b2World> mundo, float anchoVentana, float altoVentana, int tipo, float desplazarHitbox) : Bot(posicionX,posicionY, rutaImagen, ancho,alto), conversiones(anchoVentana,altoVentana), desplazarHitbox(desplazarHitbox){

    caminata = true;
    alerta = false;
    voltearSprite = 1;
    sprite.setScale(1.15f,1.15f);
    sprite.setOrigin(this->ancho/2.0, this->alto/2.0);

    b2BodyDef defEnemigos;
    defEnemigos.type = b2_dynamicBody;
    defEnemigos.position.Set(conversiones.centroX_box2D(posicionX, this->ancho*sprite.getScale().x), conversiones.centroY_box2D(posicionY, this->alto*sprite.getScale().y));
    cuerpoEnemigo = mundo->CreateBody(&defEnemigos);

    b2PolygonShape formaEnemigo;
    formaEnemigo.SetAsBox(conversiones.mitadAnchoBox2D(this->ancho * sprite.getScale().x), conversiones.mitadAltoBox2D(this->alto* sprite.getScale().y));

    b2FixtureDef fixEnemigo;
    fixEnemigo.shape = &formaEnemigo;
    fixEnemigo.density = 1.0f;

    cuerpoEnemigo->CreateFixture(&fixEnemigo);

    b2PolygonShape formaHitbox;
    formaHitbox.SetAsBox(conversiones.mitadAnchoBox2D(this->ancho - 4), conversiones.mitadAltoBox2D(this->alto - 4), b2Vec2(conversiones.anchoBox2D(ancho*sprite.getScale().x), 0), 0.0f);

    b2FixtureDef fixHitbox;
    fixHitbox.shape = &formaHitbox;
    fixHitbox.isSensor = true;

    hitbox = cuerpoEnemigo->CreateFixture(&fixHitbox);

}

Enemigos::~Enemigos(){

}

void Enemigos::actualizar(float& dt, bool derecha, float posObjetivo,float anchoObjetivo,float altoObjetivo,float distanciaClaveObjetivo){
        this->posObjetivo = posObjetivo;
        this->anchoObjetivo = anchoObjetivo;
        this->altoObjetivo = altoObjetivo;
        this->distanciaClaveObjetivo = distanciaClaveObjetivo;

        movimientos(dt, false);
}

void Enemigos::movimientos(float &dt, bool derecha){

 if((posObjetivo + (this->anchoObjetivo/2)) > sprite.getPosition().x + distanciaClaveObjetivo || (posObjetivo + (this->anchoObjetivo/2)) < sprite.getPosition().x - distanciaClaveObjetivo){
        alerta = false;
    }else{
        alerta = true;
        if(posObjetivo + (this->anchoObjetivo/2) > sprite.getPosition().x + 1){
            vel.x = 2.0f;
            cuerpoEnemigo->SetLinearVelocity(vel);
            caminata = true;
            sprite.setScale(1.15,1.15);
        }
        else{
            vel.x = -2.0f;
            cuerpoEnemigo->SetLinearVelocity(vel);
            caminata = false;
            sprite.setScale(-1.15,1.15);
        }
    }
    if(caminata){ 
        voltearSprite = 1;
    }else{
        voltearSprite = -1;
    }

    //Camina a la derecha
    
        if(!alerta){
            vel = cuerpoEnemigo->GetLinearVelocity();
            vel.x = 2.0f * voltearSprite;
            cuerpoEnemigo->SetLinearVelocity(vel);

        }
       
        contador+=dt;
        if(contador < 0.20){
            recorte = sf::IntRect(animacionX = 0,animacionY = 0,this->ancho,this->alto);// 1
            sprite.setTextureRect(recorte);
        }
        else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = this->ancho,animacionY = 0,this->ancho,this->alto);// 2
            sprite.setTextureRect(recorte);
        }
        else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = this->ancho*2,animacionY = 0,this->ancho,this->alto);// 3
            sprite.setTextureRect(recorte);     
        }
        else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = 0,animacionY = this->alto,this->ancho,this->alto);// 4
            sprite.setTextureRect(recorte);         
        }
        else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = this->ancho,animacionY = this->alto,this->ancho,this->alto);// 5
            sprite.setTextureRect(recorte);       
        }
        else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = this->ancho*2,animacionY = this->alto,this->ancho,this->alto);// 6
            sprite.setTextureRect(recorte);     
        }
        else{
            contador=0; 
        }

        pos = cuerpoEnemigo->GetPosition();

        sprite.setPosition(conversiones.box2d_sfml_x(pos.x), conversiones.box2d_sfml_y(pos.y));

    //camina a la derecha
        if(conversiones.box2d_sfml_x(pos.x) >= 1040 && !alerta){
            caminata=false;// cambiamos a falso para podercaminar a la izquierda
            sprite.setScale(-1.15, 1.15);
        }
    //Camina a la izquierda      
   
        if(conversiones.box2d_sfml_x(pos.x) <= 840 && !alerta){
            caminata=true;
            sprite.setScale(1.15, 1.15);
        }
    


   
}


bool Enemigos::estaVivo(){
        return vivo;
    }

b2Body* Enemigos::getCuerpo(){
    return cuerpoEnemigo;
}

b2Fixture* Enemigos::getHitbox(){
    return hitbox;
}
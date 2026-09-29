#include "../include/Jugador.hpp"

Jugador::Jugador(float posicionX, float posicionY,std::string rutaImagen,float ancho, float alto , std::shared_ptr<b2World> mundo ,ContactListener* listaColisiones, float anchoVentana, float altoVentana, std::string nombre) :nombre(nombre), listaColisiones(listaColisiones),Bot(posicionX, posicionY, rutaImagen,ancho,alto), conversion(anchoVentana,altoVentana){
            sprite.setScale(1.15f,1.15f);
            sprite.setOrigin(this->ancho /2.0 , this->alto/2.0);
            vista.setSize(1280,720);
            limiteDerecho = 3000;
            centroVistaX = 640;
            centroVistaY = 360;
            vista.setCenter(centroVistaX,centroVistaY);
            impulsoSalto.x = 0.0f;
            impulsoSalto.y = 0.0f;
            this->anchoFrameSalto = this->ancho;
            altoFrameSalto = this->alto;

            estadoActual = Estados::Quieto;

            b2BodyDef defCuerpoJugador;
            defCuerpoJugador.type = b2_dynamicBody;
            defCuerpoJugador.fixedRotation = true;
            defCuerpoJugador.position.Set(conversion.centroX_box2D(posicionX,this->ancho * sprite.getScale().x),conversion.centroY_box2D(posicionY,this->alto * sprite.getScale().y));

            cuerpoJugador = mundo->CreateBody(&defCuerpoJugador);

            b2PolygonShape formaJugador;
            formaJugador.SetAsBox(conversion.mitadAnchoBox2D(this->ancho * sprite.getScale().x),conversion.mitadAltoBox2D(this->alto * sprite.getScale().y));

            b2FixtureDef fixJugador;
            fixJugador.shape = &formaJugador;
            fixJugador.density = 1.0;

            cuerpoJugador->CreateFixture(&fixJugador);

            b2PolygonShape formaPies;                                                               //centro sensor
            formaPies.SetAsBox(conversion.mitadAnchoBox2D((this->ancho * sprite.getScale().x) - 4), 0.05f, b2Vec2(0, - (conversion.mitadAltoBox2D(this->alto * sprite.getScale().y)  + 0.025)), 0.0f);
            
            b2FixtureDef fixPies;
            fixPies.shape = &formaPies;
            fixPies.isSensor = true; //Al avisar que es sensor no le afecta la física solo informa

            sensorPies = cuerpoJugador->CreateFixture(&fixPies);

            b2PolygonShape formaHitbox;
            formaHitbox.SetAsBox(conversion.mitadAnchoBox2D(this->ancho - 4), conversion.mitadAltoBox2D(this->alto - 4));

            b2FixtureDef fixHitbox;
            fixHitbox.shape = &formaHitbox;
            fixHitbox.isSensor = true;

            hitbox = cuerpoJugador->CreateFixture(&fixHitbox);

        }

Jugador::~Jugador(){}

void Jugador::movimientos(float& dt, bool derecha){

    if(listaColisiones->tocaSuelo()){

        //aplicar velocidad apenas se presione la tecla
        contador+=dt;

        if(derecha){
            posRecorte = 0;

            vel = cuerpoJugador->GetLinearVelocity();
            vel.x = 5.0;
            cuerpoJugador->SetLinearVelocity(vel);
        }
        else{
            posRecorte = 1;
            vel = cuerpoJugador->GetLinearVelocity();
            vel.x = -5.0;
            cuerpoJugador->SetLinearVelocity(vel);
        }
        
        
        
        if(contador < 0.20){
            recorte = sf::IntRect(animacionX = 0,animacionY = this->alto* posRecorte,this->ancho,this->alto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = this->ancho,animacionY = this->alto*posRecorte,this->ancho,this->alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = this->ancho*2,animacionY = this->alto*posRecorte,this->ancho,this->alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = this->ancho*3,animacionY = this->alto*posRecorte,this->ancho,this->alto);
            sprite.setTextureRect(recorte);

        }else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = this->ancho*4,animacionY = this->alto*posRecorte,this->ancho,this->alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = this->ancho*5,animacionY = this->alto*posRecorte,this->ancho,this->alto);
            sprite.setTextureRect(recorte);
            contador = 0;
        }
    }
    pos = cuerpoJugador->GetPosition();

    if (conversion.box2d_sfml_x(pos.x) > limiteDerecho - this->anchoFrame) {
        pos.x = (limiteDerecho - this->anchoFrame)/conversion.getEscala(); // añadir funciones a conversiones
    }
    if (conversion.box2d_sfml_x(pos.x) < 0) {
        pos.x = (limiteDerecho - this->anchoFrame)/ conversion.getEscala();
    }

    sprite.setPosition(conversion.box2d_sfml_x(pos.x), conversion.box2d_sfml_y(pos.y));

    centroVistaX = sprite.getPosition().x;

    if(centroVistaX < 640){
        centroVistaX = 640;
    }
    if(centroVistaX > limiteDerecho-640){
        centroVistaX = limiteDerecho-640;
    }
    vista.setCenter(centroVistaX,centroVistaY);
}

void Jugador::setAnchoSalto_setAltoSalto(float ancho, float alto){
    anchoFrameSalto = ancho;
    altoFrameSalto = alto;
}

void Jugador::iniciarSalto(){
    if(listaColisiones->tocaSuelo()){
            impulsoSalto.y = 80.0f;
            cuerpoJugador->ApplyLinearImpulseToCenter(impulsoSalto, true);
            contador = 0;
        }
        
    sprite.setPosition(conversion.box2d_sfml_x(cuerpoJugador->GetPosition().x) , conversion.box2d_sfml_y(cuerpoJugador->GetPosition().y));

}

void Jugador::saltar(float& dt, float recorteAnimacionColumna){
        contador += dt;

         if(contador < 0.20){
            recorte = sf::IntRect(animacionX = 0,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna), this->anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = this->anchoFrameSalto,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),this->anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = this->anchoFrameSalto*2,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),this->anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = this->anchoFrameSalto*3,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),this->anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = this->anchoFrameSalto*4,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),this->anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = this->anchoFrameSalto*5,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),this->anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
            contador = 0;
        }
        
        sprite.setPosition(conversion.box2d_sfml_x(cuerpoJugador->GetPosition().x) , conversion.box2d_sfml_y(cuerpoJugador->GetPosition().y));

        centroVistaX = sprite.getPosition().x;

        if(centroVistaX < 640){
            centroVistaX = 640;
        }
        if(centroVistaX > limiteDerecho-640){
            centroVistaX = limiteDerecho-640;
        }
        vista.setCenter(centroVistaX,centroVistaY);

}

b2Fixture* Jugador::getSensor(){
    return sensorPies;
}

void Jugador::interactuar(float posicionX, float posicionY){

}

void Jugador::quieto(float& dt, bool derecha){
    
    if(derecha){
        posRecorte = 0;
    }else{
        posRecorte = 1;
    }

    vel = cuerpoJugador->GetLinearVelocity();
    vel.x = 0.0;
    cuerpoJugador->SetLinearVelocity(vel);
    contador+=dt;

    if(contador < 0.20){
        recorte = sf::IntRect(animacionX = 0,animacionY = this->alto*(2 + posRecorte),this->ancho,this->alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.33){
        recorte = sf::IntRect(animacionX = this->ancho,animacionY = this->alto*(2 + posRecorte),this->ancho,this->alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.46){
        recorte = sf::IntRect(animacionX = this->ancho*2,animacionY = this->alto*(2 + posRecorte),this->ancho,this->alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.59){
        recorte = sf::IntRect(animacionX = this->ancho*3,animacionY = this->alto*(2 + posRecorte),this->ancho,this->alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.72){
        recorte = sf::IntRect(animacionX = this->ancho*4,animacionY = this->alto*(2 + posRecorte),this->ancho,this->alto);
        sprite.setTextureRect(recorte);
    }else if(contador >= 0.72){
        recorte = sf::IntRect(animacionX = this->ancho*5,animacionY = this->alto*(2 + posRecorte),this->ancho,this->alto);
        sprite.setTextureRect(recorte);
        contador = 0;
    }
    
    sprite.setPosition(conversion.box2d_sfml_x(cuerpoJugador->GetPosition().x), conversion.box2d_sfml_y(cuerpoJugador->GetPosition().y));

}

void Jugador::cambiarEstado(Estados nuevoEstado){
    if(estadoActual != nuevoEstado){
        estadoActual = nuevoEstado;
    }
}

void Jugador::actualizar(float& dt, bool eventoSaltar){
     teclaW = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    teclaA = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    teclaS = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    teclaD = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    estaEnSuelo =  listaColisiones->tocaSuelo();
    if(eventoSaltar && estaEnSuelo){
            cambiarEstado(Estados::Salto);
            iniciarSalto();
    }else if(!estaEnSuelo || (estadoActual == Estados::Salto && getVelocidadY() > 0.5f)){
            cambiarEstado(Estados::Salto);
    }else if(estaEnSuelo){
            if(teclaA && !teclaD && estaEnSuelo){
            cambiarEstado(Estados::CaminarIzq);
            izq = true;
            der = false;
        }else if(teclaD && !teclaA && listaColisiones->tocaSuelo()){
            cambiarEstado(Estados::CaminarDer);
            izq = false;
            der = true;
        }else{
            estadoActual = Estados::Quieto;
        }
    }

    switch (estadoActual){
  
    case Estados::CaminarIzq:
        movimientos(dt, false);
        break;
    case Estados::CaminarDer:
        movimientos(dt, true);
        break;
    case Estados::Quieto:
        if(izq){
            quieto(dt, false);
        }else{
            quieto(dt, true);
        }
        break;
    case Estados::Salto:
        if(izq){
            saltar(dt, 1.025);
        }else{
            saltar(dt,0);
        }
        break;
    }
}

float Jugador::getVelocidadY(){
    return cuerpoJugador->GetLinearVelocity().y;
}

void Jugador::dibujarTodo(sf::RenderWindow& ventana){
    Diseño::dibujarTodo(ventana);
    ventana.setView(vista);
}

std::string Jugador::getNombre(){
    return nombre;
}

b2Body* Jugador::getCuerpo(){
    return cuerpoJugador;
}

b2Fixture* Jugador::getHitbox(){
    return hitbox;
}
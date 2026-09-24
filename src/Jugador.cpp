#include "../include/Jugador.hpp"

Jugador::Jugador(float posicionX, float posicionY,std::string rutaImagen,float ancho, float alto , std::shared_ptr<b2World> mundo ,ContactListener* listaColisiones, float anchoVentana, float altoVentana, std::string nombre) :nombre(nombre), listaColisiones(listaColisiones),Bot(posicionX, posicionY, rutaImagen,ancho,alto), conversion(anchoVentana,altoVentana){
            sprite.setScale(1.15f,1.15f);
            sprite.setOrigin(ancho /2.0 , alto/2.0);
            vista.setSize(1280,720);
            limiteDerecho = 3000;
            centroVistaX = 640;
            centroVistaY = 360;
            vista.setCenter(centroVistaX,centroVistaY);
            impulsoSalto.x = 0.0f;
            impulsoSalto.y = 0.0f;
            anchoFrameSalto = ancho;
            altoFrameSalto = alto;

            estadoActual = Estados::Quieto;

            b2BodyDef defCuerpoJugador;
            defCuerpoJugador.type = b2_dynamicBody;
            defCuerpoJugador.fixedRotation = true;
            defCuerpoJugador.position.Set(conversion.centroX_box2D(posicionX,ancho * sprite.getScale().x),conversion.centroY_box2D(posicionY,alto * sprite.getScale().y));

            cuerpoJugador = mundo->CreateBody(&defCuerpoJugador);

            b2PolygonShape formaJugador;
            formaJugador.SetAsBox(conversion.mitadAnchoBox2D(ancho),conversion.mitadAltoBox2D(alto));

            b2FixtureDef fixJugador;
            fixJugador.shape = &formaJugador;
            fixJugador.density = 1.0;

            cuerpoJugador->CreateFixture(&fixJugador);

            b2PolygonShape formaPies;                                                               //centro sensor
            formaPies.SetAsBox(conversion.mitadAnchoBox2D(ancho - 4), 0.05f, b2Vec2(0, - (conversion.mitadAltoBox2D(alto)  + 0.025)), 0.0f);
            
            b2FixtureDef fixPies;
            fixPies.shape = &formaPies;
            fixPies.isSensor = true; //Al avisar que es sensor no le afecta la física solo informa

            sensorPies = cuerpoJugador->CreateFixture(&fixPies);
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
            recorte = sf::IntRect(animacionX = 0,animacionY = alto* posRecorte,ancho,alto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = ancho,animacionY = alto*posRecorte,ancho,alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = ancho*2,animacionY = alto*posRecorte,ancho,alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = ancho*3,animacionY = alto*posRecorte,ancho,alto);
            sprite.setTextureRect(recorte);

        }else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = ancho*4,animacionY = alto*posRecorte,ancho,alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = ancho*5,animacionY = alto*posRecorte,ancho,alto);
            sprite.setTextureRect(recorte);
            contador = 0;
        }
    }
    pos = cuerpoJugador->GetPosition();

    if (conversion.box2d_sfml_x(pos.x) > limiteDerecho - anchoFrame) {
        pos.x = (limiteDerecho - anchoFrame)/conversion.getEscala(); // añadir funciones a conversiones
    }
    if (conversion.box2d_sfml_x(pos.x) < 0) {
        pos.x = (limiteDerecho - anchoFrame)/ conversion.getEscala();
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
            recorte = sf::IntRect(animacionX = 0,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna), anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = anchoFrameSalto,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = anchoFrameSalto*2,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = anchoFrameSalto*3,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = anchoFrameSalto*4,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),anchoFrameSalto,altoFrameSalto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = anchoFrameSalto*5,animacionY = altoFrameSalto*(4 + recorteAnimacionColumna),anchoFrameSalto,altoFrameSalto);
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
        recorte = sf::IntRect(animacionX = 0,animacionY = alto*(2 + posRecorte),ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.33){
        recorte = sf::IntRect(animacionX = ancho,animacionY = alto*(2 + posRecorte),ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.46){
        recorte = sf::IntRect(animacionX = ancho*2,animacionY = alto*(2 + posRecorte),ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.59){
        recorte = sf::IntRect(animacionX = ancho*3,animacionY = alto*(2 + posRecorte),ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.72){
        recorte = sf::IntRect(animacionX = ancho*4,animacionY = alto*(2 + posRecorte),ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador >= 0.72){
        recorte = sf::IntRect(animacionX = ancho*5,animacionY = alto*(2 + posRecorte),ancho,alto);
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
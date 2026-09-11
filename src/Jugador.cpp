#include "../include/Jugador.hpp"

Jugador::Jugador(float posicionX, float posicionY,std::string rutaImagen,float ancho, float alto , std::string nombre, std::shared_ptr<b2World> mundo ,ContactListener* listaColisiones, float anchoVentana, float altoVentana) :nombre(nombre), listaColisiones(listaColisiones),Bot(posicionX, posicionY, rutaImagen,ancho,alto), maquinaEstado(this), conversion(anchoVentana, altoVentana){
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

void Jugador::movimientoDer(sf::RenderWindow& ventana,float& dt){
    if(listaColisiones->tocaSuelo()){
        //aplicar velocidad apenas se presione la tecla
        contador+=dt;
        vel = cuerpoJugador->GetLinearVelocity();
        vel.x = 5.0;
        cuerpoJugador->SetLinearVelocity(vel);
        
        if(contador < 0.20){
            recorte = sf::IntRect(animacionX = 0,animacionY = 0,ancho,alto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = ancho,animacionY = 0,ancho,alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = ancho*2,animacionY = 0,ancho,alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = ancho*3,animacionY = 0,ancho,alto);
            sprite.setTextureRect(recorte);

        }else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = ancho*4,animacionY = 0,ancho,alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = ancho*5,animacionY = 0,ancho,alto);
            sprite.setTextureRect(recorte);
            contador = 0;
        }
    }
    pos = cuerpoJugador->GetPosition();

    if (conversion.box2d_sfml_x(pos.x) > limiteDerecho - ancho) {
        pos.x = (limiteDerecho - ancho)/conversion.getEscala(); // añadir funciones a conversiones
    }
    if (conversion.box2d_sfml_x(pos.x) < 0) {
        pos.x = (limiteDerecho - ancho)/ conversion.getEscala();
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

void Jugador::movimientoIzq(sf::RenderWindow& ventana, float& dt){
    if (listaColisiones->tocaSuelo()) {

        vel = cuerpoJugador->GetLinearVelocity();
        vel.x = -5.0;
        cuerpoJugador->SetLinearVelocity(vel);
        contador+=dt;
        if(contador < 0.20){
            recorte = sf::IntRect(animacionX = 0,animacionY = alto,ancho,alto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.33){
            recorte = sf::IntRect(animacionX = ancho,animacionY = alto,ancho,alto);
            sprite.setTextureRect(recorte);
            
        }else if(contador < 0.46){
            recorte = sf::IntRect(animacionX = ancho*2,animacionY = alto,ancho,alto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.59){
            recorte = sf::IntRect(animacionX = ancho*3,animacionY = alto,ancho,alto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.72){
            recorte = sf::IntRect(animacionX = ancho*4,animacionY = alto,ancho,alto);
            sprite.setTextureRect(recorte);
        }else if(contador < 0.85){
            recorte = sf::IntRect(animacionX = ancho*5,animacionY = alto,ancho,alto);
            sprite.setTextureRect(recorte);
            contador = 0;
        }
    }

        pos = cuerpoJugador->GetPosition();

        if (conversion.box2d_sfml_x(pos.x) > limiteDerecho - ancho) {
            pos.x = (limiteDerecho - ancho)/ conversion.getEscala();
        }
        if (conversion.box2d_sfml_x(pos.x) < 1) {
            pos.x = 1;
        }
    sprite.setPosition(conversion.box2d_sfml_x(pos.x) , conversion.box2d_sfml_y(pos.y));

    centroVistaX = sprite.getPosition().x;

    if(centroVistaX < 640){
        centroVistaX = 640;
    }
    if(centroVistaX > limiteDerecho-640){
        centroVistaX = limiteDerecho-640;
    }
    vista.setCenter(centroVistaX ,centroVistaY);
}

void Jugador::setAnchoSalto_setAltoSalto(float ancho, float alto){
    anchoFrameSalto = ancho;
    altoFrameSalto = alto;
}

void Jugador::iniciarSalto(){
    if(listaColisiones->tocaSuelo()){
            impulsoSalto.y = 50.0f;
            cuerpoJugador->ApplyLinearImpulseToCenter(impulsoSalto, true);
            contador = 0;
        }
        
    sprite.setPosition(conversion.box2d_sfml_x(cuerpoJugador->GetPosition().x) , conversion.box2d_sfml_y(cuerpoJugador->GetPosition().y));

}

void Jugador::saltar(sf::RenderWindow& ventana, float& dt, float recorteAnimacionColumna){
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

void Jugador::quietoDer(sf::RenderWindow& ventana,float& dt){
    
    vel = cuerpoJugador->GetLinearVelocity();
    vel.x = 0.0;
    cuerpoJugador->SetLinearVelocity(vel);
    contador+=dt;

    if(contador < 0.20){
        recorte = sf::IntRect(animacionX = 0,animacionY = alto*2,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.33){
        recorte = sf::IntRect(animacionX = ancho,animacionY = alto*2,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.46){
        recorte = sf::IntRect(animacionX = ancho*2,animacionY = alto*2,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.59){
        recorte = sf::IntRect(animacionX = ancho*3,animacionY = alto*2,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.72){
        recorte = sf::IntRect(animacionX = ancho*4,animacionY = alto*2,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador >= 0.72){
        recorte = sf::IntRect(animacionX = ancho*5,animacionY = alto*2,ancho,alto);
        sprite.setTextureRect(recorte);
        contador = 0;
    }
    
    sprite.setPosition(conversion.box2d_sfml_x(cuerpoJugador->GetPosition().x), conversion.box2d_sfml_y(cuerpoJugador->GetPosition().y));

}

void Jugador::quietoIzq(sf::RenderWindow& ventana,float& dt){
    contador+=dt;
    vel = cuerpoJugador->GetLinearVelocity();
    vel.x = 0.0;
    cuerpoJugador->SetLinearVelocity(vel);

    if(contador < 0.20){
        recorte = sf::IntRect(animacionX = 0,animacionY = alto*3,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.33){
        recorte = sf::IntRect(animacionX = ancho,animacionY = alto*3,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.46){
        recorte = sf::IntRect(animacionX = ancho*2,animacionY = alto*3,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.59){
        recorte = sf::IntRect(animacionX = ancho*3,animacionY = alto*3,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.72){
        recorte = sf::IntRect(animacionX = ancho*4,animacionY = alto*3,ancho,alto);
        sprite.setTextureRect(recorte);
    }else if(contador >= 0.72){
        recorte = sf::IntRect(animacionX = ancho*5,animacionY = alto*3,ancho,alto);
        sprite.setTextureRect(recorte);
        contador = 0;
    }
    
    sprite.setPosition(conversion.box2d_sfml_x(cuerpoJugador->GetPosition().x), conversion.box2d_sfml_y(cuerpoJugador->GetPosition().y));


}

void Jugador::actualizar(sf::RenderWindow& ventana, float& dt, bool eventoSaltar){
    maquinaEstado.actualizar(ventana, dt, eventoSaltar); //La maquina de estado decide que se ejecutará
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
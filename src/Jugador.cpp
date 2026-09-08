#include "../include/Jugador.hpp"

Jugador::Jugador(float posicionX, float posicionY,std::string rutaImagen,float alto, float ancho , std::string nombre, std::shared_ptr<b2World> mundo) :nombre(nombre), Bot(posicionX, posicionY, rutaImagen,alto,ancho), maquinaEstado(this){
            sprite.setScale(1.15f,1.15f);
            sprite.setOrigin(ancho/2.0 , alto/2.0);
            vista.setSize(1280,720);
            limiteDerecho = 3000;
            centroVistaX = 640;
            centroVistaY = 360;
            vista.setCenter(centroVistaX,centroVistaY);
            
            b2BodyDef defCuerpoJugador;
            defCuerpoJugador.type = b2_dynamicBody;
            defCuerpoJugador.fixedRotation = true;
            defCuerpoJugador.position.Set(centroX_box2D(posicionX,ancho * sprite.getScale().x), centroY_box2D(posicionY,alto * sprite.getScale().y));

            cuerpoJugador = mundo->CreateBody(&defCuerpoJugador);

            b2PolygonShape formaJugador;
            formaJugador.SetAsBox(mitadAnchoBox2D(ancho), mitadAltoBox2D(alto));

            b2FixtureDef fixJugador;
            fixJugador.shape = &formaJugador;
            fixJugador.density = 1.0;

            cuerpoJugador->CreateFixture(&fixJugador);
}
Jugador::~Jugador(){
    
}

void Jugador::movimientoDer(sf::RenderWindow& ventana,float& dt){
  
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        //aplicar velocidad apenas se presione la tecla
        contador+=dt;
        vel = cuerpoJugador->GetLinearVelocity();
        vel.x = 5.0;
        cuerpoJugador->SetLinearVelocity(vel);
        
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
    }

    pos = cuerpoJugador->GetPosition();

    if (box2d_sfml_x(pos.x) > limiteDerecho - anchoFrame) {
        pos.x = (limiteDerecho - anchoFrame)/escala; // añadir funciones a conversiones
    }
    if (box2d_sfml_x(pos.x) < 0) {
        pos.x = (limiteDerecho - anchoFrame)/ escala;
    }

    sprite.setPosition(box2d_sfml_x(pos.x), box2d_sfml_y(pos.y));

    centroVistaX = sprite.getPosition().x;
    centroVistaY = sprite.getPosition().y - 150;

    if(centroVistaX < 640){
        centroVistaX = 640;
    }
    if(centroVistaX > limiteDerecho-640){
        centroVistaX = limiteDerecho-640;
    }
    vista.setCenter(centroVistaX,centroVistaY);
}

void Jugador::movimientoIzq(sf::RenderWindow& ventana, float& dt){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

        vel = cuerpoJugador->GetLinearVelocity();
        vel.x = -5.0;
        cuerpoJugador->SetLinearVelocity(vel);
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
    }

        pos = cuerpoJugador->GetPosition();

        if (box2d_sfml_x(pos.x) > limiteDerecho - anchoFrame) {
            pos.x = (limiteDerecho - anchoFrame)/ escala;
        }
        if (box2d_sfml_x(pos.x) < 1) {
            pos.x = 1;
        }
    sprite.setPosition(box2d_sfml_x(pos.x) , box2d_sfml_y(pos.y));

    centroVistaX = sprite.getPosition().x;
    centroVistaY = sprite.getPosition().y - 150;

    if(centroVistaX < 640){
        centroVistaX = 640;
    }
    if(centroVistaX > limiteDerecho-640){
        centroVistaX = limiteDerecho-640;
    }
    vista.setCenter(centroVistaX ,centroVistaY);
}

void Jugador::saltar(float posicionX, float posicionY){

}
void Jugador::interactuar(float posicionX, float posicionY){

}

void Jugador::quietoDer(sf::RenderWindow& ventana,float dt){
    
    vel = cuerpoJugador->GetLinearVelocity();
    vel.x = 0.0;
    cuerpoJugador->SetLinearVelocity(vel);
    contador+=dt;

    if(contador < 0.20){
        recorte = sf::IntRect(animacionX = 0,animacionY = altoFrame*2,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.33){
        recorte = sf::IntRect(animacionX = anchoFrame,animacionY = altoFrame*2,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.46){
        recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = altoFrame*2,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.59){
        recorte = sf::IntRect(animacionX = anchoFrame*3,animacionY = altoFrame*2,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.72){
        recorte = sf::IntRect(animacionX = anchoFrame*4,animacionY = altoFrame*2,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador >= 0.72){
        recorte = sf::IntRect(animacionX = anchoFrame*5,animacionY = altoFrame*2,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
        contador = 0;
    }
    
    

}

void Jugador::quietoIzq(sf::RenderWindow& ventana,float dt){
    contador+=dt;
    vel = cuerpoJugador->GetLinearVelocity();
    vel.x = 0.0;
    cuerpoJugador->SetLinearVelocity(vel);

    if(contador < 0.20){
        recorte = sf::IntRect(animacionX = 0,animacionY = altoFrame*3,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.33){
        recorte = sf::IntRect(animacionX = anchoFrame,animacionY = altoFrame*3,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.46){
        recorte = sf::IntRect(animacionX = anchoFrame*2,animacionY = altoFrame*3,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.59){
        recorte = sf::IntRect(animacionX = anchoFrame*3,animacionY = altoFrame*3,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador < 0.72){
        recorte = sf::IntRect(animacionX = anchoFrame*4,animacionY = altoFrame*3,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
    }else if(contador >= 0.72){
        recorte = sf::IntRect(animacionX = anchoFrame*5,animacionY = altoFrame*3,anchoFrame,altoFrame);
        sprite.setTextureRect(recorte);
        contador = 0;
    }
    

}

void Jugador::actualizar(sf::RenderWindow& ventana, float dt){
    maquinaEstado.actualizar(ventana, dt); //La maquina de estado decide que se ejecutará
}

void Jugador::dibujarTodo(sf::RenderWindow& ventana){
    Diseño::dibujarTodo(ventana);
    ventana.setView(vista);
}
std::string Jugador::getNombre(){
    return nombre;
}
#include "../include/Fondo.hpp"

//AGREGAR UNA PARED INVISIBLE EN LOS LATERALES

Fondo::Fondo(std::vector<std::string> ruta, std::shared_ptr<b2World> mundo){
    this->posX_suelo = 0;

    
    //Cargar fondos en la GPU
    for(auto& r: ruta){
        std::shared_ptr<sf::Texture> textura = std::make_shared<sf::Texture>();
        textura->loadFromFile(r);
        cargarTexturaFondo.emplace_back(std::move(textura));
    }

    //Cielo

    for(int i = 0; i < 20; i++){
    cielo.setTexture(*cargarTexturaFondo[0]);
    cielo.setScale(1.5f,1.5f);
    cielo.setPosition(0+192*i,0);
    spritesCielo.push_back(cielo);
    }

    //Suelo

    for(int i = 0; i < MosaicosSuelos; i++){
    
        spritesSuelo.emplace_back(suelo);
        spritesSuelo.back().setTexture(*cargarTexturaFondo[1]);
        spritesSuelo.back().setScale(1.5f,1.5f);
        spritesSuelo.back().setPosition(posX_suelo + 192*i,528);
    }
    
    anchoSuelo = 192* MosaicosSuelos;

    b2BodyDef defSuelo;
    defSuelo.type = b2_staticBody;
    //para la posicion en Box2D se necesita el centro y en metros
    defSuelo.position.Set(centroX_box2D(posX_suelo, anchoSuelo), centroY_box2D(528, 200));

    cuerpoSuelo= mundo->CreateBody(&defSuelo);
    
    b2PolygonShape formaSuelo;
    formaSuelo.SetAsBox(mitadAnchoBox2D(anchoSuelo), mitadAltoBox2D(200));
        
    b2FixtureDef fixSuelo;
    fixSuelo.shape = &formaSuelo;
    fixSuelo.density = 0.0f;
    b2Fixture* fixSueloPtr = cuerpoSuelo->CreateFixture(&fixSuelo);
    //El sistema ya sabrá cual es la colisión suelo
    fixSueloPtr->GetUserData().pointer = (uintptr_t)"suelo";

    //montaña
    
    for(int i = 0; i < 5; i++){
        montaña.setTexture(*cargarTexturaFondo[2]);
        montaña.setScale(2.0f,2.0f);
        montaña.setPosition(1280 * i,0);
        spritesMontañas.push_back(montaña);
    }
}

void Fondo::dibujarTodo(sf::RenderWindow& ventana){
        
        int i;
        for(i = 0; i < spritesCielo.size(); i++){
            ventana.draw(spritesCielo[i]);
        }
        for(i = 0; i < spritesSuelo.size(); i++){
            ventana.draw(spritesSuelo[i]);
        }
        for(i = 0; i < spritesMontañas.size(); i++){
            ventana.draw(spritesMontañas[i]);
        }
}



#include "../include/Fondo.hpp"

//AGREGAR UNA PARED INVISIBLE EN LOS LATERALES

void Fondo::cargarFondo(){
    rutafondos.reserve(2);
    rutafondos.emplace_back("assets/cielo.png");
    rutafondos.emplace_back("assets/piso.png");
    rutafondos.emplace_back("assets/montañas.png");
}

Fondo::Fondo(std::shared_ptr<b2World> mundo, float anchoVentana, float alturaVentana) : conversiones(anchoVentana, alturaVentana){
    this->posX_suelo = 0;
    cargarFondo();
    
    //Cargar fondos en la GPU
    for(auto& r: rutafondos){
        std::shared_ptr<sf::Texture> textura = std::make_shared<sf::Texture>();
        textura->loadFromFile(r);
        cargarTexturaFondo.emplace_back(std::move(textura)); //mover el recurso de textura al vector
    }

    //Cielo

    for(int i = 0; i < 20; i++){
    cielo.setTexture(*cargarTexturaFondo[0]);
    if(i == 0) //solo asignar una vez
        tamañoImagen_Cielo = cielo.getGlobalBounds();
    cielo.setScale(1.5f,1.5f);
    cielo.setPosition(tamañoImagen_Cielo.width *i ,0);
    spritesCielo.push_back(cielo);
    }

    

    //Suelo

    for(int i = 0; i < MosaicosSuelos; i++){
    
        spritesSuelo.emplace_back(suelo);
        spritesSuelo.back().setTexture(*cargarTexturaFondo[1]);
        if(i == 0)
            tamañoImagen_Suelo = spritesSuelo.back().getGlobalBounds();
        spritesSuelo.back().setScale(1.5f,1.5f);
        spritesSuelo.back().setPosition(posX_suelo + (tamañoImagen_Suelo.width*i),528);
    }

    b2BodyDef defSuelo;
    defSuelo.type = b2_staticBody;
    //para la posicion en Box2D se necesita el centro y en metros
    defSuelo.position.Set(conversiones.centroX_box2D(posX_suelo, tamañoImagen_Suelo.width * MosaicosSuelos), conversiones.centroY_box2D(600, 200));

    cuerpoSuelo= mundo->CreateBody(&defSuelo);
    
    b2PolygonShape formaSuelo;
    formaSuelo.SetAsBox(conversiones.mitadAnchoBox2D(tamañoImagen_Suelo.width * MosaicosSuelos), conversiones.mitadAltoBox2D(200));
  
    cuerpoSuelo->CreateFixture(&formaSuelo, 0.0f);

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



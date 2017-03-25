#include "Mapa.hpp"


Mapa::Mapa() {   
    _width = new int();
    _height = new int();
    _tileHeight = new int();
    _tileWidth = new int();
    _x = new int();
    _y = new int();
    _oheight = new int();
    _owidth = new int();
    _capaColisiones = new int*[15];
    for(int i =0; i<15; i++){
        _capaColisiones[i] = new int[120];
    }
    
    _spritesMapa = new Sprite*[15];
     for(int i =0; i<15; i++){
        _spritesMapa[i] = new Sprite[120];
    }
    
    
    _fuegoAlto = new Sprite();
    _corona = new Sprite();
    _logo = new Sprite();
    _fuegoBajo = new Sprite();

    _diamanteAzul = new sf::Texture();
    _bola = new sf::Texture();
    _diamanteRojo = new sf::Texture();
    _copa = new sf::Texture();
    _texturaLogo = new sf::Texture();
    _puerta = new sf::Texture();
    _texturaFuegoBajo = new sf::Texture();
    _texturaFuegoBajo2 = new sf::Texture();
    _texturaFuegoAlto = new sf::Texture();
    _ladrilloRojo = new sf::Texture();
    _tubo = new sf::Texture();
    _texturaCorona = new sf::Texture();
    _tuboBajo = new sf::Texture();
    _tuboAlto = new sf::Texture();
    _ladrilloAzul = new sf::Texture();
    _ladrilloNormal = new sf::Texture();
    _ladrilloMitadB = new sf::Texture();
    _ladrilloMitadT = new sf::Texture();
    _lila = new sf::Texture();
    _ladrilloRojoMitad = new sf::Texture();
    _ladrilloRojoMitad2 = new sf::Texture();
    _texturaAgua = new sf::Texture();
    _texturaAgua2 = new sf::Texture();
    _texturaAlgas = new sf::Texture();
    _texturaAlgas2 = new sf::Texture();
    _ladrilloAzul3 = new sf::Texture();
    _pistola = new sf::Texture();
    _negro = new sf::Texture();
    _negro->loadFromFile("Tiles/negro.png");

    
    _reloj = new sf::Clock();
    _reloj2 = new sf::Clock();
    _reloj3 = new sf::Clock();
    
    _textoIntro = new Text();
    _textoIntroCopy = new Text();
    _textoIntroCopy2 = new Text();
    
    _cabecera = new Cabecera();
    
    _tieneCopa = new bool(false);
    _estaPuerta = new bool(false);
    _tienePistola = new bool(false);
}

Mapa::Mapa(const Mapa& orig) {
}

Mapa::~Mapa() {
    delete _width;
    delete _height;
    delete _tileHeight;
    delete _tileWidth;
    delete _ladrilloRojo;
    delete _ladrilloNormal;
    delete _tubo;
    delete _puerta;
    delete _diamanteAzul;
    delete _bola;
    delete _copa;
    delete _diamanteRojo;
    delete _ladrilloMitadB;
    delete _ladrilloMitadT;
    delete _textoIntro;
    delete _textoIntroCopy;
    delete _textoIntroCopy2;
    
    for(int i =0; i<15; i++){
        delete[] _capaColisiones[i];
    }
    delete[] _capaColisiones;
    
     for(int i =0; i<15; i++){
        delete[] _spritesMapa[i];
    }
    delete[] _spritesMapa;
    delete[] _colisionesIzquierda;
    delete[] _colisionesDerecha;
    delete[] _colisionesAbajo;
    delete[] _colisionesArriba;
    delete _logo;
    delete _texturaLogo;
    delete _reloj;
    delete _reloj2;
    delete _texturaFuegoBajo;
    delete _texturaFuegoBajo2;
    delete _fuegoBajo;
    delete _reloj3;
    delete _texturaFuegoAlto;
    delete _fuegoAlto;
    delete _corona;
    delete _texturaCorona;
    delete _tuboAlto;
    delete _tuboBajo;
    delete _ladrilloAzul;
    delete _lila;
    delete _ladrilloRojoMitad;
    delete _ladrilloRojoMitad2;
    delete _texturaAgua;
    delete _texturaAgua2;
    delete _texturaAlgas;
    delete _texturaAlgas2;
    delete _ladrilloAzul3;
    delete _pistola;
    delete _negro;
    delete _cabecera;
    delete _tieneCopa;
    delete _estaPuerta;
    delete _imgA;
    delete _imgB;
    delete _tienePistola;
}

void Mapa::cargarMapaXML(int nivel){
    int numLayers = 0;
    TiXmlDocument doc;
    
    if(nivel == 0){
         doc.LoadFile("Intro.tmx");        
    }if(nivel == 1){
         doc.LoadFile("Nivel1.tmx");        
    }if(nivel == 2){
        doc.LoadFile("Nivel2.tmx");
    }if(nivel == 3){
        doc.LoadFile("Nivel3.tmx");
    }if(nivel == -1 || nivel == -2){
        doc.LoadFile("Transicion.tmx");
    }
    
    //Obtenemos las caracteristicas del mapa
    TiXmlElement * map = doc.FirstChildElement("map");
    map->QueryIntAttribute("width", _width);
    map->QueryIntAttribute("height", _height);
    map->QueryIntAttribute("tilewidth", _tileWidth);
    map->QueryIntAttribute("tileheight", _tileHeight);
        
    
    
    //Creo las texturas
    _ladrilloRojo->loadFromFile("Tiles/rojo.png");
    _ladrilloNormal->loadFromFile("Tiles/ladrillo2.png");
    _ladrilloAzul3->loadFromFile("Tiles/azul3.png");
    _tubo->loadFromFile("Tiles/tubo.png");
    _puerta->loadFromFile("Tiles/puerta.png");
    _ladrilloMitadB->loadFromFile("Tiles/mitad-ladrillo2.png");
    _ladrilloMitadT->loadFromFile("Tiles/mitad-ladrillo.png");
    _tuboAlto->loadFromFile("Tiles/tubo_arriba.png");
    _tuboBajo->loadFromFile("Tiles/tubo_abajo.png");
    _ladrilloAzul->loadFromFile("Tiles/azul.png");
    _lila->loadFromFile("Tiles/lila.png");
    _ladrilloRojoMitad->loadFromFile("Tiles/rojo-mitad.png");
    _ladrilloRojoMitad2->loadFromFile("Tiles/rojo-mitad2.png");
    _texturaFuegoBajo->loadFromFile("Tiles/fuegobajo.png");
    _texturaFuegoBajo2->loadFromFile("Tiles/fuegobajo2.png");
    _texturaAgua->loadFromFile("Tiles/agua.png");
    _texturaAgua2->loadFromFile("Tiles/agua2.png");
    _texturaAlgas->loadFromFile("Tiles/algas.png");
    _texturaAlgas2->loadFromFile("Tiles/algas2.png");
    _texturaCorona->loadFromFile("Tiles/corona.png");
    
    

    //Cargando los GIDs de las colisiones
    TiXmlElement * data = map->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    for(int i=0; i<*_height; i++){
        for(int j=0; j<*_width;j++){
            data->QueryIntAttribute("gid", &_capaColisiones[i][j]);
            data = data->NextSiblingElement("tile");
        }
    }
   
   //Cargamos los objetos para las colisiones
   // _colisionesDerecha = new sf::RectangleShape[11];
    if(nivel == 1 || nivel == 2 || nivel == 3){  
      //Contamos el tamaño para introducir en el vector de rectangulos          
        int tamD=0, tamI=0, tamA = 0, tamU = 0;
      TiXmlElement * objectGroup = map->FirstChildElement("objectgroup");
      //Cargamos los objectos de colisiones de la derecha
      TiXmlElement * contadorD = objectGroup->FirstChildElement("object");
      while(contadorD){
         contadorD = contadorD->NextSiblingElement("object");
         tamD++;
      }
       _tamD = tamD; //Esta variable es para que la pueda cojer en el metodo comprobar colisiones
       _colisionesDerecha = new sf::RectangleShape[tamD];
       
       TiXmlElement * objectsD = objectGroup->FirstChildElement("object");
       for(int i=0; i<tamD; i++){
           objectsD->QueryIntAttribute("x", _x);
           objectsD->QueryIntAttribute("y", _y);
           objectsD->QueryIntAttribute("height", _oheight);
           objectsD->QueryIntAttribute("width", _owidth);
           _colisionesDerecha[i].setPosition(*_x, *_y);
           _colisionesDerecha[i].setSize(sf::Vector2f(*_owidth, *_oheight));
           objectsD = objectsD->NextSiblingElement("object");
       }
       
       //Cargamos los objectos de colisiones de la Izquierda
       TiXmlElement * contadorI = objectGroup->NextSiblingElement("objectgroup")->FirstChildElement("object");
       while(contadorI){
         contadorI = contadorI->NextSiblingElement("object");
         tamI++;
       }
       _tamI = tamI; 
       _colisionesIzquierda = new sf::RectangleShape[tamI];
       
       TiXmlElement * objectI = objectGroup->NextSiblingElement("objectgroup")->FirstChildElement("object");
       for(int i=0; i<tamI; i++){
           objectI->QueryIntAttribute("x", _x);
           objectI->QueryIntAttribute("y", _y);
           objectI->QueryIntAttribute("height", _oheight);
           objectI->QueryIntAttribute("width", _owidth);
           _colisionesIzquierda[i].setPosition(*_x, *_y);
           _colisionesIzquierda[i].setSize(sf::Vector2f(*_owidth, *_oheight));
           objectI = objectI->NextSiblingElement("object");
       }
       
       //Cargamos los objectos de colisiones de abajo
       TiXmlElement * contadorA = objectGroup->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
       while(contadorA){
         contadorA = contadorA->NextSiblingElement("object");
         tamA++;
       }
       _tamA = tamA; 
       _colisionesAbajo = new sf::RectangleShape[tamA];
       
       TiXmlElement * objectA = objectGroup->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
       
       for(int i=0; i<tamA; i++){
           objectA->QueryIntAttribute("x", _x);
           objectA->QueryIntAttribute("y", _y);
           objectA->QueryIntAttribute("height", _oheight);
           objectA->QueryIntAttribute("width", _owidth);
           _colisionesAbajo[i].setPosition(*_x, *_y);
           _colisionesAbajo[i].setSize(sf::Vector2f(*_owidth, *_oheight));
           objectA = objectA->NextSiblingElement("object");
       }
       
       //Cargamos los objectos de colisiones de arriba
       TiXmlElement * contadorU = objectGroup->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
       while(contadorU){
         contadorU = contadorU->NextSiblingElement("object");
         tamU++;
       }
       _tamU = tamU; 
       _colisionesArriba = new sf::RectangleShape[tamA];
       
       TiXmlElement * objectU = objectGroup->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->NextSiblingElement("objectgroup")->FirstChildElement("object");
       
       for(int i=0; i<tamU; i++){
           objectU->QueryIntAttribute("x", _x);
           objectU->QueryIntAttribute("y", _y);
           objectU->QueryIntAttribute("height", _oheight);
           objectU->QueryIntAttribute("width", _owidth);
           _colisionesArriba[i].setPosition(*_x, *_y);
           _colisionesArriba[i].setSize(sf::Vector2f(*_owidth, *_oheight));
           objectU = objectU->NextSiblingElement("object");
       }
       
      
    }
    
    
    //Cargando el array de sprites de las colisiones
    if(nivel == 0){ //Si el nivel es el 0 - Intro
         for(int i=0; i<*_height; i++){
               for(int j=0; j<*_width;j++){            
                   if(_capaColisiones[i][j] == 1){ 
                       _spritesMapa[i][j].setTexture(_ladrilloNormal);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 2){
                       _spritesMapa[i][j].setTexture(_ladrilloMitadT);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 3){
                       _spritesMapa[i][j].setTexture(_ladrilloMitadB);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 4){
                       _spritesMapa[i][j].setTexture(_texturaCorona);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }
               }
         }
         cargarTextoIntro();
         
    }else if(nivel == 1){ //Si el nivel es el 1
        for(int i=0; i<*_height; i++){
               for(int j=0; j<*_width;j++){            
                   if(_capaColisiones[i][j] == 1){ //Si es igual a 1 tenemos que crear los ladrillos
                       _spritesMapa[i][j].setTexture(_ladrilloRojo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 2){ //Si es 2 cargamos el ladrillo normal
                        _spritesMapa[i][j].setTexture(_ladrilloNormal);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 3){ //Si es 3 cargamos la puerta
                       _spritesMapa[i][j].setTexture(_puerta);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 4){ //Si es 4 cargamos el tubo
                       _spritesMapa[i][j].setTexture(_tubo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 5){ //Si es 4 cargamos el tubo
                       _spritesMapa[i][j].setTexture(_tuboAlto);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 6){ //Si es 4 cargamos el tubo
                       _spritesMapa[i][j].setTexture(_tuboBajo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }
               }
           }
        cargarObjetos(1);//Llamo al metodo que va a cargar los objetos
        
    }else if(nivel == 2){
         for(int i=0; i<*_height; i++){
               for(int j=0; j<*_width;j++){   
                    if(_capaColisiones[i][j] == 1){ 
                       _spritesMapa[i][j].setTexture(_ladrilloRojo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 2){
                       _spritesMapa[i][j].setTexture(_ladrilloRojoMitad);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 3){ 
                       _spritesMapa[i][j].setTexture(_lila);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 4){
                       _spritesMapa[i][j].setTexture(_puerta);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 5){
                       _spritesMapa[i][j].setTexture(_tuboAlto);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 6){
                       _spritesMapa[i][j].setTexture(_tuboBajo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 7){ //EL numero 7 es el fuego de tipo 1
                       _spritesMapa[i][j].setTexture(_texturaFuegoBajo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 8){ //EL numero 8 es el fuego de tipo 2
                       _spritesMapa[i][j].setTexture(_texturaFuegoBajo2);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 9){ //EL numero 9 es el agua de tipo 1
                       _spritesMapa[i][j].setTexture(_texturaAgua);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 10){ //EL numero 10 es el agua de tipo 2
                       _spritesMapa[i][j].setTexture(_texturaAgua2);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 14){ //EL numero 14 es la alga de tipo 1
                       _spritesMapa[i][j].setTexture(_texturaAlgas);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 15){ //EL numero 15 es la alga de tipo 2
                       _spritesMapa[i][j].setTexture(_texturaAlgas2);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }else if(_capaColisiones[i][j] == 17){ 
                       _spritesMapa[i][j].setTexture(_ladrilloRojoMitad2);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);   
                    }
               }
               
            cargarObjetos(2);//Llamo al metodo que va a cargar los objetos

         }
             
    }else if(nivel == 3){
          for(int i=0; i<*_height; i++){
               for(int j=0; j<*_width;j++){   
                    if(_capaColisiones[i][j] == 1){ 
                       _spritesMapa[i][j].setTexture(_ladrilloNormal);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 2){
                       _spritesMapa[i][j].setTexture(_ladrilloAzul3);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 3){
                       _spritesMapa[i][j].setTexture(_tubo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 6){ //El numero 6 son las algas de tipo 1
                       _spritesMapa[i][j].setTexture(_texturaAlgas);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 7){ //El numero 6 son las algas de tipo 2
                       _spritesMapa[i][j].setTexture(_texturaAlgas2);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 8){
                       _spritesMapa[i][j].setTexture(_tuboAlto);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }else if(_capaColisiones[i][j] == 9){
                       _spritesMapa[i][j].setTexture(_tuboBajo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                    }
               }
          }
        cargarObjetos(3);//Llamo al metodo que va a cargar los objetos
        
    }else if(nivel == -1 || nivel == -2){ //El -1 es una transicion
          for(int i=0; i<*_height; i++){
               for(int j=0; j<*_width;j++){            
                   if(_capaColisiones[i][j] == 1){ //Si es igual a 1 es porque es el tubo de decoracion de arrriba
                       _spritesMapa[i][j].setTexture(_tuboAlto);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 2){ //Si es igual a 1 es porque es el tubo de decoracion de abajo
                       _spritesMapa[i][j].setTexture(_tuboBajo);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 4){ //Si es igual a 4 es la puerta
                       _spritesMapa[i][j].setTexture(_puerta);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }else if(_capaColisiones[i][j] == 3){ //Si es igual a 3 es el ladrillo azul de la transicion
                       _spritesMapa[i][j].setTexture(_ladrilloAzul);
                       _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }
               }
           }
    }
    
}
//Metodo que carga los objetos que puntuan
void Mapa::cargarObjetos(int nivel) {
    _diamanteAzul->loadFromFile("Tiles/diamante.png");
    _bola->loadFromFile("Tiles/bola.png");
    _diamanteRojo->loadFromFile("Tiles/diamante-r.png");
    _pistola->loadFromFile("Tiles/pistola.png");
    _copa->loadFromFile("Tiles/copa.png");

    
    if(nivel == 1){
        /* 7 Diamante Azul
           8 Bola Rosa
           9 Diamante Rojo
           10 Copa */
       for(int i=0; i<*_height; i++){
               for(int j=0; j<*_width;j++){
                   if(_capaColisiones[i][j] == 7){
                        _spritesMapa[i][j].setTexture(_diamanteAzul);
                        _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }if(_capaColisiones[i][j] == 8){
                        _spritesMapa[i][j].setTexture(_bola);
                         _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }if(_capaColisiones[i][j] == 9){
                        _spritesMapa[i][j].setTexture(_diamanteRojo);
                         _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }if(_capaColisiones[i][j] == 10){
                        _spritesMapa[i][j].setTexture(_copa);
                        _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }            
               }
       }
    }else if(nivel == 2){
        /* 11 Diamante Azul
           13 Bola Rosa
           12 Diamante Rojo
           16 Copa */
         for(int i=0; i<*_height; i++){
               for(int j=0; j<*_width;j++){
                   if(_capaColisiones[i][j] == 11){
                        _spritesMapa[i][j].setTexture(_diamanteAzul);
                        _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }if(_capaColisiones[i][j] == 13){
                        _spritesMapa[i][j].setTexture(_bola);
                         _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }if(_capaColisiones[i][j] == 12){
                        _spritesMapa[i][j].setTexture(_diamanteRojo);
                         _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }if(_capaColisiones[i][j] == 16){
                        _spritesMapa[i][j].setTexture(_copa);
                         _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }
               }
       }
      
    }else if(nivel == 3){
        /* 4 Diamante Azul
           5 Pistola */
         for(int i=0; i<*_height; i++){
               for(int j=0; j<*_width;j++){
                   if(_capaColisiones[i][j] == 4){
                        _spritesMapa[i][j].setTexture(_diamanteAzul);
                        _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }if(_capaColisiones[i][j] == 5){
                        _spritesMapa[i][j].setTexture(_pistola);
                        _spritesMapa[i][j].setPosition(j* *_tileWidth, i* *_tileHeight);
                   }         
               }
       }
    }
}

void Mapa::cargarTextoIntro() {
    _textoIntro->setString("Pulsa espacio para empezar");
    _textoIntro->setCharacterSize(25);
    _textoIntro->setPosition(400, 700);
    
    _textoIntroCopy->setString("By Sergio Perez");
    _textoIntroCopy->setCharacterSize(25);
    _textoIntroCopy->setPosition(500, 180);
    
    _textoIntroCopy2->setString("( c) 2016 SERGIO DESIGN");
    _textoIntroCopy2->setCharacterSize(25);
    _textoIntroCopy2->setPosition(450, 220);
}


Sprite * Mapa::getLadrillos(int i, int j) {
    return &_spritesMapa[i][j];
}

Text * Mapa::getTextoIntro() {
    return _textoIntro;
}

Text* Mapa::getTextoIntroCopy() {
    return _textoIntroCopy;
}

Text* Mapa::getTextoIntroCopy2() {
    return _textoIntroCopy2;
}

Sprite * Mapa::getLogotipoIntro() {
    float rt = _reloj->getElapsedTime().asSeconds();
    if(rt > 0.1 && rt < 0.2){
      _texturaLogo->loadFromFile("Resources/logo.png");
      _logo->setTexture(_texturaLogo);
    }else if(rt > 0.2 && rt < 0.3){
      _texturaLogo->loadFromFile("Resources/logo2.png");
      _logo->setTexture(_texturaLogo);
    }else if(rt > 0.3 && rt <0.4){
      _texturaLogo->loadFromFile("Resources/logo3.png");
      _logo->setTexture(_texturaLogo);
      _reloj->restart();
    }else if(rt > 0.4){
      _reloj->restart();
    }  
    _logo->setPosition(425, 10);
    return _logo;
}
//Este metodo carga el fuego bajo del intro
Sprite* Mapa::getFuegoBajo() {
   float rt = _reloj2->getElapsedTime().asSeconds();
    if(rt > 0.1 && rt < 0.2){
      _texturaFuegoBajo->loadFromFile("Tiles/fuegobajo.png");
      _fuegoBajo->setTexture(_texturaFuegoBajo);
    }else if(rt > 0.2 && rt < 0.3){
      _texturaFuegoBajo->loadFromFile("Tiles/fuegobajo2.png");
      _fuegoBajo->setTexture(_texturaFuegoBajo);
      _reloj2->restart();
    }else if(rt > 0.3){
      _reloj2->restart();
    }
    _fuegoBajo->setPosition(800, 625);
    return _fuegoBajo;
}
//Esto metodo carga el fuego alto del intro
Sprite* Mapa::getFuegoAlto() {
  float rt = _reloj3->getElapsedTime().asSeconds();
    if(rt > 0.1 && rt < 0.2){
      _texturaFuegoAlto->loadFromFile("Tiles/fuegoalto.png");
      _fuegoAlto->setTexture(_texturaFuegoAlto);
    }else if(rt > 0.2 && rt < 0.3){
      _texturaFuegoAlto->loadFromFile("Tiles/fuegoalto2.png");
      _fuegoAlto->setTexture(_texturaFuegoAlto);
      _reloj3->restart();
    }else if(rt > 0.3){
       _reloj3->restart();
    }
    _fuegoAlto->setPosition(500, 550);
    return _fuegoAlto;
}
//Aqui lo que hago es cambiar las texturas del fuego y agua cada cierto tiempo y asi parece que se mueve
void Mapa::moverFuegoAguaAlgas() {
    float rt = _reloj2->getElapsedTime().asSeconds();
    if(rt > 0.1 && rt < 0.2){
      _texturaFuegoBajo->loadFromFile("Tiles/fuegobajo.png");
      _texturaFuegoBajo2->loadFromFile("Tiles/fuegobajo2.png");
      _texturaAgua->loadFromFile("Tiles/agua.png");
      _texturaAgua2->loadFromFile("Tiles/agua2.png");
      _texturaAlgas->loadFromFile("Tiles/algas.png");
      _texturaAlgas2->loadFromFile("Tiles/algas2.png");
    }else if(rt > 0.2 && rt < 0.3){
      _texturaFuegoBajo->loadFromFile("Tiles/fuegobajo2.png");
      _texturaFuegoBajo2->loadFromFile("Tiles/fuegobajo.png");
      _texturaAgua->loadFromFile("Tiles/agua2.png");
      _texturaAgua2->loadFromFile("Tiles/agua.png");
      _texturaAlgas->loadFromFile("Tiles/algas2.png");
      _texturaAlgas2->loadFromFile("Tiles/algas.png");
      _reloj2->restart();
    }else if(rt > 0.3){
        _reloj2->restart();
    }
  
}

//Este metodo carga la copa y hace que se mueve da igual en que nivel este
void Mapa::moverCopa() {
    float rt = _reloj->getElapsedTime().asSeconds();
        if(rt > 0.1 && rt < 0.4){
          _copa->loadFromFile("Tiles/copa2.png");
        }else if(rt > 0.4 && rt < 0.7){
          _copa->loadFromFile("Tiles/copa3.png");
        }else if(rt > 0.7 && rt <1.0){
          _copa->loadFromFile("Tiles/copa4.png");
        }else if(rt > 1.0 && rt <1.3){
          _copa->loadFromFile("Tiles/copa.png");
        }else if(rt > 1.3){
            _reloj->restart();
        }
    
}

//Aqui borramos el mapa para superponer el mapa siguiente
void Mapa::limpiarMapa() {
    sf::Texture * quitar = new sf::Texture;
    quitar->loadFromFile("Tiles/negro.png");
    for(int i=0; i<*_height; i++){
        for(int j=0; j<*_width;j++){
           _capaColisiones[i][j]=0;
           _spritesMapa[i][j].setTexture(quitar);
        }
    }   
}

bool Mapa::comprobarColision(AnimatedSprite * player, int pos, int estado) {
    bool res = false;
    if(estado == 1 || estado == 2 || estado == 3){
        if(pos == 1){ //Muevo el teclado de la derecha por lo que compruebo las colisiones de la izquierda
        for(int i =0; i<_tamD && !res ;i++){
            if(player->getGlobalBounds().intersects(_colisionesDerecha[i].getGlobalBounds())){
                res = true;
            }
        }
    }else if(pos == 2){
        for(int i =0; i<_tamI && !res ;i++){
            if(player->getGlobalBounds().intersects(_colisionesIzquierda[i].getGlobalBounds())){
                res = true;
            }
        }
    }else if(pos == 3){
        for(int i =0; i<_tamU && !res ;i++){
            if(player->getGlobalBounds().intersects(_colisionesArriba[i].getGlobalBounds())){
                res = true;
            }
        }
    }
    
    int x = player->getPosition().x;
    int y = player->getPosition().y;
    if(estado == 1){
        if(_capaColisiones[y/50][x/50] == 3){ //Comprobamos si esta en la puerta
             *_estaPuerta = true;
        }else{
              *_estaPuerta = false;
        }
    }else if(estado == 2){
        if(_capaColisiones[y/50][x/50+1] == 4){ //Comprobamos si esta en la puerta
             *_estaPuerta = true;
        }else{
             *_estaPuerta = false;
        }
    }
    
    }
    
   
   return res;
}

bool Mapa::comprobarColisionSuelo(AnimatedSprite* player, int estado) {
    bool res = false;
    
    if(_colisionesAbajo != NULL){
         for(int i =0; i<_tamA && !res ;i++){
            if(_colisionesAbajo[i].getGlobalBounds().intersects(player->getGlobalBounds())){
                res = true;
            }
        }
    }
         
    return res;
}

void Mapa::eliminaObjetos(AnimatedSprite* player, int estado) {

    
    int diAzul=-1, bolaRosa=-1, diRojo=-1, copa=-1, pistola=-1;
    if(estado == 1){ //Objetos Nivel 1
        diAzul = 7;
        bolaRosa = 8;
        diRojo = 9;
        copa = 10;
    }else if(estado == 2){ //Objetos Nivel 2
        diAzul = 11;
        bolaRosa = 13;
        diRojo = 12;
        copa = 16;
    }else if(estado == 3){ //Objetos Nivel 3
        diAzul = 4;
        pistola = 5;
    }
    
    int x = player->getPosition().x;
    int y = player->getPosition().y;
    if(_capaColisiones[y/50][x/50] == diAzul || _capaColisiones[y/50][x/50] == bolaRosa || _capaColisiones[y/50][x/50] == diRojo ||  _capaColisiones[y/50][x/50] == copa ||  _capaColisiones[y/50][x/50] == pistola){
             if(_capaColisiones[y/50][x/50] == diAzul){
                 _cabecera->setPuntuacion(diAzul);
             }else if(_capaColisiones[y/50][x/50] == bolaRosa){
                 _cabecera->setPuntuacion(bolaRosa);
             }else if(_capaColisiones[y/50][x/50] == diRojo){
                 _cabecera->setPuntuacion(diRojo);
             }else if(_capaColisiones[y/50][x/50] == copa){
                 _cabecera->setPuntuacion(copa);
                 *_tieneCopa = true;
             }else if(_capaColisiones[y/50][x/50] == pistola){
                 *_tienePistola = true;
             }   
             _capaColisiones[y/50][x/50] = 0;
             _spritesMapa[y/50][x/50].setTexture(_negro);
    }
    
    
    
}

bool Mapa::comprobarMuerte(AnimatedSprite* player, Estado* estado) {
    if(*estado->getEstado() == 2){ //Si estamos en el nivel 2 
         int x = player->getPosition().x;
         int y = player->getPosition().y;
         if(_capaColisiones[y/50+1][x/50] == 7 || _capaColisiones[y/50+1][x/50] == 8 || _capaColisiones[y/50+1][x/50] == 9  || _capaColisiones[y/50+1][x/50] == 10){
             return true;
         }
         
    }else if(*estado->getEstado() == 3){ //Si estamos en el nivel 3
         int x = player->getPosition().x;
         int y = player->getPosition().y;
         if(_capaColisiones[y/50+1][x/50] == 6 || _capaColisiones[y/50+1][x/50] == 7 || _capaColisiones[y/50][x/50+1] == 6 || _capaColisiones[y/50][x/50+1] == 7 || _capaColisiones[y/50][x/50] == 6 || _capaColisiones[y/50][x/50+1] == 7){
             return true;
         }
         
    } 
    return false;
}


void Mapa::setCabecera(Cabecera* c) {
    _cabecera = c;
}

bool* Mapa::tieneCopa() {
    return _tieneCopa;
}

bool* Mapa::tienePistola() {
    return _tienePistola;
}

bool* Mapa::estaPuerta() {
    return _estaPuerta;
}

void Mapa::setEstaPuerta() {
    *_estaPuerta = false;
}


void Mapa::setTieneCopa() {
    *_tieneCopa = false;
     
}

void Mapa::setTienePistola() {
    *_tienePistola = false;
}


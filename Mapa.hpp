#ifndef MAPA_HPP
#define MAPA_HPP
#include "tinyxml/tinyxml.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Motor/Sprite.hpp"
#include "Motor/Text.hpp"
#include "AnimatedSprite.hpp"
#include "Estado.hpp"
#include "Cabecera.hpp"

using namespace std;

class Mapa {
public:
    Mapa();
    Mapa(const Mapa& orig);
    virtual ~Mapa();
    void cargarMapaXML(int nivel);
    Sprite * getLadrillos(int i, int j);
    void cargarObjetos(int nivel);
    void cargarTextoIntro();
    Sprite * getLogotipoIntro();
    Sprite * getFuegoBajo();
    void moverFuegoAguaAlgas();
    Sprite * getFuegoAlto();
    void moverCopa();
    Text * getTextoIntro();
    Text * getTextoIntroCopy();
    Text * getTextoIntroCopy2();
    void limpiarMapa();
    bool compruebaColision();
    bool comprobarColision(AnimatedSprite * player, int pos, int estado);
    bool comprobarColisionSuelo(AnimatedSprite * player, int estado);
    void eliminaObjetos(AnimatedSprite * player, int estado);
    void setCabecera(Cabecera * c);
    bool comprobarMuerte(AnimatedSprite * player, Estado * estado);
    bool * tieneCopa();
    bool * estaPuerta();
    bool * tienePistola();
    void setTieneCopa();
    void setEstaPuerta();
    void setTienePistola();
    
private:
    int *_width;
    int *_height;
    int *_tileWidth;
    int *_tileHeight;
    int *_x, *_y, *_oheight, *_owidth, _tamD, _tamI, _tamA, _tamU;
    int **_capaColisiones;
    Sprite ** _spritesMapa, *_logo, *_fuegoBajo, *_fuegoAlto, *_corona;
    sf::RectangleShape *_colisionesIzquierda, *_colisionesDerecha, *_colisionesAbajo, *_colisionesArriba;
    sf::Texture * _ladrilloRojo, * _ladrilloNormal, *_ladrilloAzul, *_lila, *_ladrilloRojoMitad, *_ladrilloRojoMitad2, * _tubo, *_tuboBajo, *_tuboAlto, * _puerta, * _diamanteAzul, * _bola, * _diamanteRojo, * _copa, * _ladrilloMitadT, * _ladrilloMitadB, *_texturaLogo, * _texturaFuegoBajo, *_texturaFuegoBajo2, *_texturaFuegoAlto, *_texturaCorona, *_texturaAgua, *_texturaAgua2, *_texturaAlgas, *_texturaAlgas2, *_ladrilloAzul3, *_pistola, *_negro;
    Text *_textoIntro, *_textoIntroCopy, *_textoIntroCopy2;
    sf::Clock * _reloj,  * _reloj2, *_reloj3;
    Cabecera * _cabecera;
    bool * _tieneCopa, *_estaPuerta, *_tienePistola;
    sf::Image * _imgA, *_imgB;

};

#endif /* MAPA_HPP */


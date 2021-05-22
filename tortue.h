#pragma warning(disable : 4996)
#pragma once

#include <SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include <SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include<SFML/System/InputStream.hpp>
#include <cmath>
#include <stack>
#include <queue>
#include "ligne.h"
#include<string>
#include "game.h"
#include <fstream>
using namespace std;



class tortue :public game
{
    float x;
    float y;
    float angle;
    sf::Texture    texture;
    sf::Sprite     sprite;
    vector<class ligne> lignes;
    //("Lancer", ( 80,30 ), 40, ( 128,128,128 ), sf::Color::Black);
    bool pen_down;
public: 
    tortue();
    void render();
    void Avance(float i);
    void Recule(float i);
    void Gauche(float i);
    void Droite(float i);
    void poser_crayon();
    void lever_crayon();
    void Nettoyer();
    float getX() {return x;};
    float getY() { return y; };
    sf::Texture getTexture() {return texture;};
    sf::Sprite getSprite() { return sprite; };
    void dessiner_ligne(ligne l);
    void dessiner_toutes_les_lignes();
    void Exporte_Historique();
    void Importe_Historique();
    //void ajouterInstruct(intruction inst) { instructions.push_back(inst);};
};




static const uint8_t __turtle_png[1479] = {
    0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d,
    0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20,
    0x08, 0x03, 0x00, 0x00, 0x00, 0x44, 0xa4, 0x8a, 0xc6, 0x00, 0x00, 0x00,
    0x03, 0x73, 0x42, 0x49, 0x54, 0x08, 0x08, 0x08, 0xdb, 0xe1, 0x4f, 0xe0,
    0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x00, 0xdd,
    0x00, 0x00, 0x00, 0xdd, 0x01, 0x70, 0x53, 0xa2, 0x07, 0x00, 0x00, 0x00,
    0x19, 0x74, 0x45, 0x58, 0x74, 0x53, 0x6f, 0x66, 0x74, 0x77, 0x61, 0x72,
    0x65, 0x00, 0x77, 0x77, 0x77, 0x2e, 0x69, 0x6e, 0x6b, 0x73, 0x63, 0x61,
    0x70, 0x65, 0x2e, 0x6f, 0x72, 0x67, 0x9b, 0xee, 0x3c, 0x1a, 0x00, 0x00,
    0x02, 0x8b, 0x50, 0x4c, 0x54, 0x45, 0xff, 0xff, 0xff, 0x00, 0x80, 0x80,
    0x00, 0x80, 0x80, 0x40, 0xff, 0x80, 0x4d, 0xe6, 0x66, 0xb3, 0xe6, 0x33,
    0x5d, 0xe8, 0x5d, 0xb9, 0xe8, 0x2e, 0x4e, 0xeb, 0x62, 0xb1, 0xd8, 0x3b,
    0x5b, 0xdb, 0x5b, 0xb6, 0xdb, 0x37, 0xbb, 0xdd, 0x33, 0xb8, 0xe3, 0x39,
    0x00, 0xaa, 0x61, 0x55, 0xe7, 0x61, 0x55, 0xdf, 0x60, 0x00, 0xad, 0x5b,
    0x84, 0xe5, 0x46, 0xbc, 0xda, 0x3c, 0x55, 0xe5, 0x62, 0xb7, 0xde, 0x3b,
    0x00, 0x9f, 0x59, 0xb9, 0xdf, 0x39, 0xb6, 0xdb, 0x37, 0x51, 0xe2, 0x63,
    0x53, 0xe3, 0x5e, 0xb7, 0xde, 0x37, 0x00, 0xa4, 0x57, 0xb7, 0xdd, 0x3a,
    0x55, 0xe3, 0x5e, 0x55, 0xe3, 0x61, 0xba, 0xdf, 0x39, 0x52, 0xe4, 0x5e,
    0x55, 0xe4, 0x61, 0xb9, 0xdc, 0x3a, 0xb8, 0xdd, 0x38, 0xba, 0xde, 0x3a,
    0x53, 0xe2, 0x61, 0xbb, 0xdf, 0x39, 0x55, 0xe3, 0x60, 0x83, 0xe0, 0x4f,
    0x00, 0xab, 0x5e, 0x81, 0xde, 0x4c, 0xb9, 0xde, 0x38, 0x0a, 0xae, 0x5a,
    0x53, 0xe4, 0x5f, 0xba, 0xde, 0x3a, 0x00, 0xaa, 0x5d, 0x54, 0xe4, 0x5f,
    0x55, 0xe2, 0x60, 0xba, 0xdc, 0x38, 0xb8, 0xde, 0x3a, 0xb9, 0xdd, 0x3a,
    0xb8, 0xdd, 0x39, 0x00, 0xa0, 0x59, 0x7d, 0xe0, 0x50, 0x02, 0xa2, 0x59,
    0x53, 0xe3, 0x60, 0xb8, 0xdd, 0x39, 0x54, 0xe3, 0x60, 0xb9, 0xde, 0x3a,
    0x15, 0x9a, 0x4a, 0x00, 0x9f, 0x57, 0x53, 0xe3, 0x61, 0xb9, 0xde, 0x39,
    0x00, 0xab, 0x5e, 0x54, 0xe2, 0x60, 0x79, 0xe1, 0x52, 0x54, 0xe3, 0x60,
    0xb9, 0xdd, 0x3a, 0x00, 0xab, 0x5f, 0xb9, 0xdd, 0x39, 0x55, 0xe3, 0x60,
    0x54, 0xe3, 0x60, 0xba, 0xdd, 0x39, 0x77, 0xe0, 0x52, 0xb9, 0xdd, 0x39,
    0xb9, 0xde, 0x39, 0x54, 0xe3, 0x5f, 0x00, 0xab, 0x5f, 0xba, 0xde, 0x39,
    0xb9, 0xdd, 0x39, 0x55, 0xe3, 0x60, 0x54, 0xe3, 0x60, 0xba, 0xdd, 0x39,
    0x04, 0x8a, 0x46, 0x31, 0xc8, 0x5e, 0x8e, 0xd1, 0x43, 0x55, 0xe3, 0x60,
    0xb9, 0xdd, 0x38, 0x55, 0xe3, 0x5f, 0xb9, 0xdd, 0x39, 0xb9, 0xdc, 0x39,
    0x54, 0xe3, 0x60, 0x00, 0x9e, 0x57, 0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39,
    0x54, 0xe3, 0x5f, 0xb9, 0xdd, 0x39, 0x53, 0xe3, 0x60, 0xb9, 0xdd, 0x39,
    0x00, 0xab, 0x5e, 0x00, 0x9d, 0x56, 0x00, 0xa2, 0x57, 0x54, 0xe3, 0x60,
    0x00, 0x96, 0x50, 0x3c, 0xbb, 0x52, 0xb9, 0xdd, 0x39, 0x00, 0x9d, 0x56,
    0x2c, 0xb7, 0x55, 0x54, 0xe3, 0x60, 0x69, 0xe2, 0x59, 0x54, 0xe3, 0x60,
    0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39, 0xb9, 0xdd, 0x39, 0x0a, 0xa6, 0x58,
    0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39, 0x00, 0x9b, 0x55, 0x54, 0xe3, 0x5f,
    0xb9, 0xdd, 0x39, 0xb9, 0xdd, 0x39, 0x00, 0x83, 0x44, 0x00, 0x8e, 0x4c,
    0x0f, 0xa5, 0x55, 0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39, 0x00, 0x82, 0x41,
    0x03, 0x98, 0x50, 0x08, 0xa3, 0x56, 0x0d, 0x98, 0x4b, 0x4a, 0xb2, 0x46,
    0x54, 0xe3, 0x60, 0xb9, 0xdd, 0x39, 0x00, 0x75, 0x39, 0x00, 0x76, 0x39,
    0x00, 0x76, 0x3a, 0x00, 0x77, 0x3a, 0x00, 0x78, 0x3b, 0x00, 0x79, 0x3c,
    0x00, 0x7b, 0x3e, 0x00, 0x7c, 0x3e, 0x00, 0x7d, 0x3f, 0x00, 0x7e, 0x3f,
    0x00, 0x7f, 0x40, 0x00, 0x80, 0x41, 0x00, 0x81, 0x41, 0x00, 0x81, 0x42,
    0x00, 0x82, 0x42, 0x00, 0x82, 0x43, 0x00, 0x83, 0x43, 0x00, 0x85, 0x44,
    0x00, 0x85, 0x45, 0x00, 0x87, 0x45, 0x00, 0x87, 0x46, 0x00, 0x88, 0x46,
    0x00, 0x88, 0x47, 0x00, 0x89, 0x47, 0x00, 0x8d, 0x4b, 0x00, 0x8e, 0x4a,
    0x00, 0x8e, 0x4b, 0x00, 0x8f, 0x4b, 0x00, 0x90, 0x4b, 0x00, 0x90, 0x4c,
    0x00, 0x91, 0x4c, 0x00, 0x94, 0x4e, 0x00, 0x95, 0x4f, 0x00, 0x96, 0x50,
    0x00, 0x96, 0x52, 0x00, 0x97, 0x52, 0x00, 0x99, 0x52, 0x00, 0x99, 0x54,
    0x00, 0x9a, 0x53, 0x00, 0x9a, 0x54, 0x00, 0x9c, 0x54, 0x00, 0x9d, 0x55,
    0x00, 0xa2, 0x58, 0x00, 0xa9, 0x5d, 0x00, 0xaa, 0x5d, 0x00, 0xaa, 0x5e,
    0x00, 0xab, 0x5e, 0x01, 0x8f, 0x4c, 0x01, 0x9b, 0x55, 0x01, 0xab, 0x5e,
    0x02, 0x9d, 0x56, 0x03, 0x85, 0x43, 0x06, 0xac, 0x5d, 0x07, 0xa3, 0x57,
    0x09, 0xa5, 0x58, 0x0c, 0xa8, 0x58, 0x12, 0xb0, 0x5a, 0x14, 0xaf, 0x59,
    0x1e, 0xb3, 0x58, 0x2b, 0xb8, 0x54, 0x2d, 0xc4, 0x5c, 0x37, 0xba, 0x53,
    0x3c, 0xbb, 0x52, 0x3f, 0xcc, 0x5b, 0x3f, 0xd3, 0x5e, 0x40, 0xd3, 0x5e,
    0x42, 0xbd, 0x51, 0x4b, 0xdc, 0x5f, 0x50, 0xe0, 0x60, 0x54, 0xe3, 0x60,
    0x56, 0xe3, 0x5f, 0x57, 0xe3, 0x5f, 0x5a, 0xc3, 0x4c, 0x85, 0xc8, 0x3f,
    0x88, 0xd0, 0x43, 0x9c, 0xd2, 0x3c, 0xa0, 0xd6, 0x3e, 0xa1, 0xd7, 0x3e,
    0xaf, 0xda, 0x3b, 0xb5, 0xdc, 0x3a, 0xb9, 0xdd, 0x39, 0x36, 0xf4, 0x4c,
    0x4d, 0x00, 0x00, 0x00, 0x88, 0x74, 0x52, 0x4e, 0x53, 0x00, 0x02, 0x04,
    0x04, 0x0a, 0x0a, 0x0b, 0x0b, 0x0d, 0x0d, 0x0e, 0x0e, 0x0f, 0x12, 0x15,
    0x15, 0x18, 0x1c, 0x1d, 0x22, 0x27, 0x27, 0x28, 0x28, 0x2a, 0x2c, 0x2e,
    0x2e, 0x35, 0x35, 0x36, 0x3f, 0x3f, 0x41, 0x42, 0x42, 0x44, 0x46, 0x47,
    0x47, 0x48, 0x4a, 0x4c, 0x4d, 0x4d, 0x4f, 0x56, 0x5c, 0x5d, 0x5e, 0x60,
    0x60, 0x65, 0x6a, 0x70, 0x81, 0x83, 0x84, 0x90, 0x90, 0x92, 0x92, 0x95,
    0x98, 0x99, 0x99, 0x9e, 0xa0, 0xa2, 0xa4, 0xa4, 0xaa, 0xaa, 0xac, 0xad,
    0xad, 0xaf, 0xaf, 0xb0, 0xb3, 0xba, 0xbf, 0xc1, 0xc7, 0xc9, 0xca, 0xcc,
    0xcf, 0xcf, 0xd0, 0xd0, 0xd3, 0xd3, 0xd6, 0xd8, 0xda, 0xda, 0xda, 0xdb,
    0xdb, 0xdc, 0xdc, 0xe0, 0xe3, 0xe4, 0xe9, 0xea, 0xea, 0xea, 0xec, 0xed,
    0xef, 0xef, 0xf0, 0xf1, 0xf6, 0xf7, 0xf8, 0xf9, 0xf9, 0xfb, 0xfb, 0xfb,
    0xfc, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    0xfe, 0xa7, 0x5c, 0x18, 0x53, 0x00, 0x00, 0x02, 0x1a, 0x49, 0x44, 0x41,
    0x54, 0x38, 0x4f, 0x75, 0xd2, 0xf9, 0x5b, 0x4c, 0x51, 0x18, 0x07, 0xf0,
    0x83, 0x92, 0x7d, 0x27, 0x4a, 0x52, 0x76, 0x22, 0x6b, 0xb6, 0x42, 0x28,
    0xfb, 0xbe, 0x65, 0x5f, 0xb2, 0xef, 0x2d, 0x84, 0xca, 0x56, 0x38, 0xd3,
    0x36, 0x39, 0x97, 0x21, 0xc2, 0xd4, 0x84, 0x19, 0x1c, 0x14, 0x4d, 0x0a,
    0x65, 0xdf, 0x8f, 0x25, 0xe1, 0xfc, 0x39, 0xce, 0x7b, 0xce, 0xdc, 0x99,
    0x3b, 0xcf, 0xd3, 0xfd, 0xfe, 0x30, 0xcf, 0x7d, 0xe6, 0xfb, 0x99, 0x3b,
    0xe7, 0x7d, 0xef, 0x45, 0xc8, 0x98, 0x18, 0xce, 0x19, 0x5b, 0x88, 0x4c,
    0xd3, 0x3b, 0x1d, 0xc0, 0x8f, 0x11, 0xa6, 0x60, 0x19, 0x07, 0xc0, 0x0e,
    0x9b, 0xf5, 0xc1, 0x5c, 0x01, 0x36, 0xcc, 0x04, 0xc4, 0xe8, 0xc0, 0xec,
    0x14, 0xe3, 0x75, 0x30, 0xdb, 0x04, 0x44, 0xe9, 0x60, 0x92, 0x09, 0xe8,
    0x70, 0x82, 0xff, 0xfb, 0xf3, 0xf9, 0x1b, 0xfb, 0xde, 0xad, 0xf9, 0xbe,
    0xc5, 0xf0, 0x83, 0xaf, 0x6a, 0xdd, 0x94, 0x3e, 0xcb, 0x99, 0xd8, 0xb2,
    0x99, 0x3a, 0x70, 0xda, 0x6e, 0x37, 0x84, 0x42, 0xb2, 0x57, 0x07, 0xf8,
    0xb7, 0xfd, 0x17, 0x6c, 0x3d, 0x47, 0x6c, 0x55, 0x3a, 0x28, 0xcf, 0xc3,
    0xb9, 0x5b, 0xe6, 0x87, 0x7b, 0xeb, 0xa0, 0xb8, 0x0b, 0xbc, 0xe9, 0x85,
    0x43, 0x09, 0xd5, 0x5b, 0x1f, 0x7d, 0x62, 0xe7, 0x63, 0x5b, 0xab, 0x3e,
    0x74, 0x87, 0x38, 0xfc, 0x7b, 0x77, 0xb5, 0x12, 0xaa, 0xa7, 0xf4, 0xa5,
    0x98, 0x66, 0x7b, 0x08, 0xf4, 0x6d, 0x93, 0x45, 0xdf, 0x28, 0x7e, 0x0b,
    0xc2, 0xe1, 0xb0, 0x5a, 0x65, 0x4f, 0xe9, 0x3b, 0x21, 0xb6, 0xb5, 0x11,
    0x20, 0x11, 0xa6, 0xff, 0x09, 0x7f, 0x5f, 0x7d, 0x9d, 0x10, 0x82, 0x31,
    0x2e, 0x90, 0x07, 0x7d, 0x0d, 0x1b, 0x49, 0x40, 0x68, 0x08, 0xf4, 0xfc,
    0x03, 0x80, 0x2a, 0xa2, 0x3d, 0x78, 0x78, 0xad, 0x04, 0xe3, 0x72, 0x00,
    0xf5, 0x00, 0xd8, 0x60, 0x34, 0x55, 0x82, 0x37, 0x00, 0x6e, 0x91, 0xbb,
    0x70, 0x06, 0x0d, 0x17, 0x02, 0xa8, 0x93, 0x60, 0x0a, 0x5a, 0x27, 0xc1,
    0x59, 0x97, 0xcb, 0x75, 0x87, 0x5c, 0x7d, 0x02, 0xe0, 0x5e, 0x1e, 0xbe,
    0x78, 0x45, 0x44, 0x82, 0xb5, 0x28, 0xf3, 0xf4, 0x86, 0xf8, 0x71, 0x3d,
    0xcf, 0x10, 0x88, 0x53, 0x8d, 0x79, 0x19, 0x43, 0x2c, 0x3d, 0xc6, 0xce,
    0x58, 0x7f, 0xea, 0x38, 0x1a, 0xd0, 0x1e, 0x46, 0xd9, 0xeb, 0x74, 0x3a,
    0x6f, 0x93, 0x92, 0xa7, 0x00, 0xee, 0xe7, 0xe3, 0x62, 0x4d, 0xd3, 0xb2,
    0xe0, 0xfb, 0x76, 0x91, 0x9e, 0x5d, 0xcd, 0x84, 0x33, 0xdc, 0x80, 0x5b,
    0x50, 0x6a, 0x53, 0x63, 0x6c, 0x46, 0xc6, 0x8c, 0x56, 0x53, 0x5c, 0x7a,
    0x5c, 0x79, 0xb3, 0xd4, 0x82, 0xed, 0x00, 0xa6, 0xfb, 0x81, 0xae, 0xf2,
    0x41, 0x95, 0x1a, 0xf7, 0xd0, 0xd7, 0x0f, 0xa0, 0xa5, 0xa2, 0xaf, 0x20,
    0xb6, 0xb2, 0xb2, 0xa2, 0x22, 0x0b, 0x2e, 0x16, 0xfd, 0x01, 0xff, 0x3e,
    0x2c, 0xa9, 0x16, 0x7a, 0xf9, 0x2c, 0xec, 0x52, 0xac, 0xe9, 0x63, 0xec,
    0xa3, 0xd2, 0xf8, 0x97, 0x0a, 0xef, 0xd3, 0x04, 0xd1, 0xc0, 0x52, 0x23,
    0x7c, 0x7d, 0xf7, 0x34, 0xce, 0x7f, 0x3f, 0xf7, 0xbd, 0x0f, 0x76, 0x4b,
    0xfe, 0x47, 0xc6, 0x0e, 0x75, 0xf1, 0x82, 0xc5, 0xb0, 0xcc, 0x5f, 0x27,
    0x7d, 0x6f, 0x54, 0xcd, 0x5b, 0xd8, 0xe2, 0x2c, 0xbd, 0x0f, 0xca, 0x90,
    0xeb, 0xfe, 0xbb, 0x4f, 0x07, 0x47, 0xbe, 0xca, 0x35, 0xa7, 0xb4, 0xf2,
    0x80, 0x41, 0x5c, 0x65, 0xf9, 0xc8, 0x39, 0x3b, 0xdd, 0xf4, 0xd8, 0xae,
    0xc9, 0x2b, 0x98, 0x4a, 0x3f, 0x0f, 0x98, 0xa0, 0xfa, 0x45, 0x1d, 0xc5,
    0x75, 0xa7, 0x5e, 0xe2, 0xa3, 0xf3, 0x12, 0x05, 0xc6, 0x78, 0x40, 0xf4,
    0xaa, 0xfd, 0x19, 0x1b, 0xe7, 0x0e, 0x44, 0x86, 0x0c, 0x9d, 0xb7, 0xe9,
    0xe8, 0x9e, 0x95, 0xa3, 0xc4, 0xd5, 0x7f, 0xbc, 0x59, 0x87, 0x09, 0x1b,
    0x60, 0xeb, 0xd2, 0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae,
    0x42, 0x60, 0x82
};
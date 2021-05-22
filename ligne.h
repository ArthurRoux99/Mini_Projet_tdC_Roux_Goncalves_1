#pragma once
#include "game.h"
class ligne
{
    float Xi;
    float Yi;
    float Xf;
    float Yf;
    sf::Color couleur;
//vertex
public:
    ligne(float xi, float yi, float xf, float yf, sf::Color Couleur);
    float GetXi() { return Xi; };
    float GetYi() { return Yi; };
    float GetXf() { return Xf; };
    float GetYf() { return Yf; };
    sf::Color Getcouleur() { return couleur; };
 };
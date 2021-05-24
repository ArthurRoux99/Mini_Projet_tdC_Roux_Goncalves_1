#pragma once
#include "game.h"

//cette fonction permet de créer des éléments lignes en partant de deux points nécessaires
//Auteur Arthur ROUX
class ligne
{
    float Xi;
    float Yi;
    float Xf;
    float Yf;
    sf::Color couleur;
//vertex
public:
    ligne(float xi, float yi, float xf, float yf, sf::Color Couleur);//constructeur qui affecte les inputs aux attributs de la classe
    float GetXi() { return Xi; };// retourne Xi
    float GetYi() { return Yi; };// retourne Yi
    float GetXf() { return Xf; };// retourn Xf
    float GetYf() { return Yf; };// retourne Yf
    sf::Color Getcouleur() { return couleur; };// retourne la couleur
 };
//
// Created by LENOVO I7 on 30/3/2023.
//

#ifndef PROYECTO_POO_MACAMILAGUZMAN_ANIMAL_H
#define PROYECTO_POO_MACAMILAGUZMAN_ANIMAL_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::find;

class Animal {
private:
    string nombreAnimal;
    string cualHabitad;
    int horasDormirMax;
    int horasDormirMin;
    int edad;
    bool juego;
    string alimento;
    string salud;
    vector <string> alimentosAnimal;

public:
    Animal();

    string &getNombreAnimal();
    void setNombreAnimal(string &nombreAnimal);
    string &getCualHabitad();
    void setCualHabitad(string &cualHabitad);
    int getEdad();
    void setEdad(int edad);
    bool isJuego();
    void setJuego(bool juego);
    string &getAlimento();
    void setAlimento(string &alimento);
    string &getSalud();
    void setSalud(string &salud);
    int getHorasDormirMax();
    void setHorasDormirMax(int horasDormirMax);
    int getHorasDormirMin();
    void setHorasDormirMin(int horasDormirMin);

    //Acciones
    void comer(vector <string> vectorDeZoo);
    void jugar();
    void dormir();

    void EditAlimento(vector <string> vectorAlimentoZoo);
};


#endif //PROYECTO_POO_MACAMILAGUZMAN_ANIMAL_H

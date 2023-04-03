//
// Created by LENOVO I7 on 30/3/2023.
//

#ifndef PROYECTO_POO_MACAMILAGUZMAN_HABITAD_H
#define PROYECTO_POO_MACAMILAGUZMAN_HABITAD_H

#include <string>
#include <iostream>
#include <vector>
#include "Animal.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;


class Habitad {
private:
    string nombreHabitad;
    vector <Animal*> animales;
public:
    Habitad();

    string getNombreHabitad();
    void setNombreHabitad(string &nombreHabitad);
    void agregarAnimal(Animal*pAnimal);
    void listarAnimales();
};


#endif //PROYECTO_POO_MACAMILAGUZMAN_HABITAD_H

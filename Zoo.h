//
// Created by LENOVO I7 on 30/3/2023.
//

#ifndef PROYECTO_POO_MACAMILAGUZMAN_ZOO_H
#define PROYECTO_POO_MACAMILAGUZMAN_ZOO_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#include "Habitad.h"
#include "Animal.h"
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::find;


class Zoo {
private:
    string nombreZoo;
    vector<Animal*> animales;
    vector<Habitad*> habitads;
    vector<string> habitadsEnString;
    vector<string> habitadsDisponibles = {"Salvatico","Desertico","Polar","Acuatico"};
    vector<string> tipoAlimento = {"Carnivoro","Herbivoro","Omnivoro"};
    vector<string> typeCarnivoro = {"Carne", "Pescado", "Pollo", "Cordero", "Cerdo"};
    vector<string> typeHerbivoro = {"Hojas", "Raices", "Semillas", "Frutos", "Flores", "Nectar"};
    vector<string> typeOnmivoro = { "Pescado", "Cerdo", "Huevos", "Leche", "Aguacate", "Mango"};
    vector<string> accionesDisponibles ={"Jugar","Dormir","Comer"};

public:
    Zoo();
    Zoo(string nombreZoo);

    string &getNombreZoo();

    void agragarGuardarHabitad();
    void GuardarAnimal();
    void listarAnimalesDeHabitads();
    void acciones();
    void EdiatrAimento();
};


#endif //PROYECTO_POO_MACAMILAGUZMAN_ZOO_H

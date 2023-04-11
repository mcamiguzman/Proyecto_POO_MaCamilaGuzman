//
// Created by LENOVO I7 on 30/3/2023.
//

#include "Habitad.h"

Habitad::Habitad(){
    this->nombreHabitad="";
}

string Habitad::getNombreHabitad(){
    return nombreHabitad;
}

void Habitad::setNombreHabitad(string &nombreHabitad) {
    Habitad::nombreHabitad = nombreHabitad;
}

//El animal creado en la clase Zoo se mete al vector de clase habitad
void Habitad::agregarAnimal(Animal *pAninal) {
    this->animales.push_back(pAninal);
    cout << "Se agrego el animal al habitad "<< nombreHabitad<< endl;
}

//Imprime la informacion de todos los animales del vector de la clase habitad
void Habitad::listarAnimales() {
    for(auto & itera : animales){
        cout<<"Animal "<<itera->getNombreAnimal()<<", Del habitad "<<itera->getCualHabitad()<<", Edad: "<<itera->getEdad()
        <<", Debe consumir alimento del grupo "<<itera->getAlimento()<<", Su estado de salud es: "<<itera->getSalud()<<endl;
    }
}
//
// Created by LENOVO I7 on 30/3/2023.
//

#include "Animal.h"

Animal::Animal() {
    this->nombreAnimal="";
    this->cualHabitad="";
    this->edad=0;
    this->horasDormirMax=0;
    this->horasDormirMin=0;
    this->alimento="";
    this->salud="";
    this->juego=false;
}

string &Animal::getNombreAnimal() {
    return nombreAnimal;
}
void Animal::setNombreAnimal(string &nombreAnimal) {
    Animal::nombreAnimal = nombreAnimal;
}

string &Animal::getCualHabitad() {
    return cualHabitad;
}
void Animal::setCualHabitad(string &cualHabitad) {
    Animal::cualHabitad = cualHabitad;
}

int Animal::getEdad() {
    return edad;
}
void Animal::setEdad(int edad) {
    Animal::edad = edad;
}

bool Animal::isJuego(){
    return juego;
}
void Animal::setJuego(bool juego) {
    Animal::juego = juego;
}

string &Animal::getAlimento(){
    return alimento;
}
void Animal::setAlimento(string &alimento) {
    Animal::alimento = alimento;
}

string &Animal::getSalud(){
    return salud;
}
void Animal::setSalud(string &salud) {
    Animal::salud = salud;
}

int Animal::getHorasDormirMax(){
    return horasDormirMax;
}
void Animal::setHorasDormirMax(int horasDormirMax) {
    Animal::horasDormirMax = horasDormirMax;
}

int Animal::getHorasDormirMin(){
    return horasDormirMin;
}
void Animal::setHorasDormirMin(int horasDormirMin) {
    Animal::horasDormirMin = horasDormirMin;
}


//Acciones
void Animal::comer(vector <string> vectorDeZoo){
    string alimentoUsuario="";
    //En el metodo comer de la clase Zoo se especifica el vector del tipo de alimento
    if(alimentosAnimal.size()==0) {
        alimentosAnimal=vectorDeZoo;
    }
    cout<<"Alimetos disponibles"<<endl;
    for(auto & itera : alimentosAnimal) {
        cout << itera << endl;
        cout<< endl;
    }
    cout<<"Introduzca el alimento que desea dar "<<endl;
    cin >> alimentoUsuario;
    auto iterador = find(alimentosAnimal.begin(), alimentosAnimal.end(), alimentoUsuario);
    if(iterador != alimentosAnimal.end()) {
        cout<<" El animal: "<<nombreAnimal<<", Comer: "<<alimentoUsuario<<endl;
    }
    else{
        cout<<"El animal no puede comer"<<endl;
    }
}

void Animal::jugar(){
    if(juego==false){
        cout<<"El animal "<<nombreAnimal<<" a jugar."<<endl;
        this->juego=true;
    }
    else{
        cout<<"El animal ya tuvo su momento de jugar hoy"<<endl;
    }
}

void Animal::dormir(){
    int horasUsuario=0;
    cout<<"Introduzca el numero de horas de dormir "<<endl;
    cin >> horasUsuario;
    if(horasUsuario>=horasDormirMin && horasUsuario<=horasDormirMax){
        cout<<" El animal: "<<nombreAnimal<<", Dormir: "<<horasUsuario<<" horas "<<endl;
    }
    else{
        cout<<"El animal no puede dormir"<<endl;
    }
}

void Animal::EditAlimento(vector <string> vectorAlimentoZoo){
    string alimentoUsuario="";
    //En el metodo comer de la clase Zoo se especifica el vector del tipo de alimento
    if(alimentosAnimal.size()==0) {
        alimentosAnimal=vectorAlimentoZoo;
    }
    cout<<"Alimetos disponibles"<<endl;
    for(auto & itera : alimentosAnimal) {
        cout << itera << endl;
        cout<< "\n";
    }

    // Pedir al usuario que ingrese la cadena de caracteres a buscar y reemplazar
    string oldStr, newStr;
    cout << "Introduzca lo que desea reemplazar: \n";
    cin >> oldStr;
    cout << "Introduzca el reemplazo: \n";
    cin >> newStr;

    // Recorrer el vector y reemplazar la cadena de caracteres correspondiente
    for (auto& str : alimentosAnimal) {
        if (str == oldStr) {
            str = newStr;
            break;
        }else{
            cout<<"Alimento no disponible\n";
            break;
        }
    }

    // Imprimir el vector después del reemplazo
    std::cout << "Vector modificado: ";
    for (const auto& str : alimentosAnimal) {
        std::cout << str << " \n";
    }
}





//
// Created by LENOVO I7 on 30/3/2023.
//

#include "Zoo.h"
Zoo::Zoo(string nombreZoo): nombreZoo(nombreZoo){};


void Zoo::agragarGuardarHabitad() {
    string nombreHabitad="";
    cout << "Introduzca el nombre del habitad" << endl;
    cin >> nombreHabitad;
    auto iterador = find(habitadsDisponibles.begin(), habitadsDisponibles.end(), nombreHabitad);
    if(iterador != habitadsDisponibles.end()){
        habitadsEnString.push_back(nombreHabitad);
        Habitad* pHabitad= new Habitad();
        pHabitad -> setNombreHabitad(nombreHabitad);
        this->habitads.push_back(pHabitad);
        cout << "Se agrego el habitad "<< nombreHabitad << endl;
    }
    else{
        cout<<"Habitad no disponible"<< endl;
    }
}

void Zoo::GuardarAnimal() {
    string habitat = "";
    string nombreAnimal="";
    //int salir; //Si el usuario se desea salir rapido
    int horasMax = -1;
    int horasMin = -1;
    string salud;
    string alimento;
    int edad = -1;

    //Pedir y verificar si es el caso

    cout << "Introduzca el habitad donde desea aniadir el animal \n";
    cin >> habitat;

    cout << "Introduzca el nombre del animal \n";
    cin>>nombreAnimal;


    while (edad < 0 || edad > 40) { // Mientras la edad sea posotiva y menor a 40 (el maximo de edad para mi)
        cout << "Introduzca la edad del animal \n";
        cin >> edad;

        if (cin.fail()) { // Verificar si la entrada es incorrecta
            cin.clear(); // Limpiar el estado del flujo de entrada
            cin.ignore(1000, '\n'); // Ignorar cualquier entrada pendiente

            cout << "Numero Incoherente. Intentelo de nuevo.\n" << endl;
            edad = -1;
        } else if (edad < 0 || edad > 40) { // Verificar si el número está fuera del rango válido
            edad = -1; // Volver a asignar un valor inválido a num
        }
    }

    while (horasMin < 0 ) { // Mientras la edad sea posotiva y menor a 40 (el maximo de edad para mi)
        cout << "Introduzca las horas minimo de suenio del animal \n";
        cin >> horasMin;
        if (cin.fail()) { // Verificar si la entrada es incorrecta
            cin.clear(); // Limpiar el estado del flujo de entrada
            cin.ignore(1000, '\n'); // Ignorar cualquier entrada pendiente
            cout << "Numero Incoherente. Intentelo de nuevo.\n" << endl;
            horasMin = -1; // Volver a asignar un valor inválido a num
        } else if (horasMin < 0) { // Verificar si el número está fuera del rango válido
            horasMin = -1; // Volver a asignar un valor inválido a num
        }
    }

    cout << "Introduzca las horas maximo de suenio del animal "<<endl;
    cin >> horasMax;// Estas no las evalua ya que depende de cada animal

    cout << "Introduzca el estado de salud del animal \n";
    cin >> salud;

    while (find(tipoAlimento.begin(), tipoAlimento.end(), alimento) == tipoAlimento.end()) { // Bucle while mientras entrada no esté en el vector v
        cout << "Introduzca el tipo de alimento del animal \n";
        cin >> alimento;
        if (find(tipoAlimento.begin(), tipoAlimento.end(), alimento) == tipoAlimento.end()) { // Verificar si la entrada no está en el vector v
            cout << "El tipo de alimento no existe. Inténtelo de nuevo.\n" << std::endl;
        }
    }


    for(auto & itera : habitads){
        if(itera->getNombreHabitad()==habitat){


            Animal*pAnimal=new Animal();

            pAnimal->setCualHabitad(habitat);
            pAnimal->setNombreAnimal(nombreAnimal);
            pAnimal->setEdad(edad);
            pAnimal->setAlimento(alimento);
            pAnimal->setHorasDormirMax(horasMax);
            pAnimal->setHorasDormirMin(horasMin);
            pAnimal->setSalud(salud);
            this->animales.push_back(pAnimal);

            itera->agregarAnimal(pAnimal);

        }
        else{
            cout<<"No existe el habitad del animal";
        }
        break;
    }
}


void Zoo::listarAnimalesDeHabitads() {
    for(auto & itera : habitads){
        itera->listarAnimales();
        cout<<"\n";
    }
}

void Zoo::acciones(){
    string accionUsuario = "";
    string nomAnimal ="";

    cout << "Introduzca la accion a realixar \n";
    cin >> accionUsuario;

    while (find(accionesDisponibles.begin(), accionesDisponibles.end(), accionUsuario) == accionesDisponibles.end()) { // Bucle while mientras entrada no esté en el vector v
        cout << "Introduzca la accion a realixar \n";
        cin >> accionUsuario;
        if (find(tipoAlimento.begin(), tipoAlimento.end(), accionUsuario) == accionesDisponibles.end()){
            cout << "La ccion no existe. Inténtelo de nuevo.\n" << std::endl;
        }
    }

    cout << "Introduzca el nombre del animal"<< endl;
    cin >> nomAnimal;

    for (int i = 0; i < animales.size(); i++) {
        if (animales[i]->getNombreAnimal() == nomAnimal) {
            if(accionUsuario==accionesDisponibles[0]){
                animales[i]->jugar();
            }
            if(accionUsuario==accionesDisponibles[1]){
                animales[i]->dormir();
            }
            if(accionUsuario==accionesDisponibles[2]){
                if(animales[i]->getAlimento()=="Herbivoro"){
                    animales[i]->comer(typeHerbivoro);
                }
                if(animales[i]->getAlimento()=="Carnivoro"){
                    animales[i]->comer(typeCarnivoro);
                }
                if(animales[i]->getAlimento()=="Omnivoro"){
                    animales[i]->comer(typeOnmivoro);
                }
            }
            break;         // Salir del bucle cuando se encuentra el valor buscado
        }
        else{
            cout<<"El animal no exite"<<endl;
        }

    }

}

string &Zoo::getNombreZoo(){
    return nombreZoo;
}

void Zoo::EdiatrAimento(){
    string nomAnimal;
    cout << "Introduzca el nombre del animal \n";
    cin >> nomAnimal;

    for (int i = 0; i < animales.size(); i++) {
        if (animales[i]->getNombreAnimal() == nomAnimal) {
            if(nomAnimal==accionesDisponibles[2]){
                if(animales[i]->getCualHabitad()=="Herbivoro"){
                    animales[i]->comer(typeHerbivoro);
                }
                if(animales[i]->getCualHabitad()=="Carnivoro"){
                    animales[i]->comer(typeCarnivoro);
                }
                if(animales[i]->getCualHabitad()=="Omnivoro"){
                    animales[i]->comer(typeOnmivoro);
                }
            }
            break;         // Salir del bucle cuando se encuentra el valor buscado
        }
        else{
            cout<<"El animal no exite"<<endl;
        }

    }

}


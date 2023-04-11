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
string &Zoo::getNombreZoo(){
    return nombreZoo;
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
    //Datos: Nombre, Habitad, Edad, Horas Minmo de dormir(<0), horas maximo de dormir,Estado de salud, Alimento

    cout << "Introduzca el habitad donde desea aniadir el animal \n";
    cin >> habitat;

    cout << "Introduzca el nombre del animal \n";
    cin>>nombreAnimal;

    // Mientras la edad sea posotiva y menor a 40 (el maximo de edad para mi) si no se vuelve a pedir
    while (edad < 0 || edad > 40) {
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

    // Mientras la edad sea posotiva sino se vuelve a pedir
    while (horasMin < 0 ) {
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

    // Estas no las evalua ya que depende de cada animal
    cout << "Introduzca las horas maximo de suenio del animal "<<endl;
    cin >> horasMax;

    cout << "Introduzca el estado de salud del animal \n";
    cin >> salud;

    //El vector tipoAlimento tiene definido los tipos de alimentos Que son las opciones correctas
    while (find(tipoAlimento.begin(), tipoAlimento.end(), alimento) == tipoAlimento.end()) { //Mientras entrada no esté en el vector
        cout << "Introduzca el tipo de alimento del animal \n";
        cin >> alimento;
        if (find(tipoAlimento.begin(), tipoAlimento.end(), alimento) == tipoAlimento.end()) { //Si la entrada no está en el vector
            cout << "El tipo de alimento no existe. Inténtelo de nuevo.\n" << std::endl;
        }
    }

    //Si esta el habitad que introdujo dentro de vector habitat(almacena los habitats creados) se puede crear el animal
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

            //Se guardas en el vector animales (guarda todos los animales
            this->animales.push_back(pAnimal);
            //Se guarda en el vector de la clase habitat (del habitat que pertenece)
            itera->agregarAnimal(pAnimal);

        }
        else{
            cout<<"No existe el habitad del animal";
        }
        break;
    }
}

//Llama al metodo de la clase habitad listarAnimales() que imprime los animales de cada habitad
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

    //Las acciones disponibles esta definidas en el vector accionesDisponibles
    while (find(accionesDisponibles.begin(), accionesDisponibles.end(), accionUsuario) == accionesDisponibles.end()) { // Bucle while mientras entrada no esté en el vector v
        cout << "Introduzca la accion a realixar \n";
        cin >> accionUsuario;
        if (find(tipoAlimento.begin(), tipoAlimento.end(), accionUsuario) == accionesDisponibles.end()){
            cout << "La ccion no existe. Inténtelo de nuevo.\n" << std::endl;
        }
    }

    cout << "Introduzca el nombre del animal"<< endl;
    cin >> nomAnimal;

    //El vector animales continen todos los animales creados
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


void Zoo::EdiatrAimento(){

    string nomAnimal;
    cout << "Introduzca el nombre del animal \n";
    cin >> nomAnimal;

    //Si se encuetra el animal obtiene el vector definido para alimentaciom se la pasa al metodo de la clase Animal
    for (int i = 0; i < animales.size(); i++) {
        if (animales[i]->getNombreAnimal() == nomAnimal) {
            if(animales[i]->getAlimento()=="Herbivoro"){
                    animales[i]->EditAlimento(typeHerbivoro);
            }
            if(animales[i]->getAlimento()=="Carnivoro"){
                    animales[i]->EditAlimento(typeCarnivoro);
            }
            if(animales[i]->getAlimento()=="Omnivoro"){
                    animales[i]->EditAlimento(typeOnmivoro);
            }
        }
        else{
            cout<<"El animal no exite"<<endl;
        }
    }
}


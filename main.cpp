#include <iostream>
#include "Zoo.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;
void mostrarMenu(Zoo* zoo) {
    int opc = 0;
    do
    {
        cout << "\n**** Bienvenidos a  " << zoo->getNombreZoo() << " ****\n";
        cout << "1. Agregar haitad\n";
        cout << "2. Agregar Animal\n";
        cout << "3. Listar Animales\n";
        cout << "4. Hacer acciones\n";
        cout << "5. Editar lista de alimentos \n";
        cout << "0. Salir\n" << endl;

        cin >> opc;

        switch (opc)
        {
            case 1: zoo->agragarGuardarHabitad();
                break;
            case 2: zoo->GuardarAnimal();
                break;
            case 3: zoo->listarAnimalesDeHabitads();
                break;
            case 4: zoo->acciones();
                break;
            case 5: zoo->EdiatrAimento();
                break;
        }
    } while (opc != 0);
}

int main() {
    Zoo*pZoo=new Zoo("Zoologico");
    mostrarMenu(pZoo);
    delete pZoo;
    return 0;
}

#include <iostream>
#include <cstring>
#include <string>
#include "class.h"
#include "implement.cpp"

using namespace std;

int main(){

int escolha;

do{
    cout << "\nMENU PRINCIPAL\n"; 
    cout << "1. Cadastrar Passageiro\n";
    cout << "2. Cadastrar Tripulante\n";
    cout << "3. Cadastrar Voo\n";
    cout << "4. Cadastrar Assento\n";
    cout << "5. Criar Reserva\n";
    cout << "6. Cancelar Reserva\n";
    cout << "7. Consultas\n";
    cout << "8. Programa de Fidelidade\n";
    cout << "9. Sair\n";
    cout << "Escolha uma opção: ";
    cin >> escolha;

    switch (escolha)
    {
            case 1: cadastrarPassageiro(); break;
            case 2: cadastrarTripulacao(); break;
            case 3: cadastrarVoo(); break;
            case 4: cadastrarAssento(); break;
            case 5: criarReserva(); break;
            case 6: /* função de cancelamento */ break;
            case 7: /* função de consulta */ break;
            case 8: /* programa de fidelidade */ break;
            case 9: cout << "Saindo..." << endl; break;
            default: cout << "Opção inválida!" << endl;
    }

}while(escolha != 9);

return 0;


}
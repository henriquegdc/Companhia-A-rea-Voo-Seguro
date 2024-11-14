#include <iostream>
#include <cstring>
#include <string>
#include "class.h"
#include "implement.cpp"

int main(){
    int escolha;

    switch (escolha){
            case 1:
            cadastrarPassageiro();
        break;
            case 2:
            cadastrarTripulacao();
        break;
            case 3:
            cadastrarVoo();
        break;
            case 4:
            cadastrarAssento();
        break;
            case 5:
            criarReserva();
        break;
            case 6:
            cancelarReserva();
        break;
            case 7:
            buscaPassageiro();
        break;
            case 8:
            buscaTripulante();
        break;
            default:

        break;
        
    }

}

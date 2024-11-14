#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Pessoa {
public:
    int codigo;
    string nome;
    string telefone;

    Pessoa(int cod = 0, const string& nome = "Nome:", const string& telefone = "00(00) 00000-0000")
        : codigo(cod), nome(nome), telefone(telefone) {}
};

class Tripulacao : public Pessoa {
public:
    string cargo;

    Tripulacao(int cod = 0, const string& nome = "Nome:", const string& telefone = "00(00) 00000-0000", const string& cargo = "Cargo:")
        : Pessoa(cod, nome, telefone), cargo(cargo) {}
};

class Passageiro : public Pessoa {
public:
    string endereco;
    bool fidelidade;
    int pt_fidelidade;

    Passageiro(int cod = 0, const string& nome = "Nome:", const string& telefone = "00(00) 00000-0000", const string& endereco = "Endereço:")
        : Pessoa(cod, nome, telefone), endereco(endereco), fidelidade(true), pt_fidelidade(0) {}

    void confirmarFidelidade() {
        fidelidade = true;
        cout << "Passageiro fidelizado: " << nome << endl;
    }

};

class Voo {
public:
    int codigo_voo;
    string data;
    string origem;
    string destino;
    int cod_aviao;
    Tripulacao tripulacao;  

    Voo(int codigo_voo = 0, const string& data = "00/00/0000", const string& origem = "XXX", const string& destino = "XXX", int cod_aviao = 0)
        : codigo_voo(codigo_voo), data(data), origem(origem), destino(destino), cod_aviao(cod_aviao) {}
};

class Assento{
public:
    string cadeira;
    bool status;
    Voo voo;
    Passageiro passageiro;

    Assento(const string& cadeira= "X00", bool status = false)
        :cadeira(cadeira), status(false){}

};

class Reserva {
public:
    int codigo_reserva;
    Passageiro passageiro;
    Assento assento;
    Voo voo;
    bool status; 

    Reserva(int codigo_reserva, const Passageiro& passageiro, const Assento& assento, const Voo& voo)
        : codigo_reserva(codigo_reserva), passageiro(passageiro), assento(assento), voo(voo), status(true) {}

    void confirmarReserva() {
        status = true;
        assento.status = true;  
        cout << "Reserva" << codigo_reserva <<" confirmada para o passageiro: " << passageiro.nome << endl;
    }

    void cancelarReserva() {
        status = false;
        assento.status = false;  
        cout << "Reserva " << codigo_reserva <<" cancelada para o passageiro: " << passageiro.nome << endl;
    }
};


#pragma once

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Pessoa {
public:
    int codigo;
    string nome;
    string telefone;

    Pessoa(int cod = 0, const string& nome = "", const string& telefone = "")
        : codigo(cod), nome(nome), telefone(telefone) {}
};

class Tripulacao : public Pessoa {
public:
    string cargo;

    Tripulacao(int cod = 0, const string& nome = "", const string& telefone = "", const string& cargo = "")
        : Pessoa(cod, nome, telefone), cargo(cargo) {}
};

class Passageiro : public Pessoa {
public:
    string endereco;
    bool fidelidade;
    int pt_fidelidade;

    Passageiro(int cod = 0, const string& nome = "", const string& telefone = "", const string& endereco = "")
        : Pessoa(cod, nome, telefone), endereco(endereco), fidelidade(false), pt_fidelidade(0) {}
};

class Voo {
public:
    int codigo_voo;
    string data;
    string origem;
    string destino;
    int cod_aviao;

    Voo(int codigo_voo = 0, const string& data = "", const string& origem = "", const string& destino = "", int cod_aviao = 0)
        : codigo_voo(codigo_voo), data(data), origem(origem), destino(destino), cod_aviao(cod_aviao) {}
};


class Assento {
public:
    string cadeira;
    bool status;

    Assento(const string& cadeira = "", bool status = false)
        : cadeira(cadeira), status(status) {}
};

class Reserva {
private:
    int codigo_reserva;
    Passageiro passageiro;
    Voo& voo;
    Assento& assento;
    bool status;

public:
    Reserva(int codigo_reserva, const Passageiro& passageiro, Voo& voo, Assento& assento)
        : codigo_reserva(codigo_reserva), passageiro(passageiro), voo(voo), assento(assento), status(false) {}
};

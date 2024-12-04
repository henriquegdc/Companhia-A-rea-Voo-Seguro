#include <iostream>
#include <cstdio>
#include <string>
#include "class.h"

using namespace std;

void inicializarSistema() {
    // Arquivos que serão removidos no início
    const char* arquivos[] = {"passageiro.bin", "reserva.bin", "assento.bin"};
    int numArquivos = sizeof(arquivos) / sizeof(arquivos[0]);

    for (int i = 0; i < numArquivos; ++i) {
        if (remove(arquivos[i]) == 0) {
            cout << "Arquivo " << arquivos[i] << " excluído com sucesso.\n";
        } else {
            cout << "Arquivo " << arquivos[i] << " não encontrado ou não pode ser excluído.\n";
        }
    }
}

void cadastrarPassageiro()
{
    FILE *arq_passageiro = fopen("passageiro.bin", "ab");
    if (arq_passageiro == NULL)
    {
        cout << "Erro ao abrir arquivo" << endl;
        return;
    }

    Passageiro passageiro;

    cout << "Digite o código do passageiro: ";
    cin >> passageiro.codigo;
    cin.ignore();

    cout << "Digite o nome do passageiro: ";
    getline(cin, passageiro.nome);

    cout << "Digite o telefone do passageiro: ";
    getline(cin, passageiro.telefone);

    cout << "Digite o endereco do passageiro: ";
    getline(cin, passageiro.endereco);

    char opcaoFidelidade;
    cout << "Deseja fidelizar o passageiro? (s/n): ";
    cin >> opcaoFidelidade;
    passageiro.fidelidade = (opcaoFidelidade == 's' || opcaoFidelidade == 'n');

    struct PassageiroBin
    {
        int codigo;
        char nome[100];
        char telefone[20];
        char endereco[200];
        bool fidelidade;
        int pt_fidelidade;
    };

    PassageiroBin passageiroBin;
    passageiroBin.codigo = passageiro.codigo;
    strncpy(passageiroBin.nome, passageiro.nome.c_str(), sizeof(passageiroBin.nome));
    strncpy(passageiroBin.telefone, passageiro.telefone.c_str(), sizeof(passageiroBin.telefone));
    strncpy(passageiroBin.endereco, passageiro.endereco.c_str(), sizeof(passageiroBin.endereco));
    passageiroBin.fidelidade = passageiro.fidelidade;
    passageiroBin.pt_fidelidade = passageiro.pt_fidelidade;

    if (fwrite(&passageiroBin, sizeof(PassageiroBin), 1, arq_passageiro) != 1)
    {
        cerr << "Erro ao salvar os dados no arquivo!" << endl;
    }
    else
    {
        cout << "Passageiro cadastrado com sucesso!" << endl;
    }

    fclose(arq_passageiro);
}

void cadastrarTripulacao()
{
    FILE *arq_tripulacao = fopen("tripulacao.bin", "ab");
    if (arq_tripulacao == NULL)
    {
        cout << "Erro ao abrir arquivo" << endl;
    }

    Tripulacao tripulacao;

    cout << "Digite o código do tripulante: ";
    cin >> tripulacao.codigo;
    cin.ignore();

    cout << "Digite o nome do tripulante: ";
    getline(cin, tripulacao.nome);

    cout << "Digite o telefone do tripulante: ";
    getline(cin, tripulacao.telefone);

    cout << "\nQual o cargo:" << endl;
    cout << "1 - Piloto" << endl;
    cout << "2 - Copiloto" << endl;
    cout << "3 - Comissário" << endl;
    int opcaoCargo;
    cout << "Digite o número do cargo: ";
    cin >> opcaoCargo;

    while (opcaoCargo < 1 || opcaoCargo > 3)
    {
        switch (opcaoCargo)
        {
        case 1:
            tripulacao.cargo = "Piloto";
            break;
        case 2:
            tripulacao.cargo = "Copiloto";
            break;
        case 3:
            tripulacao.cargo = "Comissário";
            break;
        default:
            cout << "Cargo inválido! " << endl;
            break;
        }
    }

    struct TripulacaoBin
    {
        int codigo;
        char nome[100];
        char telefone[20];
        char cargo[20];
        bool fidelidade;
        int pt_fidelidade;
    };

    TripulacaoBin tripulacaoBin;
    tripulacaoBin.codigo = tripulacao.codigo;
    strncpy(tripulacaoBin.nome, tripulacao.nome.c_str(), sizeof(tripulacaoBin.nome));
    strncpy(tripulacaoBin.telefone, tripulacao.telefone.c_str(), sizeof(tripulacaoBin.telefone));
    strncpy(tripulacaoBin.cargo, tripulacao.cargo.c_str(), sizeof(tripulacaoBin.cargo));

    if (fwrite(&tripulacaoBin, sizeof(TripulacaoBin), 1, arq_tripulacao) != 1)
    {
        cerr << "Erro ao salvar os dados no arquivo!" << endl;
    }
    else
    {
        cout << "Tripulante cadastrado com sucesso!" << endl;
    }

    fclose(arq_tripulacao);
}

void cadastrarVoo()
{
    FILE *arq_voo = fopen("voo.bin", "ab");
    if (arq_voo == NULL)
    {
        cout << "Erro ao abrir arquivo" << endl;
    }

    Voo voo;

    cout << "Digite o código do voo: ";
    cin >> voo.codigo_voo;
    cin.ignore();

    cout << "Qual a data do voo?: ";
    getline(cin, voo.data);

    cout << "Origem: ";
    getline(cin, voo.origem);

    cout << "Destino: ";
    getline(cin, voo.destino);

    cout << "Digite o código do avião: ";
    cin >> voo.cod_aviao;
    cin.ignore();

    struct VooBin
    {
        int codigo_voo;
        char data[10];
        char origem[3];
        char destino[3];
        int cod_aviao;
    };

    VooBin vooBin;
    vooBin.codigo_voo = voo.codigo_voo;
    strncpy(vooBin.data, voo.data.c_str(), sizeof(vooBin.data));
    strncpy(vooBin.origem, voo.origem.c_str(), sizeof(vooBin.origem));
    strncpy(vooBin.destino, voo.destino.c_str(), sizeof(vooBin.destino));
    vooBin.cod_aviao = voo.cod_aviao;

    if (fwrite(&vooBin, sizeof(VooBin), 1, arq_voo) != 1)
    {
        cerr << "Erro ao salvar os dados no arquivo!" << endl;
    }
    else
    {
        cout << "Tripulante cadastrado com sucesso!" << endl;
    }

    fclose(arq_voo);
}

struct AssentoBin {
    char cadeira[4];    
    int codigo_voo;     
    bool status;        
};

void cadastrarAssento() {
    FILE *arq_assento = fopen("assento.bin", "rb+");  
    if (!arq_assento) {
        cerr << "Arquivo de assentos não encontrado. Criando um novo arquivo..." << endl;
        arq_assento = fopen("assento.bin", "wb+");
        if (!arq_assento) {
            cerr << "Erro ao criar o arquivo de assentos." << endl;
            return;
        }
    }

    AssentoBin novoAssento;
    cout << "Digite o código do voo: ";
    cin >> novoAssento.codigo_voo;
    cin.ignore();

    cout << "Digite o número do assento (ex: 1A): ";
    cin.getline(novoAssento.cadeira, sizeof(novoAssento.cadeira));

    AssentoBin assentoExistente;
    bool assentoDuplicado = false;

    while (fread(&assentoExistente, sizeof(AssentoBin), 1, arq_assento) == 1) {
        if (assentoExistente.codigo_voo == novoAssento.codigo_voo &&
            strcmp(assentoExistente.cadeira, novoAssento.cadeira) == 0) {
            assentoDuplicado = true;
            break;
        }
    }

    if (assentoDuplicado) {
        cout << "Erro: Este assento já foi cadastrado para este voo!" << endl;
        fclose(arq_assento);
        return;
    }
    
    novoAssento.status = false;  

    fseek(arq_assento, 0, SEEK_END);  
    if (fwrite(&novoAssento, sizeof(AssentoBin), 1, arq_assento) != 1) {
        cerr << "Erro ao salvar o assento no arquivo." << endl;
    } else {
        cout << "Assento cadastrado com sucesso no voo " << novoAssento.codigo_voo << ", assento " << novoAssento.cadeira << "." << endl;
    }

    fclose(arq_assento);
}

struct ReservasBin{
    int codigo_voo;
    char cadeira[3];
    int codigo_passageiro;

};

void criarReserva() {
    FILE *arq_assento = fopen("assento.bin", "rb+");
    FILE *arq_reserva = fopen("reserva.bin", "ab");
    if (arq_assento == NULL || arq_reserva == NULL) {
        cerr << "Erro ao abrir arquivo(s)." << endl;
        return;
    }

    ReservasBin novaReserva;
    cout << "Digite o código do voo: ";
    cin >> novaReserva.codigo_voo;
    cin.ignore();

    cout << "Digite o numero do assento: ";
    cin.getline(novaReserva.cadeira, sizeof(novaReserva.cadeira));

    cout << "Digite o codigo do passageiro: ";
    cin >> novaReserva.codigo_passageiro;

    AssentoBin assento;
    bool assentoEncontrado = false, assentoLivre = false;
    while (fread(&assento, sizeof(AssentoBin), 1, arq_assento) == 1) {
        if (assento.codigo_voo == novaReserva.codigo_voo &&
            strcmp(assento.cadeira, novaReserva.cadeira) == 0) {
            assentoEncontrado = true;
            if (!assento.status) {
                assentoLivre = true;
                assento.status = true;
                fseek(arq_assento, -sizeof(AssentoBin), SEEK_CUR);
                fwrite(&assento, sizeof(AssentoBin), 1, arq_assento);
            }
            break;
        }
    }

    if (!assentoEncontrado) {
        cout << "Assento nao encontrado no voo." << endl;
    } else if (!assentoLivre) {
        cout << "Assento ja ocupado." << endl;
    } else {
        fwrite(&novaReserva, sizeof(ReservasBin), 1, arq_reserva);
        cout << "Reserva criada com sucesso para o passageiro " << novaReserva.codigo_passageiro << "." << endl;
    }

    fclose(arq_assento);
    fclose(arq_reserva);
}

void cancelarReserva() {
    FILE *arq_reserva = fopen("reserva.bin", "rb");
    FILE *arq_assento = fopen("assento.bin", "rb+");
    if (!arq_reserva || !arq_assento) {
        cerr << "Erro ao abrir os arquivos necessários.\n";
        if (arq_reserva) fclose(arq_reserva);
        if (arq_assento) fclose(arq_assento);
        return;
    }

    int codigo_voo;
    char cadeira[4];
    cout << "Digite o código do voo: ";
    cin >> codigo_voo;
    cin.ignore();
    cout << "Digite o número do assento (ex: 1A): ";
    cin.getline(cadeira, sizeof(cadeira));

    ReservasBin reserva;
    AssentoBin assento;
    bool reservaEncontrada = false;

    // Criar um arquivo temporário para armazenar reservas não canceladas
    FILE *temp_reserva = fopen("temp_reserva.bin", "wb");
    if (!temp_reserva) {
        cerr << "Erro ao criar o arquivo temporário para reservas.\n";
        fclose(arq_reserva);
        fclose(arq_assento);
        return;
    }

    // Procurar a reserva a ser cancelada
    while (fread(&reserva, sizeof(ReservasBin), 1, arq_reserva) == 1) {
        if (reserva.codigo_voo == codigo_voo && strcmp(reserva.cadeira, cadeira) == 0) {
            reservaEncontrada = true;

            // Encontrar e liberar o assento correspondente
            rewind(arq_assento);  // Reinicia a leitura no arquivo de assentos
            while (fread(&assento, sizeof(AssentoBin), 1, arq_assento) == 1) {
                if (assento.codigo_voo == codigo_voo && strcmp(assento.cadeira, cadeira) == 0) {
                    assento.status = false;  // Marca o assento como livre
                    fseek(arq_assento, -sizeof(AssentoBin), SEEK_CUR);  // Volta para sobrescrever
                    fwrite(&assento, sizeof(AssentoBin), 1, arq_assento);
                    cout << "Assento " << cadeira << " no voo " << codigo_voo << " foi liberado.\n";
                    break;
                }
            }
        } else {
            fwrite(&reserva, sizeof(ReservasBin), 1, temp_reserva);  // Copia reservas não canceladas
        }
    }

    fclose(arq_reserva);
    fclose(arq_assento);
    fclose(temp_reserva);

    // Substituir o arquivo de reservas pelo temporário
    remove("reserva.bin");
    rename("temp_reserva.bin", "reserva.bin");

    if (reservaEncontrada) {
        cout << "Reserva cancelada com sucesso.\n";
    } else {
        cout << "Reserva não encontrada.\n";
    }
}

void listarVoosPorPassageiro(){
    FILE *arq_reserva = fopen("reserva.bin", "rb");
    if (!arq_reserva) {
        cerr << "Erro ao abrir arquivo de reservas.\n";
        return;
    }

    int codigo_passageiro;
    cout << "Digite o código do passageiro: ";
    cin >> codigo_passageiro;

    ReservasBin reserva;
    bool encontrado = false;

    cout << "Voos do passageiro " << codigo_passageiro << ":\n";
    while (fread(&reserva, sizeof(ReservasBin), 1, arq_reserva) == 1) {
        if (reserva.codigo_passageiro == codigo_passageiro) {
            cout << "- Voo " << reserva.codigo_voo << ", Assento: " << reserva.cadeira << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "Nenhum voo encontrado para este passageiro.\n";
    }

    fclose(arq_reserva);
}

struct PassageiroBin {
        int codigo;
        char nome[100];
        char telefone[20];
        char endereco[200];
        bool fidelidade;
        int pt_fidelidade;
    };

void buscarPassageiro(){
    FILE *arq_passageiro = fopen("passageiro.bin", "rb");
    if (!arq_passageiro) {
        cerr << "Erro ao abrir arquivo de passageiros.\n";
        return;
    }

    int codigo;
    cout << "Digite o código do passageiro: ";
    cin >> codigo;

    PassageiroBin passageiro;
    bool encontrado = false;

    while (fread(&passageiro, sizeof(PassageiroBin), 1, arq_passageiro) == 1) {
        if (passageiro.codigo == codigo) {
            cout << "Passageiro encontrado:\n";
            cout << "Nome: " << passageiro.nome << "\n";
            cout << "Telefone: " << passageiro.telefone << "\n";
            cout << "Endereço: " << passageiro.endereco << "\n";
            cout << "Fidelidade: " << (passageiro.fidelidade ? "Sim" : "Não") << "\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Passageiro não encontrado.\n";
    }

    fclose(arq_passageiro);
}

void programaFidelidade() {
    FILE *arq_passageiro = fopen("passageiro.bin", "rb+");
    FILE *arq_reserva = fopen("reserva.bin", "rb");
    if (!arq_passageiro || !arq_reserva) {
        cerr << "Erro ao abrir arquivos necessários.\n";
        if (arq_passageiro) fclose(arq_passageiro);
        if (arq_reserva) fclose(arq_reserva);
        return;
    }

    int codigo;
    cout << "Digite o código do passageiro: ";
    cin >> codigo;

    PassageiroBin passageiro; 
    bool encontrado = false;

    // Verifica se o passageiro existe no arquivo
    while (fread(&passageiro, sizeof(PassageiroBin), 1, arq_passageiro) == 1) {
        if (passageiro.codigo == codigo) {
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Passageiro com código " << codigo << " não encontrado.\n";
        fclose(arq_passageiro);
        fclose(arq_reserva);
        return;
    }

    // Conta o número de voos realizados pelo passageiro
    ReservasBin reserva; 
    int voosRealizados = 0;

    while (fread(&reserva, sizeof(ReservasBin), 1, arq_reserva) == 1) {
        if (reserva.codigo_passageiro == codigo) {
            voosRealizados++;
        }
    }

    // Calcula os novos pontos de fidelidade
    int novosPontos = voosRealizados * 10;
    passageiro.pt_fidelidade = novosPontos;

    // Atualiza o arquivo de passageiros
    fseek(arq_passageiro, -sizeof(PassageiroBin), SEEK_CUR);
    fwrite(&passageiro, sizeof(PassageiroBin), 1, arq_passageiro);

    cout << "Pontos de fidelidade atualizados!\n";
    cout << "Voos realizados: " << voosRealizados << "\n";
    cout << "Novos pontos de fidelidade: " << passageiro.pt_fidelidade << "\n";

    fclose(arq_passageiro);
    fclose(arq_reserva);
}


void buscarTripulacao() {
    FILE *arq_tripulacao = fopen("tripulacao.bin", "rb");
    if (!arq_tripulacao) {
        cerr << "Erro ao abrir arquivo de tripulação.\n";
        return;
    }

    int codigo;
    cout << "Digite o código do tripulante: ";
    cin >> codigo;

    struct TripulacaoBin {
        int codigo;
        char nome[100];
        char telefone[20];
        char cargo[20];
    };

    TripulacaoBin tripulacao;
    bool encontrado = false;

    while (fread(&tripulacao, sizeof(TripulacaoBin), 1, arq_tripulacao) == 1) {
        if (tripulacao.codigo == codigo) {
            cout << "Tripulante encontrado:\n";
            cout << "Nome: " << tripulacao.nome << "\n";
            cout << "Telefone: " << tripulacao.telefone << "\n";
            cout << "Cargo: " << tripulacao.cargo << "\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Tripulante não encontrado.\n";
    }

    fclose(arq_tripulacao);
}
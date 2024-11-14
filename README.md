# Companhia-A-rea-Voo-Seguro

Deseja-se cadastrar passageiros, tripulação e voos da companhia aérea. As informações a serem cadastradas são:

PASSAGEIRO: código, nome, endereço, telefone, fidelidade (sim/não), pontos
fidelidade.
TRIPULAÇÃO: código, nome, telefone, cargo (piloto, copiloto, comissário).
VOO: código do voo, data, hora, origem, destino, código do avião, código do piloto,
código do copiloto, código do comissário, status (ativo/inativo), tarifa.
ASSENTO: número do assento, código do voo, status (ocupado/livre).
RESERVA: código do voo, número do assento, código do passageiro.

Devem ser implementadas:
1. Cadastro de Passageiro:
o Deve garantir que não haja dois passageiros com o mesmo código.
o Opcionalmente, pode-se gerar o código automaticamente.
2. Cadastro de Tripulação:
o Cada membro da tripulação deve ter um cargo específico.
o Deve garantir que não haja dois membros da tripulação com o mesmo código.
o Opcionalmente, pode-se gerar o código automaticamente.
3. Cadastro de Voo:
o Deve ser possível cadastrar informações sobre data, hora, origem, destino, tarifa,
tripulação e o avião.
o Deve verificar a presença de ao menos um piloto e um copiloto para que o voo
seja marcado como ativo.
4. Cadastro de Assento:
o Deve ser possível cadastrar os assentos de cada voo.
5. Reserva:
o Deve garantir que o assento esteja disponível antes de reservar.
o Reservas duplicadas para o mesmo assento no mesmo voo devem ser evitadas.
6. Baixa em Reserva:
o Deve liberar o assento e atualizar o status para livre.
o Calcular o valor total a ser pago, se necessário, de acordo com a tarifa do voo.
7. Pesquisa:
o Deve ser possível buscar passageiros e membros da tripulação pelo nome ou
código.
o Deve ser possível listar todos os voos de um determinado passageiro.
9. Programa de Fidelidade:
o Cada voo concede 10 pontos de fidelidade ao passageiro.
o Um passageiro pode acumular pontos ao longo de múltiplos voos.

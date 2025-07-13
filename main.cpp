#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "agenda.h"
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<Corretor> corretores;
    for (int i = 0; i < n; ++i) {
        std::string telefone; int avaliador; double lat, lon;
        std::cin >> telefone >> avaliador >> lat >> lon;
        std::string nome;
        std::getline(std::cin >> std::ws, nome);
        corretores.emplace_back(telefone, avaliador, lat, lon, nome);
    }

    std::cin >> n;
    std::vector<Cliente> clientes;
    for (int i = 0; i < n; ++i) {
        std::string telefone;
        std::string nome;
        std::cin >> telefone;
        std::getline(std::cin >> std::ws, nome);
        clientes.emplace_back(telefone, nome);
    }

    std::cin >> n;
    std::vector<Imovel> imoveis;
    for (int i = 0; i < n; ++i) {
        std::string tipo; int propId; double lat, lon, preco;
        std::cin >> tipo >> propId >> lat >> lon >> preco;
        std::string endereco;
        std::getline(std::cin >> std::ws, endereco);
        imoveis.emplace_back(tipo, propId, lat, lon, preco, endereco);
    }

    agendarVisitas(corretores, imoveis);
    return 0;
}

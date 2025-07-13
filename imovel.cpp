#include "imovel.h"

int Imovel::nextId = 1;

Imovel::Imovel(const std::string& tipoStr, int proprietarioId, double lat, double lng, double preco, const std::string& endereco)
    : proprietarioId(proprietarioId), lat(lat), lng(lng), preco(preco), endereco(endereco) {
    if (tipoStr == "Casa") tipo = TipoImovel::Casa;
    else if (tipoStr == "Apartamento") tipo = TipoImovel::Apartamento;
    else tipo = TipoImovel::Terreno;
    id = nextId++;
}

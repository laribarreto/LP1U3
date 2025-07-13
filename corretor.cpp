#include "corretor.h"

int Corretor::nextId = 1;

Corretor::Corretor(const std::string& telefone, bool avaliador, double lat, double lng, const std::string& nome)
    : telefone(telefone), avaliador(avaliador), lat(lat), lng(lng), nome(nome) {
    id = nextId++;
}

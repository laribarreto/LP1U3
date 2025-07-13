#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>

class Corretor {
public:
    static int nextId;
    int id;
    std::string telefone;
    bool avaliador;
    double lat, lng;
    std::string nome;

    Corretor(const std::string& telefone, bool avaliador, double lat, double lng, const std::string& nome);
};

#endif

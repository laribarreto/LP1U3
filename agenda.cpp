#include "agenda.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <map>

constexpr double EARTH_R = 6371.0;

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d) { return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat / 2), 2) + std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) * std::pow(std::sin(dlon / 2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

void agendarVisitas(std::vector<Corretor>& corretores, const std::vector<Imovel>& imoveis) {
    std::vector<Corretor*> avaliadores;
    for (auto& c : corretores)
        if (c.avaliador)
            avaliadores.push_back(&c);

    std::map<int, std::vector<const Imovel*>> agenda;

    for (size_t i = 0; i < imoveis.size(); ++i) {
        agenda[avaliadores[i % avaliadores.size()]->id].push_back(&imoveis[i]);
    }

    for (auto* c : avaliadores) {
        std::cout << "Corretor " << c->id << "\n";

        double cx = c->lat;
        double cy = c->lng;

        int hora = 9;
        int minuto = 0;

        std::vector<const Imovel*>& lista = agenda[c->id];
        std::vector<bool> visitado(lista.size(), false);

        for (size_t i = 0; i < lista.size(); ++i) {
            double menorDist = 1e9;
            int idx = -1;

            for (size_t j = 0; j < lista.size(); ++j) {
                if (!visitado[j]) {
                    double d = haversine(cx, cy, lista[j]->lat, lista[j]->lng);
                    if (d < menorDist) {
                        menorDist = d;
                        idx = j;
                    }
                }
            }

            if (idx != -1) {
                int tempoDesloc = static_cast<int>(std::floor(menorDist * 2));

                minuto += tempoDesloc;
                hora += minuto / 60;
                minuto %= 60;

                std::cout << std::setfill('0') << std::setw(2) << hora << ":" 
                          << std::setw(2) << minuto << " Imóvel " << lista[idx]->id << "\n";

                minuto += 60;
                hora += minuto / 60;
                minuto %= 60;

                cx = lista[idx]->lat;
                cy = lista[idx]->lng;
                visitado[idx] = true;
            }
        }
        std::cout << "\n";
    }
}

//
// Created by USER on 11/06/2026.
//

#include "MetricaEngagement.h"

MetricaEngagement:: MetricaEngagement() {
    mensajes_chat = 0;
    usuarios_unicos_chat=0;
    clips_generados=0;
}

MetricaEngagement:: ~MetricaEngagement() {
}

int MetricaEngagement::get_mensajes_chat() const {
    return mensajes_chat;
}

void MetricaEngagement::set_mensajes_chat(int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngagement::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}

void MetricaEngagement::set_usuarios_unicos_chat(int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngagement::get_clips_generados() const {
    return clips_generados;
}

void MetricaEngagement::set_clips_generados(int clips_generados) {
    this->clips_generados = clips_generados;
}
// ENGAGEMENT,573984,161,Q&A largo,2025-08-07,2025-12-31,1586,571,27
void MetricaEngagement::leer(ifstream &arch) {
    char c;
    Metrica::leer(arch);
    arch>>mensajes_chat>>c>>usuarios_unicos_chat>>c>>clips_generados;
    arch.get();
}

void MetricaEngagement::imprimir(ofstream &arch) const {
    Metrica::imprimir(arch);
    arch<<right<<setw(5)<<mensajes_chat<<setw(5)<<usuarios_unicos_chat<<setw(5)<<clips_generados<<endl;
}

// int MetricaEngagement::obtenerID() {
//
// }
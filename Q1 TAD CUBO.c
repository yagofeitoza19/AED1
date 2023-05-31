#include <stdio.h>

typedef struct {
    double lado;
} Cubo;

void criarCubo(Cubo *c, double l) {
    c->lado = l;
}

double getLado(const Cubo *c) {
    return c->lado;
}

void setLado(Cubo *c, double l) {
    c->lado = l;
}

double getArea(const Cubo *c) {
    double area = 6 * c->lado * c->lado;
    return area;
}

double getVolume(const Cubo *c) {
    double volume = c->lado * c->lado * c->lado;
    return volume;
}

int main() {
    Cubo cubo;
    criarCubo(&cubo, 5.0);
    
    double lado = getLado(&cubo);
    printf("Tamanho do lado do cubo: %.2f\n", lado);
    
    double area = getArea(&cubo);
    printf("Área do cubo: %.2f\n", area);
    
    double volume = getVolume(&cubo);
    printf("Volume do cubo: %.2f\n", volume);
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complexo;

void criarComplexo(Complexo *c, double real, double imag) {
    c->real = real;
    c->imag = imag;
}

Complexo somaComplexos(const Complexo *c1, const Complexo *c2) {
    Complexo resultado;
    resultado.real = c1->real + c2->real;
    resultado.imag = c1->imag + c2->imag;
    return resultado;
}

Complexo subtraiComplexos(const Complexo *c1, const Complexo *c2) {
    Complexo resultado;
    resultado.real = c1->real - c2->real;
    resultado.imag = c1->imag - c2->imag;
    return resultado;
}

Complexo multiplicaComplexos(const Complexo *c1, const Complexo *c2) {
    Complexo resultado;
    resultado.real = c1->real * c2->real - c1->imag * c2->imag;
    resultado.imag = c1->real * c2->imag + c1->imag * c2->real;
    return resultado;
}

Complexo divideComplexos(const Complexo *c1, const Complexo *c2) {
    Complexo resultado;
    double divisor = c2->real * c2->real + c2->imag * c2->imag;
    resultado.real = (c1->real * c2->real + c1->imag * c2->imag) / divisor;
    resultado.imag = (c1->imag * c2->real - c1->real * c2->imag) / divisor;
    return resultado;
}

int main() {
    Complexo z1, z2;
    criarComplexo(&z1, 3.0, 2.0);
    criarComplexo(&z2, 1.5, -4.0);

    Complexo soma = somaComplexos(&z1, &z2);
    printf("Soma: %.2f + %.2fi\n", soma.real, soma.imag);

    Complexo subtracao = subtraiComplexos(&z1, &z2);
    printf("Subtração: %.2f + %.2fi\n", subtracao.real, subtracao.imag);

    Complexo multiplicacao = multiplicaComplexos(&z1, &z2);
    printf("Multiplicação: %.2f + %.2fi\n", multiplicacao.real, multiplicacao.imag);

    Complexo divisao = divideComplexos(&z1, &z2);
    printf("Divisão: %.2f + %.2fi\n", divisao.real, divisao.imag);

    return 0;
}

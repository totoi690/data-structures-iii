#ifndef __GRAFOS_H__
#define __GRAFOS_H__

#include "../headers/registro.h"
#define BRANCO 1
#define CINZA 2
#define PRETO 3

typedef struct Aresta {
    int idPoPsConectado;
    long int velocidade;
    struct Aresta* proxAresta;
} Aresta;

typedef struct Vertice {
    int idConecta;
    char *nomePoPs;
    char *nomePais;
    char *siglaPais;

    int tamanho;
    Aresta* inicioArestas;
    struct Vertice* proxVertice;

    int cor;
} Vertice;

typedef struct {
    int tamanho;
    Vertice* inicioVertices;
} Grafo;

long int converterGbpsParaMpbs (int velocidade, char unidade);

Aresta* alocaAresta ();
void destroiAresta (Aresta* aresta);
void copiaRegistroParaAresta (Registro* r, Aresta* aresta);

Vertice* alocaVertice();
void destroiVertice (Vertice* lista);
void copiaRegistroParaVertice (Registro* r, Vertice* vertice);
void adicionaArestaVertice (Vertice* lista, Aresta* aresta);
void imprimeVertice (Vertice* lista);

Grafo* alocaGrafo ();
void destroiGrafo (Grafo* grafo);
void adicionaVerticeGrafo (Grafo* grafo, Vertice *vertice);
void imprimeGrafo (Grafo* grafo);

Vertice* procuraIdVertice (Grafo* grafo, int id);

int qtdCiclosGrafo (Grafo* g);
int criaGrafoArquivo (Grafo* g, Cabecalho* c, FILE* bin);
void adicionaRegistroGrafo (Grafo* g, Registro* r);

int buscaIdConecta (int id, Registro *r, FILE* bin, int qtdRegs);

int ContaCiclosSimplesGrafo(Grafo* g);
int buscaEmProfundidade(Grafo* g, Vertice* v, Vertice* p, unsigned short* color, Vertice** parent);

#endif
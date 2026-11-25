#ifndef LISTA_H // Se não for declarado, declare agora.
#define LISTA_H // declara que a lista.h foi declarada.

typedef struct Lista Lista; // Declaração da estrutura Lista.

Lista *lista_criar(void); // Função para criar uma lista.
void lista_destruir(Lista *l); // Função para destruir uma lista.

int lista_vazia(const Lista *l); // Função para verificar se a lista está vazia.
int lista_tamanho(const Lista *l); // Função para obter o tamanho da lista.

int lista_inserir_fim(Lista *l, int valor); // Função para inserir um elemento no final da lista.
int lista_eliminar_contando(Lista *l, int passagens, int *valor); // Elimina quem recebe a batata apos as passagens.
int lista_obter_inicio(const Lista *l, int *valor); // Obtem o valor do primeiro elemento.
void lista_imprimir(const Lista *l); // Função para imprimir os elementos da lista.

#endif

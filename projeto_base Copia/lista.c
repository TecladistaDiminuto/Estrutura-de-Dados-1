#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct No {
    int valor;
    struct No *prox;
} No;

struct Lista {
    No *inicio;
    No *fim;
    int tamanho;
};

Lista *lista_criar(void) {
    Lista *l = (Lista *) malloc(sizeof(Lista));
    if (l == NULL) {
        return NULL;
    }
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
    return l;
}

void lista_destruir(Lista *l) {
    if (l == NULL) {
        return;
    }

    No *atual = l->inicio;
    int restantes = l->tamanho;
    while (restantes > 0) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
        restantes--;
    }
    free(l);
}

int lista_vazia(const Lista *l) {
    return l == NULL || l->tamanho == 0;
}

int lista_tamanho(const Lista *l) {
    return l == NULL ? 0 : l->tamanho;
}

int lista_inserir_fim(Lista *l, int valor) {
    if (l == NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;

    if (l->fim == NULL) {
        l->inicio = novo;
        novo->prox = novo;
    } else {
        novo->prox = l->inicio;
        l->fim->prox = novo;
    }
    l->fim = novo;
    l->tamanho++;
    return 1;
}

int lista_eliminar_contando(Lista *l, int passagens, int *valor) {
    if (l == NULL || l->tamanho == 0 || passagens < 1 || valor == NULL) {
        return 0;
    }

    No *anterior = l->fim;
    No *atual = l->inicio;
    int passos = passagens % l->tamanho;
    int i;

    for (i = 0; i < passos; i++) {
        anterior = atual;
        atual = atual->prox;
    }

    *valor = atual->valor;
    if (atual == anterior) {
        l->inicio = NULL;
        l->fim = NULL;
    } else {
        anterior->prox = atual->prox;
        l->inicio = atual->prox;
        l->fim = anterior;
        l->fim->prox = l->inicio;
    }

    free(atual);
    l->tamanho--;
    return 1;
}

int lista_obter_inicio(const Lista *l, int *valor) {
    if (l == NULL || l->inicio == NULL || valor == NULL) {
        return 0;
    }

    *valor = l->inicio->valor;
    return 1;
}

void lista_imprimir(const Lista *l) {
    if (l == NULL || l->inicio == NULL) {
        printf("[ ]\n");
        return;
    }

    No *atual = l->inicio;
    printf("[ ");
    do {
        printf("%d ", atual->valor);
        atual = atual->prox;
    } while (atual != l->inicio);
    printf("]\n");
}

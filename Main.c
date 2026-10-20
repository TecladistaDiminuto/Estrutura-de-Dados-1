#include <stdio.h>
#include "Entidades.h"
#include "Chamado.h"
#include "Fila_Chamados.h"

int main() {
    Fila_Chamados fila;
    inicializar_fila(&fila);

    //1. criar entidades de teste
    Usuario u1 = criar_usuario(1, "Emerson", "Sistemas de Informacao");
    Tecnico t1 = criar_tecnico(101, "Carlos", "Redes / Software");

    //2. Criar e enfileirar chamados
    Chamado c1 = abrir_chamado(1,u1, "Computador não liga no laboratório");
    enfileirar_chamado(&fila, c1);

    //3. Exibir fila pendente
    printf ("--- CHAMADOS PENDENTES ---\n");
    listar_chamados(fila);

    //4.Técnico atende o chamado
    Chamado c_atendimento = desenfileirar_chamado(&fila);
    atender_chamado(&c_atendimento, t1);
    fechar_chamado (&c_atendimento, "fonte trocada com sucesso");

    printf ("--- CHAMADO RESOLVIDO ---\n");
    exibir_chamado(&c_atendimento);

return 0;
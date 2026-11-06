#ifdef _win32
    #include <windows.h>
#endif
#include <stdio.h>
#include "Entidades.h"
#include "Chamado.h"
#include "Fila_Chamados.h"

int main() {

    #ifdef _win32
        SetConsoleOutputCP(65001); // Configura a saída do console para UTF-8 no Windows
    #endif

    Fila_Chamados fila = criar_fila(10); // Inicializa a fila com capacidade para 10 chamados

    //1. criar entidades de teste
    Usuario u1 = criar_usuario(1, "Emerson", "Sistemas de Informacao");
    Tecnico t1 = criar_tecnico(101, "Carlos", "Redes / Software");

    //2. Criar e enfileirar chamados
    Chamado c1 = abrir_chamado(1,u1, "Computador não liga no laboratório");
    enfileirar_chamado(&fila, c1);

    //3. Exibir fila pendente
    printf ("--- CHAMADOS PENDENTES ---\n");
    listar_chamados(fila); //possivelmente aqui há um erro, pois a função listar_chamados não foi definida no código fornecido. Certifique-se de implementar essa função para exibir os chamados na fila.

    //4.Técnico atende o chamado
    Chamado c_atendimento = desenfileirar_chamado(&fila);
    atender_chamado(&c_atendimento, t1);
    fechar_chamado (&c_atendimento, "fonte trocada com sucesso");

    printf ("--- CHAMADO RESOLVIDO ---\n");
    exibir_chamado(&c_atendimento);

    return 0;
}

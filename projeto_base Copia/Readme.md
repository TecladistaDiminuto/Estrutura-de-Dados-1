# ENTENDIMENTO DA PROPOSTA DA ATIVIDADE

A atividade segue a lógica das estruturas de dados. Antes foram vistas as estruturas do tipo fila, pilha e etc. Agora, nesta atividade, foi proposta a estrutura em lista circular, em que, no momento da execução de um código, ao final da lista, retorna para o primeiro.

> 1 until 5 >> 1, 2, 3, 4, 5, 1 ,2 , 3, ...
> Em termos de analogia, é como se fosse um loop, em que ao invés de terminar no último item, volta para o primeiro

**A proposta da atividade é da criação de um jogo chamado "Batatinha quente", em é feito uma contagem dos participantes e definido um número em que a batata segue.**

---

> N = número de jogadores;
> K = número de posição;
> i = não sei o que é isso kkkkkkkk

O jogo começa com 10 jogadores a posição da batata seja 4; então **N recebe 10** e **K recebe 4**  

> N = 10
> K = 4

Todos os jogadores recebem um valor booleano indicando se está "vivo" ou "morto", verdadeiro ou falso, digamos assim. Vence aquele que unicamente estiver "vivo".

## REGRAS

- Tem que ser definido quantidade de jogadores;
- Tem que ser definido o número de posições;
- Tem que declarar cada jogador como verdadeiro;
- A batatinha começa com o primeiro jogador e vai avançando;
- A batatinha que assumir a posição tem que tornar o jogador desta posição falso, avança para o próximo jogador continua o jogo;
- Caso a batatinha assuma a posição de um jogador "morto" então a rodada inicia no próximo jogador
- Vence aquele que estiver "vivo".


# Estrutura-de-Dados-1
Inclui os trabalhos e arquivos referentes à esta disciplina

O objetivo deste trabalho consiste em fazer um sistema de chamados

Algumas anotações importantes sobre o trabalho construído:
1. o trabalho foi construído unicamente, ou seja, sozinho, sem nenhuma ajuda humana na construção do código.
2. o trabalho foi construído sob instrução da Inteligência Artificial GEMINI.

Conceitos universais:
"#include [arquivo]": ele inclui o conteúdo (código) de um arquivo inteiramente. Sua importância se dá na praticidade de não precisar rescrever. O #include é processado pelo pré-processador do C antes da compilação de fato. Ele literalmente pega todo o texto do arquivo especificado e insere exatamente no local daquela linha.

"#ifndef [arquivo]": na tradução "If Not Defined", ou seja, se não estiver definido. Este avaliador analisa se o código que está puxando existe este arquivo. Se falso, se não tiver, então vai "copiar" e "colar" no código precendente.

"#define [arquivo]": na tradução "Define". Este é um comando para executar o código caso a condição do ifndef seja verdadeira, ou seja, se o código não existe no arquivo precendente.

"endif": marca o fim da avaliação condicional. é como se fosse um end if normal que encerra uma condição.

## Conceitos Gerais do Pré-processador C

- `#include <arquivo.h>` ou `#include "arquivo.h"`:
  Funciona como um "copiar e colar" automático do conteúdo do arquivo indicado diretamente na linha onde foi chamado. Evita a reescrita de código e permite a modularização das TADs.

- `#ifndef NOME_DO_GUARDA` ("If Not Defined"):
  Verifica se a etiqueta/macro (ex: `ENTIDADES_H`) já foi registrada na memória do compilador. 
  - Se NÃO foi definida (Verdadeiro): O compilador lê e processa o conteúdo do arquivo.
  - Se JÁ foi definida (Falso): O compilador pula todo o conteúdo até o `#endif`, evitando duplicar as `structs` e funções na compilação.

- `#define NOME_DO_GUARDA`:
  Cria e registra a etiqueta/macro na memória do compilador logo no primeiro acesso ao arquivo, garantindo que leituras futuras acionem a trava de segurança.

- `#endif`:
  Marca o término do bloco condicional iniciado pelo `#ifndef` (equivalente ao `End If` do VBA).

- `typedef struct {} [nome]`:
  Typedef struct é como se fosse a criação de tabela, onde as características e atributos são passadas dentro desta função

- `Const` (constante):
  Indica que um valor passado como parâmetro para a função é de **somente leitura**.
  Funciona como uma trava de segurança que impede a função de alterar ou corromper o texto/dado original.

### Quando utilizar Ponteiros (`*`)?

1. **Modificação Direta:** Para permitir que uma função altere os valores da variável/struct original.
2. **Eficiência de Memória:** Para passar estruturas grandes sem precisar de criar cópias pesadas na memória.
3. **Cadeias de Caracteres (Strings):** Para apontar para o início de textos (`const char*`).
4. **Manipulação de TADs:** Para atualizar diretamente o estado de estruturas dinâmicas ou coleções (como a `FilaChamados*`).



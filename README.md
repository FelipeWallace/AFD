# AUTÔMATO FINITO DETERMINÍSTICO (AFD)
## Introdução

Neste trabalho, foi desenvolvida uma implementação capaz de ler um arquivo de entrada contendo as informações necessárias para definir o autômato. O arquivo de entrada contém as seguintes informações:

* Lista de estados: Os estados que compõem o AFD.
* Alfabeto: O conjunto de símbolos que podem ser utilizados como entrada.
* Transições: As regras que definem a função de transição do autômato.
* Estado inicial: O estado a partir do qual o autômato inicia a leitura das palavras.
* Estados finais: O conjunto de estados que representam o estado de aceitação do autômato.
* Palavras de teste: Um conjunto de palavras a serem testadas pelo autômato.

## Desenvolvimento

A implementação lê o arquivo de entrada e armazena as informações em estruturas de dados adequadas, como listas e mapas. Em seguida, realiza a simulação do autômato para cada palavra de teste, percorrendo as transições e atualizando o estado atual conforme os caracteres da palavra. Ao final, verifica se o estado atual está presente na lista de estados finais, determinando se a palavra é aceita ou não pelo autômato.

### Exemplo do arquivo de entrada de dados:

```plaintext
Lista de estados: q0, q1, q2
Alfabeto: a, b, c
Transições: q0,a,q1;q1,b,q2;q2,c,q0
Estado inicial: q0
Estados finais: q2
Palavras de teste: abc, bca, cab
```

## Resultados de testes realizados

### AFD 1

- Todas as palavras do alfabeto $\Sigma = \{a, b, c\}$ que tenham o sufixo $aca$ ou $bca$.

Exemplo de arquivo de entrada para a AFD 1:

```plaintext
q0,q1,q2
a,b,c
q0,a,q1;q1,b,q2;q2,c,q0
q0
q2
abc,bca,cab
```

![AFD 1](images/1.png)

Saída no terminal para o AFD 1:

![Saída AFD 1](images/Teste1.png)

### AFD 2

- Conjunto das cadeias sobre $\{a,b\}$ que contenham um número par de substrings $ba$.

Exemplo de arquivo de entrada para a AFD 2:

```plaintext
q0,q1,q2
a,b
q0,a,q0;q0,b,q1;q1,a,q0;q1,b,q2;q2,a,q0;q2,b,q1
q0
q2
abaabab,babab,bbaabba
```

![AFD 2](images/2.png)

Saída no terminal para o AFD 2:

![Saída AFD 2](images/Teste3.png)

### AFD 3

- Conjunto das cadeias sobre $\{a,b\}$ que contenham a substring $aabba$.

Exemplo de arquivo de entrada para a AFD 3:

```plaintext
q0,q1,q2,q3,q4
a,b
q0,a,q1;q1,a,q2;q2,b,q3;q3,b,q4;q4,a,q2
q0
q4
aabba,baabba,aabbaa
```

![AFD 3](images/3.png)

Saída no terminal para o AFD 3:

![Saída AFD 3](images/Teste5.png)

### AFD 4

- Conjunto das cadeias sobre $\{a,b\}$ com um número ímpar de $a's$ e um número par de $b's$.

Exemplo de arquivo de entrada para a AFD 4:

```plaintext
q0,q1,q2
a,b
q0,a,q1;q1,a,q0;q0,b,q2;q2,b,q0
q0
q2
abbaaab,bbabbaa,aaabba
```

![AFD 4](images/4.png)

Saída no terminal para o AFD 4:

![Saída AFD 4](images/Teste4.png)

### AFD 5

- Exemplo retirado do PDF do trabalho.

Exemplo de arquivo de entrada para a AFD 5:

```plaintext
q0,q1,q2,q3
0,1
q0,0,q1;q1,0,q2;q2,1,q3;q3,1,q2
q0
q3
001,0001,0011
```

![AFD 5](images/5.png)

Saída no terminal para o AFD 5:

![Saída AFD 5](images/Teste2.png)

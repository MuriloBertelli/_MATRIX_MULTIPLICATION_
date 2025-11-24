### _MATRIX_MULTIPLICATION_
---

Este projeto implementa operações de multiplicação de matrizes em C. O objetivo é praticar lógica de programação, manipulação de arrays bidimensionais, alocação de memória e processamento numérico. O código é simples, direto e focado no aprendizado dos fundamentos da linguagem.

## 📌 Objetivo do projeto
---
- Implementar multiplicação entre duas matrizes.

- Trabalhar com laços aninhados.

- Entender multiplicação de matrizes na prática.

- Reforçar leitura e escrita em C.

- Servir como base para exercícios mais avançados envolvendo álgebra linear.

## 🛠️ Como compilar

O repositório acompanha um Makefile genérico, que compila todos os .c automaticamente e gera executáveis na pasta bin/.
```
make
```

Versão debug:
```
make debug
```
## ▶️ Como executar
---
Liste os executáveis disponíveis:
```
make list

```

Execute o binário desejado:

```
make run NAME=main
```

Ou direto:
```
./bin/main
```

(O nome pode variar conforme o nome do arquivo .c no repositório.)

## 📄 Como funciona a multiplicação
---
O algoritmo segue a regra clássica:
```
Seja:

A = matriz m x n
B = matriz n x p
C = matriz m x p


Então:

C[i][j] = Σ (A[i][k] * B[k][j])
```

O código implementa exatamente essa lógica por meio de três loops aninhados.

## 📚 O que este projeto ensina
---
- Como declarar e trabalhar com matrizes em C.

- Como organizar um algoritmo usando loops internos.

- Como validar tamanhos de matrizes antes da multiplicação.

- Como estruturar entrada/saída via terminal.

- Boas práticas básicas de modularização.

## 🔧 Possíveis melhorias
---
- Validar dimensões antes da multiplicação.

- Tornar o programa interativo (ler dimensões e valores do usuário).

- Adicionar suporte a alocação dinâmica (malloc) para matrizes grandes.

- Criar um módulo separado para operações matriciais.

- Adicionar testes automatizados simples.

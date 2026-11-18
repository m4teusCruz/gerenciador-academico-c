# 🎓 Gerenciador Acadêmico em C (CLI)

Sistema de gerenciamento acadêmico via linha de comando (CLI) desenvolvido em **Linguagem C**, focado em manipulação eficiente de memória, estruturas de dados homogêneas (vetores e matrizes paralelas) e algoritmos clássicos de busca e ordenação.

---

## 🚀 Funcionalidades

* **Cadastro com Validação:** Registro de até 50 alunos (`MAX_ALUNOS`) com matrícula única (bloqueio de duplicidades), nome completo e duas notas semestrais, calculando a média automaticamente.
* **Listagem e Situação Acadêmica:** Exibição completa da turma e classificação automática de status (`APROVADO` para média $\ge 7.0$ ou `REPROVADO`).
* **Consultas e Filtros:**
  * Busca exata por número de matrícula.
  * Pesquisa por prefixo de nome utilizando comparação controlada de strings (`strncmp`).
* **Estatísticas da Turma:** Cálculo de maior média, menor média, média geral da turma e contagem total de aprovados e reprovados.
* **Ordenação e Destaques:**
  * Ordenação crescente de todos os registros por média utilizando o algoritmo **Bubble Sort** sincronizado entre os vetores paralelos.
  * Identificação rápida do aluno com o maior desempenho acadêmico.
* **Tratamento de Buffer e Entradas:** Limpeza do buffer de entrada (`stdin`) e validação de leitura (`scanf`) para evitar loops infinitos com entradas inválidas.

---

## 🛠️ Tecnologias e Conceitos Aplicados

* **Linguagem:** C (Padrão ANSI/C99)
* **Bibliotecas Padrão:** `stdio.h` (Entrada/Saída) e `string.h` (`strcpy`, `strlen`, `strncmp`)
* **Estruturas e Algoritmos:**
  * Vetores paralelos e matrizes bidimensionais de caracteres (`char nomes[50][50]`)
  * Passagem de parâmetros por valor e por referência (ponteiros `*total`)
  * Algoritmo de ordenação **Bubble Sort**
  * Busca linear e busca por prefixo

---

## 📁 Estrutura do Repositório

```text
gerenciador-academico-c/
├── src/
│   └── main.c          # Código-fonte completo da aplicação
└── README.md           # Documentação do projeto
```

---

## ⚙️ Como Compilar e Executar

Certifique-se de ter um compilador C instalado (como **GCC** ou **Clang**).

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/m4teusCruz/gerenciador-academico-c.git
   cd gerenciador-academico-c
   ```

2. **Compile o código-fonte:**
   ```bash
   gcc src/main.c -o gerenciador
   ```

3. **Execute o programa:**
   * **Linux / macOS:**
     ```bash
     ./gerenciador
     ```
   * **Windows:**
     ```cmd
     gerenciador.exe
     ```

---

## 👨‍💻 Autor

* **Mateus Gonçalves da Cruz** — [GitHub](https://github.com/m4teusCruz)

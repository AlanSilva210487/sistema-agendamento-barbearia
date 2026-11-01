# ✂️ Sistema de Agendamento para Barbearia (C++)

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Code::Blocks](https://img.shields.io/badge/Code::Blocks-339933?style=for-the-badge&logo=codeblocks&logoColor=white)
![License MIT](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)

Sistema em C++ desenvolvido via terminal (CLI) para gerenciamento completo de horários e serviços de barbearia. O projeto inclui validação de disponibilidade, ordenação cronológica automática de horários, busca de registros e persistência de dados local.

---

## 🚀 Funcionalidades

- *Cadastrar Agendamento:* Valida conflitos para impedir dois agendamentos no mesmo dia e horário.
- *Listagem Cronológica:* Exibe a agenda organizada por data e hora.
- *Busca por Cliente ou Data:* Filtra agendamentos por trecho do nome ou data específica (AAAA-MM-DD).
- *Cancelar Agendamento:* Remove registros pelo ID.
- *Persistência de Dados:* Gravação e leitura automática em arquivo .csv.

---

## 🛠️ Tecnologias e Conceitos Aplicados

- *Linguagem:* C++
- *Orientação a Objetos:* Modelagem de entidades e encapsulamento em classes.
- *Estruturas de Dados:* Manipulação dinâmica na memória com std::vector.
- *Algoritmos:* Ordenação de dados utilizando std::sort com funções lambda.
- *Entrada/Saída de Arquivos:* Persistência em disco via std::fstream e std::stringstream.

---

## 💻 Como Executar o Projeto

### Pré-requisitos
Compilador C++ (g++, MinGW) ou uma IDE como *Code::Blocks* ou *Visual Studio*.

### Passos para compilar via terminal:
```bash
# 1. Clonar o repositório
git clone [https://github.com/AlanSilva210487/sistema-agendamento-barbearia.git](https://github.com/AlanSilva210487/sistema-agendamento-barbearia.git)

# 2. Entrar no diretório
cd sistema-agendamento-barbearia

# 3. Compilar o código C++
g++ barbearia_agendamento.cpp -o barbearia

# 4. Executar a aplicação
./barbearia

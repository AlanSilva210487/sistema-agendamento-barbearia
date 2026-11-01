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

<img width="973" height="491" alt="bartearia01" src="https://github.com/user-attachments/assets/20ab42c8-7060-41cb-865c-6ab8f3ff661d" />

<img width="966" height="490" alt="barbearia02" src="https://github.com/user-attachments/assets/96d8cd74-fd22-4368-8c00-3c742fb75f03" />

<img width="963" height="498" alt="barbearia03" src="https://github.com/user-attachments/assets/3dd19d60-fb14-40c1-a564-d58767be0ca9" />

<img width="875" height="464" alt="barbearia04" src="https://github.com/user-attachments/assets/bb717323-2bee-4b77-8960-9bab8f97a4b2" />

<img width="964" height="494" alt="barbearia05" src="https://github.com/user-attachments/assets/8eb10c05-10e1-4c34-95a8-076ef2cc3990" />

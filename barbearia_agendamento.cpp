#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

// 1. Estrutura de dados do Agendamento
struct Agendamento {
    int id;
    std::string cliente;
    std::string servico;
    std::string data;    // Formato: AAAA-MM-DD
    std::string horario; // Formato: HH:MM
};

// 2. Classe de gerenciamento e regras de negocio
class GerenciadorBarbearia {
private:
    std::vector<Agendamento> agendamentos;
    const std::string nomeArquivo = "agendamentos.csv";

    // Verifica se o horario ja esta ocupado no mesmo dia
    bool horarioOcupado(const std::string& data, const std::string& horario) const {
        for (const auto& a : agendamentos) {
            if (a.data == data && a.horario == horario) {
                return true;
            }
        }
        return false;
    }

public:
    GerenciadorBarbearia() {
        carregarDoArquivo(); // Restaura os dados salvos ao instanciar a classe
    }

    // Ordena os registros em ordem cronologica (Data -> Horario)
    void ordenarAgendamentos() {
        std::sort(agendamentos.begin(), agendamentos.end(), [](const Agendamento& a, const Agendamento& b) {
            if (a.data == b.data) {
                return a.horario < b.horario;
            }
            return a.data < b.data;
        });
    }

    // Cadastra um agendamento garantindo que nao haja choque de horario
    bool cadastrarAgendamento(const std::string& cliente, const std::string& servico, const std::string& data, const std::string& horario) {
        if (horarioOcupado(data, horario)) {
            std::cout << "\n[ERRO] O horario " << horario << " no dia " << data << " ja esta ocupado!\n";
            return false;
        }

        // Gera o proximo ID com base no maior ID existente
        int novoId = 1;
        for (const auto& a : agendamentos) {
            if (a.id >= novoId) {
                novoId = a.id + 1;
            }
        }

        agendamentos.push_back({novoId, cliente, servico, data, horario});
        ordenarAgendamentos(); // Reordena apos insercao
        std::cout << "\n[SUCESSO] Agendamento registrado com sucesso para " << cliente << "!\n";
        return true;
    }

    // Exibe todos os agendamentos ordenados
    void listarAgendamentos() {
        if (agendamentos.empty()) {
            std::cout << "\nNenhum agendamento cadastrado.\n";
            return;
        }

        ordenarAgendamentos();

        std::cout << "\n=============================================================\n";
        std::cout << "                   AGENDA DA BARBEARIA                       \n";
        std::cout << "=============================================================\n";
        for (const auto& a : agendamentos) {
            std::cout << "Data: " << a.data
                      << " | Horario: " << a.horario
                      << " | ID: " << a.id
                      << " | Cliente: " << a.cliente
                      << " | Servico: " << a.servico << "\n";
        }
        std::cout << "-------------------------------------------------------------\n";
    }

    // Busca agendamentos por nome (busca parcial)
    void buscarPorCliente(const std::string& termo) const {
        bool encontrado = false;
        std::cout << "\n--- RESULTADO DA BUSCA POR CLIENTE: \"" << termo << "\" ---\n";

        for (const auto& a : agendamentos) {
            if (a.cliente.find(termo) != std::string::npos) {
                std::cout << "ID: " << a.id
                          << " | Data: " << a.data
                          << " " << a.horario
                          << " | Cliente: " << a.cliente
                          << " | Servico: " << a.servico << "\n";
                encontrado = true;
            }
        }

        if (!encontrado) {
            std::cout << "Nenhum registro encontrado para este termo.\n";
        }
    }

    // Busca agendamentos por data especifica
    void buscarPorData(const std::string& dataBusca) const {
        bool encontrado = false;
        std::cout << "\n--- AGENDAMENTOS PARA A DATA: " << dataBusca << " ---\n";

        for (const auto& a : agendamentos) {
            if (a.data == dataBusca) {
                std::cout << "ID: " << a.id
                          << " | Horario: " << a.horario
                          << " | Cliente: " << a.cliente
                          << " | Servico: " << a.servico << "\n";
                encontrado = true;
            }
        }

        if (!encontrado) {
            std::cout << "Nenhum agendamento localizado para esta data.\n";
        }
    }

    // Exclui um agendamento com base no ID
    bool cancelarAgendamento(int id) {
        for (auto it = agendamentos.begin(); it != agendamentos.end(); ++it) {
            if (it->id == id) {
                std::cout << "\n[SUCESSO] Agendamento ID " << id
                          << " (" << it->cliente << " - " << it->data << " " << it->horario
                          << ") foi cancelado!\n";
                agendamentos.erase(it);
                return true;
            }
        }

        std::cout << "\n[ERRO] Nenhum agendamento localizado com o ID " << id << ".\n";
        return false;
    }

    // Persiste os dados do vector no arquivo CSV
    void salvarEmArquivo() const {
        std::ofstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            std::cerr << "\n[ERRO] Nao foi possivel abrir o arquivo para salvar os dados.\n";
            return;
        }

        for (const auto& a : agendamentos) {
            arquivo << a.id << ";"
                    << a.cliente << ";"
                    << a.servico << ";"
                    << a.data << ";"
                    << a.horario << "\n";
        }

        arquivo.close();
        std::cout << "\n[INFO] Dados salvos com sucesso em '" << nomeArquivo << "'.\n";
    }

    // Carrega os dados do arquivo CSV para a memoria
    void carregarDoArquivo() {
        std::ifstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            return; // Arquivo ainda nao existe (primeira execucao)
        }

        agendamentos.clear();
        std::string linha;

        while (std::getline(arquivo, linha)) {
            if (linha.empty()) continue;

            std::stringstream ss(linha);
            std::string idStr, cliente, servico, data, horario;

            if (std::getline(ss, idStr, ';') &&
                std::getline(ss, cliente, ';') &&
                std::getline(ss, servico, ';') &&
                std::getline(ss, data, ';') &&
                std::getline(ss, horario, ';')) {

                Agendamento a;
                a.id = std::stoi(idStr);
                a.cliente = cliente;
                a.servico = servico;
                a.data = data;
                a.horario = horario;

                agendamentos.push_back(a);
            }
        }

        arquivo.close();
        ordenarAgendamentos();
    }
};

// 3. Interface de usuario via menu interativo
int main() {
    GerenciadorBarbearia sistema;
    int opcao = 0;

    do {
        std::cout << "\n=====================================\n";
        std::cout << "   SISTEMA DE GESTAO DE BARBEARIA   \n";
        std::cout << "=====================================\n";
        std::cout << "1. Cadastrar Agendamento\n";
        std::cout << "2. Listar Todos os Agendamentos\n";
        std::cout << "3. Buscar Agendamento (Nome ou Data)\n";
        std::cout << "4. Cancelar Agendamento por ID\n";
        std::cout << "5. Salvar e Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpa o buffer de entrada

        if (opcao == 1) {
            std::string cliente, servico, data, horario;

            std::cout << "Nome do Cliente: ";
            std::getline(std::cin, cliente);

            std::cout << "Servico (ex: Corte, Barba, Combo): ";
            std::getline(std::cin, servico);

            std::cout << "Data (AAAA-MM-DD): ";
            std::getline(std::cin, data);

            std::cout << "Horario (HH:MM): ";
            std::getline(std::cin, horario);

            sistema.cadastrarAgendamento(cliente, servico, data, horario);

        } else if (opcao == 2) {
            sistema.listarAgendamentos();

        } else if (opcao == 3) {
            int subOpcao = 0;
            std::cout << "\n1. Buscar por Nome do Cliente\n";
            std::cout << "2. Buscar por Data (AAAA-MM-DD)\n";
            std::cout << "Opcao: ";
            std::cin >> subOpcao;
            std::cin.ignore();

            if (subOpcao == 1) {
                std::string termo;
                std::cout << "Digite o nome (ou parte do nome): ";
                std::getline(std::cin, termo);
                sistema.buscarPorCliente(termo);
            } else if (subOpcao == 2) {
                std::string data;
                std::cout << "Digite a data (AAAA-MM-DD): ";
                std::getline(std::cin, data);
                sistema.buscarPorData(data);
            } else {
                std::cout << "Opcao de busca invalida!\n";
            }

        } else if (opcao == 4) {
            sistema.listarAgendamentos();
            int idCancelamento;
            std::cout << "\nDigite o ID do agendamento a ser cancelado: ";
            std::cin >> idCancelamento;
            std::cin.ignore();

            sistema.cancelarAgendamento(idCancelamento);

        } else if (opcao == 5) {
            sistema.salvarEmArquivo();
            std::cout << "Encerrando o sistema...\n";

        } else {
            std::cout << "Opcao invalida! Tente novamente.\n";
        }

    } while (opcao != 5);

    return 0;
}

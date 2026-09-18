#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Parte 1: escreva aqui as classes Astronauta, Voo e Agencia.
// Depois, em cada comando, apague a linha do cout com "TODO" e descomente
// a chamada ao metodo da Agencia.

class Astronauta {
private:
    string cpf;
    string nome;
    int idade;
    bool vivo;
    bool disponivel;
public:
    Astronauta(string c, string n, int i);
    string getCpf() const;
    string getNome() const;
    int getIdade() const;
    bool estaVivo() const;
    bool estaDisponivel() const;
    void embarcar();
    void desembarcar();
    void morrer();
};

Astronauta::Astronauta(string c, string n, int i) {
    cpf = c;
    nome = n;
    idade = i;
    vivo = true;
    disponivel = true;
}

string Astronauta::getCpf() const {
    return cpf;
}

string Astronauta::getNome() const {
    return nome;
}

int Astronauta::getIdade() const {
    return idade;
}

bool Astronauta::estaVivo() const {
    return vivo;
}

bool Astronauta::estaDisponivel() const {
    return disponivel;
}

void Astronauta::embarcar() {
    disponivel = false;
}

void Astronauta::desembarcar() {
    if (vivo) {
        disponivel = true;
    }
}

void Astronauta::morrer() {
    vivo = false;
    disponivel = false;
}

class Voo {
private:
    int codigo;
    string estado;
    vector<string> cpfs;
public:
    Voo(int c);
    int getCodigo() const;
    string getEstado() const;
    int getQuantidadeAstronautas() const;
    string getCpf(int posicao) const;
    bool temAstronauta(string cpf) const;
    void adicionarAstronauta(string cpf);
    bool removerAstronauta(string cpf);
    void lancar();
    void finalizar();
    void explodir();
};

Voo::Voo(int c) {
    codigo = c;
    estado = "planejado";
}

int Voo::getCodigo() const {
    return codigo;
}

string Voo::getEstado() const {
    return estado;
}

int Voo::getQuantidadeAstronautas() const {
    return (int) cpfs.size();
}

string Voo::getCpf(int posicao) const {
    return cpfs[posicao];
}

bool Voo::temAstronauta(string cpf) const {
    for (int i = 0; i < (int) cpfs.size(); i++) {
        if (cpfs[i] == cpf) {
            return true;
        }
    }
    return false;
}

void Voo::adicionarAstronauta(string cpf) {
    cpfs.push_back(cpf);
}

bool Voo::removerAstronauta(string cpf) {
    for (int i = 0; i < (int) cpfs.size(); i++) {
        if (cpfs[i] == cpf) {
            cpfs.erase(cpfs.begin() + i);
            return true;
        }
    }
    return false;
}

void Voo::lancar() {
    estado = "em curso";
}

void Voo::finalizar() {
    estado = "finalizado com sucesso";
}

void Voo::explodir() {
    estado = "finalizado com explosao";
}

class Agencia {
private:
    vector<Astronauta> astronautas;
    vector<Voo> voos;
    int buscarAstronauta(string cpf) const;
    int buscarVoo(int codigo) const;
    int vooEmCursoDo(string cpf) const;
public:
    void cadastrarAstronauta(string cpf, string nome, int idade);
    void cadastrarVoo(int codigo);
    void adicionarAstronauta(string cpf, int codigo);
    void removerAstronauta(string cpf, int codigo);
    void lancarVoo(int codigo);
    void finalizarVoo(int codigo);
    void explodirVoo(int codigo);
    void listarVoos() const;
    void listarMortos() const;
    void listarAstronautas() const;
    void historico(string cpf) const;
    void salvar(string nome) const;
    void carregar(string nome);
    void relatorio() const;
};

int Agencia::buscarAstronauta(string cpf) const {
    for (int i = 0; i < (int) astronautas.size(); i++) {
        if (astronautas[i].getCpf() == cpf) {
            return i;
        }
    }
    return -1;
}

void Agencia::cadastrarAstronauta(string cpf, string nome, int idade) {
    if (buscarAstronauta(cpf) != -1) {
        cout << "ERRO: astronauta com CPF " << cpf << " ja cadastrado" << endl;
        return;
    }
    astronautas.push_back(Astronauta(cpf, nome, idade));
    cout << "OK: astronauta " << cpf << " cadastrado" << endl;
}

int Agencia::buscarVoo(int codigo) const {
    for (int i = 0; i < (int) voos.size(); i++) {
        if (voos[i].getCodigo() == codigo) {
            return i;
        }
    }
    return -1;
}

int Agencia::vooEmCursoDo(string cpf) const {
    for (int i = 0; i < (int) voos.size(); i++) {
        if (voos[i].getEstado() == "em curso" && voos[i].temAstronauta(cpf)) {
            return voos[i].getCodigo();
        }
    }
    return -1;
}

void Agencia::cadastrarVoo(int codigo) {
    if (buscarVoo(codigo) != -1) {
        cout << "ERRO: voo " << codigo << " ja cadastrado" << endl;
        return;
    }
    voos.push_back(Voo(codigo));
    cout << "OK: voo " << codigo << " cadastrado" << endl;
}

void Agencia::adicionarAstronauta(string cpf, int codigo) {
    int a = buscarAstronauta(cpf);
    if (a == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }
    int v = buscarVoo(codigo);
    if (v == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }
    if (voos[v].getEstado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }
    if (!astronautas[a].estaVivo()) {
        cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
        return;
    }
    if (voos[v].temAstronauta(cpf)) {
        cout << "ERRO: astronauta " << cpf << " ja esta no voo " << codigo << endl;
        return;
    }
    voos[v].adicionarAstronauta(cpf);
    cout << "OK: astronauta " << cpf << " adicionado ao voo " << codigo << endl;
}

void Agencia::removerAstronauta(string cpf, int codigo) {
    int a = buscarAstronauta(cpf);
    if (a == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }
    int v = buscarVoo(codigo);
    if (v == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }
    if (voos[v].getEstado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }
    if (!voos[v].removerAstronauta(cpf)) {
        cout << "ERRO: astronauta " << cpf << " nao esta no voo " << codigo << endl;
        return;
    }
    cout << "OK: astronauta " << cpf << " removido do voo " << codigo << endl;
}

void Agencia::lancarVoo(int codigo) {
    int v = buscarVoo(codigo);
    if (v == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }
    if (voos[v].getEstado() != "planejado") {
        cout << "ERRO: voo " << codigo << " nao esta planejado" << endl;
        return;
    }
    if (voos[v].getQuantidadeAstronautas() == 0) {
        cout << "ERRO: voo " << codigo << " nao possui astronautas" << endl;
        return;
    }
    for (int i = 0; i < voos[v].getQuantidadeAstronautas(); i++) {
        string cpf = voos[v].getCpf(i);
        int a = buscarAstronauta(cpf);
        if (!astronautas[a].estaVivo()) {
            cout << "ERRO: astronauta " << cpf << " esta morto" << endl;
            return;
        }
        if (!astronautas[a].estaDisponivel()) {
            cout << "ERRO: astronauta " << cpf << " esta indisponivel" << endl;
            return;
        }
    }
    for (int i = 0; i < voos[v].getQuantidadeAstronautas(); i++) {
        string cpf = voos[v].getCpf(i);
        int a = buscarAstronauta(cpf);
        astronautas[a].embarcar();
    }
    voos[v].lancar();
    cout << "OK: voo " << codigo << " lancado" << endl;
}

void Agencia::finalizarVoo(int codigo) {
    int v = buscarVoo(codigo);
    if (v == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }
    if (voos[v].getEstado() != "em curso") {
        cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
        return;
    }
    for (int i = 0; i < voos[v].getQuantidadeAstronautas(); i++) {
        string cpf = voos[v].getCpf(i);
        int a = buscarAstronauta(cpf);
        astronautas[a].desembarcar();
    }
    voos[v].finalizar();
    cout << "OK: voo " << codigo << " finalizado com sucesso" << endl;
}

void Agencia::explodirVoo(int codigo) {
    int v = buscarVoo(codigo);
    if (v == -1) {
        cout << "ERRO: voo " << codigo << " nao cadastrado" << endl;
        return;
    }
    if (voos[v].getEstado() != "em curso") {
        cout << "ERRO: voo " << codigo << " nao esta em curso" << endl;
        return;
    }
    for (int i = 0; i < voos[v].getQuantidadeAstronautas(); i++) {
        string cpf = voos[v].getCpf(i);
        int a = buscarAstronauta(cpf);
        astronautas[a].morrer();
    }
    voos[v].explodir();
    cout << "OK: voo " << codigo << " explodiu" << endl;
}

void Agencia::listarVoos() const {
    string estados[4] = {"planejado", "em curso",
                         "finalizado com sucesso", "finalizado com explosao"};
    cout << "LISTA DE VOOS" << endl;
    for (int e = 0; e < 4; e++) {
        cout << "== " << estados[e] << " ==" << endl;
        bool achou = false;
        for (int i = 0; i < (int) voos.size(); i++) {
            if (voos[i].getEstado() == estados[e]) {
                achou = true;
                cout << "Voo " << voos[i].getCodigo() << ": ";
                if (voos[i].getQuantidadeAstronautas() == 0) {
                    cout << "sem astronautas" << endl;
                } else {
                    for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {
                        if (j > 0) {
                            cout << ", ";
                        }
                        string cpf = voos[i].getCpf(j);
                        int pos = buscarAstronauta(cpf);
                        cout << cpf << " " << astronautas[pos].getNome();
                    }
                    cout << endl;
                }
            }
        }
        if (!achou) {
            cout << "(nenhum)" << endl;
        }
    }
}

void Agencia::listarMortos() const {
    cout << "ASTRONAUTAS MORTOS" << endl;
    bool achou = false;
    for (int i = 0; i < (int) astronautas.size(); i++) {
        if (!astronautas[i].estaVivo()) {
            achou = true;
            cout << astronautas[i].getCpf() << " " << astronautas[i].getNome() << " - voos:";
            bool temVoo = false;
            for (int j = 0; j < (int) voos.size(); j++) {
                if (voos[j].getEstado() != "planejado" &&
                    voos[j].temAstronauta(astronautas[i].getCpf())) {
                    cout << " " << voos[j].getCodigo();
                    temVoo = true;
                }
            }
            if (!temVoo) {
                cout << " nenhum";
            }
            cout << endl;
        }
    }
    if (!achou) {
        cout << "(nenhum)" << endl;
    }
}

void Agencia::listarAstronautas() const {
    cout << "LISTA DE ASTRONAUTAS" << endl;

    cout << "== disponiveis ==" << endl;
    bool achou = false;
    for (int i = 0; i < (int) astronautas.size(); i++) {
        if (astronautas[i].estaVivo() && vooEmCursoDo(astronautas[i].getCpf()) == -1) {
            achou = true;
            cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                 << " (" << astronautas[i].getIdade() << " anos)" << endl;
        }
    }
    if (!achou) {
        cout << "(nenhum)" << endl;
    }

    cout << "== em voo ==" << endl;
    achou = false;
    for (int i = 0; i < (int) astronautas.size(); i++) {
        if (astronautas[i].estaVivo()) {
            int codigo = vooEmCursoDo(astronautas[i].getCpf());
            if (codigo != -1) {
                achou = true;
                cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                     << " (" << astronautas[i].getIdade() << " anos) - voo "
                     << codigo << endl;
            }
        }
    }
    if (!achou) {
        cout << "(nenhum)" << endl;
    }

    cout << "== mortos ==" << endl;
    achou = false;
    for (int i = 0; i < (int) astronautas.size(); i++) {
        if (!astronautas[i].estaVivo()) {
            achou = true;
            cout << astronautas[i].getCpf() << " " << astronautas[i].getNome()
                 << " (" << astronautas[i].getIdade() << " anos)" << endl;
        }
    }
    if (!achou) {
        cout << "(nenhum)" << endl;
    }
}

void Agencia::historico(string cpf) const {
    int a = buscarAstronauta(cpf);
    if (a == -1) {
        cout << "ERRO: astronauta " << cpf << " nao cadastrado" << endl;
        return;
    }
    cout << "HISTORICO DE " << astronautas[a].getCpf() << " "
         << astronautas[a].getNome() << endl;
    bool achou = false;
    for (int i = 0; i < (int) voos.size(); i++) {
        if (voos[i].getEstado() != "planejado" && voos[i].temAstronauta(cpf)) {
            achou = true;
            cout << "voo " << voos[i].getCodigo() << ": "
                 << voos[i].getEstado() << endl;
        }
    }
    if (!achou) {
        cout << "(nenhum voo)" << endl;
    }
}

void Agencia::salvar(string nome) const {
    ofstream arquivo(nome.c_str());
    if (!arquivo.is_open()) {
        cout << "ERRO: nao foi possivel salvar em " << nome << endl;
        return;
    }
    for (int i = 0; i < (int) astronautas.size(); i++) {
        arquivo << "ASTRONAUTA " << astronautas[i].getCpf() << " "
                << astronautas[i].getIdade() << " " << astronautas[i].estaVivo()
                << " " << astronautas[i].estaDisponivel() << " "
                << astronautas[i].getNome() << "\n";
    }
    for (int i = 0; i < (int) voos.size(); i++) {
        arquivo << "VOO " << voos[i].getCodigo() << " "
                << voos[i].getQuantidadeAstronautas();
        for (int j = 0; j < voos[i].getQuantidadeAstronautas(); j++) {
            arquivo << " " << voos[i].getCpf(j);
        }
        arquivo << " " << voos[i].getEstado() << "\n";
    }
    cout << "OK: dados salvos em " << nome << endl;
}

void Agencia::carregar(string nome) {
    ifstream entrada(nome.c_str());
    if (!entrada.is_open()) {
        cout << "ERRO: nao foi possivel carregar de " << nome << endl;
        return;
    }
    astronautas.clear();
    voos.clear();
    string tipo;
    while (entrada >> tipo) {
        if (tipo == "ASTRONAUTA") {
            string cpf, nomeAstronauta;
            int idade, vivo, disponivel;
            entrada >> cpf >> idade >> vivo >> disponivel;
            getline(entrada >> ws, nomeAstronauta);
            Astronauta a(cpf, nomeAstronauta, idade);
            if (vivo == 0) {
                a.morrer();
            } else if (disponivel == 0) {
                a.embarcar();
            }
            astronautas.push_back(a);
        } else if (tipo == "VOO") {
            int codigo, quantidade;
            entrada >> codigo >> quantidade;
            Voo v(codigo);
            for (int i = 0; i < quantidade; i++) {
                string cpf;
                entrada >> cpf;
                v.adicionarAstronauta(cpf);
            }
            string estado;
            getline(entrada >> ws, estado);
            if (estado == "em curso") {
                v.lancar();
            } else if (estado == "finalizado com sucesso") {
                v.lancar();
                v.finalizar();
            } else if (estado == "finalizado com explosao") {
                v.lancar();
                v.explodir();
            }
            voos.push_back(v);
        }
    }
    cout << "OK: dados carregados de " << nome << endl;
}

void Agencia::relatorio() const {
    int planejados = 0, emCurso = 0, sucesso = 0, explosao = 0;
    for (int i = 0; i < (int) voos.size(); i++) {
        string e = voos[i].getEstado();
        if (e == "planejado") {
            planejados++;
        } else if (e == "em curso") {
            emCurso++;
        } else if (e == "finalizado com sucesso") {
            sucesso++;
        } else if (e == "finalizado com explosao") {
            explosao++;
        }
    }

    int vivos = 0, mortos = 0;
    for (int i = 0; i < (int) astronautas.size(); i++) {
        if (astronautas[i].estaVivo()) {
            vivos++;
        } else {
            mortos++;
        }
    }

    int maisExperiente = -1;
    int maiorExperiencia = 0;
    for (int i = 0; i < (int) astronautas.size(); i++) {
        int experiencia = 0;
        for (int j = 0; j < (int) voos.size(); j++) {
            if (voos[j].getEstado() != "planejado" &&
                voos[j].temAstronauta(astronautas[i].getCpf())) {
                experiencia++;
            }
        }
        if (experiencia > maiorExperiencia) {
            maiorExperiencia = experiencia;
            maisExperiente = i;
        }
    }

    cout << "RELATORIO" << endl;
    cout << "voos planejados: " << planejados << endl;
    cout << "voos em curso: " << emCurso << endl;
    cout << "voos finalizados com sucesso: " << sucesso << endl;
    cout << "voos finalizados com explosao: " << explosao << endl;
    cout << "astronautas cadastrados: " << astronautas.size() << endl;
    cout << "astronautas vivos: " << vivos << endl;
    cout << "astronautas mortos: " << mortos << endl;
    if (maisExperiente == -1) {
        cout << "astronauta mais experiente: (nenhum)" << endl;
    } else {
        cout << "astronauta mais experiente: "
             << astronautas[maisExperiente].getCpf() << " "
             << astronautas[maisExperiente].getNome()
             << " (voos lancados: " << maiorExperiencia << ")" << endl;
    }
    int finalizados = sucesso + explosao;
    if (finalizados == 0) {
        cout << "taxa de sucesso: (nenhum voo finalizado)" << endl;
    } else {
        cout << "taxa de sucesso: " << (sucesso * 100 / finalizados) << "%" << endl;
    }
}

int main() {
    Agencia agencia;
    string comando;

    while (cin >> comando) {   // le uma palavra; para no FIM ou quando a entrada acaba
        if (comando == "FIM") {
            break;
        } else if (comando == "CADASTRAR_ASTRONAUTA") {
            string cpf, nome;
            int idade;
            cin >> cpf >> idade;
            getline(cin >> ws, nome);   // o nome vem por ultimo e pode ter espacos
            agencia.cadastrarAstronauta(cpf, nome, idade);
        } else if (comando == "CADASTRAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.cadastrarVoo(codigo);
        } else if (comando == "ADICIONAR_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.adicionarAstronauta(cpf, codigo);
        } else if (comando == "REMOVER_ASTRONAUTA") {
            string cpf;
            int codigo;
            cin >> cpf >> codigo;
            agencia.removerAstronauta(cpf, codigo);
        } else if (comando == "LANCAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.lancarVoo(codigo);
        } else if (comando == "EXPLODIR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.explodirVoo(codigo);
        } else if (comando == "FINALIZAR_VOO") {
            int codigo;
            cin >> codigo;
            agencia.finalizarVoo(codigo);
        } else if (comando == "LISTAR_VOOS") {
            agencia.listarVoos();
        } else if (comando == "LISTAR_MORTOS") {
            agencia.listarMortos();
        } else if (comando == "LISTAR_ASTRONAUTAS") {
            agencia.listarAstronautas();
        } else if (comando == "HISTORICO") {
            string cpf;
            cin >> cpf;
            agencia.historico(cpf);
        } else if (comando == "SALVAR") {
            string nome;
            cin >> nome;
            agencia.salvar(nome);
        } else if (comando == "CARREGAR") {
            string nome;
            cin >> nome;
            agencia.carregar(nome);
        } else if (comando == "RELATORIO") {
            agencia.relatorio();
        } else if (comando == "MENU") {
            int op;
            do {
                cout << "========== MENU ==========" << endl;
                cout << "1) Cadastrar astronauta" << endl;
                cout << "2) Cadastrar voo" << endl;
                cout << "3) Adicionar astronauta ao voo" << endl;
                cout << "4) Remover astronauta do voo" << endl;
                cout << "5) Lancar voo" << endl;
                cout << "6) Finalizar voo" << endl;
                cout << "7) Explodir voo" << endl;
                cout << "8) Relatorio" << endl;
                cout << "0) Sair" << endl;
                cout << "==========================" << endl;
                cout << "opcao: ";
                if (!(cin >> op)) {
                    break;
                }
                if (op == 1) {
                    cout << "cpf: ";
                    string cpf;
                    cin >> cpf;
                    cout << "idade: ";
                    int idade;
                    cin >> idade;
                    cout << "nome: ";
                    string nome;
                    getline(cin >> ws, nome);
                    agencia.cadastrarAstronauta(cpf, nome, idade);
                } else if (op == 2) {
                    cout << "codigo: ";
                    int codigo;
                    cin >> codigo;
                    agencia.cadastrarVoo(codigo);
                } else if (op == 3) {
                    cout << "cpf: ";
                    string cpf;
                    cin >> cpf;
                    cout << "codigo: ";
                    int codigo;
                    cin >> codigo;
                    agencia.adicionarAstronauta(cpf, codigo);
                } else if (op == 4) {
                    cout << "cpf: ";
                    string cpf;
                    cin >> cpf;
                    cout << "codigo: ";
                    int codigo;
                    cin >> codigo;
                    agencia.removerAstronauta(cpf, codigo);
                } else if (op == 5) {
                    cout << "codigo: ";
                    int codigo;
                    cin >> codigo;
                    agencia.lancarVoo(codigo);
                } else if (op == 6) {
                    cout << "codigo: ";
                    int codigo;
                    cin >> codigo;
                    agencia.finalizarVoo(codigo);
                } else if (op == 7) {
                    cout << "codigo: ";
                    int codigo;
                    cin >> codigo;
                    agencia.explodirVoo(codigo);
                } else if (op == 8) {
                    agencia.relatorio();
                } else if (op != 0) {
                    cout << "opcao invalida" << endl;
                }
            } while (op != 0);
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}

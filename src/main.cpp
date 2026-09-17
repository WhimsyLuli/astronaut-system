#include <iostream>
#include <string>
#include <vector>

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
        } else {
            cout << "ERRO: comando desconhecido " << comando << endl;
        }
    }

    return 0;
}

# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`):
- Modelo usado: BigPickle

## Parte 1: antes de programar

- O que cada classe guarda: 

O sistema guarda 3 classes: astronauta, voo e agencia. um astronauta eh definido por um nome, um cpf, idade, se esta vivo e se esta disponivel. a classe voo guarda o codigo do voo, o estado daquele voo e um vector de cpfs dos astronautas. a classe agencia por fim guarda todos os astronautas, voos, e acessa os cpfs e os codigos de voo.

- O que acontece em `LANCAR_VOO`, em palavras:

A agencia verifica todos os estados necessarios para embarcar o astronauta e modificar o estado. (procura o voo, confere o estado, confere se tem alguém a bordo, para cada CPF procura o astronauta e confere se está vivo e disponível).

- Uma dúvida que eu tinha antes de começar:

não sabia por onde começar porque era muita coisa pra olhar.

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"):

por onde começar
como escrever a classe agencia
como fazer listar voos, listar mortos, remover astronautas. muitas das parte
mesmo sabendo quais eram os metodos eu fiquei confusa e sobrecarregada de como escrever o codigo de fato, entao acabei pedindo ajuda mesmo assim.


- O que aprendi:

aprendi a criar classes e aprendi que uma classe pode ter "poder" sobre outras classes, pode ter acesso direto a alguns atributos e usa-los pra criar um novo metodo. por exemplo nesse caso a classe agencia tem "poder" sobre as classes astronauta e voo, a partir do momento que usa os cpfs dos astronautas, codigos de voos, e etc. percebi que isso eh muito util ao se criar um sistema e pode ser usado em diversos cenarios diferentes, como por exemplo: um banco, os clientes, e os saques. ou ainda, uma escola, os alunos e os boletins. de toda forma, ve-se que saber como funcionam classes, objetos e seus metodos eh super importante para a criacao de qualquer sistema e saber disso eh o basico.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:

const nos métodos que só leem
Constantes para os estados, em vez de repetir as strings
Separar em include/ e src/

- A que escolhi e por quê:

const nos metodos que so leem. nao muda a saida e oferece uma camada de protecao ja que eu nao quero
mudar nenhum atributo dentro desses metodos

- O que mudou no código, e se os seis testes continuaram passando:

nao mudou a saida e os seis testes continuaram passando

- O que entendi que não sabia antes:

o uso do const eh util e deve ser reforçado porque protege o funcionamento do codigo de eventuais erros de escrita e tambem isola o que nao precisa ser mexido

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano):

eu ja tinha oferecido contexto ao big pickle então só pedi pra ele começar a executar a missao 1 e ele mostrou um plano corretamente.

- O plano que a IA apresentou, resumido:

O que existe: o sistema da Parte 1, com as classes Astronauta, Voo e Agencia em src/main.cpp. Os seis testes passam.

O que quero: dois comandos novos

LISTAR_ASTRONAUTAS → imprime LISTA DE ASTRONAUTAS e três grupos nesta ordem: == disponiveis ==, == em voo ==, == mortos ==. Na ordem de cadastro em cada grupo. Vazio imprime (nenhum).

HISTORICO cpf → HISTORICO DE 111 Ana Maria e uma linha por voo em que ele participou, voo 10: finalizado com sucesso, na ordem de cadastro dos voos. Sem voos: (nenhum voo). CPF desconhecido: ERRO: astronauta 999 nao cadastrado. "Participou" = voo lançado com ele a bordo (estado ≠ planejado).

Agencia::vooEmCursoDo(cpf) (privado): percorre voos e devolve o código do voo em "em curso" que tem esse CPF, ou -1. É o que decide se o astronauta está "em voo".
listarAstronautas: três laços sobre astronautas, um por grupo, na ordem de cadastro. disponiveis = vivo e vooEmCursoDo == -1; em voo = vivo e com código; mortos = !estaVivo(). Cada grupo imprime (nenhum) se vazio.
historico: buscarAstronauta; se -1, o erro; senão imprime HISTORICO DE cpf nome e percorre voos na ordem de cadastro, mostrando os que têm estado diferente de "planejado" e contêm o CPF. Sem nenhum, (nenhum voo).
main: ramos LISTAR_ASTRONAUTAS e HISTORICO (este lê o CPF).

- Mudei algo no plano antes de liberar? 

nao.

- Resultado de `testar.sh missao1` e de `testar.sh parte1`:

todos passaram.

- Precisei refazer? O que mudou no pedido:

nao precisei refazer.

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem: 

"ok. vamos seguir para a missao 2."

- O plano, resumido:

O que existe: o sistema com as Missões da Parte 1 e a Missão 1 prontos. Todos os testes passam.
queremos criar SALVAR e CARREGAR.
cria-se os metodos salvar e carregar em Agencia. usa-se ofstream e ifstream para escrever e ler os 
arquivos.


- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):

ASTRONAUTA 111 30 1 1 Ana Maria
ASTRONAUTA 222 35 0 0 Bruno Costa
ASTRONAUTA 333 28 1 1 Carla Souza
VOO 10 1 111 finalizado com sucesso
VOO 20 1 222 finalizado com explosao


- Resultado de `testar.sh missao2` e de `testar.sh parte1`:

passou 3/3 e 6/6.


- Precisei refazer? O que mudou no pedido:

nao precisei refazer.

## Missão 3: RELATORIO

- Primeira mensagem: 

"siga para o proximo passo e construa um plano para a missao 3"

- O plano, resumido:

Plano — Missão 3 (RELATORIO)
Arquivo: só src/main.cpp.

Novo método void relatorio() const; na Agencia (público).
Ramo RELATORIO no main (não tem argumento).
Não mexo em Voo/Astronauta: já existem os getters necessários (getEstado, temAstronauta, getCpf, getNome, estaVivo).

- Resultado de `testar.sh missao3` e de `testar.sh parte1`:

missao3 5/5 e parte1 6/6.

- Precisei refazer? O que mudou no pedido:

nao precisei refazer.

## Missão 4: livre

- O que escolhi e por quê: 

escolhi um menu porque achei que seria legal e queria ver como ficaria.

- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):

Menu Interativo
A saída esperada é o menu propriamente dito, que confere.
meus_testes/

- Primeira mensagem:

"para a missão 4, que é livre, como faríamos um menu interativo por cima dos comandos que
já existem?"

- O que veio, comparado com o que eu esperava:

veio o que eu esperava.

- `testar.sh parte1` continuou passando?

sim. 

- Aceitei, ajustei ou descartei? Por quê:

aceitei.

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:

implementou metodos que eu nao sabia muito bem como fazer, fez o trabalho repetitivo de implementar
os metodos que eu ja sabia mas eram muitos, me direcionou no inicio e sempre guardou o meu checkpoint (nao me perdi onde estava mesmo tendo que parar de fazer o trabalho e viver minha vida) fez o menu (que eu ate poderia fazer sozinha mas nunca tinha feito antes).

- Onde ela errou ou fez algo que eu não pedi:

no momento em que ela errou ela se corrigiu e conseguiu dar andamento ao processo, entao eu apenas verifiquei se tudo ainda compilava e se os testes passaram.

- O que eu faria diferente da próxima vez:

acho que num cenario em que eu tivesse mais tempo e nao estivesse pagando 7 materias e 420 horas eu teria tentado fazer esse trabalho com mais parcimonia e aprendido com mais calma os conceitos e programado tudo sozinha. mas eu vou tentar fazer de novo, em outro momento. outro projeto!
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
mesmo sabendo quais eram os metodos eu fiquei confusa e sobrecarregada de como escrever o codigo de fato,
entao acabei pedindo ajuda mesmo assim.


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
- O plano que a IA apresentou, resumido:
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
- O plano, resumido:
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 3: RELATORIO

- Primeira mensagem:
- O plano, resumido:
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 4: livre

- O que escolhi e por quê:
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
- Primeira mensagem:
- O que veio, comparado com o que eu esperava:
- `testar.sh parte1` continuou passando?
- Aceitei, ajustei ou descartei? Por quê:

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
- Onde ela errou ou fez algo que eu não pedi:
- O que eu faria diferente da próxima vez:

# Universidade de Brasília
## Introdução ao Desenvolvimento de Jogos - 2016/01

Aluno

    * Juarez Aires Sampaio Filho    11/0032829  juarez.asf@gmail.com
    *
### Compilar

    1. No diretório raíz(o que contém esse readme), execute:

        mkdir build
        cd build
        cmake ..
        make

    O executável foi gerado e colocado em buil/bin/
### Executar


    1. Para que o jogo execute, você deve colocar o executável no mesmo
    diretório que o conteúdo do diretório resources. Por exemplo:

        build/
            bin/
                audio/
                font/
                img/
                map/
                game01

    2. Agora, mude para o diretório onde está o jogo e execute

        cd build/bin
        ./game01

### Parâmetros

    1. Visualizar a o hitbox.
        Inicie o jogo com:
            
            ./game01 printHitBox
        
        para a hitbox em torno de cada objeto

### Jogando
    
    Pressione:

        - 'a' e 'd' para rotacionar o jogador
        - 'w' e 's' para acelerar o jogador
        - movimente o mouse para mirar com o jogador atirador
        - clique com o botão esquedo do mouse para atirar
        -
    Objetivo:
        - o jogador ganha caso elimine todos os Aliens
        - o jogador perde caso seja elimador pelo Aliens
        -
### Problemas Conhecidos

    * O jogo não possui tela de início, game over ou vitória.
    * Há somente um inimigo na tela.
    * O jogador não colide com os inimigos. A única colisão
    implementada é entre a bala e o Alien e entre a bala e o Penuin.
    * Ainda não há som no jogo
    * O penguin não morre ao sair do cenário.


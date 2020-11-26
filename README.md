#  *PIM 2 - Análise e Desenvolvimento de Sistemas* ![UNIP](.github/logo-UNIP.png)

**Usuários para entrar no sistema:**

*  **Administrador**
    *  *E-mail:* admin@gmail.com  
    *  *Senha:*  12345
* **Unidade 1**
    *  *E-mail:* davi@gmail.com  
    *  *Senha:*  12345
*  **Unidade 2**
    *  *E-mail:* miguel@gmail.com  
    *  *Senha:*  12345
* **Unidade 3**
    *  *E-mail:* gabriel@gmail.com  
    *  *Senha:*  12345
#
## *Fluxograma das telas da aplicação* ![Fluxograma](.github/fluxograma.png)


# *Configurar o vscode para compilar códigos C*
1. Instale o compilador [MinGW](http://www.mingw.org/wiki/Getting_Started)

1.1 clicando aonde a seta aponta 

![Fluxograma](.github/download_mingw.png)


1.2 Selecione "Basic Setup" e marque a caixa de seleção como a imagem abaixo, clique com o botão direito e selecione a opção "Mark for install"

![Fluxograma](.github/marcacao_mingw.png)


1.3 Clique em "installation" -> "Apply changes"

![Fluxograma](.github/apply_changes.png)


1.4 Vá nas variáveis ambiente do seu computador 

![Fluxograma](.github/variaveis_ambiente.png)


1.5 Em "Variáveis do sistema" cliquem em "Path" e em seguida "editar" 

![Fluxograma](.github/editar_path.png)


1.6 Clique em "Novo" e insira o caminho em que foi instalado o MinGW.

![Fluxograma](.github/mingw_path)


2. No Visual studio code, vá na aba de extensões (ctrl + shift + x) e procure por "C/C++ Compile Run" e "C/C++", instale ambas em seu editor.

![Fluxograma](.github/c_compile.png)

![Fluxograma](.github/c.png)


3. Para compilar o código, basta entrar no arquivo Main.c e precionar a tecla "F6".

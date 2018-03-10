1. Por que o Linux recebeu esse nome?  
O nome Linux é uma combinação do nome de seu criador, Linus Torvalds,
com Unix, o sistema operacional com o qual o projeto de Linus
objetivava ser compatível.

2. O que são daemons?  
Daemons são programas que são executados no plano de fundo sem necessidade de
intervenção do usuário.

3. O que é o shell?  
O shell é o programa responsável por interpretar comandos do usuário
e passá-los ao sistema operacional.

4. Por que é importante evitar executar o terminal como super-usuário?  
Deve-se evitar o uso do super-usuário devido aos altos privilégios que este
possui como: leitura, escrita e acesso a todos arquivos e diretórios, os quais
podem contribuir para potencializar as consequências de erros do usuário e
deixam o sistema vulnerável.

5. Qual botão do teclado completa o que o usuário escreve no terminal, de acordo com o contexto?  
A maioria dos *shells* utiliza a tecla 'Tab' para o completar as entradas dos
usuários de acordo com o contexto.

6. Quais botões do teclado apresentam instruções escritas anteriormente?  
Os botões e combinações de botões mais comuns para acessar o histórico de comandos são: as teclas navegação (setas) para cima e para baixo, a combinação 'Ctrl+r' e a 'Ctrl+s'.

7. Apresente os respectivos comandos no terminal para:  
  (a) Obter mais informações sobre um comando.  
  `man comando`  
  (b) Apresentar uma lista com os arquivos dentro de uma pasta.  
  `ls diretorio`  
  (c) Apresentar o caminho completo da pasta.  
  `pwd`  
  (d) Trocar de pasta.  
  `cd diretorio`  
  (e) Criar uma pasta.  
  `mkdir diretorio`  
  (f) Apagar arquivos definitivamente.  
  `rm arquivo`  
  (g) Apagar pastas definitivamente.  
  `rmdir diretorio` (pasta deve estar vazia)  
  (h) Copiar arquivos.  
  `cp arquivo destino`  
  (i) Copiar pastas.  
  `cp -R fonte destino`  
  (j) Mover arquivos.  
  `mv arquivo destino`  
  (k) Mover pastas.  
  `mv -R fonte destino`  
  (l) Renomear pastas.  
  `mv nomevelho nomenovo`  
  (m) Apresentar o conteúdo de um arquivo.  
  `cat arquivo` ou `less arquivo` ou `more arquivo`  
  (n) Apresentar o tipo de um arquivo.  
  `file arquivo`  
  (o) Limpar a tela do terminal.  
  `clear`  
  (p) Encontrar ocorrências de palavras-chave em um arquivo-texto.  
  `grep padrao arquivo`  
  (q) Ordenar informações em um arquivo-texto.  
  `sort arquivo`. Caso queira escrever no próprio arquivo, `sort arquivo > arquivo`  
  (r) Substituir ocorrências de palavras-chave em um arquivo-texto.  
  `sed -e 's\palavra-chave\substituicao\g' arquivo`  
  (s) Conferir se dois arquivos são iguais.  
  `diff arquivo1 arquivo2`  
  (t) Escrever algo na tela.  
  `echo mensagem`

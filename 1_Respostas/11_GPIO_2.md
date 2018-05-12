1. Defina qual modelo de Raspberry Pi você utilizará no projeto desta disciplina com o Raspberry Pi. Justifique sua escolha.  
Será utilizado o modelo 3B, o qual possui maior capacidade de processamento que
o modelo Zero, Zero W ou 2B. A capacidade de processamento maior será necessária
pois o projeto envolve processamento de imagens de 4 MP.

2. Defina qual sistema operacional você utilizará no projeto desta disciplina com o Raspberry Pi. Justifique sua escolha.  
Será utilizado o Raspbian, pois grande parte dos softwares e das bibliotecas
que o projeto precisará estão já empacotadas neste sistema. Outro motivo é que
o Raspbian é construído em grande parte com software livre, evitando problemas
com licenças.

3. Defina de qual forma você instalará o sistema operacional escolhido. Escreva o passo-a-passo da instalação e forneça os links necessários para isto.  
Será utilizado o Raspbian, o qual será instalado através do instalador Lite do
próprio sistema operacional, dispensando o uso de ambiente gráfico pois o
projeto não requer um.

4. Defina de qual forma você desenvolverá software para o Raspberry Pi no projeto desta disciplina. Escreva o passo-a-passo do desenvolvimento e forneça os links necessários para isto.  
O software será desenvolvido através da compilação cruzada do programa principal
em C, ou então a compilação será feita nativamente no próprio Raspberry Pi.
Os demais programas necessários para realizar o reconhecimento ótico de
caracteres e para comunicar com a câmera fotográfica digital não serão
implementados, apenas chamados dentro do próprio código em C.

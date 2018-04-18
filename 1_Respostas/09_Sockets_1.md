1. Com relação ao modelo cliente-servidor, responda:

(a) Quais são as características básicas deste modelo?  
O modelo de comunicação cliente servidor divide tarefas entre os provedores, 
chamados servidores, e os que solicitam o serviço, os clientes. A comunicação 
pode ser feita por meio de redes de computadores ou dentro da própria máquina.

(b) Quais são as características básicas do servidor?  
O servidor aguarda passivamente as requisiçoes dos clientes para respondê-las.

(c) Quais são as características básicas do cliente?  
O cliente faz as requisições ativamente e inicia a comunicação. Um cliente deve 
conhecer o endereço e a porta do servidor com o qual comunicará.

2.  Com relação ao protocolo de comunicação da internet, responda:

(a) O que são protocolos de comunicação?  
Protocolos de comunicação são sistemas com regras que definem como ocorrerá a 
troca de informações entre duas entidades. Os protocolos definem formatos bem 
definidos para a troca de mensagens, incluindo a sintaxe, a sincronização, 
e até o tipo da correção de erros usada.

(b) Quais são as características básicas de protocolos de comunicação?  
Protocolos de comunicação devem especificar os formatos dos dados que serão 
transferidos, os formatos dos endereços das entidades que se comunicarão, como 
estes endereços serão mapeados, como a mensagem será transmitida ao receptor, 
se existirá ou não correção de erros e os detalhes do funcionamento desta, 
se há sinal de aceitação de requisição, se há mensagem será repetida em caso de 
erros irrecuperáveis, a direção do fluxo de informações, se há o controle de 
sequência e como ocorrerá o controle de fluxo.

3. Com relação ao protocolo TCP, responda:

(a) O que são portas no protocolo TCP?  
Tanto o TCP (Transmission Control Protocol) quanto o UDP (User Datagram 
Protocol) usam portas numeradas para enviar e receber informações. Cada lado 
da conexão possui um número de 16 bits sem sinal indicando a porta.

(b) Para que servem estas portas?  
As portas servem para receber e enviar mensagens que chegam através dos 
sockets. Todos os pacotes TCP são identificadas pelo seu socket, composto pelo 
endereço do anfitrião (host), a porta fonte, o endereço de destino e a porta de 
destino.

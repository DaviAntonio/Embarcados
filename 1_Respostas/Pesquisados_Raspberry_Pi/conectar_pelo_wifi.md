# Conectar a Raspberry Pi pela rede Wi-Fi do próprio PC
1. Criar uma rede no PC pelo Network Manager:  
*Na aba Geral:*  
Destaivar a opção de conectar automaticamente quando disponível. essa configuração será ajustada no Pi.  
*Na aba Wi-Fi:*
* SSID: nome escolhido para acessar a rede.
* Modo: Ponto de acesso
* Faixa: Automático
* Canal: padrão
* Dispositivo: o dispositivo de Wi-Fi do computador.
* MTU: automático.
*Na aba Segurança Wi-Fi:*
* Segurança: configurar o tipo desejado, normalmente WPA & WPA2 pessoal.
* Senha: escolher a senha de preferência.
*Na aba Configurações IPv4:*
* Modo: Compartilhado com outros computadores.
*Na aba Configurações IPv6:*
* Modo: Ignorar. Apenas para maior facilidade de conexão.

2. No PC, para se conectar à rede, opção `Conectar à rede Wi-Fi oculta`.

3. No Raspberry a conexão será feita por meio tradicional, utilizando as configurações do `wpa_supplicant`. Caso tenha outras redes de Wi-Fi, utilizar a opção `priority=`. Quanto mais alta, maior a prioridade de conexão caso várias redes estejam presentes.

## Bibliografia
https://www.vivaolinux.com.br/topico/Helps-e-dicas-para-usuarios-iniciantes/TUTORIAL-Hotspot-AP-compativel-com-Android-Compartilhar-Internet-via-Wi-Fi-usando-o-Network-Manager
`man 5 wpa_supplicant.conf`
https://www.daemon-systems.org/man/wpa_supplicant.conf.5.html

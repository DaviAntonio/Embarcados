# Tirar fotos pelo terminal

1. Instalar o pacote `ffmpeg`, não precisa de ser tudo completo.  
`apt install --no-install-recommends ffmpeg`

2. Encontrar os dispositivos de captura  
`ls /dev/video*`  
`v4l2-ctl --list-devices`  
O último comando depende do pacote `v4l-utils`

3. As resoluçãos disponíveis para o dispositivo de entrada podem ser obtidas através dos comandos  
`ffmpeg -f v4l2 -list_formats all -i /dev/video0`  
`v4l2-ctl --list-formats-ext`  
Sendo este útimo comando pertencente ao pacote `v4l-utils`

4. As fotos são tiradas pela execução do comando:  
`ffmpeg -f v4l2 -s 640x480 -i /dev/video0 -ss 0:0:2 -frames 1 out.png`  
Os parâmetros utilizados:
`-f` especifica o formato da captura, no caso será `v4l2`, video for Linux 2, uma captura de webcam.
`-s` especifica a resolução a ser usada, deve ser compatível com o dispositivo de captura.
`-i` especifica o caminho para o dispositivo de captura, o qual estpa normalmente em `/dev/video`.
`-ss` especifica um pequeno atraso na captura para que a câmera tenha tempo de autoajustar.
`-frames` especifica quantos quadros serão produzidos após o pequeno atraso

5. Opcionalmente os comandos da câmera podem ser ajustados pelas ferramentas disponíveis no `v4l-utils`
Para listar os parâmetros `v4l2-ctl -L`  
Para ajustá-los `v4l2-ctl -c <option>=<value>`

## Bibliografia
https://trac.ffmpeg.org/wiki/Capture/Webcam
https://askubuntu.com/questions/106770/take-a-picture-from-terminal
https://wiki.archlinux.org/index.php/Webcam_setup
http://www.ideasonboard.org/uvc/
https://help.ubuntu.com/community/Webcam
https://wiki.debian.org/Webcam

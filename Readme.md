## Movitação
Inspirando pelo programador e criador de contéudo [@Tsoding](https://www.youtube.com/@Tsoding/videos) resolvi experimentar com a criação de imagens .ppm que, quando unificadas utilizando `ffmpeg`, tornam-se um vídeo


## Descrição
Utilizando a biblioteca padrão de input e output do C - `stdio.h` - podemos escrever um arquivo binário qualquer. Porém, se o especificarmos seguindo o [padrão do formato de imagens .ppm](https://netpbm.sourceforge.net/doc/ppm.html), podemos gerar uma imagem específica. Além disso, se gerarmos uma colêtanea desses arquivos, podemos obter um vídeo ao final.

Essa é a ideia do código.

## Rodando o Código
É necessário:
- Compilador da Linguagem C
- ffmpeg (Utilizado para produção do vídeo)

Para fazer a ação, basta compilar o arquivo main.c e rodar o executável produzido. No código do main.c, encontram-se pontos que podem ser modificados como resolução e fps, o qual determina a quantidade de imagens produzidas.

Sem modificar nada, o código gera 30 imagens de um padrão de tabuleiro. Para transformá-las em um vídeo, utilizamos o ffmpeg com o seguinte comando:
`ffmpeg -i output-%02d.ppm -r 30 output.mp4`

Para saber mais sobre a execução desse comando, veja [aqui](https://www.ffmpeg.org/ffmpeg.html).


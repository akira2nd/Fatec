// Inclui o arquivo de cabe�alho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabe�alho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
//para utilizar fprintf
#include <stdio.h>

int main(void)
{
    // Vari�vel representando a janela principal
    ALLEGRO_DISPLAY *janela = NULL;
    // Vari�vel representando a imagem
    ALLEGRO_BITMAP *imagem = NULL;
    ALLEGRO_BITMAP *imagem2 = NULL;
    // Inicializamos a biblioteca
    al_init();
    // Inicializa o add-on para utiliza��o de imagens
    al_init_image_addon();
    // Criamos a nossa janela - dimens�es de 640x480 px
    janela = al_create_display(640, 480);

    //crrega imagem
    imagem = al_load_bitmap("bigimage.jpg");
    imagem2 = al_load_bitmap("helicoptero_03.gif");
    //desenha a imagem na tela
    al_draw_bitmap(imagem,0,0,0);
    al_draw_bitmap(imagem2,10,0,0);
    // Preenchemos a janela de branco
    //****al_clear_to_color(al_map_rgb(255, 255, 255));

    // Atualiza a tela
    al_flip_display();

    // Segura a execu��o por 10 segundos
    al_rest(10.0);

    // Finaliza a janela
    al_destroy_display(janela);

    return 0;
}

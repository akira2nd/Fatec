#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>


int main(void){
    ALLEGRO_DISPLAY *janela = NULL;

    al_init();

    janela = al_create_display(800, 600);

    al_init_image_addon();

    ALLEGRO_BITMAP *background = al_load_bitmap("img/bg.jpg");
    ALLEGRO_BITMAP *arvore1 = al_load_bitmap("img/arvore-01.png");

    //al_draw_bitmap(background,0, 0, NULL);
    al_draw_scaled_bitmap(background,0,0,1920,1080,0,0,al_get_display_width(janela),al_get_display_height(janela),0);
    //al_draw_bitmap(arvore,0,100,0);
    //al_draw_scaled_bitmap(arvore1,0,0,al_get_bitmap_height(arvore1),al_get_bitmap_width(arvore1),180,0,al_get_display_width(janela),al_get_display_height(janela),0);
    al_draw_scaled_bitmap(arvore1,0,0,212,373,325,70,al_get_display_width(janela)/4,al_get_display_height(janela)/4,0);
    al_flip_display();

    al_rest(10.0);

    al_destroy_bitmap(background);
    al_destroy_bitmap(arvore1);
    al_destroy_display(janela);

    return 0;
}

/* DESTE PONTO PRA CIMA EDITADO NO SERVIÇO ***********


/* estrutura do código e comentários retirados do site
http://www.rafaeltoledo.net/tutoriais-allegro-5/
começando a implementar a partir dessa base. 


// Inclui o arquivo de cabeçalho da biblioteca Allegro 5
#include <allegro5/allegro.h>
// Inclui o cabeçalho do add-on para uso de imagens
#include <allegro5/allegro_image.h>
//para utilizar fprintf
#include <stdio.h>

int main(void)
{
    // Variável representando a janela principal
    ALLEGRO_DISPLAY *janela = NULL;
    // Variável representando a imagem
    ALLEGRO_BITMAP *imagem = NULL;
    ALLEGRO_BITMAP *imagem2 = NULL;
    // Inicializamos a biblioteca
    al_init();
    // Inicializa o add-on para utilização de imagens
    al_init_image_addon();
    // Criamos a nossa janela - dimensões de 640x480 px
    janela = al_create_display(640, 360);

    //crrega imagem
    imagem = al_load_bitmap("img/bigimage.jpg");
    imagem2 = al_load_bitmap("img/helicoptero_03.gif");
    //desenha a imagem na tela
    al_draw_bitmap(imagem,0,0,0);
    //al_draw_bitmap(imagem2,10,0,0);
    al_draw_tinted_bitmap(imagem2, al_map_rgba_f(1, 1, 1, 1), 0, 100, 0);
    // Preenchemos a janela de branco
    //****al_clear_to_color(al_map_rgb(255, 255, 255));

    // Atualiza a tela
    al_flip_display();

    // Segura a execução por 10 segundos
    al_rest(10.0);

    // Finaliza a janela
    al_destroy_display(janela);

    return 0;
}
*/

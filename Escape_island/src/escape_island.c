#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdbool.h>

const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

int main(void){
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *arvoreC = NULL;
    ALLEGRO_BITMAP *menu = NULL;
    ALLEGRO_BITMAP *coco = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;

    bool sair = false;
    double p = 0.666666667;

    if(!al_init()){
        printf("Erro ao iniciar allegro");
        return 1;
    }
    if(!al_install_keyboard()){
        printf("Erro ao iniciar teclado");
        return 1;
    }

    if(!al_init_image_addon()){
            printf("Erro ao iniciar imagens");
            return 1;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if(!janela){
        printf("Erro ao abrir janela");
        return 1;
    }

    background = al_load_bitmap("img/bg.jpg");
    if(!background){
        printf("Erro ao iniciar imagem de fundo");
        al_destroy_display(janela);
        return 1;
    }

    arvoreC = al_load_bitmap("img/arvore-cortar.png");
    if(!arvoreC){
        printf("Erro ao iniciar arvoreC");
        al_destroy_display(janela);
        return -1;
    }

    coco = al_load_bitmap("img/coco.png");
    if(!coco){
        printf("Erro pra carregar o coco");
        al_destroy_display(janela);
        return -1;
    }

    menu = al_load_bitmap("img/barra_itens.png");
    if(!menu){
        printf("Erro ao iniciar bitmap menu");
        al_destroy_display(janela);
        return -1;
    }

//while (!sair){
    ALLEGRO_EVENT evento;

    //al_draw_bitmap(background,0, 0, NULL);
    //printf("%lf",al_get_bitmap_width(arvoreC));

    al_draw_scaled_bitmap(background,0,0,al_get_bitmap_width(background),al_get_bitmap_height(background),0,0,al_get_display_width(janela),al_get_display_height(janela),0);

    al_draw_scaled_bitmap(arvoreC,0,0,al_get_bitmap_width(arvoreC),al_get_bitmap_height(arvoreC),620,44,p*al_get_bitmap_width(arvoreC),p*al_get_bitmap_height(arvoreC),0);

    al_draw_scaled_bitmap(menu,0,0,al_get_bitmap_width(menu),al_get_bitmap_height(menu),50,512,p*al_get_bitmap_width(menu),p*al_get_bitmap_height(menu),0);

    al_draw_scaled_bitmap(coco,0,0,al_get_bitmap_width(coco),al_get_bitmap_height(coco),20,5,p*al_get_bitmap_width(coco),p*al_get_bitmap_height(coco),0);


    al_flip_display();

    //al_wait_for_event(fila_eventos, &evento);

    //if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        //sair = true;

/*
    //teclado
    ; = al_create_event_queue();

    if(evento_fila == NULL)
        return 1;

    al_register_event_source(evento_fila, al_get_keyboard_event_source());

*/

    al_rest(7.0);
//}
    al_destroy_bitmap(background);
    al_destroy_bitmap(arvoreC);
    al_destroy_bitmap(coco);
    al_destroy_bitmap(menu);
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

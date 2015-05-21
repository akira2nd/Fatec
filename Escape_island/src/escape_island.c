#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdbool.h>

erro_imagem(ALLEGRO_BITMAP *x , char y[150],ALLEGRO_DISPLAY *janela){
    if(!x){
        printf("Erro ao iniciar imagem %s", y);
        al_destroy_display(janela);
        return -1;
    }
}


const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;

int main(void){
    ALLEGRO_DISPLAY *janela = NULL;

 //imagens
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *arvoreC = NULL;
    ALLEGRO_BITMAP *menu = NULL;
    ALLEGRO_BITMAP *coco = NULL;
    ALLEGRO_BITMAP *arvore01 = NULL;
    ALLEGRO_BITMAP *arvore02 = NULL;
    ALLEGRO_BITMAP *arvoretombada = NULL;
    ALLEGRO_BITMAP *coqueiro01 = NULL;
    ALLEGRO_BITMAP *coqueiro02 = NULL;
    ALLEGRO_BITMAP *coqueiro03 = NULL;
    ALLEGRO_BITMAP *coqueiro04 = NULL;
    ALLEGRO_BITMAP *coqueiro05 = NULL;
    ALLEGRO_BITMAP *coqueiro06 = NULL;
    ALLEGRO_BITMAP *coqueiro07 = NULL;
    ALLEGRO_BITMAP *coqueiro08 = NULL;
    ALLEGRO_BITMAP *espinha = NULL;
    ALLEGRO_BITMAP *fogueira = NULL;
    ALLEGRO_BITMAP *fogueiraapagada = NULL;
    ALLEGRO_BITMAP *galhocomum = NULL;
    ALLEGRO_BITMAP *galhofino = NULL;
    ALLEGRO_BITMAP *galhorigido = NULL;
    ALLEGRO_BITMAP *galhoseco = NULL;
    ALLEGRO_BITMAP *lanca = NULL;
    ALLEGRO_BITMAP *machado = NULL;
    ALLEGRO_BITMAP *mapa = NULL;
    ALLEGRO_BITMAP *pedracortante = NULL;
    ALLEGRO_BITMAP *peixe = NULL;

//outros
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_TIMER *timer = NULL;

    bool sair = false;
    double p = 0.666666667;

    if(!al_init()){
        printf("Erro ao iniciar allegro");
        return 1;
    }
/*
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        printf("erro ao carregar timer");
        return -1;
    }
*/
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

    arvoreC = al_load_bitmap("arvore-cortar.png");
    erro_imagem(arvoreC, "img/arvore-cortar.png",janela);

    coco = al_load_bitmap("img/coco.png");
    erro_imagem(coco, "img/coco.png",janela);

    menu = al_load_bitmap("img/barra_itens.png");
    erro_imagem(menu, "img/barra_itens.png",janela);

arvore01= al_load_bitmap("img/arvore-01.png");
erro_imagem(arvore01,"img/arvore-01.png",janela);

arvore02= al_load_bitmap("img/arvore-02.png");
erro_imagem(arvore02,"img/arvore-02.png",janela);

arvoretombada= al_load_bitmap("img/arvore-tombada.png");
erro_imagem(arvoretombada,"img/arvore-tombada.png",janela);

coqueiro01= al_load_bitmap("img/coqueiro-01.png");
erro_imagem(coqueiro01,"img/coqueiro-01.png",janela);

coqueiro02= al_load_bitmap("img/coqueiro-02.png");
erro_imagem(coqueiro02,"img/coqueiro-02.png",janela);

coqueiro03= al_load_bitmap("img/coqueiro-03.png");
erro_imagem(coqueiro03,"img/coqueiro-03.png",janela);

coqueiro04= al_load_bitmap("img/coqueiro-04.png");
erro_imagem(coqueiro04,"img/coqueiro-04.png",janela);

coqueiro05= al_load_bitmap("img/coqueiro-05.png");
erro_imagem(coqueiro05,"img/coqueiro-05.png",janela);

coqueiro06= al_load_bitmap("img/coqueiro-06.png");
erro_imagem(coqueiro06,"img/coqueiro-06.png",janela);

coqueiro07= al_load_bitmap("img/coqueiro-07.png");
erro_imagem(coqueiro07,"img/coqueiro-07.png",janela);

coqueiro08= al_load_bitmap("img/coqueiro-08.png");
erro_imagem(coqueiro08,"img/coqueiro-08.png",janela);

espinha= al_load_bitmap("img/espinha.png");
erro_imagem(espinha,"img/espinha.png",janela);

fogueira= al_load_bitmap("img/fogueira.png");
erro_imagem(fogueira,"img/fogueira.png",janela);

fogueiraapagada= al_load_bitmap("img/fogueira-apagada.png");
erro_imagem(fogueiraapagada,"img/fogueira-apagada.png",janela);

galhocomum= al_load_bitmap("img/galho-comum.png");
erro_imagem(galhocomum,"img/galho-comum.png",janela);

galhofino= al_load_bitmap("img/galho-fino.png");
erro_imagem(galhofino,"img/galho-fino.png",janela);

galhorigido= al_load_bitmap("img/galho-rigido.png");
erro_imagem(galhorigido,"img/galho-rigido.png",janela);

galhoseco= al_load_bitmap("img/galho-seco.png");
erro_imagem(galhoseco,"img/galho-seco.png",janela);

lanca= al_load_bitmap("img/lanca.png");
erro_imagem(lanca,"img/lanca.png",janela);

machado= al_load_bitmap("img/machado.png");
erro_imagem(machado,"img/machado.png",janela);

mapa= al_load_bitmap("img/mapa.png");
erro_imagem(mapa,"img/mapa.png",janela);

pedracortante= al_load_bitmap("img/pedra-cortante.png");
erro_imagem(pedracortante,"img/pedra-cortante.png",janela);

peixe= al_load_bitmap("img/peixe.png");
erro_imagem(peixe,"img/peixe.png",janela);





//while (!sair){
    ALLEGRO_EVENT evento;

    //al_draw_bitmap(background,0, 0, NULL);
    //printf("%lf",al_get_bitmap_width(arvoreC));

    al_draw_scaled_bitmap(background,0,0,al_get_bitmap_width(background),al_get_bitmap_height(background),0,0,al_get_display_width(janela),al_get_display_height(janela),0);

    al_draw_scaled_bitmap(arvoreC,0,0,al_get_bitmap_width(arvoreC),al_get_bitmap_height(arvoreC),620,44,p*al_get_bitmap_width(arvoreC),p*al_get_bitmap_height(arvoreC),0);




    al_draw_scaled_bitmap(menu,0,0,al_get_bitmap_width(menu),al_get_bitmap_height(menu),50,512,p*al_get_bitmap_width(menu),p*al_get_bitmap_height(menu),0);





    al_draw_scaled_bitmap(coco,0,0,al_get_bitmap_width(coco),al_get_bitmap_height(coco),195,600,100,100,0);


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

    al_rest(10.0);
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

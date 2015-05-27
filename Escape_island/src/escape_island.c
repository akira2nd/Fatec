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
    ALLEGRO_BITMAP *mato01 = NULL;
    ALLEGRO_BITMAP *mato02 = NULL;
    ALLEGRO_BITMAP *mato03 = NULL;

//outros
    ALLEGRO_EVENT_QUEUE *fila_evento = NULL;
    ALLEGRO_FONT *fonte = NULL;
    ALLEGRO_TIMER *timer = NULL;

    double p = 0.666666667;
    double i = 0.35;
    double f = 0.45;

    if(!al_init()){
        printf("Erro ao iniciar allegro");
        return -1;
    }

    al_init_font_addon();
    if(!al_init_ttf_addon()){
        printf("erro ao carregar fontes");
        return -1;
    }

    if(!al_install_keyboard()){
        printf("Erro ao iniciar teclado");
        return -1;
    }

    if(!al_init_image_addon()){
            printf("Erro ao iniciar imagens");
            return -1;
    }

    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if(!janela){
        printf("Erro ao abrir janela");
        return -1;
    }

    al_set_window_title(janela,"Escape The Island - Projeto LP [Denis Campos // Akira]");

    fonte = al_load_font("img/comic.ttf",16,0);
    if(!fonte){
        al_destroy_display(janela);
        printf("Erro ao carregar fonte arquivo.");
        return -1;
    }

    if(!al_install_mouse()){
        printf("Erro ao iniciar o mouse.\n");
        return -1;
    }

    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT)){
        printf("Erro ao iniciar ponteiro do mouse(seta).\n");
        al_destroy_display(janela);
        return -1;
    }


    background = al_load_bitmap("img/bg.jpg");
    if(!background){
        printf("Erro ao iniciar imagem de fundo");
        al_destroy_display(janela);
        return -1;
    }

    if (!al_set_system_mouse_cursor(janela, ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT))
    {
        printf("Erro ao iniciar mouse ponteiro");
        al_destroy_display(janela);
        return -1;
    }


    arvoreC = al_load_bitmap("img/arvore-cortar.png");
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

    mato01 = al_load_bitmap("img/mato-01.png");
    erro_imagem(peixe,"img/mato-01.png",janela);

    mato02 = al_load_bitmap("img/mato-02.png");
    erro_imagem(peixe,"img/mato-02.png",janela);

    mato03 = al_load_bitmap("img/mato-03.png");
    erro_imagem(peixe,"img/mato-03.png",janela);


    fila_evento = al_create_event_queue();
    if(!fila_evento){
        printf("Erro ao carregar fila_evento");
        al_destroy_display(janela);
        return -1;
    }

    al_register_event_source(fila_evento, al_get_display_event_source(janela));


int yMenu = 530;
int x = 0;
bool item = true;

while (1){

    ALLEGRO_EVENT evento;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);

    bool get_event = al_wait_for_event_until(fila_evento, &evento, &timeout);

    if(get_event && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        break;
    }

    al_draw_scaled_bitmap(background,0,0,al_get_bitmap_width(background),al_get_bitmap_height(background),0,0,al_get_display_width(janela),al_get_display_height(janela),0);

    al_draw_scaled_bitmap(arvoreC,0,0,al_get_bitmap_width(arvoreC),al_get_bitmap_height(arvoreC),620,44,p*al_get_bitmap_width(arvoreC),p*al_get_bitmap_height(arvoreC),0);

    al_draw_scaled_bitmap(arvore02,0,0,al_get_bitmap_width(arvore02),al_get_bitmap_height(arvore02),670,280,p*al_get_bitmap_width(arvore02),p*al_get_bitmap_height(arvore02),0);

    al_draw_scaled_bitmap(fogueira,0,0,al_get_bitmap_width(fogueira),al_get_bitmap_height(fogueira),980,100,f*al_get_bitmap_width(fogueira),f*al_get_bitmap_height(fogueira),0);
    al_draw_scaled_bitmap(fogueiraapagada,0,0,al_get_bitmap_width(fogueiraapagada),al_get_bitmap_height(fogueiraapagada),140,140,p*al_get_bitmap_width(fogueiraapagada),p*al_get_bitmap_height(fogueiraapagada),0);

    al_draw_scaled_bitmap(arvoretombada,0,0,al_get_bitmap_width(arvoretombada),al_get_bitmap_height(arvoretombada),675,135,p*al_get_bitmap_width(arvoretombada),p*al_get_bitmap_height(arvoretombada),0);
    al_draw_scaled_bitmap(coqueiro01,0,0,al_get_bitmap_width(coqueiro01),al_get_bitmap_height(coqueiro01),75,0,p*al_get_bitmap_width(coqueiro01),p*al_get_bitmap_height(coqueiro01),0);
    al_draw_scaled_bitmap(coqueiro02,0,0,al_get_bitmap_width(coqueiro02),al_get_bitmap_height(coqueiro02),300,-95,p*al_get_bitmap_width(coqueiro02),p*al_get_bitmap_height(coqueiro02),0);

    al_draw_scaled_bitmap(arvore01,0,0,al_get_bitmap_width(arvore01),al_get_bitmap_height(arvore01),245,170,p*al_get_bitmap_width(arvore01),p*al_get_bitmap_height(arvore01),0);

    al_draw_scaled_bitmap(coqueiro03,0,0,al_get_bitmap_width(coqueiro03),al_get_bitmap_height(coqueiro03),340,230,p*al_get_bitmap_width(coqueiro03),p*al_get_bitmap_height(coqueiro03),0);
    al_draw_scaled_bitmap(coqueiro04,0,0,al_get_bitmap_width(coqueiro04),al_get_bitmap_height(coqueiro04),475,-115,p*al_get_bitmap_width(coqueiro04),p*al_get_bitmap_height(coqueiro04),0);
    al_draw_scaled_bitmap(coqueiro05,0,0,al_get_bitmap_width(coqueiro05),al_get_bitmap_height(coqueiro05),475,15,p*al_get_bitmap_width(coqueiro05),p*al_get_bitmap_height(coqueiro05),0);
    al_draw_scaled_bitmap(coqueiro06,0,0,al_get_bitmap_width(coqueiro06),al_get_bitmap_height(coqueiro06),850,300,p*al_get_bitmap_width(coqueiro06),p*al_get_bitmap_height(coqueiro06),0);
    al_draw_scaled_bitmap(coqueiro07,0,0,al_get_bitmap_width(coqueiro07),al_get_bitmap_height(coqueiro07),850,-110,p*al_get_bitmap_width(coqueiro07),p*al_get_bitmap_height(coqueiro07),0);
    al_draw_scaled_bitmap(coqueiro08,0,0,al_get_bitmap_width(coqueiro08),al_get_bitmap_height(coqueiro08),960,-30,p*al_get_bitmap_width(coqueiro08),p*al_get_bitmap_height(coqueiro08),0);


    al_draw_scaled_bitmap(espinha,0,0,al_get_bitmap_width(espinha),al_get_bitmap_height(espinha),120,120,p*al_get_bitmap_width(espinha),p*al_get_bitmap_height(espinha),0);


    al_draw_scaled_bitmap(galhocomum,0,0,al_get_bitmap_width(galhocomum),al_get_bitmap_height(galhocomum),150,150,p*al_get_bitmap_width(galhocomum),p*al_get_bitmap_height(galhocomum),0);
    al_draw_scaled_bitmap(galhofino,0,0,al_get_bitmap_width(galhofino),al_get_bitmap_height(galhofino),160,160,p*al_get_bitmap_width(galhofino),p*al_get_bitmap_height(galhofino),0);
    al_draw_scaled_bitmap(galhorigido,0,0,al_get_bitmap_width(galhorigido),al_get_bitmap_height(galhorigido),170,170,p*al_get_bitmap_width(galhorigido),p*al_get_bitmap_height(galhorigido),0);
    al_draw_scaled_bitmap(galhoseco,0,0,al_get_bitmap_width(galhoseco),al_get_bitmap_height(galhoseco),180,180,p*al_get_bitmap_width(galhoseco),p*al_get_bitmap_height(galhoseco),0);
    al_draw_scaled_bitmap(lanca,0,0,al_get_bitmap_width(lanca),al_get_bitmap_height(lanca),190,190,p*al_get_bitmap_width(lanca),p*al_get_bitmap_height(lanca),0);
    al_draw_scaled_bitmap(machado,0,0,al_get_bitmap_width(machado),al_get_bitmap_height(machado),200,200,p*al_get_bitmap_width(machado),p*al_get_bitmap_height(machado),0);

    al_draw_scaled_bitmap(pedracortante,0,0,al_get_bitmap_width(pedracortante),al_get_bitmap_height(pedracortante),245,455,i*al_get_bitmap_width(pedracortante),i*al_get_bitmap_height(pedracortante),0);


    //al_draw_scaled_bitmap(peixe,0,0,al_get_bitmap_width(peixe),al_get_bitmap_height(peixe),230,230,p*al_get_bitmap_width(peixe),p*al_get_bitmap_height(peixe),0);
    //al_draw_scaled_bitmap(mapa,0,0,al_get_bitmap_width(mapa),al_get_bitmap_height(mapa),210,210,p*al_get_bitmap_width(mapa),p*al_get_bitmap_height(mapa),0);


    al_draw_scaled_bitmap(coco,0,0,al_get_bitmap_width(coco),al_get_bitmap_height(coco),195,600,100,100,0);

    al_draw_scaled_bitmap(menu,0,0,al_get_bitmap_width(menu),al_get_bitmap_height(menu),65,yMenu,p*al_get_bitmap_width(menu),p*al_get_bitmap_height(menu),0);


    //if(yMenu <512 && yMenu >670)
    //menu largura xMenu = 50 altura yMenu = 512
    //menu largura xMenu = 50 altura yMenu = 670

    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 139, yMenu+51, ALLEGRO_ALIGN_LEFT , "%d", x);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 247, yMenu+51, ALLEGRO_ALIGN_LEFT  , "%d", x+1);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 355, yMenu+51, ALLEGRO_ALIGN_LEFT  , "%d", x+2);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 466, yMenu+51, ALLEGRO_ALIGN_LEFT  , "%d", x+3);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 574, yMenu+51, ALLEGRO_ALIGN_LEFT  , "%d", x+4);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 682, yMenu+51, ALLEGRO_ALIGN_LEFT  , "%d", x+5);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 790, yMenu+51,ALLEGRO_ALIGN_LEFT , "%d", x+6);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 898, yMenu+51, ALLEGRO_ALIGN_LEFT  , "%d", x+7);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 1006, yMenu+51, ALLEGRO_ALIGN_LEFT  , "%d", x+8);
    al_draw_textf(fonte,al_map_rgb(255, 255, 255), 1114, yMenu+51, ALLEGRO_ALIGN_LEFT  , "%d", x+9);

    //al_rest(0.005);
    //x++;
    al_flip_display();



//Criar evento do mouse para alterar **item** true e false
    if(item && yMenu <= 670){
        yMenu = 670;
    /*
    }else{
        item = false;
    */
    }

//545,675 --- 725,720


    if(!item && yMenu >= 530){
        yMenu = 530;
    /*
    }else{
        item = true;
    */
    }
//545, 535 == 725,585


    ALLEGRO_MOUSE_STATE state;

    al_get_mouse_state(&state);
    if (state.buttons & 1) {
    //while(al_mouse_button_down(state.buttons , 1)){
        /* Primary (e.g. left) mouse button is held. */
        if(state.x >= 545 && state.x <= 725 && state.y >= 675 && state.y <= 720){
            item = false;
        }
        if(state.x >= 545 && state.x <= 725 && state.y >= 535 && state.y <= 585){
            item = true;
        }
        printf("Mouse position: (%d, %d)\n", state.x, state.y);
    }




}

    al_destroy_bitmap(background);
    al_destroy_bitmap(arvoreC);
    al_destroy_bitmap(coco);
    al_destroy_bitmap(menu);

    al_destroy_bitmap(arvore01);
    al_destroy_bitmap(arvore02);
    al_destroy_bitmap(arvoretombada);
    al_destroy_bitmap(coqueiro01);
    al_destroy_bitmap(coqueiro02);
    al_destroy_bitmap(coqueiro03);
    al_destroy_bitmap(coqueiro04);
    al_destroy_bitmap(coqueiro05);
    al_destroy_bitmap(coqueiro06);
    al_destroy_bitmap(coqueiro07);
    al_destroy_bitmap(coqueiro08);
    al_destroy_bitmap(espinha);
    al_destroy_bitmap(fogueira);
    al_destroy_bitmap(fogueiraapagada);
    al_destroy_bitmap(galhocomum);
    al_destroy_bitmap(galhofino);
    al_destroy_bitmap(galhorigido);
    al_destroy_bitmap(galhoseco);
    al_destroy_bitmap(lanca);
    al_destroy_bitmap(machado);
    al_destroy_bitmap(mapa);
    al_destroy_bitmap(pedracortante);
    al_destroy_bitmap(peixe);

    al_destroy_event_queue(fila_evento);
    al_destroy_font(fonte);
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
>>>>>>> origin/master
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

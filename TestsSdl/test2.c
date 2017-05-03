#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>


const int WIDTH  = 640;
const int HEIGHT = 480;

SDL_Texture* loadTexture(char * filename, SDL_Renderer *ren){
    SDL_Surface *image;
    SDL_Texture *texture;

    image = IMG_Load(filename);
    texture = SDL_CreateTextureFromSurface(ren, image);
    if (!texture)
    {
        SDL_FreeSurface(image);
        fprintf(stderr,"Erreur chargement image : %s\n",SDL_GetError());
        return 0;
    }
    SDL_FreeSurface(image);
    return texture;
}

void dessin3(SDL_Renderer * ren)
{
    SDL_Texture * tex = 0;
    SDL_Rect dst;

    tex = loadTexture("./Horizon.jpg",ren);
    if (tex == 0) return;

    // Récupération de la taille de la texture
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);

    // Centrage
    dst.x = (WIDTH - dst.w)/2;
    dst.y = (HEIGHT- dst.h)/2;

    // Affichage
    SDL_RenderCopy(ren, tex, NULL, &dst);
    SDL_RenderPresent(ren);
    SDL_DestroyTexture(tex);
}

void dessin2(SDL_Renderer * ren)
{
    int colr, colg, colb;
    SDL_Rect r;
    int i;

    SDL_SetRenderDrawBlendMode(ren,SDL_BLENDMODE_BLEND);
    for(i=0;i<30;i++)
    {
        r.x = rand()%WIDTH;
        r.y = rand()%HEIGHT;
        r.w = rand()%(WIDTH-r.x);
        r.h = rand()%(HEIGHT-r.y);
        colr = rand()%256;
        colg = rand()%256;
        colb = rand()%256;
        SDL_SetRenderDrawColor(ren,colr,colg,colb,20);
        SDL_RenderFillRect(ren,&r);
    }
    SDL_RenderPresent(ren);
}

void  dessin(SDL_Renderer * ren)
{
    SDL_Rect rect;
    int cr,cv,cb;
    int res;
    unsigned int value;
    int i,j;

    rect.w=1;
    rect.h=1;
    for (i=0;i<WIDTH; i++) {

        for (j = 0; j < HEIGHT; j++) {
            if ((i < 10 || i >= WIDTH - 10)) {
                rect.x = i;
                rect.y = j;
                res = SDL_RenderReadPixels(ren, &rect, SDL_PIXELFORMAT_ARGB8888, &value, 32 * WIDTH);
                if (res < 0) {
                    printf("Lecture erronée : %s\n", SDL_GetError());
                }
                cr = (value & 0xFF0000) >> 16;
                cv = (value & 0x00FF00) >> 8;
                cb = (value & 0x0000FF);

                SDL_SetRenderDrawColor(ren, cv, 150, 150, 0);
                SDL_RenderDrawPoint(ren, i, j);
            }
            else {
                if ((j<10) || (j>=HEIGHT-10)){
                    rect.x = i;
                    rect.y = j;
                    res = SDL_RenderReadPixels(ren, &rect, SDL_PIXELFORMAT_ARGB8888, &value, 32 * WIDTH);
                    if (res < 0) {
                        printf("Lecture erronée : %s\n", SDL_GetError());
                    }
                    cr = (value & 0xFF0000) >> 16;
                    cv = (value & 0x00FF00) >> 8;
                    cb = (value & 0x0000FF);

                    SDL_SetRenderDrawColor(ren, cv, 150, 150, 0);
                    SDL_RenderDrawPoint(ren, i, j);
                }
            }
        }
    }
    SDL_RenderPresent(ren);
}


int main(int argc, char** argv)
{
    SDL_Window *win = 0;
    SDL_Renderer *ren = 0;

    /* Initialisation de la SDL. Si ça se passe mal, on quitte */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
    {
        fprintf(stderr,"Erreur initialisation\n");
        return -1;
    }
    /* Création de la fenêtre et du renderer */

    /*SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &ren); // SDL_WINDOW_SHOWN|SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC,&win,&ren);
    */
    win = SDL_CreateWindow("Planet Side", SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED,
                           640,
                           480,
                           SDL_WINDOW_SHOWN);

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!win || !ren)
    {
        fprintf(stderr,"Erreur à la création des fenêtres\n");
        SDL_Quit();
        return -1;
    }
    /* Affichage du fond noir */
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    SDL_RenderPresent(ren);
    dessin(ren);
    SDL_Delay(4000);

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}

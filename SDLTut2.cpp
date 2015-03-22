//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to:
SDL_Window* gWindow = NULL;

//The surface contained by the window:
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on screen:
SDL_Surface* gXOut = NULL;

int main( int argc, char* args[] ) {
  //Start up SDL and create window
  if(!init()) {
    printf("Failed to initialize!\n");
  }else{
     //Load media
     if(!loadMedia()) {
       printf("Failed to load media!\n");
     }else{
        bool quit = false;
        SDL_Event e;
        while(!quit){
          while(SDL_PollEvent(&e) != 0) {
            if(e.type == SDL_QUIT) {
              quit = true;
            }
          }
          SDL_BlitSurface(gXOut, NULL, gScreenSurface, NULL);
          SDL_UpdateWindowSurface(gWindow);
        }
     }
  }
  close();
  
  return 0;
}

bool init() {
  //Initialization flag
  bool success = true;
  
  //Initialization SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    success = false;
  }else{
    //Create window
    gWindow = SDL_CreateWindow("SDL Tutorial 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(gWindow == NULL){
      printf("Window could not be created! SDL_Error %s\n", SDL_GetError());
      success = false;
    }else{
      //Get window surface:
      gScreenSurface = SDL_GetWindowSurface(gWindow);
    }
  }
return success;
}

bool loadMedia() {
  //Laoding success flag
  bool success = true;

  //Load splash image
   gXOut = SDL_LoadBMP("derg.bmp");
   if(gXOut == NULL) {
     printf("Unable to load image %s! SDL Error: %s\n", "SDL/derg.bmp", SDL_GetError());
     success = false;
   }
   return success;
}

void close() {
  //Deallocate surface
  SDL_FreeSurface(gXOut);
  gXOut = NULL;

  //Destroy window
  SDL_DestroyWindow(gWindow);
  gWindow = NULL;
 
  //Qui SDL subsystems
  SDL_Quit();
}

 

 
   



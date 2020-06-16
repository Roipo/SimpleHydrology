#include <functional>
#include <initializer_list>
#include <string>

using Handle = std::function<void()>;

using slist = std::initializer_list<std::string>;

//Interface Dependencies (DearImGUI)
#include "include/imgui/imgui.h"
#include "include/imgui/imgui_impl_sdl.h"
#include "include/imgui/imgui_impl_opengl3.h"
#define SDL_MAIN_HANDLED

//Drawing Dependencies
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//File IO
#include <sstream>
#include <iostream>
#include <fstream>
// #include <boost/filesystem/operations.hpp>
// #include <boost/filesystem/path.hpp>

//Helpers
#include "include/helpers/helper.h"
#include "include/helpers/ease.h"
#include "include/helpers/color.h"
#include "include/helpers/draw.h"
#include "include/helpers/image.h"
#include "include/helpers/timer.h"

//Utility Classes for the Engine
#include "include/utility/texture.h"
#include "include/utility/shader.h"
#include "include/utility/sprite.h"
#include "include/utility/particle.h"
#include "include/utility/billboard.h"
#include "include/utility/model.h"

#include "include/view.h"
#include "include/event.h"
#include "include/audio.h"

/* TINY ENGINE */

namespace Tiny {

//Main Engine Elements
static View view;       //Window and Interface
static Event event;     //Event Handler
static Audio audio;     //Audio Processor

bool init(std::string windowName, int width, int height){
  //Initialize SDL Core
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
    printf( "SDL could not initialize! Error: %s\n", SDL_GetError() );
    return false;
  }

  //Initialize SDL_Image
  if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) ){
    printf( "SDL_Image could not initialize! Error: %s\n", IMG_GetError() );
    return false;
  }

  //Initialize SDL_TTF
  TTF_Init();

  //Initialize the View
  if(!view.init(windowName, width, height)){
    std::cout<<"Failed to launch visual interface."<<std::endl;
    return false;
  }

  if(!audio.init()){
    std::cout<<"Failed to launch audio interface."<<std::endl;
		return false;
	}
}

void quit(){
  view.cleanup();
  audio.cleanup();
  TTF_Quit();
  SDL_Quit();
};

template<typename F, typename... Args>
void loop(F function, Args&&... args){
  while(!event.quit){
    event.input();        //Handle Input
    event.handle(view);

    audio.process();      //Audio Processor

    function(args...);    //User-defined Game Loop

    view.render();        //Render View
  }
};

//End of Namespace
};

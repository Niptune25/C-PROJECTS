#include<iostream>
#include "SDL2/SDL.h"
#include "Screen.h"
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include "Swarm.h"
using namespace graphicproj;
using namespace std;
int main(int argv, char** args)
{
	
	srand(time(NULL));
	
	Screen screen;
	if(screen.init()==false){
		cout<<"Error Initializing SDL"<<endl;
	}
	
	Swarm swarm;
    while(true){
    	const Particle *const pParticles = swarm.getParticles();
    	int elapsed =SDL_GetTicks();
    	screen.clear();
    	swarm.update();
    	unsigned char green =(1+sin(elapsed*0.001))*128;
    	unsigned char red =(1+acos(elapsed*0.005))*128;
    	unsigned char blue =(1+sin(elapsed*0.004))*128;
    	for (int i=0;i<Swarm::NPARTICLES;i++){
    		Particle particle =pParticles[i];
    		int x=(particle.m_x +1) * Screen::SCREEN_WIDTH/2;
    		int y=(particle.m_y +1) * Screen::SCREEN_HEIGHT/2;
    		
    		screen.setPixel(x,y,red,green,blue);
    		
		}
    	/*
    	int elapsed =SDL_GetTicks();
    	unsigned char green =(1+sin(elapsed*0.001))*128;
    	unsigned char red =(1+sin(elapsed*0.0005))*128;
    	unsigned char blue =(1+sin(elapsed*0.0004))*128;
    	for(int y=0;y<Screen::SCREEN_HEIGHT;y++){
    		for(int x=0; x<(Screen::SCREEN_WIDTH);x++){
    			screen.setPixel(x,y,red,green,blue);
    			}
	}*/
		screen.update();
        
    	if(screen.processEvents()==false){
    		break;
		}
    	//MORE WILL BE ADDED HERE AS WE EXPAND!!
	}
	screen.close();

	
	return 0;
}


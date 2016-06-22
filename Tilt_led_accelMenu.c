#include "libfreenect.h"
#include "libfreenect_sync.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void no_kinect_quit(void)
{
	printf("Error: Kinect not connected?\n");
	exit(1);
}

int main(int argc, char *argv[])
{
		int tilt=0;
		short main_menu=0,intmenu=0;
		while(main_menu!=4){
			printf("Menu Kinect, Que desea hacer? \n\n1.Cambiar estado del led\n2.Cambiar inclinacion\n3.Adquirir Datos del acelerometro\n4.Salir ");
			scanf("%d",&main_menu);
			switch(main_menu){
				case 1:
					while(intmenu!=6){
						printf("1.Rojo\n2.Verde\n3.amarillo\n4.Parpadeo verde\n5.Otro\n6.Salir\n");
						scanf("%d",&intmenu);
						if(intmenu>0&&intmenu<6){
							if (freenect_sync_set_led((freenect_led_options) (intmenu-1), 0)) no_kinect_quit();
						}
						else
							printf("No es un numero valido");
					}
					break;
				default:
					printf("Not an option yet implemented");
			}	
		
		
		}
}

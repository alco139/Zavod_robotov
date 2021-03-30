#include <stdio.h>
#include "robot_race.h"
track draha, *p_draha = &draha;
ROBOT pole_robotov[MAX_ROBOTS];
ROBOT robot, *p_robot1 = &pole_robotov[0], *p_robot2 = &pole_robotov[1];
int vitaz,x;
void main()
{
	srand(time(0));
	int n = 2;
	initTrack(p_draha);
	initRobots(pole_robotov, n, p_draha);
	print(p_draha);
	
	while (x==0)
	{	
		for (int i = 0; i < n; i++)
		{
			int u= isCollision(&pole_robotov[i],p_draha);
			updateRobotDirection(&pole_robotov[i], p_draha, u);
			updateRobotPosition(&pole_robotov[i]);
			if (pole_robotov[i].x_r >= draha.vyska)
			{
				x = i+1;
				break;
			}
			
		}

		SLEEP(100);
		CLEAR_SCREEN();
		
		print(p_draha);
		
	}
	printf("VYHRAL ROBOT S CISLOM : %i", x);
}
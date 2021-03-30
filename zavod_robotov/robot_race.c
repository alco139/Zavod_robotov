#include <stdio.h>
#include "robot_race.h"
#include <math.h>


void initTrack(track *track)
{
	track->sirka = 25;
	track->vyska = 25;
	track->pocet_prekazok = 6;
	for (int i = 0; i < track->pocet_prekazok; i++)
	{
		track->pole_prekazok[i].x_p = 2 + i * 4;
		track->pole_prekazok[i].y_p = abs(rand() % track->sirka + 2 );
		
		track->pole_prekazok[i].sirka_prekazky = (rand() % 4 + 2)*2 ;
		track->pole_prekazok[i].vyska_prekazky = 1;

	}
	for (int i = 0; i < track->pocet_prekazok; i++)
	{
		for (int j = 0; j < track->pole_prekazok[i].sirka_prekazky; j++)
		{
			zavodnepole[track->pole_prekazok[i].x_p][track->pole_prekazok[i].y_p + j] = 'X';
		}
	}
	
	
}
void initRobots(ROBOT robots[], int n, track* track)
{
	for (int i = 0; i < n; i++)
	{
		robots[i].smer = 1;
		robots[i].rychlost = 1;
		robots[i].y_r = rand() % track->sirka + 1;
		robots[i].x_r = 0;
		zavodnepole[robots[i].x_r = 0][robots[i].y_r] = '+';
	}
}
void updateRobotPosition(ROBOT* robot)
{
	zavodnepole[robot->x_r][robot->y_r] = '.';
	if (robot->smer == 1)
	{
		robot->x_r = robot->x_r + robot->rychlost;
		zavodnepole[robot->x_r][robot->y_r] = '+';

	}
	else if (robot->smer == 2)
	{
		robot->y_r = robot->y_r - robot->rychlost;
		zavodnepole[robot->x_r][robot->y_r] = '+';
	}
	else if (robot->smer == 3)
	{
		
		robot->y_r = robot->y_r + robot->rychlost;
		zavodnepole[robot->x_r][robot->y_r] = '+';
	}
}
int isCollision(ROBOT* robot, track* track)
{
	
	for (int i = 0; i < track->pocet_prekazok; i++)
	{
		int a = track->pole_prekazok[i].vyska_prekazky;
		int b = track->pole_prekazok[i].sirka_prekazky;
		if (robot->x_r + 1 >= track->pole_prekazok[i].x_p && robot->x_r + 1 < track->pole_prekazok[i].x_p + a &&
			robot->y_r >= track->pole_prekazok[i].y_p && robot->y_r < track->pole_prekazok[i].y_p + b)
		{

			if (robot->y_r - 1 == 0)
			{
				return -2;
			}
			else if (robot->y_r + 1 == track->sirka)
			{
				return -3;
			}
			return i;
		}

		
		
	}
	return -1;
	
}
void updateRobotDirection(ROBOT* robot, track* track, int obstacle_id)
{
	if (obstacle_id >= 0)
	{
		int a = track->pole_prekazok[obstacle_id].y_p;
		int b = track->pole_prekazok[obstacle_id].sirka_prekazky + a - 1;
		if (abs(robot->y_r - a) >= abs(robot->y_r - b))
		{
			robot->smer = 3;
		}
		else
			robot->smer = 2;
		
	}
	
	
	
	if (robot->smer != 1)
	{
		int smerik = robot->smer;
		robot->smer = 1;
		if ((isCollision(robot, track)) >= 0)
		{
			robot->smer = smerik;
		}
	}
	if (obstacle_id == -2)
	{
		robot->smer = 3;
	}
	if (obstacle_id == -3)
	{
		robot->smer = 2;
	}
	
}
void print(track* track)

{
	
	for (int i = 0; i < track->vyska; i++)
	{
		zavodnepole[i][0] = '|';
		zavodnepole[i][track->sirka] = '|';
	}
	for (int i = 0; i < track->vyska; i++)
	{
		
		for (int j = 0; j <= track->sirka; j++)
		{
			printf("%c", zavodnepole[i][j]);
		}
		printf("\n");
	}
	
}
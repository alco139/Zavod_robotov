#pragma once
#ifndef ROBOT_RACE_H
#define ROBOT_RACE_H

#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

// MAKRA na vymazanie obsahu konzoly a uspanie programu
#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#else
#include <unistd.h>
#define CLEAR_SCREEN() system("clear")
#define SLEEP(sleepMs) usleep(sleepMs * 1000)
#endif

// KONSTANTY
#define MAX_ROBOTS 5 // max. pocet robotov na trati
#define MAX_OBSTACLES 100 // max. pocet prekazok na trati (zmente podla potreby)
#define MAX_TRACK_HEIGHT 50 // max. vyska trate (zmente podla potreby)
#define MAX_TRACK_WIDTH 150 // max. sirka trate (zmente podla potreby)
#define ROBOT_SPEED 1 // predvolena rychlost robota (dlzka jedneho kroku)
zavodnepole[MAX_TRACK_WIDTH][MAX_TRACK_HEIGHT];

// DATOVE STRUKTURY
typedef struct
{
	int x_p, y_p;
	int sirka_prekazky;
	int vyska_prekazky;
} obstacle;
obstacle prekazka;
typedef struct 
{
	int sirka;
	int vyska;
	int pocet_prekazok;
	obstacle pole_prekazok[MAX_OBSTACLES];
} track;



typedef struct
{
	int x_r, y_r;
	int rychlost;
	int smer;
}ROBOT;



// FUNKCIE

void initTrack(track *track); // funkcia, ktora inicializuje trat pred zavodom
void initRobots(ROBOT robots[], int n, track* track); // funkcia, ktora inicializuje robotov pred zavodom
void updateRobotPosition(ROBOT* robot); // funkcia na aktualizaciu pozicie robota
void updateRobotDirection(ROBOT* robot, track* track, int obstacle_id); // funkcia na aktualizaciu smeru robota
int isCollision(ROBOT* robot, track* track); // funkcia, ktora zisti, ci pohyb robota aktualnym smerom nesposobi koliziu

#endif // ROBOT_RACE_H
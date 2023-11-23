#pragma once

#include <chrono> //use for time

class Game
{
public:
	//Constructor
	Game();
	//Function
	void Play();

private:
	//Size of grid
	const int gridSize = 10;
	//Player position
	int playerX, playerY;
	//Enemy position
	int enemyX, enemyY;

	//Time for timer
	std::chrono::steady_clock::time_point startTime; //add std before chrono because chrono is apart of std namespace

	//Function to draw the game
	void DrawGrid();
	//Function to move the player
	void MovePlayer(char direction);
	//Function to move the enemy
	void MoveEnemy();

};
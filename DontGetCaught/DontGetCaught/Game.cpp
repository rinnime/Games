#include "Game.h"
#include <iostream>
#include <conio.h> //use for _getch();

using namespace std;
using namespace chrono;

Game::Game() 
{
	//Random number generator with the current time
	srand(static_cast<unsigned int>(time(nullptr)));

	//Initialize player and enemy positions
	//Player position based on user input
	playerX = gridSize / 2;
	playerY = gridSize / 2;

	//Random enemy position
	enemyX = rand() % gridSize;
	enemyY = rand() % gridSize;

}

void Game::DrawGrid()
{
	system("cls");

	for (int y = 0; y < gridSize; ++y)
	{
		for (int x = 0; x < gridSize; ++x)
		{
			if (x == playerX && y == playerY)
			{
				cout << 'C';
			}
			else if (x == enemyX && y == enemyY)
			{
				cout << 'E';
			}
			else
			{
				cout << '.';
			}
		}
		cout << endl;
	}
	//Show the amount the time the player has survived the game of tag
	cout << "Time: " << chrono::duration_cast<seconds>(steady_clock::now() - startTime).count() << " seconds\n";
}

//Player movement
void Game::MovePlayer(char direction)
{
	switch (direction)
	{
	case 'w':
	case 'W':
		if (playerY > 0) {
			playerY--;
		}
		break;
	case 's':
	case 'S':
		if (playerY < gridSize - 1) {
			playerY++;
		}
		break;
	case 'a':
	case 'A':
		if (playerX > 0) {
			playerX--;
		}
		break;
	case 'd':
	case 'D':
		if (playerX < gridSize - 1) {
			playerX++;
		}
		break;
	default:
		break;
	}
}

void Game::MoveEnemy()
{
	// Enemy move in random direction
	int direction = rand() % 4;

	switch (direction)
	{
	case 0:
		if (enemyY > 0) {
			enemyY--;
		}
		break;
	case 1:
		if (enemyY < gridSize - 1) {
			enemyY++;
		}
		break;
	case 2:
		if (enemyX > 0) {
			enemyX--;
		}
		break;
	case 3:
		if (enemyX < gridSize - 1) {
			enemyX++;
		}
		break;
	}
}

void Game::Play()
{
	char move;
	bool gameOver = false;

	//Start timer when game starts
	startTime = std::chrono::steady_clock::now();

	do
	{
		DrawGrid();
		//Display WSAD to move the player and Q to quit
		cout << "Use W/S/A/D keys to move. Press Q to quit.\n";

		// Use _getch() for single-character input
		move = _getch();

		if (move == 'Q' || move == 'q')
		{
			gameOver = true;
		}
		else
		{
			MovePlayer(move);
			MoveEnemy();
		}

		// If enemy and player are in the same position, the enemy has caught the player.
		if (playerX == enemyX && playerY == enemyY)
		{
			gameOver = true;
			cout << "Game Over! The enemy caught you.\n";
		}

		auto currentTime = std::chrono::steady_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
		cout << "Time Survived: " << elapsedTime << " seconds\n";

	} 
	//If the player has not been caught the game will continue, until caught
	while (!gameOver);

	// Calculate and display the total survival time
	auto totalTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - startTime).count();
	cout << "You survived for " << totalTime << " seconds.\n";
}

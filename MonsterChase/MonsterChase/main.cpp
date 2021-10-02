#define _CRTDBG_MAP_ALLOC

#include <cstdlib>
#include <crtdbg.h>

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <conio.h>
#include <time.h>

#include "object.h"
#include "monster.h"
#include "player.h"

#include "list.h"

#include "UnitTest/Point2DUnitTest.h"

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

void init()
{
	srand((unsigned int)time(NULL));
}

void draw_all(const Engine::List<Monster>& monsters, const Player& player);

bool update(Engine::List<Monster>& monsters, Player& player);

Monster create_monster(int i);

void get_input(char* buffer, int size)
{
	fgets(buffer, size, stdin);
	buffer[strcspn(buffer, "\n\r")] = 0;
}

const int BUF_SIZE = 256;
const int MAX_LIFE = 10;

int entry()
{
	init();

	printf("Welcome to MonsterChase!\n\n");

	int monster_num = 0;
	char buffer[BUF_SIZE];
	do 
	{
		printf("How many monsters to start:");
		
		get_input(buffer, BUF_SIZE);
		monster_num = atoi(buffer);

		if (monster_num <= 0)
			printf("Bad input. Please enter an integer greater than 0.");
	} while (monster_num <= 0);

	printf("\n");
	Engine::List<Monster> monsters;

	for (auto i = 0; i < monster_num; ++i)
		monsters.push_back(create_monster(i));
	
	printf("\nEnter a name for the player:");
	Player player;

	do 
	{
		buffer[0] = 0;
		get_input(buffer, BUF_SIZE);
		if (strlen(buffer) == 0)
			printf("Empty name not allowed.Enter a name for the player:");
		else
			player.SetName(buffer);
	} while (strlen(buffer) == 0);
	
	draw_all(monsters, player);

	bool run = true;
	while (run)
	{
		run = update(monsters, player);
	}

	return 0;
}

int main()
{
	Point2DUnitTest();
	entry();
	_CrtDumpMemoryLeaks();
	return 0;
}

void draw_all(const Engine::List<Monster>& monsters, const Player& player)
{
	printf("\nMonsters:\n");
	for (auto cur = monsters.begin(); cur != monsters.end(); cur++)
	{
		cur->data.Draw();
	}

	printf("\nPlayer:\n");
	player.Draw();

	printf("Press A to move left, D to move right, W to move up, S to move down, M to create monster or Q to quit\n");
}

bool update(Engine::List<Monster>& monsters, Player& player)
{
	char command = _getch();
	if(command == 'Q' || command == 'q')
		return false;

	if (command == 'M' || command == 'm')
	{
		monsters.push_back(create_monster(monsters.size()));
	}
	else
	{
		// remove all the monster if they have been alive for too long
		monsters.remove([](const Monster& m) {return m.GetLifeTime() >= MAX_LIFE; });

		for (auto cur = monsters.begin(); cur != monsters.end(); cur++)
				cur->data.Update(command);

		player.Update(command);
	}

	draw_all(monsters, player);

	printf("\n");
	return true;
}

Monster create_monster(int i)
{
	printf("Enter a name for monster %d: ", i);
	char buffer[BUF_SIZE];
	while (true)
	{
		get_input(buffer, BUF_SIZE);

		if (strlen(buffer) == 0)
			printf("Empty name not allowed. Enter a name for monster %d:", i);
		else
			break;
	}
	return Monster(buffer);
}
#pragma once
#include <iostream>
#include <ctime>
//#include <Windows.h>

#define MAP_SIZE 20

#define ROOM 30
#define R_ROOM ROOM/2
#define BOSS 'B'
#define N_ROOM 'r'
#define B_ROOM 'R'
#define SHOP 'C'
#define SECRET 'T'
#define START 'S'

namespace createMap {
	//��ǥ
	class Spot
	{
		friend class Map;
	private:
		int x;
		int y;
	public:
		bool operator ==(const Spot &T) const
		{
			return x == T.x&&y == T.y;
		}
	};

	class Map
	{
	private:
		char **table;//���� ���̺�
		Spot *point;//���� ���� ����
		Spot *bossRoom;
		Spot *rSpot;
		int cnt;//���� ����
		int rCnt;
		void start();//���� ���ۺκ� ����
		bool makeRoom(Spot spot, int mode);
		bool inTableCheck(Spot spot);
		bool roomCheck(Spot spot);
		int bossCnt;

	public:
		Map();
		void make(int floor);
		void show();
		void showSpot();
	};

}
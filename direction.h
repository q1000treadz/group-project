#pragma once
/*
2) база данных направлений Ч название направление,
точка ј (исходна€) в координатах (х, у) и точка Ѕ Ч конечна€ (х, у).
*/
#include"plane.h"
#include<string>
class Direction {
private:
	std::string name;
	int startX;
	int startY;
	int endX;
	int endY;
	tm link_to_plane; //Name of var can be improved
	Plane* plane;
	
public:
	Direction() {

	} //add plane
	Direction(std::string name, int startX, int startY, int endX, int endY) : name(name), startX(startX), startY(startY), endX(endX), endY(endY) {
		
	}
	friend std::ostream& operator<< (std::ostream& out, const Direction& direction)
	{
		return out;
	}

	friend std::istream& operator>> (std::istream& is, Direction& direction)
	{
		is >> direction.name >> direction.startX >> direction.startY >> direction.endX >> direction.endY;
		return is;
	}

	void SetName(std::string s) {
		this->name = s;
	}
	std::string GetName() {
		return this->name;
	}
	void SetStartX(int i) {
		this->startX = i;
	}
	int GetStartX() {
		return this->startX;
	}
	void SetStartY(int i) {
		this->startY = i;
	}
	int GetStartY() {
		return this->startY;
	}
	void SetEndX(int i) {
		this->endX = i;
	}
	int GetEndX() {
		return this->endX;
	}
	void SetEndY(int i) {
		this->endY = i;
	}
	int GetStartX() {
		return this->endY;
	}

	void skipTime(int t) {
		if (plane) {

		}
	}

	~Direction() {

	}
};

class direction_Menu {
private:
	List* begin;
	List* end;
	size_t size;
	List* find(int index);
public:
	//TODO ALL FUNCTIONS
	Menu() {
		begin = NULL;
		end = NULL;
		size = 0;
	}
	Menu(Direction dirc) {
		List* tmp = new List(dirc);
		end = tmp;
		begin = tmp;
		size = 1;
	}

	Menu(List* h) : end(h) {
		List* tmp = new List();
		tmp->info = h->info;
		end = tmp;
		begin = tmp;
		size = 1;
	}
	Direction& operator[](int i) {
		if (i > size) {
			std::cout << "Index out of bounds" << std::endl;
			return end->info;
		}

		List* tmp = begin;
		int j = 0;
		while (j < i) {
			if (tmp->next == NULL) break;
			tmp = tmp->next;
			j++;
		}
		return tmp->info;
	}
	List* findDirectionByName(std::string fname);

	size_t getSize();

	void edit(int index, std::string info, std::string newvalue);

	void pushFront(std::string name int startX int startY int endX int endY;);

	void print();

	void readFile(std::string fileName);

	void printFile(std::string fileName);

	void del(int index);

	void freeList();

	void setPlane();//Prototype have not wrote correctly yet

	void printCurrentPosition();//Prototype have not wrote correctly yet

	void printRemainingTime();//Prototype have not wrote correctly yet
	
	~Menu() {
		freeList();
	}
};
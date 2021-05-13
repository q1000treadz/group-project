#pragma once
/*
1) база данных самолЄтов Ч каждый самолЄт имеет название/пилота/характеристики (сами придумаете пол€)
и пол€ Ђмаксимальна€ дальность полЄтаї, скорость полЄта ;
*/
#include "list.h"
#include<string>

class Plane {
private:
	std::string name;
	std::string pilotname;
	std::string info;
	int maxrange;
	int speed;
public:
	Plane() {

	}
	Plane(std::string name, std::string pilotname, std::string info, int maxrange, int speed) : name(name), pilotname(pilotname), info(info), maxrange(maxrange), speed(speed) {

	}
	friend std::ostream& operator<< (std::ostream& out, const Plane& plane)
	{
		return out;
	}

	friend std::istream& operator>> (std::istream& is, Plane& plane)
	{
		is >> plane.name >> plane.pilotname >> plane.info >> plane.maxrange>> plane.speed;
		return is;
	}
	
	void SetName(std::string s) {
		this->name = s;
	}
	std::string GetName() {
		return this->name;
	}
	void SetPilotname(std::string s) {
		this->pilotname = s;
	}
	std::string GetPilotname() {
		return this->pilotname;
	}

	void SetInfo(std::string s) {
		this->info = s;
	}
	std::string GetInfo() {
		return this->info;
	}
	void SetMaxrange(int i) {
		this->maxrange = i;
	}
	int GetMaxrange() {
		return this->maxrange;
	}
	void SetSpeed(int i) {
		this->speed = i;
	}
	int GetSpeed() {
		return this->speed;
	}
	~Plane() {

	}
};

class plane_Menu {
private:
	List* begin;
	List* end;
	size_t size;
	List* find(int index);
public:
	//TODO ALL FUNCTIONS
	plane_Menu() {
		begin = NULL;
		end = NULL;
		size = 0;
	}
	plane_Menu(Plane pl) {
		List* tmp = new List(pl);
		end = tmp;
		begin = tmp;
		size = 1;
	}

	plane_Menu(List* h) : end(h) {
		List* tmp = new List();
		tmp->info = h->info;
		end = tmp;
		begin = tmp;
		size = 1;
	}
	Plane& operator[](int i) {
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
	List* findPlaneByName(std::string fname);

	size_t getSize();

	void edit(int index, std::string info, std::string newvalue);

	void pushFront(std::string name, std::string pilotname, std::string info, int maxrange, int speed);

	void print();

	void readFile(std::string fileName);

	void printFile(std::string fileName);

	void del(int index);

	void freeList();

	~Menu() {
		freeList();
	}
};
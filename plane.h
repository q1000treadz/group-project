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
#pragma once
/*
1) база данных самолётов — каждый самолёт имеет название/пилота/характеристики (сами придумаете поля)
и поля «максимальная дальность полёта», скорость полёта ;
*/
#include<fstream>
#include<string>
#include <vector>
using namespace std;
class Plane {
private:
	string pilotname;
	string info;
	string name;
	int maxrange;
	int speed;
public:
	Plane() {

	}
	Plane(string name, string pilotname, string info, int maxrange, int speed) : name(name), pilotname(pilotname), info(info), maxrange(maxrange), speed(speed) {

	}
	friend ostream& operator<< (ostream& out, const Plane& plane)
	{
		out<<plane.name<<endl<<plane.pilotname<<endl<<plane.info<<endl<<plane.maxrange<<endl<<plane.speed;
		return out;
	}

	friend istream& operator>> (istream& is, Plane& plane)
	{
		is >> plane.name >> plane.pilotname >> plane.info >> plane.maxrange>> plane.speed;
		return is;
	}
	
	void SetName(string s) {
		this->name = s;
	}
	string GetName() {
		return this->name;
	}
	void SetPilotname(string s) {
		this->pilotname = s;
	}
	string GetPilotname() {
		return this->pilotname;
	}

	void SetInfo(string s) {
		this->info = s;
	}
	string GetInfo() {
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
	size_t size;
	vector<Plane> vec;
public:

	void findPlaneByName(string fname);

	void edit(int index, string info, string newvalue);

	void pushFront(string name, string pilotname, string info, int maxrange, int speed);

	void print();

	void readFile(string fileName);

	void printFile(string fileName);

	void del(int index);
};
#pragma once
#include<fstream>
#include<string>
#include <vector>
#include<iostream>
using namespace std;
class Plane {
private:
	string pilotname;
	string info;
	string name;
	int maxrange;
	int speed;
	bool isDirection;
public:
	Plane() {
		isDirection = 0;
	}
	Plane(string name, string pilotname, string info, int maxrange, int speed) : name(name), pilotname(pilotname), info(info), maxrange(maxrange), speed(speed) {
		isDirection = 0;
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
	int GetState() {
		return this->isDirection;
	}
	void SetState(bool t) {
		this->isDirection = t;
	}
	void print() {
		cout << "Name: " << this->name << endl;
		cout << "Pilot name: " << this->pilotname << endl;
		cout << "Info: " << this->info << endl;
		cout << "Maxrange: " << this->maxrange << endl;
		cout << "Speed: " << this->speed << endl;
		cout << (isDirection ? "Plane have direction" : "Plane doesnt have direction" )<< endl;
	}

	~Plane() {

	}
};

class plane_Menu {
private:
	size_t size;
public:

	vector<Plane> vec;
	void findPlaneByName(string fname);

	void edit(int index, string info, string newvalue);

	void pushFront(string name, string pilotname, string info, int maxrange, int speed);

	void print();

	void readFile(string fileName);

	void printFile(string fileName);

	void del(int index);
};
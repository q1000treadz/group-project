#pragma once
#include"plane.h"
#include<string>
#include<vector>
#include<iostream>
class Direction {
private:
	std::string name;
	int start;
	int end;
	int dist;
	int time;
	int plane;

public:
	Direction() {
		plane = -1;
		time = 0;
		dist = 0;
	}
	Direction(std::string name, int start, int end) : name(name), start(start), end(end) {
		plane = -1;
		time = 0;
		dist = 0;
	}
	friend std::ostream& operator<< (std::ostream& out, const Direction& direction)
	{
		out << direction.name << endl << direction.start << endl << direction.end << endl << direction.dist << endl << direction.time;

		return out;
	}

	friend std::istream& operator>> (std::istream& is, Direction& direction)
	{
		is >> direction.name >> direction.start >> direction.end;
		return is;
	}

	void SetName(std::string s) {
		this->name = s;
	}
	std::string GetName() {
		return this->name;
	}
	void SetStart(int i) {
		this->start = i;
	}
	int GetStart() {
		return this->start;
	}
	void SetEnd(int i) {
		this->end = i;
	}
	int GetEnd() {
		return this->end;
	}
	void SetPlane(int id) {
		this->plane = id;
	}
	int GetPlane() {
		return this->plane;
	}
	void skipTime(std::vector<Plane> pl, int t) {
		if (plane!=-1) {
			this->dist = (this->time+t)*pl[plane].GetSpeed();
			this->time += t;
		}
	}
	bool checkEnd() {
		return (this->end - this->start) <= dist;
	}
	void print() {
		cout << "Name: " << this->name << endl;
		cout << "Start coord: " << this->start << endl;
		cout << "End coord: " << this->end << endl;
		cout << "Distance: " << this->dist << endl;
		cout << "Time: " << this->time << endl;
		cout << "Plane ID: " << this->plane << endl;
	}
	~Direction() {

	}
};

class direction_Menu {
private:
public:

	vector<Direction> vec;

	void findDirectionByName(string fname);

	void editName(int index, string name);

	void pushFront(string name, int start, int end);

	void print();

	void readFile(string fileName);

	void printFile(string fileName);

	void del(int index);


	size_t size() {
		return vec.size();
	}
};

class direction_Menu {
private:
public:

	vector<Direction> vec;
	//TODO ALL FUNCTIONS

	Plane findPlaneByName(string fname);

	void edit(int index, string info, string newvalue);

	void pushFront(string name, int start, int end);

	void print();

	void readFile(string fileName);

	void printFile(string fileName);

	void del(int index);


	size_t size() {
		return vec.size();
	}
};

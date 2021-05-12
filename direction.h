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
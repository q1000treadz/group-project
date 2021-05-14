	
#include"plane.h"

int findPlaneByName(string fname){}

void edit(int index, string info, string newvalue,vector<plane>& vec)
{
	try
	{
		vec.at(index);
	}
	catch(const std::out_of_range & ex)
	{
		cout<<ex.what()<<endl<<endl;
		return;
	}
	if (info == "name")
	{
		vec[index].SetName(newvalue);
	}
	else if (info == "pilotname")
	{
		vec[index].SetPilotname(newvalue);
	}
	else if (info == "info")
	{
		vec[index].SetInfo(newvalue);
	}
	else if (info == "maxrange")
	{
		int newMaxrange = stoi(newvalue);
		vec[index].SetMaxrange(newMaxrange);
	}
	else if (info == "speed")
	{
		int newSpeed = stoi(newvalue);
		vec[index].SetSpeed(newSpeed);
	}
	else
	{
		cout << "can't find info string: " << info << '\n';
		return;
	}
}

void pushFront(string name, string pilotname, string info, int maxrange, int speed, vector<plane>& vec)
{
	vec.pushFront(plane(name,pilotname,info,maxrange,speed));
}
void print()
{

}

void readFile(string fileName){}

void printFile(string fileName){}

void del(int index){}

void freeList(){}

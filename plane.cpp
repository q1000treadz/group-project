	
#include"plane.h"
#include <iostream>
#include <vector>
#include <string>

void plane_Menu::findPlaneByName(string fname)
{
	int flag=0;
	Plane finded;
		for(int i = 0;i<vec.size();i++)
		{
			string check = vec[i].GetName();

			if (check == fname)
			{
				flag = 1;
				finded = vec[i];
			}
		}
	if(!flag)
	{
		cout<<"Plane have not been found"<<endl;
		return;
	}
	cout << "Name of plane: " <<finded.GetName()<< endl;
	cout << "Pilot name of plane: " << finded.GetPilotname()<< endl;
	cout << "Info of plane: " << finded.GetInfo()<< endl;
	printf("maxrange of finded plane:  %d\n", finded.GetMaxrange());
	printf("speed of finded plane:  %d\n", finded.GetSpeed());
}

void  plane_Menu::edit(int index, string info, string newvalue)
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

void  plane_Menu::pushFront(string name, string pilotname, string info, int maxrange, int speed)
{
	vec.push_back(Plane(name,pilotname,info,maxrange,speed));
}
void  plane_Menu::readFile(string fileName)
{
	ifstream in(fileName);
	string n,p,i,m,s;
	if (in.is_open())
	{
		while (1)
		{
			if (getline(in, n) && getline(in, p) && getline(in, i) && getline(in, m) && getline(in, s))
			{
				int max_range = stoi(m);
				int speed = stoi(s);
				vec.push_back(Plane(n,p,i, max_range, speed));
			}
			else
			{
				break;
			}
		}
		in.close();
	}
	else
	{
		std::cout << "Can't open file " << fileName << '\n';
	}
}
void plane_Menu::print()
{
	for (int i = 0;i < vec.size(); i++)
	{
		cout << "Plane: " << i << '\n';
		vec[i].print();
	}
}

void  plane_Menu::printFile(string fileName)
{
	ofstream out(fileName);
	if (out.is_open())
	{
		for (int i = 0; i < vec.size(); i++)
		{
			out << vec[i].GetName() << '\n' << vec[i].GetPilotname() << '\n' << vec[i].GetInfo() << '\n' << vec[i].GetMaxrange() << '\n'<< vec[i].GetSpeed() << '\n';
		}
	}
	else
	{
		cout << "Can't open file " << fileName << '\n';
	}
	out.close();
}

void  plane_Menu::del(int index)
{
	if (index < vec.size())
	vec.erase(vec.begin() + index);
}

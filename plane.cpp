	
#include"plane.h"
#include <iostream>
#include <vector>
#include <string>

Plane plane_Menu::findPlaneByName(string fname)
{
	int index=-1;
	Plane finded;
		for(int i = 0;i<vec.size();i++)
		{
			string check = &(vec[i].GetName);

			if(check == fname)
				finded = vec[i];
		}
	if(index==-1)
	{
		cout<<"Plane have not been found"<<endl;
	}
	return finded;
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
void  plane_Menu::print()
{
	int i = 0;
	while (vec.size()<i) {
		cout << "Plane" << i << '\n';
		cout << vec[i];
		i++;
	}
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
/*
void  plane_Menu::printFile(string fileName)
{
	std::ofstream out(fileName);
	if (out.is_open())
	{
		List* tmp = begin;
		int i = 1;
		while (tmp != NULL) {
			out << tmp->info.GetSender() << '\n' << tmp->info.GetReceiver() << '\n' << tmp->info.GetTitle() << '\n' << tmp->info.GetMessage() << '\n';
			tmp = tmp->next;
			i++;
		}
	}
	else {
		std::cout << "Can't open file " << fileName << '\n';
	}
	out.close();
}
*/
void  plane_Menu::del(int index)
{
	vec.erase(vec.begin() + index);
}


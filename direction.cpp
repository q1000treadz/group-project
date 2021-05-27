#include"direction.h"
/*
void direction_Menu::findPlaneByName(string fname)
{
	int flag = 0;
	Plane finded;
	for (int i = 0; i < vec.size(); i++)
	{
		string check = vec[i].GetName();

		if (check == fname)
		{
			flag = 1;
			finded = vec[i];
		}
	}
	if (!flag)
	{
		cout << "Plane have not been found" << endl;
		return;
	}
	cout << "Name of plane: " << finded.GetName() << endl;
	cout << "Pilot name of plane: " << finded.GetPilotname() << endl;
	cout << "Info of plane: " << finded.GetInfo() << endl;
	printf("maxrange of finded plane:  %d\n", finded.GetMaxrange());
	printf("speed of finded plane:  %d\n", finded.GetSpeed());
}

void  direction_Menu::edit(int index, string info, string newvalue)
{
	try
	{
		vec.at(index);
	}
	catch (const std::out_of_range & ex)
	{
		cout << ex.what() << endl << endl;
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
*/
void  direction_Menu::pushFront(string name, int start, int end) 
{
	vec.push_back(Direction(name, start, end));
}

void  direction_Menu::readFile(string fileName)
{
	ifstream in(fileName);
	string n, s,e;
	if (in.is_open())
	{
		while (1)
		{
			if (getline(in, n) && getline(in, s) && getline(in, e))
			{
				int start = stoi(s);
				int end = stoi(e);
				vec.push_back(Direction(n, start, end));
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

void direction_Menu::print()
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << "Direction: " << i << '\n';
		cout << vec[i] << endl;
	}
}

void  direction_Menu::printFile(string fileName)
{
	ofstream out(fileName);
	if (out.is_open())
	{
		for (int i = 0; i < vec.size(); i++)
		{
			out << vec[i].GetName() << '\n' << vec[i].GetStart() << '\n' << vec[i].GetEnd() << '\n';
		}
	}
	else
	{
		cout << "Can't open file " << fileName << '\n';
	}
	out.close();
}

void  direction_Menu::del(int index)
{
	vec.erase(vec.begin() + index);
}


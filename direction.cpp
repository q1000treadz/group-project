#include"direction.h"

void direction_Menu::findDirectionByName(string fname)
{
	int flag = 0;
	Direction finded;
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
		cout << "Direction have not been found" << endl;
		return;
	}
	finded.print();
}

void direction_Menu::editName(int index, string name)
{
	try
	{
		this->vec.at(index);
	}
	catch (const std::out_of_range & ex)
	{
		cout << ex.what() << endl << endl;
		return;
	}
	vec[index].SetName(name);
}

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
		vec[i].print();
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
	if(index<vec.size())
	vec.erase(vec.begin() + index);
}

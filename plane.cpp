	
#include"plane.h"

int findPlaneByName(string fname)
{
	int index=-1;
	for(int i = 0;i<vec.size();i++)
	{
		if(vec[i].GetName == fname)
			index = i;
	}
	if(index==-1)
	{
		cout<<"Plane have not been found"<<endl;
	}
	return index;
}

void edit(int index, string info, string newvalue)
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

void pushFront(string name, string pilotname, string info, int maxrange, int speed)
{
	vec.pushFront(plane(name,pilotname,info,maxrange,speed));
}
void print(vector<plane>& vec)
{
	int i = 0;
	while (vec.size()<i) {
		cout << "Plane" << i << '\n';
		cout << vec[i];
		i++;
	}
}

void readFile(string fileName)
{
	ifstream in(fileName);
	string n,p,i,m,s;
	index;
	if (in.is_open())
	{
		while (index)
		{
			if (std::getline(in, n) && std::getline(in, r) && std::getline(in, t) && std::getline(in, m)) 
			{
				stoi(m);
				stoi(s);
				vec.pushFront(Plane(n,p,i,m,s));
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
void printFile(string fileName)
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
void del(int index)
{
	vec.erase(vec.begin() + index);
}


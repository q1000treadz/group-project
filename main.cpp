#include "plane.h";
#include <iostream>
using namespace std;

int main(int argc, int argv[])
{
	if (argc < 2) 
	{
		std::cout << "No arguments\n";
		return 1;
	}
	string fileName = argv[1];
	plane_Menu plane_menu;
	plane_menu.readFile(fileName);
	int choose = -1;
	while (choose != 8) {

		printf("1)findPlaneByName\n2)print\n3)pushFront\n4)edit\n5)del\n");
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			string fname;
			cout<<"Enter name of the plane";
			cin>>fname;
			cout<<plane_menu.vec[findPlaneByName(fname)]<<endl;
		}
			break;
		case 2:
			menu.print();
			break;
		case 3:
		{
			string name,pilotName,info;
			int maxrange,speed;
			cout<<"name"<<endl;
			cin>>name;
			cout<<"pilotname"<<endl
			cin>>pilotname;
			cout<<"info"<<endl
			cin>>info;
			cout<<"maxrange"<<endl
			cin>>maxrange;
			cout<<"speed"<<endl
			cin>>speed;
			plane_menu.pushFront(name,pilotName,info,maxrange,speed;)
		}
			break;
		case 4:
		{
			int index;
			string editname;
			string value;
			cin >> index;
			printf("Enter edit line: name, pilotName, info, maxrange, speed: ");
			cin >> editname;
			printf("Enter value: ");
			cin >> value;
			menu.edit(index, editname, value);
			//menu.printFile(fileName);
		}
			break;
		case 5:
		{
			int index;
			cout<<"Del index:"<<endl;
			cin>>index;
			plane_menu.del(index);
		}
		default:
			break;
		}
	return 0;
}
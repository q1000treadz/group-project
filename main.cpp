#include "plane.h";
#include"direction.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	if (argc < 3) // Correct it to release, argc<2 -> argc<3
	{
		std::cout << "No arguments\n";
		return 1;
	}
	string fileName_plane = argv[1]; // Correct it to release, argv[1] -> argv[2]
	string fileName_direction = argv[2];
	plane_Menu plane_menu;
	direction_Menu direction_menu;
	plane_menu.readFile(fileName_plane);
	direction_menu.readFile(fileName_direction);
	int choose;
	while (1)
	{
l1:
		printf("1)Work with plane's database\n2)Work with direction's database\n3) Connect plane with direction\n4)Skip time\n 5)exit \n");
		cin >> choose;
		switch (choose) 
		{
			case 1:
			{
				printf("1)findPlaneByName\n2)print\n3)pushFront\n4)edit\n5)del \n");
				cin >> choose;
				switch (choose)
				{

				case 1:
				{
					string fname;
					cout << "Enter name of the plane"<<endl;
					cin >> fname;
					plane_menu.findPlaneByName(fname);
				}
				break;
				case 2:
					plane_menu.print();
					break;
				case 3:
				{
					string name, pilotName, info;
					int maxrange, speed;
					cout << "name" << endl;
					cin >> name;
					cout << "pilotname" << endl;
					cin >> pilotName;
					cout << "info" << endl;
					cin >> info;
					cout << "maxrange" << endl;
					cin >> maxrange;
					cout << "speed" << endl;
					cin >> speed;
					plane_menu.pushFront(name, pilotName, info, maxrange, speed);
				}
				break;
				case 4:
				{
					int index;
					string editname;
					string value;
					cin >> index;
					printf("Enter edit line: name, pilotname, info, maxrange, speed: ");
					cin >> editname;
					printf("Enter value: ");
					cin >> value;
					plane_menu.edit(index, editname, value);
				}
				break;
				case 5:
				{
					int index;
					cout << "Del index:" << endl;
					cin >> index;
					plane_menu.del(index);
				}
				default:
					break;
				}
				goto l1;
			}
			case 2:
			{
				printf("1)\n2)print\n3)pushFront\n4)edit\n5)del \n");
				cin >> choose;
				switch (choose)
				{

				case 1:
				{
					/*
					string fname;
					cout << "Enter name of the plane"<<endl;
					cin >> fname;
					plane_menu.findPlaneByName(fname);*/
				}
				break;
				case 2:
					direction_menu.print();
					break;
				case 3:
				{
					string name;
					int start, end;
					cout << "name" << endl;
					cin >> name;
					cout << "start" << endl;
					cin >> start;
					cout << "end" << endl;
					cin >> end;
					direction_menu.pushFront(name, start, end);
				}
				break;
				case 4:
				{
					/*
					int index;
					string editname;
					string value;
					cin >> index;
					printf("Enter edit line: name, pilotname, info, maxrange, speed: ");
					cin >> editname;
					printf("Enter value: ");
					cin >> value;
					plane_menu.edit(index, editname, value); */
				}
				break;
				case 5:
				{
					/*
					int index;
					cout << "Del index:" << endl;
					cin >> index;
					plane_menu.del(index); */
				}
				default:
					break;
				}
				goto l1;
			}
			case 3:
			{
				plane_menu.print();
				int Pind;
				cout << "Choose plane: " << endl;
				cin >> Pind;
				direction_menu.print();
				int Dind;
				cout << "Choose direction: " << endl;
				cin >> Dind;
				direction_menu.vec[Dind].setPlane(Pind);
				break;
			}
			case 4:
			{
				int tm;
				cout << "Enter time " << endl;
				cin >> tm;
				for (int i = 0; i<direction_menu.vec.size(); i++) {
					direction_menu.vec[i].skipTime(plane_menu.vec,tm);
					bool res = direction_menu.vec[i].checkEnd();
					if (res) {
						cout << "direction " << direction_menu.vec[i].GetName() << " complete" << endl;
						direction_menu.del(i);
						i--;
						
					}
				}
				break;
			}
			case 5:
			{
				plane_menu.printFile(fileName_plane);
				direction_menu.printFile(fileName_direction);
				return 0;
			}
		}
	}
	return 1;
}
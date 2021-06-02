#include "plane.h"
#include"direction.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	if (argc < 3) 
	{
		std::cout << "No arguments\n";
		return 1;
	}
	string fileName_plane = argv[1]; 
	string fileName_direction = argv[2];
	plane_Menu plane_menu;
	direction_Menu direction_menu;
	plane_menu.readFile(fileName_plane);
	direction_menu.readFile(fileName_direction);
	int choose;
	while (1)
	{
l1:
		printf("==========MAIN MENU==========\n");
		printf("=============================\n");
		printf("1) Work with plane's database\n2) Work with direction's database\n3) Connect plane with direction\n4) Skip time\n5) exit \n");
		cin >> choose;
		switch (choose) 
		{
			case 1:
			{
				printf("1)FindPlaneByName\n2)print\n3)pushFront\n4)edit\n5)del \n");
				cin >> choose;
				switch (choose)
				{

				case 1:
				{
					string fname;
					cout << "Enter name of the plane"<<endl;
					cin >> fname;
					plane_menu.findPlaneByName(fname);
					break;
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
				printf("1)FindDirectionByName\n2)print\n3)pushFront\n4)edit\n5)del \n");
				cin >> choose;
				switch (choose)
				{

				case 1:
				{
					
					string fname;
					cout << "Enter name of the direction"<<endl;
					cin >> fname;
					direction_menu.findDirectionByName(fname);
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
					
					break;
				}
				case 4:
				{
					
					int index;
					string name;
					cout << "Enter index:" << endl;
					cin >> index;
					printf("Enter name: ");
					cin >> name;
					direction_menu.editName(index, name);
				}
				break;
				case 5:
				{
					
					int index;
					cout << "Del index:" << endl;
					cin >> index;
					direction_menu.del(index);
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
				if ((Dind >= 0 && Dind < direction_menu.vec.size()) || (Pind >= 0 && Pind < plane_menu.vec.size())) {
					if (abs(direction_menu.vec[Dind].GetEnd() - direction_menu.vec[Dind].GetStart()) > plane_menu.vec[Pind].GetMaxrange()) {
						cout << "This plane cant flight this long distance" << endl;
					}
					else {
						if (plane_menu.vec[Pind].GetState() == 0) {
							direction_menu.vec[Dind].SetPlane(Pind);
							plane_menu.vec[Pind].SetState(1);
						}
						else {
							cout << "Plane already on flight" << endl;
						}
					}
				}
				else {
					cout << "Wrong index" << endl;
				}
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
						plane_menu.vec[direction_menu.vec[i].GetPlane()].SetState(0);
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
				break;
			}
		}
	}
	return 1;
}
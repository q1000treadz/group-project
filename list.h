/*
Планировщик полётов самолётов:
1) база данных самолётов — каждый самолёт имеет название/пилота/характеристики (сами придумаете поля)
и поля «максимальная дальность полёта», скорость полёта ;
2) база данных направлений — название направление,
точка А (исходная) в координатах (х, у) и точка Б — конечная (х, у).
Программа должна уметь: добавлять\удалять\выводить на экран\искать самолёты и направления,
отправлять самолёт на вылет по какому-то направлению. Добавить функцию «прошло N часов»,
которая будет пересчитывать местоположение самолёта (сколько ему ещё часов осталось лететь от A до Б и текущую координату)
*/

template <class T>
class List {
public:
	T info;
	List* next;
	List* prev;
	List() {
		next = NULL;
		prev = NULL;
	}
	List(T inf) : info(inf) {
		next = NULL;
		prev = NULL;
	}

	List(const List& copy) :
		info(copy.info), next(copy.next), prev(copy.prev)
	{

	}

	List& operator= (const List& drob)
	{
		info = drob.info;
		next = drob.next;
		prev = drob.prev;
		return *this;
	}

	~List() {

	}
};

template <class T>
class Menu {
private:
	List* begin;
	List* end;
	size_t size;
	List* find(int index);
public:
	//TODO ALL FUNCTIONS
	Menu() {
		begin = NULL;
		end = NULL;
		size = 0;
	}
	Menu(Mail ml) {
		List* tmp = new List(ml);
		end = tmp;
		begin = tmp;
		size = 1;
	}

	Menu(List* h) : end(h) {
		List* tmp = new List();
		tmp->info = h->info;
		end = tmp;
		begin = tmp;
		size = 1;
	}
	/*
	List& operator[](int i) {
		if (i > size) {
			std::cout << "Index out of bounds" << std::endl;
			return *head;
		}

		List* tmp = head;
		int j = 0;
		while (j < i) {
			if (tmp->next == NULL) break;
			tmp = tmp->next;
			j++;
		}
		return *tmp;
	}*/


	Mail& operator[](int i) {
		if (i > size) {
			std::cout << "Index out of bounds" << std::endl;
			return end->info;
		}

		List* tmp = begin;
		int j = 0;
		while (j < i) {
			if (tmp->next == NULL) break;
			tmp = tmp->next;
			j++;
		}
		return tmp->info;
	}
	List* findMessageByTitle(std::string ftitle);

	size_t getSize();

	void edit(int index, std::string info, std::string newvalue);

	void pushFront(std::string sender, std::string receiver, std::string title, std::string message);

	void print();

	void readFile(std::string fileName);

	void printFile(std::string fileName);

	void del(int index);

	void freeList();

	~Menu() {
		freeList();
	}
};
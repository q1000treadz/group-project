

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


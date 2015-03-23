/** @file Queue.cpp */
#include <iostream>
using namespace std;

//! Class Queue.
/*!
Opisanie classa.
*/
class Queue
{
private:
	int *arr;  /*!< Massiv-bufer */
	int bufferSize; /*!< Razmer bufera */
	int length; /*!< Dlina ocheredi */
	int tail; /*!< Konec ocheredi */
	int head; /*!< Nachalo ocheredi */
public:
	//! Constructor.
	/*!
	Opisanie konstruktora.
	*/
	Queue(int size)
	{
		head = tail = length = 0;        
		bufferSize = size; /// Sozdanie bufera zadannogo razmera 
		arr = new int[bufferSize];
		for (int i = 0; i < bufferSize; ++i) /// Zapolnenie bufera nuljami
			arr[i] = 0;
	}
	//! Destructor.
	
	~Queue()
	{
		delete[] arr;
	}
	//! Funkcija dobavleniya jelementa.
	/*!
	\param value - znachenie jelementa 
	\return 0 - esli spisok polon
	*/
	void put(int value)
	{

		if (length == bufferSize) /// Proverka na polnotu
		{
			cout << "Очередь полна.\n";
			return;
		}
		if (tail == bufferSize) tail = 0; /// Zaciklivanie bufera                    
		arr[tail] = value; /// Dobavlenie jelementa
		++tail;
		++length;
	}
	//! Funkcija udaleniya jelementa.	
	void get()
	{
		if (length == 0) /// Proverka na pustotu
		{
			cout << "Очередь пуста.\n";
			return;
		}
		if (head == bufferSize) head = 0; /// Zaciklivanie bufera        
		arr[head] = 0; // Obnulenie jelementa 
		++head;
		--length;
	}
	//! Funkcija pechati.
	void printQueue() const
	{
		int i;
		cout << "Элементы очереди: ";
		if (length == 0) /// Proverka na pustotu
			cout << "Очередь пуста";
		else if (tail > head) /// Esli jelementy v bufere idut po porjadku
		{
			for (i = head; i < tail; ++i)
				cout << arr[i] << ' ';
		}
		else /// Esli bufer uzhe zaciklen
		{
			for (i = head; i < bufferSize; ++i) /// Vyvod chasti "golovy" 
				cout << arr[i] << ' ';
			for (i = 0; i < tail; ++i) /// Vyvod chasti do "hvosta" 
				cout << arr[i] << ' ';
		}
		cout << endl;
	}
};
//! Glavnaja funkcija.
int main()
{
	setlocale(LC_ALL, "RUS");	
	int value, x, n, k;
	cout << "Введите размер очереди: "; /// Vvod razmera ocheredi
	cin >> n;
	cout << "Введите кол-во операций: "; /// Vvod kolichestva operacij s ochered'ju
	cin >> k;
	Queue *p = new Queue(n);
	cout << endl;
	for (int i = 0; i < k; i++) /// Cikl dejstvij s ochered'ju:	
	{
		cout << "1. Добавить" << endl; 
		cout << "2. Удалить" << endl; 
		cout << "\nНомер операции > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; cin >> value;
			cout << endl;
			p->put(value); break;
		case 2:
			p->get(); break;
			cout << endl << endl;
		}
	}
	p->printQueue(); /// Pechat' ocheredi
	system("pause");
	return 0;
}
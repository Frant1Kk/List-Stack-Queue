/** @file List.cpp */
#include <iostream>
using namespace std;

//! Struktura LIST.
/*!
Opisanie struktury.
*/
struct LIST
{
	int data; /*!< Informacionnoe pole */
	LIST *pNext; /*!< Ukazatel'  */
};
LIST *pHead; //! Ukazatel' na pervyj jelement 

//! Funkcija dobavleniya jelementa.
/*!
\param value - znachenie jelementa 
\param position - pozicija jelementa 
*/
void AddLIST(int value, int position)
{
	LIST *pNov = new LIST;   
	pNov->data = value; /// Prisvoenie znachenija
	if (position <= 1 || pHead == NULL) /// Esli spisok pust:
	{
		pNov->pNext = pHead; /// - Ustanovka ukazatelja pNext
		pHead = pNov; /// - Opredelenie "golovy" spiska
	}
	else /// Esli spisok ne pust:
	{
		/// - Dobavlenie jelementa
		LIST *pA = pHead;
		for (int i = 1; i < position - 1; i++)
		{
			if (pA->pNext != NULL)
				pA = pA->pNext;
		}
		pNov->pNext = pA->pNext;
		pA->pNext = pNov;
	}
	cout << "\nЭлемент добавлен в список...\n\n";
}
//! Funkcija udaleniya jelementa. 
/*!
\param position - pozicija jelementa
\return 0 - esli spisok pust
*/
int DeleteLIST(int position)
{
	if (pHead == NULL) { cout << "\nНевозможно удалить, список пуст.\n\n"; return 0; } /// Proverka spiska na pustotu 
	LIST *pA = pHead, *pB;
	int i = 0;
	while (pA != NULL)
	{
		pA = pA->pNext;
		i++;
	}
	if (position > i || position < 1) /// Proverka na suschestvovanie pozicii 
	{
		cout << endl << "Такой позиции в списке нет." << endl << endl;
	}
	else /// Udalenie jelementa:
	{
		if (position == 1) /// - Esli jeto pervyj jelement:
		{
			pA = pHead->pNext; /// 1) Sdvig ukazatelja
			pHead = pA; /// 2) Sdvig "golovy" spiska 
		}
		if (position > 1) /// - Esli ne pervyj jelement:
		{
			i = 1;
			pA = pHead;
			while (i != position - 1)
			{
				i++;
				pA = pA->pNext; /// 1) Nastrojka ukazatelja na jelement, kotoryj stoit pered udaljaemym 
			}
			pB = pA->pNext; /// 2) Nastojka ukazatelja na udaljaemyj jelement 
			pA->pNext = pB->pNext; /// 3) Najstrojka ukazatelja na jelement, kotoryj stoit posle udaljaemogo
			delete pB; /// 4) Udalenie jeementa
		}
		cout << "\nЭлемент удален ...\n\n";
	}
}
//! Funkcija pechati spiska.
void PrintLIST()
{
	if (pHead == NULL) cout << "Список пуст.\n";
	else
	{
		LIST *pA = pHead;
		cout << "Элементы списка: ";
		while (pA != NULL)
		{
			cout << pA->data << " -> ";
			pA = pA->pNext;
		}
		cout << "\b\b\b  \n";
	}
}
//! Glavnaja funkcija.
int main()
{
	setlocale(LC_ALL, "RUS");
	int value, position, x, N;
	cout << "Введите кол-во операций со списком: "; /// Vvod kolichestva dejstvij so spiskom
	cin >> N;
	cout << endl;
	for (int i = 0; i < N; i++)	/// Cikl dejstvij so spiskom:
	{
		cout << "1. Добавить" << endl; 
		cout << "2. Удалить" << endl; 
		cout << "\nНомер операции > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Значение > "; cin >> value;
			cout << "Позиция > "; cin >> position;
			AddLIST(value, position); break;
		case 2:
			cout << "Позиция > "; cin >> position;
			DeleteLIST(position); break;
		}
	}
	PrintLIST(); /// Pechat' spiska
	system("pause");
}
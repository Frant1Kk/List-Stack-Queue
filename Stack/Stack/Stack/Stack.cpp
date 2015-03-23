/** @file Stack.cpp */
#include <iostream>
using namespace std;

//! Struktura STACK.
/*!
Opisanie struktury.
*/
struct STACK
{
	int value; /*!< Informacionnoe pole */
	STACK *pNext; /*!< Ukazatel' na sledujushhij jelement */
};
//! Funkcija opredeleniya pustoty steka.

int EmptySTACK(STACK **pHead)
{
	return *pHead == NULL;
}
//! Funkcija dobavleniya jelementa.
/*!
\param **pHead - dvojnoj ukazatel' na "golovu" steka
\param value - nekotoroe znachenie jelementa steka
*/
void AddSTACK(STACK **pHead, int value)
{
	STACK *pNov = new STACK; /// Sozdanie novogo jelementa     
	pNov->value = value; /// Prisvoenie jelementu znachenija    
	pNov->pNext = NULL; /// Formirovanie adresnoj chasti     
	if (!EmptySTACK(pHead)) /// Esli stek ne pust, to vershina dolzhna ukazyvat' na predydushhij jelement
		pNov->pNext = *pHead;
	(*pHead) = pNov; /// Dobavlenie jelementa
	cout << "\n������� �������� � ����...\n\n";
}
//! Funkcija udaleniya jelementa. 
/*!
\param **pHead - dvojnoj ukazatel' na "golovu" steka
*/
void DeleteSTACK(STACK **pHead)
{
	STACK *pNov;
	if (EmptySTACK(pHead)) cout << "\n������� ������, ���� ����.\n" << endl; /// Proverka na pustotu     
	if (!EmptySTACK(pHead)) /// Esli stek ne pust:
	{
		pNov = *pHead; 
		*pHead = (*pHead)->pNext;
		delete pNov; /// - Udalenie jelementa       
		pNov = NULL;
		cout << "\n������� ������...\n\n";
	}
}
//! Funkcija pechataeti.
/*!
\param **pHead - dvojnoj ukazatel' na "golovu" steka
*/
void PrintSTACK(STACK **pHead)
{
	STACK *pNode;
	if (EmptySTACK(pHead)) cout << "���� ����." << endl;
	else
	{
		cout << "�������� �����: ";
		for (pNode = *pHead; pNode != NULL; pNode = pNode->pNext)
			cout << pNode->value << " -> ";
		cout << "\b\b\b   \n";
	}
}
//! Glavnaja funkcija.
int main()
{
	STACK *s = NULL;
	setlocale(LC_ALL, "RUS");
	int value, position, x, n;
	cout << "������� ���-�� ��������: "; /// Vvod kolichestva dejstvij so stekom
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++)	/// Cikl dejstvij so stekom:
	{
		cout << "1. ��������" << endl; 
		cout << "2. �������" << endl; 
		cout << "\n����� �������� > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "�������� > "; cin >> value;
			AddSTACK(&s, value); break;
		case 2:
			DeleteSTACK(&s); break;
		}
	}
	PrintSTACK(&s); /// Pechat' steka
	system("pause");
}
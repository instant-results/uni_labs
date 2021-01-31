#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


/*
Napisz funkcję otrzymującą jako argumenty wskaźniki do dwóch zmiennych typu int, która zamienia ze sobą wartości wskazywanych zmiennych tylko wtedy, gdy wskazywana przez drugi argument zmienna jest mniejsza od zmiennej wskazywanej przez pierwszy argument.
*/
void zadanie1(int *var1, int *var2){
	cout << "\n\nCzy " << *var1 << " jest większe od " << *var2<<" ?\n";
	if (*var1 > *var2) {
		cout << "Tak, więc dokonujemy podmiany:";
		int temp = *var1;
		*var1 = *var2;
		*var2 = temp;
		
	}
	else cout << "Nie.";
}

/*
Napisz funkcję otrzymującą jako argumenty referencje do dwóch zmiennych typu int, która zamienia ze sobą wartości zmiennych, do których referencje dostaliśmy w argumentach.
*/
void zadanie2(int &var1, int &var2){
	//cout <<"var1 = "<< *var1 << "\nvar2 = " << *var2;
	int temp;
	temp = var1;
	var1 = var2;
	var2 = temp;
}

/*
Napisz funkcję otrzymującą dwa argumenty referencję a oraz wskaźnik b do zmiennych typu int, która zamienia ze sobą wartości zmiennych, do których wskaźnik i referencję dostała w argumentach.
*/
void zadanie3(int& a, int* b) {
	int temp = a;
	a = *b;
	*b = temp;
}

/*
Napisz funkcję, która pobiera dwa argumenty i zwraca dwa odrębne wyniki. Jednym z wyników powinien być iloczyn obu argumentów, a drugim ich suma. Ponieważ funkcja może bezpośrednio zwracać tylko jedną wartość, druga powinna być zwracana poprzez parametr wskaźnikowy albo referencję.
*/
int zadanie4(int a, int &b) {
	int sum = a + b;
	b *= a;
	return sum;
}

/*
Napisz funkcję, która zamienia miejscami wartości swoich dwóch argumentów. Przekaż do funkcji argumenty przy użyciu wskaźników albo referencji. Przygotuj odpowiednie testy dla zaproponowanego rozwiązania.
*/

//wydaje się, że poprzednie zadania są spełnieniem tego założenia
void zadanie5(int& a, int* b) {
	int temp = a;
	a = *b;
	*b = temp;
}

/*
swap
*/
template <class T> void zadanie6(T **a, T **b)
{	
	T *c = *a;
	*a = *b;
	*b = c;
}

int main(){

	int choice = -1;
	do {
		cout << "\n\nWybierz zadanie od 1 do 6, lub 0 aby wyjść\n";
		cin >> choice;
		if (!choice) return 0;

		int a, b;
		cout << "Wprowadź a oraz b:\n";
		cin >> a >> b;

switch(choice){
		
	case 1:
	{
		cout << "\nZadanie1:\n";
		int a1 = a;
		int b1 = b;
		int* var1 = &a1;
		int* var2 = &b1;
		cout << "\nWartości przed wykonaniem funkcji:\nvar1 = " << *var1 << " var2 = " << *var2;
		zadanie1(var1, var2);
		cout << "\nWartości po wykonaniu funkcji:\nvar1 = " << *var1 << " var2 = " << *var2;
	}break;

	case 2:
	{
		cout << "\nZadanie2:\n";
		int a2 = a;
		int b2 = b;
		cout << "a = " << a2 << " b = " << b2;
		zadanie2(a2, b2);
		cout << "\npo wykonaniu funkcji 2:\na = " << a2 << " b = " << b2;
	}break;

	case 3:
	{
		cout << "\nZadanie 3:\n";
		int a3 = a;
		int holdb3 = b;
		int* b3 = &holdb3;
		cout << "a = " << a3 << " b = " << *b3;
		zadanie3(a3, b3);
		cout << "\npo wykonaniu funkcji 3:\na = " << a3 << " b = " << *b3;
	}break;

	case 4:
	{
		cout << "\nZadanie 4:\n";
		int a4 = a;
		int b4 = b;
		cout << "a = " << a4 << " b = " << b4;
		cout << "\nSuma a oraz b = " << zadanie4(a4, b4) << "\niloczyn a oraz b = " << b4;
	}break;

	case 5:
	{
		cout << "\nZadanie 5:\n";
		int a5 = a;
		int holdb5 = b;
		int* b5 = &holdb5;
		cout << "a = " << a5 << " b = " << *b5;
		zadanie5(a5, b5);
		cout << "\npo wykonaniu funkcji 5:\na = " << a5 << " b = " << *b5;
	}break;

	case 6:
	{
		cout << "\nZadanie 6:\nFunkcja swap\n";
		int *a6 = &a;
		int *b6 = &b;
		cout << "a = " << *a6 << " b = " << *b6;
		zadanie6(&a6, &b6);
		cout << "\npo wykonaniu funkcji 6:\na = " << *a6 << " b = " << *b6;
	}
	}
	} while (choice);

	return 0;
}
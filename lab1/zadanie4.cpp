#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Tester par liczb skojarzonych\n";
    cout << "Proszę wprowadzić pierwszą liczbę całkowitą, większą od 1\n";
    int num1, num2;
    cin >> num1;
    cout << "Proszę wprowadzić drugą liczbę całkowitą, większą od 1\n";
    cin >> num2;

    cout<<"Dzielniki pierwszej liczby:\n";

    int div1_sum = 0, div2_sum = 0;
    for (int i = 1; i < (num1 / 2)+1; i++) {
        if (num1 % i == 0) {
            div1_sum += i;
            cout << i << " ";
        }
    }
    cout << "Ich suma = " << div1_sum;

    cout << "\n\nDzielniki drugiej liczby:\n";
    for (int i = 1; i < (num2 / 2)+ 1; i++) {
        if (num2 % i == 0) {
            div2_sum += i;
            cout << i << " ";
        }
    }
    cout << "Ich suma = " << div2_sum;

    if (div2_sum - 1 == num1 && div1_sum - 1 == num2) {
        cout << "\nLiczby te są skojarzone";
    }
    else cout << "\nLiczby te nie są skojarzone";

    return 0;
}
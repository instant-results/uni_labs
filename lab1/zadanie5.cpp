#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int arr1[2][3], arr2[2][3], arr3[2][3];
    cout << "Proszę o wprowadzenie pierwszej macierzy o wymiarach 2 x 3:" << endl<<"wiersz 1:\n";
    cin >> arr1[0][0] >> arr1[0][1] >> arr1[0][2];
    cout << "wiersz 2:"<<endl;
    cin >> arr1[1][0] >> arr1[1][1] >> arr1[1][2];

    cout << "\nProszę o wprowadzenie drugiej macierzy o wymiarach 2 x 3:" << endl << "wiersz 1:\n";
    cin >> arr2[0][0] >> arr2[0][1] >> arr2[0][2];
    cout << "wiersz 2:" << endl;
    cin >> arr2[1][0] >> arr2[1][1] >> arr2[1][2];

    cout << "Macierz pierwsza:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Macierz druga\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Macierz powstała z dodania powyższych:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
            cout << arr3[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
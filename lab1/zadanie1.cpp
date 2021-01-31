#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    int *numbers = new int[argc - 1];

    for (int i = 1; i < argc; i++) {
        numbers[i - 1] = stoi(argv[i]);
    }

    int temp, j;
    for (int i = 1; i < argc-1; i++)
    {

        temp = numbers[i];
        j = i - 1;

        while (j >= 0 && numbers[j] > temp)
        {
            numbers[j + 1] = numbers[j];
            --j;
        }
        numbers[j + 1] = temp;
    }
    cout << "\n";
    for (int i = 0; i < argc-1; ++i)
        cout << numbers[i] << " ";

    delete[] numbers;

    return 0;
}
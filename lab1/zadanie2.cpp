#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc > 1) {
        string my_word = argv[1];
        bool flag = true;

        for (int i = 0; i < my_word.length(); i++) {
            if (my_word[i] != my_word[my_word.length() - i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) { cout << "Słowo jest palnidromem"<<endl; }
        else if (!flag) { cout << "Słowo nie jest palnidromem" << endl; }
    }

    else { cout << "Brak odpowiedniego argumentu programu"; return 1; }

    return 0;
}
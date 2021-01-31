#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    double body_mass, height, bmi_index;
    cout << "Kalkulator BMI, proszę wprowadzić swoją masę ciała w kg:\n";
    cin >> body_mass;
    cout << "\nProszę wprowadzić wzrost w metrach:\n";
    cin >> height;

    cout << "\nTwój wskaźnik BMI:\n";
    bmi_index = body_mass / (height * height);
    cout << setprecision(4) << bmi_index << " - ";
    if (bmi_index < 16) cout << "wygłodzenie\n";
    else if (bmi_index < 17) cout << "wychudzenie\n";
    else if (bmi_index < 18.5) cout << "niedowaga\n";
    else if (bmi_index < 25) cout << "wartość prawidłowa\n";
    else if (bmi_index < 30) cout << "nadwaga\n";
    else if (bmi_index < 35) cout << "I stopień otyłości\n";
    else if (bmi_index < 40) cout << "II stopień otyłości\n";
    else cout << "otyłość skrajna\n";

    return 0;
}
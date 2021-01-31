#include <cstdio>
#include <iostream>
#include <string>
//#include <fstream>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <limits>
using namespace std;
#include "../include/project_lab4/public_headers/lab4_class_header.hpp"

int safe_int_cin()
{

  int cin_var;
  cin >> cin_var;
  while (1)
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Wprowadziłeś niepoprawne dane " << endl;
      cin >> cin_var;
    }
    if (!cin.fail())
      break;
  }

  return cin_var;
}

Matrix choose_matrix()
{

  int argument_cons;
  string file_name, full_path;
  int n, m;

  cout << "Wybierz metodę tworzenia macierzy:\n1 --- macierz o wymiarach podanych przez użytkownika i losowych polach\n2 --- macierz kwadratowa o wymiarach podanych przez użytkownika i losowych polach\n3 --- macierz wczytana z pliku\n";
  argument_cons = safe_int_cin();

  switch (argument_cons)
  {
  case 1:

    cout << "Podaj wymiary macierzy:\n";
    n = safe_int_cin();
    m = safe_int_cin();
      {
      Matrix new_matrix(n, m);
      new_matrix.fill();
      return new_matrix;
      }
    break;

  case 2:

    cout << "Podaj wymiary macierzy:\n";
    n = safe_int_cin();
      {
      Matrix new_matrix(n);
      new_matrix.fill();
      return new_matrix;
      }
    break;

  case 3:

    cout << "\n\nDo utworzenia macierzy będę prosił o podanie bezwzględnej ścieżki do folderu z plikiem\nmoże nie działać dla ściezki zawierającej znak spacji\n(możesz podać dowolny pojedynczy znak jeśli plik zawiera się w folderze, z którego wywołałeś program),\noraz o podanie nazwy pliku, z którego odczytam macierz:\nŚcieżka do pliku:\n";

    cin.ignore();
    getline(cin, full_path);
    cout << "\nA teraz nazwa pliku (z rozszerzeniem):" << endl;
    getline(cin, file_name);
      {
      Matrix new_matrix(file_name, full_path);
     
      return new_matrix;
      }  
    break;

  default:
    string argument_exception = "Nie wybrałeś prawidłowej metody tworzenia macierzy\n";
    throw argument_exception;
  }
}

int main()
{
  int n, m;
  srand(time(NULL));
  int argument = 0;
  //Matrix matrix1, matrix2;
  string file_name, full_path;
  Matrix matrix1(1), matrix2(1);

  try
  {
    matrix1 = choose_matrix();
    cout<<"Macierz 1:\n";
    matrix1.print();
  }
  catch (string constructor_except_arg)
  {
    cout << "Wyjątek tworzenia pierwszej macierzy: " << constructor_except_arg;
    //return 1;
  }
  catch (exception &e)
  {
    cerr << "\nBłąd konstruktora macierzy\n"
         << e.what() << "\n";
    //return 1;
  }
  
  try
  {
    matrix2 = choose_matrix();
    cout<<"\nMacierz 2:\n";
    matrix2.print();
  }
  catch (string constructor_except_arg)
  {
    cout << "Wyjątek tworzenia drugiej macierzy: " << constructor_except_arg;
    //return 1;
  }
  catch (exception &e)
  {
    cerr << "\nBłąd konstruktora macierzy\n"
         << e.what() << "\n";
    //return 1;
  }
  
  
  cout<<endl;
  do
  {
    cout << "Wybierz operację:\n1 --- metoda mnożenia macierzy\n2 --- metoda dodawania macierzy\n3 --- metoda odejmowania macierzy\n4 --- wyświetlenie liczby wierszy i kolumn w podstawowych macierzach\n5 --- wyświetlenie bieżącej wartości komórki i jej zmiana w jednej z dwóch podstawowych macierzy\n6 --- zapisanie macierzy do pliku\n7 --- zmiana obecnych macierzy\n0 --- wyjście z programu\n\n";
    argument = safe_int_cin();

    switch (argument)
    {
    case 0:
      return 0;

    case 1:
      try
      {
        Matrix matrix_multiply_test = matrix1.multiply(matrix2);
        cout << "\nMacierz powstała z pomnożenia pierwszej przez drugą:\n";
        matrix_multiply_test.print();
      }
      catch (exception &e)
      {
        cerr << "\nBłąd, niezgodne macierze mnożenia\n"
             << e.what() << "\n";
      }

      break;

    case 2:
      try
      {
        Matrix matrix_add_test = matrix1.add(matrix2);
        cout << "\nMacierz powstała z dodania macierzy pierwszej do drugiej:\n";
        matrix_add_test.print();
      }
      catch (exception &e)
      {
        cerr << "\nBłąd, niezgodne macierze dodawania\n"
             << e.what() << "\n";
      }

      break;

    case 3:
      try
      {
        //Matrix matrix_subtract_test(1);
        Matrix matrix_subtract_test = matrix1.subtract(matrix2);
        cout << "\nRóżnica macierzy:\n";
        matrix_subtract_test.print();
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << '\n';
        break;
      }
      break;

    case 4:
      cout << "Liczba wierszy i kolumn w pierwszej macierzy:\n"
           << matrix1.rows() << " " << matrix1.cols() << "\nLiczba wierszy i kolumn w drugiej macierzy:\n"
           << matrix2.rows() << " " << matrix2.cols() << endl;
      break;

    case 5:
      int case5_n, case5_i, case5_j;
      double case5_new_val;
      cout << "Wybierz macierz 1 lub 2:\n";
      case5_n = safe_int_cin();
      if (case5_n > 2 || case5_n < 1)
      {
        cout << "Nie wybrałeś poprawnej macierzy\n";
        break;
      }

      cout << "\nwybierz adres komórki do sprawdzenia i zmiany:\n";
      case5_i = safe_int_cin();
      case5_j = safe_int_cin();

      if (1 == case5_n)
      {
        try
        {
          case5_new_val = matrix1.get(case5_i, case5_j);
          cout << "Aktualna wartość w komórce " << case5_i << " " << case5_j << ": " << case5_new_val << "\nWprowadź nową wartość:\n";
        cin >> case5_new_val;
        while (1)
        {
          if (cin.fail())
          {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wprowadziłeś niepoprawne dane " << endl;
            cin >> case5_new_val;
          }
          if (!cin.fail())
            break;
        }
        matrix1.set(case5_i, case5_j, case5_new_val);
        }
        catch (exception &e)
        {
          cerr << "\nBłąd zakresu macierzy\n"
               << e.what() << "\n";
               
        }
        
      }
      else if (2 == case5_n)
      {
        try
        {
          case5_new_val = matrix2.get(case5_i, case5_j);
          cout << "Aktualna wartość w komórce " << case5_i << " " << case5_j << ": " << case5_new_val << "\nWprowadź nową wartość:\n";
        cin >> case5_new_val;
        while (1)
        {
          if (cin.fail())
          {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Wprowadziłeś niepoprawne dane " << endl;
            cin >> case5_new_val;
          }
          if (!cin.fail())
            break;
        }
        matrix2.set(case5_i, case5_j, case5_new_val);
        }
        catch (exception &e)
        {
          cerr << "\nBłąd zakresu macierzy\n"
               << e.what() << "\n";
        }
        
      }
      break;

    case 6:
      int case6_n;
      cout << "Wybierz macierz 1 lub 2:\n";
      case6_n = safe_int_cin();
      if (case6_n > 2 || case6_n < 1)
      {
        cout << "Nie wybrałeś poprawnej macierzy\n";
        break;
      }
      cout << "proszę o podanie ścieżki do folderu,\nmoże nie działać dla ściezki zawierającej znak spacji\n lub podaj dowolny, pojedynczy znak, jeśli chcesz zamieścić plik w folderze, z którego wywołano program:\n";
      fflush(stdin);
      getline(cin, full_path);

      cout << "A teraz nazwa pliku (z rozszerzeniem):\n";
      //cin >> file_name;
      getline(cin, file_name);

      if (1 == case6_n)
      {
        try
        {
          matrix1.store(file_name, full_path);
        }
        catch (exception &e)
        {
          cerr << "\nBłąd zapisu macierzy\n"
               << e.what() << "\n";
          break;
        }
      }
      else if (2 == case6_n)
      {
        try
        {
          matrix2.store(file_name, full_path);
        }
        catch (exception &e)
        {
          cerr << "\nBłąd zapisu macierzy\n"
               << e.what() << "\n";
          break;
        }
      }
      break;

    case 7:
      try
      {
        matrix1 = choose_matrix();
        cout<<"Macierz 1:\n";
        matrix1.print();
      }
      catch (string constructor_except_arg)
      {
        cout << "Wyjątek tworzenia pierwszej macierzy: " << constructor_except_arg;
        //return 1;
      }
      catch (exception &e)
      {
        cerr << "\nBłąd konstruktora macierzy\n"
             << e.what() << "\n";
        //return 1;
      }

      try
      {
        matrix2 = choose_matrix();
        cout<<"Macierz 2:\n";
        matrix2.print();
      }
      catch (string constructor_except_arg)
      {
        cout << "Wyjątek tworzenia drugiej macierzy: " << constructor_except_arg;
        //return 1;
      }
      catch (exception &e)
      {
        cerr << "\nBłąd konstruktora macierzy\n"
             << e.what() << "\n";
        //return 1;
      }
      //matrix1.print();
      //matrix2.print();
      break;

    default:
      cout << "Wybrałeś niepoprawną operację operację\n";
    }

  } while (argument);

  return 0;
}
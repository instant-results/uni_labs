#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

class Matrix
{
  double *matrix;
  int n;
  int m;
  string filename;
  string path;

public:
  Matrix(int n, int m);
  Matrix(int n);
  void set(int n, int m, double val); //
  double get(int n, int m);           //
  Matrix add(Matrix);
  Matrix subtract(Matrix );
  Matrix multiply(Matrix );
  int cols();   //
  int rows();   //
  void print(); //
  void store(string filename, string path);
  Matrix(string filename, string path); //
  ~Matrix();                            //

};


Matrix Matrix::add(Matrix m2)
{
    
    if (!(this->m == m2.cols() && this->n == m2.rows()))
    {
        cout << "\nNiezgodne macierze dodawania\n";
        return 1;
    }

    Matrix new_m(n, m);

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            //cout << this->matrix[i * this->m + j] << " + " << m2.get(i, j) << "\t";
            new_m.set(i, j, this->matrix[i * this->m + j] + m2.get(i, j));
            //this->set(i, j, 5);
        }
        //cout<<"\n";
    }
    return new_m;
}



Matrix Matrix::subtract(Matrix m2)
{
  if (!(this->m == m2.m && this->n == m2.n))
  {
    cout << "\nNiezgodne macierze odejmowania\n";
    return 1;
  }

  Matrix new_m(n,m);

  for (int i = 0; i < this->n; i++)
  {
    for (int j = 0; j < this->m; j++)
    {
        new_m.set(i,j, this->matrix[i * this->m + j]-m2.get(i,j));
    }
  }
  return new_m;
}

Matrix Matrix::multiply(Matrix m2)
{
  if (this->m != m2.n)
  {
    cout <<"\nNiezgodne macierze mnożenia\n";
    return 1;
  }

  Matrix new_m(this->n,m2.m);
  double sum;

  for(int i = 0;i < this->n;i++){
      for(int j = 0; j < m2.m; j++){
          //new_m->matrix[i][j] = 0;
          sum = 0;
          for(int k = 0; k < this->m;k++){
            sum += this->matrix[i*this->m+k]*m2.matrix[k*m2.cols()+j];
          }
          new_m.matrix[i*this->m + j] += sum;
      }
  }
  return new_m;
}

int Matrix::cols()
{
  return this->m;
}

int Matrix::rows()
{
  return this->n;
}

void Matrix::print()
{
  for (int i = 0; i < this->n; i++)
  {
    for (int j = 0; j < this->m; j++)
    {
      cout << this->matrix[i * this->m + j] << "\t";
    }
    cout << "\n";
  }
}   

Matrix::Matrix(int n, int m)
{
  this->n = n;
  this->m = m;
  this->matrix = new double[n * m];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      matrix[i * this->m + j] = 0;
    }
  }
}

Matrix::Matrix(int n)
{
  this->n = n;
  this->m = n;
  this->matrix = new double[n * n];

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix[i * this->m + j] = 0;
    }
  }
}

Matrix::Matrix(string filename, string path)
{
  this->filename = filename;
  this->path = path;
  if (path.length() > 1) {
      cout << "\nWykryto ścieżkę\n";
      filename = path + '\\' + filename;
  }
  else if (path.length() == 1) {
      cout << "\nWykryto pustą ścieżkę\n";
  }

  ifstream textfile(filename);
  if (textfile) {
    
  textfile >> this->n >> this->m;
  this->matrix = new double[n * m];

  for (int i = 0; i < this->n; i++)
  {
      for (int j = 0; j < this->m; j++)
      {
          textfile >> this->matrix[i * this->m + j];  
          //cout << this->matrix[i * this->m + j] << " ";
      }
      //cout << "\n";
  }
  textfile.close();
  }
}

void Matrix::set(int n, int m, double val)
{
  this->matrix[n * this->m + m] = val;
}

double Matrix::get(int n, int m)
{
  return this->matrix[n * this->m + m];
}

void Matrix::store(string filename, string path)
{
    cout << "metoda store";
  if (path.length() > 1) {
      cout << "\nWykryto ścieżkę\n";
      filename = path +  '\\' + filename;
  }
  else if (path.length() == 1) {
      cout << "\nWykryto pustą ścieżkę\n";
  }

  ofstream textfile(filename);
  if (!textfile) {
      cout << "\nBłąd otwarcia pliku";
      return;
  }
  

  textfile << this->n << " " << this->m << "\n";
  for (int i = 0; i < this->n; i++)
  {
    for (int j = 0; j < this->m; j++)
    {
      textfile << matrix[i * this->m + j] << "\t";
    }
    textfile << "\n";
  }
  textfile.close();
}

Matrix::~Matrix()
{
  //delete[] this->matrix; //JEZU JAKIM CUDEM TO WSZYSTKO POPSUŁO
}

int main()
{
  int n,m;
  n = 4;
  //drugi konstruktor z zadania
  Matrix matrix1(n);
  //metoda rows()
  cout << "Wymiar pierwszej macierzy (kwadratowej, metoda rows()):\n" << matrix1.rows() << "\nPrzedstawienie metodą print:\n";
  //metoda print()
  matrix1.print();

  srand(time(NULL));
  n = rand() % 6 + 4;
  m = rand() % 6 + 4;
  
  //pierwszy konstruktor z zadania
  Matrix matrix2(n, m);
  //metody rows() oraz cols()
  cout << "\n\nWymiary drugiej macierzy (metody rows() i cols()):\n" << matrix2.rows() << " " << matrix2.cols() << "\n";
  matrix2.print();

  string file_name, full_path;
  cout << "\n\nDo utworzenia trzeciej macierzy będę prosił o podanie bezwzględnej ścieżki do folderu z plikiem\nmoże nie działać dla ściezki zawierającej znak spacji\n(możesz podać dowolny pojedynczy znak jeśli plik zawiera się w folderze, z którego wywołałeś program),\noraz o podanie nazwy pliku, z którego odczytam macierz:\nŚcieżka do pliku:\n";
  //cin >> full_path;
  getline(cin, full_path);
  cout << "\nA teraz nazwa pliku (z rozszerzeniem):\n";
  getline(cin, file_name);
  //cin >> file_name;
  //trzeci konstruktor z zadania
  Matrix matrix3(file_name, full_path);
  matrix3.print();
 
  //losowanie do macierzy
  cout << "\n\nMacierz pierwsza i druga po wylosowaniu do nich liczb (uzupełniane metodą set()):\n";
  for (int i = 0; i < matrix1.rows(); i++) {
      for (int j = 0; j < matrix1.cols(); j++) {
  //metoda set()
          matrix1.set(i,j,(rand()%201-100)/10.0);
    }
  }
  matrix1.print();
  cout << "\n\nMacierz druga wypisana z użyciem metody get():\n";
  for (int i = 0; i < matrix2.rows(); i++) {
      for (int j = 0; j < matrix2.cols(); j++) {
          matrix2.set(i, j, (rand() % 41 - 20));
  //metoda get()
          cout << matrix2.get(i, j) << "\t";
      }
      cout << "\n";
  }

  //Matrix matrix1_copy = matrix1;
  //cout << "\nTrzecia macierz będzie kopią pierwszej, z nią przetestujemy mnożenie\n";
  //matrix1_copy.print();

  Matrix matrix_multiply_test = matrix1.multiply(matrix1);
  cout << "\nMacierz powstała z pomnożenia pierwszej przez siebie:\n";
  matrix_multiply_test.print();

  cout << "\nTeraz przedstawimy macierz powstałą z dodania macierzy pierwszej do jej wersji spotęgowanej:\n";
  Matrix matrix_add_test = matrix1.add(matrix_multiply_test);
  matrix_add_test.print();

  cout << "\nOdejmiemy od macierzy przedostatniej ostatnią:\n";
  Matrix matrix_subtract_test = matrix_multiply_test.subtract(matrix_add_test);
  matrix_subtract_test.print();

  cout << "\nA teraz zapiszemy ostatnią macierz do pliku, proszę o podanie ścieżki do folderu,\nmoże nie działać dla ściezki zawierającej znak spacji\n lub podaj dowolny, pojedynczy znak, jeśli chcesz zamieścić plik w folderze, z którego wywołano program:\n";
  //cin >> full_path;
  getline(cin, full_path);
  cout << "\nA teraz nazwa pliku (z rozszerzeniem):\n";
  //cin >> file_name;
  getline(cin, file_name);
  matrix_subtract_test.store(file_name,full_path);


  return 0;
}
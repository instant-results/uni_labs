#include "../include/project_lab4/public_headers/lab4_class_header.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <cstring>
using namespace std;

Matrix Matrix::add(Matrix m2)
{
   
    if (!(this->m == m2.cols() && this->n == m2.rows()))
        throw domain_error("Macierze nie mają równych wymiarów");


    Matrix new_m(this->n, this->m);

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
    //---------EXCEPTION----------------------------
    /*
    if (!(this->m == m2.m && this->n == m2.n))
    {
        cout << "\nNiezgodne macierze odejmowania\n";
        return;
    }
    */

  
        if (!(this->m == m2.cols() && this->n == m2.rows()))
            throw domain_error("Macierze nie mają równych wymiarów");
  

    Matrix new_m(this->n, this->m);

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            new_m.set(i, j, this->matrix[i * this->m + j] - m2.get(i, j));
        }
    }
    return new_m;
}

Matrix Matrix::multiply(Matrix m2)
{
    //---------EXCEPTION----------------------------


    if (this->m != m2.n)
        throw domain_error("Liczba kolumn lewej macierzy nie jest równa liczbie wierszy prawej macierzy");
  

    Matrix new_m(this->n, m2.m);
    double sum;
    double a, b;

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < m2.m; j++)
        {
            //new_m->matrix[i][j] = 0;
            sum = 0;
            for (int r = 0; r < this->m; r++)
            {
                a = this->get(i, r);
                b = m2.get(r, j);
                sum += a * b;
                //sum += this->matrix[i * this->n + r] * m2.matrix[r * m2.rows() + j];
            }
            new_m.matrix[i * this->n + j] = sum;
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

void Matrix::fill()
{
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            //metoda set()
            //this->set(i, j, (rand() % 201 - 100) / 10.0);
            int x = rand() % 9;
            //cout << "x = " << x << "\n";
            this->set(i, j, x);
        }
    }
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

    if (n < 1 || m < 1){
        throw domain_error("Konstruktor macierzy n na m przyjął argument wymiaru macierzy poniżej 1\n");
    }


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
   
    if (n < 1){
        throw domain_error("Konstruktor macierzy kwadratowej przyjął rozmiar macierzy poniżej 1\n");
    }


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
Matrix::Matrix(const Matrix& copy_this){
    
    this->n = copy_this.n;
    this->m = copy_this.m;
    this->matrix = new double[n * m];

    memcpy(this->matrix, copy_this.matrix, m * n * sizeof(double));
}
//---------EXCEPTION----------------------------
Matrix::Matrix(string filename, string path)
{
    this->filename = filename;
    this->path = path;
    if (path.length() > 1)
    {
        cout << "\nWykryto ścieżkę\n";
        filename = path + '\\' + filename;
    }
    else if (path.length() == 1)
    {
        cout << "\nWykryto pustą ścieżkę\n";
    }

    ifstream textfile(filename);
    if (textfile.good())
    {

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
       /* if(!textfile.good()){
            throw runtime_error("Błąd wczytywania pliku");
        }*/
        textfile.close();
    }
    else{
        throw runtime_error("Błąd otwarcia pliku");
    }
}
//---------EXCEPTION----------------------------
void Matrix::set(int n, int m, double val)
{
        if (n < 0 || n >= this->rows() || m < 0 || m >= this->cols()){
            throw domain_error("przekraczono zakres macierzy");}
  

    this->matrix[n * this->m + m] = val;
}
//---------EXCEPTION----------------------------
double Matrix::get(int n, int m)
{
    
        if (n < 0 || n >= this->rows() || m < 0 || m >= this->cols()){
            throw domain_error("przekraczono zakres macierzy");}
   
    return this->matrix[n * this->m + m];
}

void Matrix::store(string filename, string path)
{
    //cout << "metoda store";
    if (path.length() > 1)
    {
        cout << "\nWykryto ścieżkę\n";
        filename = path + '\\' + filename;
    }
    else if (path.length() == 1)
    {
        cout << "\nWykryto pustą ścieżkę\n";
    }

    ofstream textfile(filename);
    if (!textfile.good())
    {
        throw runtime_error("Błąd otwarcia strumienia zapisu pliku");
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
    if (!textfile.good())
    {
        throw runtime_error("Błąd zapisu pliku");
    }
    textfile.close();
}

Matrix::~Matrix()
{
    //delete[] this->matrix;
}
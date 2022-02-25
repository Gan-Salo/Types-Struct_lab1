// z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

 /*Сортировка вставками*/
void floatsort(float a[], int n)
{
    int i, j;
    float x;
    for (i = 0; i < n; i++) { // цикл проходов,i- номер прохода
        x = a[i]; // поиск места элемента a[i] в готовой последовательности
        for (j = i - 1; j >= 0 && a[j] < x; j--)
            a[j + 1] = a[j]; // сдвигаем элемент направо, пока не дошли
            // место найдено, вставить элемент
        a[j + 1] = x;
    }
}

void Exchange(int i, int j, float a[])
{
    float temp;
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Quick_Sort(int left, int right, float a[]) {
    int i, j, h;
    float m;
    i = left;
    j = right;

    m = a[(i + j + 1) / 2];
    do {
        while (a[i] > m) i++; while (a[j] < m) j--; if (i <= j) {
            Exchange(i, j, a); //обмен i, j элементов местами
            i++; j--;
        }
    } while (i <= j);
    if (left < j)
        Quick_Sort(left, j, a); 
    if (i < right)
        Quick_Sort(i, right, a);
}

void SearchRez(float a[], bool flag, int m) {

    if (flag) cout << "\nЭлемент массива " << a[m] << " расположен в ячейке под индексом " << m << "\n";
    else cout << "\nТакого элемента нет в массиве...\n";
}

void Bin_Search(int left, int right, float a[], float find) {

    int i, j, m;
    
    bool flag = false;
    i = left;
    j = right;
    while ((i <= j) && (flag != true))
    {

        m = (i + j) / 2;
        if (a[m] == find) { flag = true; }
        if (a[m] < find) { j = m - 1; }
        else { i = m + 1; }
    }   
    
    SearchRez(a, flag, m);

}

int main()
{
    setlocale(LC_ALL, "rus");
    float *mass, find;
    int size;
    cin >> size;

    mass = new float[size];
    int i, j;
    
    srand((unsigned int)time(NULL));
    float x = 5.0;
    for (i = 0; i < size; i++)
    {
        cin >> mass[i];
        //mass[i] = (float(rand()) / float((RAND_MAX)) * x);
        //cout << mass[i] << "\n";
    }
    /*std::
    //floatsort(mass, size);*/
    
    Quick_Sort(0, size - 1, mass);
    cout << "\nРезультат сортировки по убыванию:\n";
    for (i = 0; i < size; i++)
        cout << mass[i] << " \n";
    

    std::cout << "\nКакое число в массиве требуется найти: ";
    std::cin >> find;

    
    cout << "\nРезультат поиска:";
    Bin_Search(0, size - 1, mass, find);

    

    delete[] mass;
    mass = 0;

    return 0;
}


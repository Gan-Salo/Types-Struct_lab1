// z1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <time.h>


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
        while (a[i] < m) i++; while (a[j] > m) j--; if (i <= j) {
            Exchange(i, j, a); //обмен i, j элементов местами
            i++; j--;
        }
    } while (i <= j);
    if (left < j)
        Quick_Sort(left, j, a); if (i < right)
        Quick_Sort(i, right, a);
}

void Bin_Search(int left, int right, float a[]) {

    int i, j, h;
    float m;
    bool flag = false;
    i = left;
    j = right;
    while ((i <= j) && (!flag))
    {

    }

    m = a[(i + j + 1) / 2];
    
}

int main()
{
      
    float *mass, x;
    int size;
    std::cin >> size;
    mass = new float[size];
    int i, j;
    
    for (i = 0; i < size; i++)
        std::cin >> mass[i];

    //floatsort(mass, size);

    Quick_Sort(0, size - 1, mass);
    for (i = 0; i < size; i++)
        std::cout << mass[i] << " ";

    delete[] mass;
    mass = 0;

    return 0;
}


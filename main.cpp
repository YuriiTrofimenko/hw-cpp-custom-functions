#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

enum order {ASC, DESC};

/*** ПРОТОТИПЫ ФУНКЦИЙ ***/

int findIndexOfInt(int x, int integers[]);
// Возвращает индекс первого попавшегося в массиве числа, равного заданному

int findIndexOfInt(int x, int integers[], int count[]);
// Возвращает индекс первого попавшегося в массиве числа, равного заданному, и сохраняет количество совпадений в первый элемент списка

void intBubbleSort(int integers[], int size, order myOrder = order::ASC);
// Сортирует элементы в массиве (переключатель внутри!)

void arrayInput(int integers[]);
// Ввод элементов в массив с консоли

void arrayPrint(int integers[]);
// Вывод элементов массива на экран

/*** ТЕЛО ПРОГРАММЫ ***/

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "*** Сортировка целых чисел ***" << endl;
	int ints[7]; // создание массива
	arrayInput(ints);
    cout << "сортировать по убыванию(д - да/н - нет)?" << endl;
    char descOrderResponse = 'н';
    cin >> descOrderResponse;
    descOrderResponse == 'н' ? intBubbleSort(ints, 7) : intBubbleSort(ints, 7, order::DESC);
    /* if (descOrderResponse == 'н') {
        cout << order::ASC << endl;
    } else if (descOrderResponse == 'д') {
        cout << order::DESC << endl;
    } */
	arrayPrint(ints);

	int toFind = 20; // ввод числа для поиска

    int count[] = { 0 }; // создание массива для сохранения туда кол-ва совпадений

    /*try
    {
        cout << findIndexOfInt(toFind, ints, count) << "\n";
    }
    catch (const exception& ex)
    {
        cout << ex.what() << endl;
    }
    */
}

/*** ФУНКЦИИ ***/

int findIndexOfInt(int x, int integers[]) // Возвращает индекс первого попавшегося в массиве числа, равного заданному
{
    int i = 0;
    while (i < 7)
    {
        if (integers[i] == x)
        {
            return i;
        }
        i++;
    }
//    throw exception("Item not found!");
}

int findIndexOfInt(int x, int integers[], int count[]) // Возвращает индекс первого попавшегося в массиве числа, равного заданному, и сохраняет количество совпадений в первый элемент списка
{
    int i = 0;
    int counter = 0;
    for (int i = 0; i < 7; i++)
    {
        if (integers[i] == x)
        {
            counter++;
        }
    }
    count[0] = counter;

    for (int i = 0; i < 7; i++)
    {
        if (integers[i] == x)
        {
            return i;
        }
    }
}

void intBubbleSort(int integers[], int size, order myOrder /* ПЕРЕКЛЮЧАТЕЛЬ */) // Сортирует элементы в массиве
{
    bool sortCheck = false;
    while (sortCheck == false)
    {
        sortCheck = true;
        for (int i = 0; i < size - 1; i++)
        {
            int comparisonResult =
                myOrder == order::ASC
                    ? integers[i] - integers[i + 1]
                    : integers[i + 1] - integers[i];
            if (comparisonResult > 0)
            {
                int temp = integers[i];
                integers[i] = integers[i + 1];
                integers[i + 1] = temp;
                sortCheck = false;
            }
        }
    }
}

void arrayInput(int integers[]) // Ввод элементов в массив с консоли
{
	cout << "Вводите целые числа, и после каждого нажимайте клавишу Ввод" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << "Число номер " << i + 1 << " из 7: ";
		cin >> integers[i];
	}
}

void arrayPrint(int integers[]) // Вывод элементов массива на экран
{
	cout << "[ ";
	for (int i = 0; i < 7; i++)
		{
			cout << integers[i] << " ";
		}
	cout << "]";
}

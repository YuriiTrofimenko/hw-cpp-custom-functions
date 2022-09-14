#include <iostream>
#include <vector>
using namespace std;


/*** ПРОТОТИПЫ ФУНКЦИЙ ***/ 

int findIndexOfInt(int x, int integers[]); 
// Возвращает индекс первого попавшегося в массиве числа, равного заданному

int findIndexOfInt(int x, int integers[], int count[]); 
// Возвращает индекс первого попавшегося в массиве числа, равного заданному, и сохраняет количество совпадений в первый элемент списка

void intBubbleSort(int integers[], int size); 
// Сортирует элементы в массиве (переключатель внутри!)

void arrayInput(int integers[]);
// Ввод элементов в массив с консоли

void arrayPrint(int integers[]);
// Вывод элементов массива на экран




/*** ТЕЛО ПРОГРАММЫ ***/

int main()
{
	int ints[7]; // создание массива
	arrayInput(ints);

	intBubbleSort(ints, 7);
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


void intBubbleSort(int integers[], int size) // Сортирует элементы в массиве
{
	enum order {ASC, DESC};
	order myOrder = order::ASC; // ПЕРЕКЛЮЧАТЕЛЬ
	
	if (myOrder == DESC){
		bool sortCheck = false;
		while (sortCheck == false)
		{
			sortCheck = true;
			for (int i = 0; i < size - 1; i++)
		    {
    	       	if (integers[i] < integers[i + 1])
        	   	{
	           	    int temp = integers[i];
               		integers[i] = integers[i + 1];
	               	integers[i + 1] = temp;
    	       	}
        	}
			for (int i = 0; i < size - 1; i++)
			{
				if (integers[i] < integers[i + 1])
				{
					sortCheck = false;
				};
			}
		}
	}
	
	if (myOrder == ASC){
		bool sortCheck = false;
		while (sortCheck == false)
		{
			sortCheck = true;
			for (int i = 0; i < size - 1; i++)
		    {
    	       	if (integers[i] > integers[i + 1])
        	   	{
	           	    int temp = integers[i];
               		integers[i] = integers[i + 1];
	               	integers[i + 1] = temp;
    	       	}
        	}
			for (int i = 0; i < size - 1; i++)
			{
				if (integers[i] > integers[i + 1])
				{
					sortCheck = false;
				};
			}
		}
	}
}



void arrayInput(int integers[]) // Ввод элементов в массив с консоли
{
	cout << "Enter the values for the array one by one." << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << "Value " << i + 1 << " out of 7: ";
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
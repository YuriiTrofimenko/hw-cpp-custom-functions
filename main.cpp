#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

enum order {ASC, DESC};

/*** ��������� ������� ***/

int findIndexOfInt(int x, int integers[]);
// ���������� ������ ������� ����������� � ������� �����, ������� ���������

int findIndexOfInt(int x, int integers[], int count[]);
// ���������� ������ ������� ����������� � ������� �����, ������� ���������, � ��������� ���������� ���������� � ������ ������� ������

void intBubbleSort(int integers[], int size, order myOrder = order::ASC);
// ��������� �������� � ������� (������������� ������!)

void arrayInput(int integers[]);
// ���� ��������� � ������ � �������

void arrayPrint(int integers[]);
// ����� ��������� ������� �� �����

/*** ���� ��������� ***/

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "*** ���������� ����� ����� ***" << endl;
	int ints[7]; // �������� �������
	arrayInput(ints);
    cout << "����������� �� ��������(� - ��/� - ���)?" << endl;
    char descOrderResponse = '�';
    cin >> descOrderResponse;
    descOrderResponse == '�' ? intBubbleSort(ints, 7) : intBubbleSort(ints, 7, order::DESC);
    /* if (descOrderResponse == '�') {
        cout << order::ASC << endl;
    } else if (descOrderResponse == '�') {
        cout << order::DESC << endl;
    } */
	arrayPrint(ints);

	int toFind = 20; // ���� ����� ��� ������

    int count[] = { 0 }; // �������� ������� ��� ���������� ���� ���-�� ����������

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

/*** ������� ***/

int findIndexOfInt(int x, int integers[]) // ���������� ������ ������� ����������� � ������� �����, ������� ���������
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

int findIndexOfInt(int x, int integers[], int count[]) // ���������� ������ ������� ����������� � ������� �����, ������� ���������, � ��������� ���������� ���������� � ������ ������� ������
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

void intBubbleSort(int integers[], int size, order myOrder /* ������������� */) // ��������� �������� � �������
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

void arrayInput(int integers[]) // ���� ��������� � ������ � �������
{
	cout << "������� ����� �����, � ����� ������� ��������� ������� ����" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << "����� ����� " << i + 1 << " �� 7: ";
		cin >> integers[i];
	}
}

void arrayPrint(int integers[]) // ����� ��������� ������� �� �����
{
	cout << "[ ";
	for (int i = 0; i < 7; i++)
		{
			cout << integers[i] << " ";
		}
	cout << "]";
}

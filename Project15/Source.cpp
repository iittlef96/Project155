#include <iostream>
#include <Windows.h>
using namespace std;

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

int differenceInDays(int day1, int month1, int year1, int day2, int month2, int year2) {
    int daysInMonth[] = { 31, 28 + isLeapYear(year1), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days1 = day1;
    for (int i = 0; i < month1 - 1; i++) {
        days1 += daysInMonth[i];
    }

    int days2 = day2;
    for (int i = 0; i < month2 - 1; i++) {
        days2 += daysInMonth[i];
    }

    int totalDays1 = days1 + year1 * 365 + year1 / 4 - year1 / 100 + year1 / 400;
    int totalDays2 = days2 + year2 * 365 + year2 / 4 - year2 / 100 + year2 / 400;

    return totalDays2 - totalDays1;
}
double averageOfArray(int arr[], int size) {
    if (size == 0) {
        return 0; 
    }

    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}
void countPositiveNegativeZero(int arr[], int size, int& positiveCount, int& negativeCount, int& zeroCount) {
    positiveCount = 0;
    negativeCount = 0;
    zeroCount = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            positiveCount++;
        }
        else if (arr[i] < 0) {
            negativeCount++;
        }
        else {
            zeroCount++;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int day1 = 1, month1 = 1, year1 = 2022;
    int day2 = 1, month2 = 1, year2 = 2023;

    cout << "Разность в днях: " << differenceInDays(day1, month1, year1, day2, month2, year2) << endl;
    int arr[] = { 10, 20, 30, 40, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);


    double average = averageOfArray(arr, size);
    cout << "Среднее арифметическое массива: " << average << endl;

    int arr2[] = { 3, -5, 0, 8, -2, 0, 10 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    int positiveCount, negativeCount, zeroCount;
    countPositiveNegativeZero(arr2, size2, positiveCount, negativeCount, zeroCount);

    cout << "Количество положительных чисел: " << positiveCount << endl;
    cout << "Количество отрицательных чисел: " << negativeCount << endl;
    cout << "Количество нулей: " << zeroCount << endl;


    return 0;
}
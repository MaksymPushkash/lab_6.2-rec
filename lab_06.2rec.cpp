#include <iostream>
#include <iomanip>
#include <vector>


void printArrayRecursive(const std::vector<int>& arr, int index = 0); 

void findMaxOddRecursive(const std::vector<int>& arr, int index, int& maxOdd, int& maxOddIndex); 

void swapLastWithMaxOdd(std::vector<int>& arr, int maxOddIndex); 

void fillArrayRecursive(std::vector<int>& arr, int index, int minValue, int maxValue); 


int main() 
{
    srand(static_cast<unsigned>(time(nullptr)));
    
    int n;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> n;
    
    std::vector<int> arr(n);
    
    
    fillArrayRecursive(arr, 0, -35, 25);
    
    
    std::cout << "Початковий масив:\n";
    printArrayRecursive(arr);
    
    
    int maxOdd = INT_MIN;
    int maxOddIndex = -1;
    findMaxOddRecursive(arr, 0, maxOdd, maxOddIndex);
    
    
    if (maxOddIndex != -1) 
    {
        swapLastWithMaxOdd(arr, maxOddIndex);
        
        
        std::cout << "Модифікований масив:\n";
        printArrayRecursive(arr);
    } 
    else 
    {
        std::cout << "Непарні елементи у масиві відсутні.\n";
    }
    
    return 0;
}


void printArrayRecursive(const std::vector<int>& arr, int index = 0) 
{
    if (index == arr.size()) 
    {
        std::cout << std::endl;
        return;
    }
    std::cout << std::setw(5) << arr[index]; 
    printArrayRecursive(arr, index + 1);
}


void findMaxOddRecursive(const std::vector<int>& arr, int index, int& maxOdd, int& maxOddIndex) 
{
    if (index == arr.size()) 
    {
        return;
    }
    
    if (arr[index] % 2 != 0 && arr[index] > maxOdd) 
    {
        maxOdd = arr[index];
        maxOddIndex = index;
    }
    
    findMaxOddRecursive(arr, index + 1, maxOdd, maxOddIndex);
}


void swapLastWithMaxOdd(std::vector<int>& arr, int maxOddIndex) 
{
    if (maxOddIndex != -1) 
    {
        std::swap(arr[arr.size() - 1], arr[maxOddIndex]);
    }
}


void fillArrayRecursive(std::vector<int>& arr, int index, int minValue, int maxValue) 
{
    if (index == arr.size()) 
    {
        return;
    }
    
    arr[index] = minValue + (rand() % (maxValue - minValue + 1));
    fillArrayRecursive(arr, index + 1, minValue, maxValue);
}
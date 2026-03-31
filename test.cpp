#include "CrossArray.hpp"
#include <iostream>

using namespace sjtu;

int main() {
    // Test 1: Basic construction and insertion
    CrossArray arr1(5);
    int data1[] = {1, 2, 3};
    int data2[] = {4, 5};
    int data3[] = {6, 7, 8, 9};

    std::cout << "Test 1: InsertArrays" << std::endl;
    std::cout << "Insert data1: " << arr1.InsertArrays(data1, 3) << std::endl;
    std::cout << "Insert data2: " << arr1.InsertArrays(data2, 2) << std::endl;
    std::cout << "Insert data3: " << arr1.InsertArrays(data3, 4) << std::endl;

    // Test 2: At function
    std::cout << "\nTest 2: At function" << std::endl;
    std::cout << "arr1.At(0, 0) = " << arr1.At(0, 0) << std::endl;
    std::cout << "arr1.At(0, 2) = " << arr1.At(0, 2) << std::endl;
    std::cout << "arr1.At(1, 1) = " << arr1.At(1, 1) << std::endl;
    std::cout << "arr1.At(2, 3) = " << arr1.At(2, 3) << std::endl;

    // Test 3: Copy constructor
    std::cout << "\nTest 3: Copy constructor" << std::endl;
    CrossArray arr2(arr1);
    std::cout << "arr2.At(0, 0) = " << arr2.At(0, 0) << std::endl;
    std::cout << "arr2.At(2, 3) = " << arr2.At(2, 3) << std::endl;

    // Test 4: IsSame
    std::cout << "\nTest 4: IsSame" << std::endl;
    std::cout << "arr1.IsSame(arr2) = " << arr1.IsSame(arr2) << std::endl;
    std::cout << "arr1.IsSame(arr1) = " << arr1.IsSame(arr1) << std::endl;

    // Test 5: AppendArrays
    std::cout << "\nTest 5: AppendArrays" << std::endl;
    int append[] = {10, 11};
    arr1.AppendArrays(append, 0, 2);
    std::cout << "After append to line 0, arr1.At(0, 3) = " << arr1.At(0, 3) << std::endl;
    std::cout << "arr1.At(0, 4) = " << arr1.At(0, 4) << std::endl;

    // Test 6: WhichGreater
    std::cout << "\nTest 6: WhichGreater" << std::endl;
    CrossArray& greater = arr1.WhichGreater(arr2);
    std::cout << "Greater is arr1: " << (&greater == &arr1) << std::endl;

    // Test 7: AtArray
    std::cout << "\nTest 7: AtArray" << std::endl;
    const int* arrayPtr = arr1.AtArray(1);
    if (arrayPtr != nullptr) {
        std::cout << "AtArray(1)[0] = " << arrayPtr[0] << std::endl;
        std::cout << "AtArray(1)[1] = " << arrayPtr[1] << std::endl;
    }

    // Test 8: DoubleCrossLength
    std::cout << "\nTest 8: DoubleCrossLength" << std::endl;
    CrossArray arr3(2);
    arr3.InsertArrays(data1, 3);
    arr3.InsertArrays(data2, 2);
    std::cout << "Before double, insert should fail: " << arr3.InsertArrays(data3, 4) << std::endl;
    arr3.DoubleCrossLength();
    std::cout << "After double, insert should succeed: " << arr3.InsertArrays(data3, 4) << std::endl;
    std::cout << "arr3.At(2, 2) = " << arr3.At(2, 2) << std::endl;

    std::cout << "\nAll tests completed!" << std::endl;

    return 0;
}

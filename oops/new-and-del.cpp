#include <iostream>
class MyArrayClass {
public:
    int* arr;
    int size;

    // Constructor
    MyArrayClass(int s) : size(s) {
        arr = new int[size];  // Allocate memory for array
        for (int i = 0; i < size; ++i) {
            arr[i] = i * 2;  // Initialize array elements
        }
    }

    // Destructor
    ~MyArrayClass() {
        delete[] arr;  // Deallocate memory for array
    }

    // Function to display the array values
    void display() const {
        std::cout << "Array values: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create an object of MyArrayClass
    MyArrayClass myArray(5);

    // Display the array values
    myArray.display();

    // Object goes out of scope here, destructor is called

    return 0;
}
/*
    write and explain a program to read and write multiple oblects from/to a file.
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Person {
public:
    string name;
    int age;

    Person() {}
    Person(string n, int a) : name(n), age(a) {}

    // Function to write object to file
    void writeToFile(ofstream &out) {
        out << name << endl;
        out << age << endl;
    }

    // Function to read object from file
    void readFromFile(ifstream &in) {
        getline(in, name);
        in >> age;
        in.ignore(); // To ignore the newline character after age
    }
};

int main() {
    // Create a vector of Person objects
    vector<Person> people = {Person("Alice", 30), Person("Bob", 25), Person("Charlie", 35)};

    // Write objects to file
    ofstream outFile("people.txt");
    for (Person &p : people) {
        p.writeToFile(outFile);
    }
    outFile.close();

    // Read objects from file
    ifstream inFile("people.txt");
    vector<Person> readPeople;
    while (!inFile.eof()) {
        Person p;
        p.readFromFile(inFile);
        if (inFile) { // Check if reading was successful
            readPeople.push_back(p);
        }
    }
    inFile.close();

    // Display read objects
    for (Person &p : readPeople) {
        cout << "Name: " << p.name << ", Age: " << p.age << endl;
    }

    return 0;
}

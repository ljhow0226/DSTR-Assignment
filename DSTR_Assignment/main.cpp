//
//  main.cpp
//  DSTR_Assignment
//
//  Created by LJH on 18/01/2023.
//

#include <iostream>
#include <string>
#include <array>
using namespace std;

class Car {
public:
    int carID;
    string title;
    int registrationDate;
    int mileage;
    string fuelType;
    string transmission;
    double engineSize;
    int doors;
    string color;
    string bodyType;
    double price;
    string url;
    string saleDate;
    Car* nextAddress;
    
    Car() {};
    
    Car(int carID, string title, int registrationDate, int mileage, string fuelType,
                 string transmission, double engineSize, int doors, string color, string bodyType, double price, string url, string saleDate) {
        this->carID = carID;
        this->title = title;
        this->registrationDate = registrationDate;
        this->mileage = mileage;
        this->fuelType = fuelType;
        this->transmission = transmission;
        this->engineSize = engineSize;
        this->doors = doors;
        this->color = color;
        this->bodyType = bodyType;
        this->price = price;
        this->url = url;
        this->saleDate = saleDate;
    }
    
    void setID(int carID) {this->carID = carID;}
    
    string getTitle() { return title; }
    int getRegistrationDate() { return registrationDate; }
    int getMileage() { return mileage; }
    string getFuelType() { return fuelType; }
    string getTransmission() { return transmission; }
    double getEngineSize() { return engineSize; }
    int getDoors() { return doors; }
    string getColor() { return color; }
    string getBodyType() { return bodyType; }
    double getPrice() { return price; }
    string getURL() { return url; }
    string getSaleDate() { return saleDate; }
    
};

class CarLinkedList {
private:
    Car* head = NULL;

public:
    Car* getHead() {return head;}

    void addNewNode(Car* car)
    {
        if (head == NULL)
        {
            head = car;
            return;
        }
        Car* current = head;
        while (true) {
            if (current->nextAddress == NULL) {
                break;
            }
            current = current->nextAddress;
        }
        current->nextAddress = car;
        //current->nextAddress = nullptr;
    }
    
    void list(int Number)
    {
        if (head == nullptr) {
            cout << "No " << Number+1 << " Linked List is empty" << endl;
            return;
        }
        cout << "Info of Number " << Number+1 << " Linked List => " << endl;
        Car* current = head;
        while(true) {
            cout << "ID: " << current->carID << " Title: " << current->title << " Registration Date: " << current->registrationDate << " Mileage: " << current->mileage << " Fuel Type: " << current->fuelType << " Transmission: " << current->transmission << " Engine Size: " << current->engineSize << " Doors: " << current->doors << " Color: " << current->color << " Body Type: " << current->bodyType << " Price: " << current->price << " URL: " << current->url << " Sale Date: " << current->saleDate << endl;
            if (current->nextAddress == nullptr) {
                break;
            }
            current = current->nextAddress;
        }
    }
};

class HashTable {
private:
    //This declares an array of type CarLinkedList, which can store multiple CarLinkedList objects.
    //The size of this array is unknown.
    CarLinkedList* CarLinkedListArray;
    //size = the number of car linked list
    int size;
    
public:
    HashTable(int size) {
        this->size = size;
        CarLinkedListArray = new CarLinkedList[size];
        //Initialize each linked list
        for (int i = 0; i < size; i++) {
            CarLinkedListArray[i] = CarLinkedList();
        }
    }
    
    void add(Car* car) {
        //Determine which linked list the car should be added to based on the car's ID
        int CarLinkedListIndex = hashFunction(car->carID);
        //Add the car to the corresponding linked list
        CarLinkedListArray[CarLinkedListIndex].addNewNode(car);
        
        cout << "added successfully" << endl;
        
    }
    
    void list() {
        //Iterate through the hash table
        for (int i = 0; i < size; i++) {
            CarLinkedListArray[i].list(i);
        }
    }
    
    //Write a hash function that uses modulo algorithm
    int hashFunction(int id) {
        return id % size;
    }
    
    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Car* current = CarLinkedListArray[i].getHead();
            while (current != nullptr) {
                Car* temp = current;
                current = current->nextAddress;
                delete temp;
            }
        }
        delete[] CarLinkedListArray;
    }
};

int main(int argc, const char * argv[]) {
    //Create a Hash Table
    HashTable* hashTable = new HashTable(1523);
    
    //Menu
    int option;
    bool loop = true;
    while (loop) {
        cout << "1. Add a new car" << endl;
        cout << "2. List all car" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";
        cin >> option;
        switch (option) {
            case 1:
            {
                int id;
                cout << "Input ID: ";
                cin >> id;
                cin.ignore();
                
                string title;
                cout << "Input Title: ";
                cin >> title;
                cin.ignore();
                
                double price;
                cout << "Price: ";
                cin >> price;
                cin.ignore();
                
                int registrationDate;
                cout << "Registration Date: ";
                cin >> registrationDate;
                cin.ignore();
                
                int mileage;
                cout << "Mileage: ";
                cin >> mileage;
                cin.ignore();
                
                string fuelType;
                cout << "Fuel Type: ";
                cin >> fuelType;
                cin.ignore();
                
                string transmission;
                cout << "Transmission: ";
                cin >> transmission;
                cin.ignore();
                
                double engineSize;
                cout << "Engine Size: ";
                cin >> engineSize;
                cin.ignore();
                
                int doors;
                cout << "Doors: ";
                cin >> doors;
                cin.ignore();
                
                string color;
                cout << "Color: ";
                cin >> color;
                cin.ignore();
                
                string bodyType;
                cout << "Body Type: ";
                cin >> bodyType;
                cin.ignore();
                
                string URL;
                cout << "URL: ";
                cin >> URL;
                cin.ignore();
                
                string saleDate;
                cout << "Sale Date: ";
                getline(cin, saleDate);
                
                Car* car = new Car(id, title, registrationDate, mileage, fuelType, transmission, engineSize, doors, color, bodyType, price, URL, saleDate);
                hashTable->add(car);
                break;
            }
            case 2:
            {
                hashTable->list();
                break;
            }
            case 3:
            {
                loop = false;
            }
            default:
                break;
        }
    }
    return 0;
}

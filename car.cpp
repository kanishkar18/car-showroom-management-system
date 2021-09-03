#include <iostream>
#include <fstream>
#include<string>
using namespace std;
int ID;
struct carshowroom {
    int id;
    string name;
    string carname;
    string price;
};

void addcustomer() {
    carshowroom customer;
    cout << "\n\tEnter the name : ";
    cin.get();
    getline(cin, customer.name);
    cout << "\n\tEnter  carname : ";
    cin >> customer.carname;
    cout << "\n\tEnter  car price : ";
    cin >> customer.price;
    ID++;

    ofstream write;
    write.open("csm.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << customer.name ;
    write << "\n" << customer.carname ;
    write << "\n" << customer.price;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file";
}

void print (carshowroom c) {
    cout << "\n\t***** customer ********";
    cout << "\n\tID  : " << c.id;
    cout << "\n\t CUSTOMER Name  : " << c.name;
    cout << "\n\t CAR NAME :" << c.carname;
    cout << "\n\t CAR PRICE  : " << c.price;

}

void readData() {
   carshowroom customer;
    ifstream read;
    read.open("csm.txt");
    while (!read.eof()) {
        read >> customer.id;
        read.ignore();
        getline(read, customer.name);
        read >> customer.carname;
        read >> customer.price;
        print(customer);
    }
    read.close();
}

int searchData() {
    int id;
    cout << "\n\tEnter the id you want to search : ";
    cin >> id;
    carshowroom customer;
    ifstream read;
    read.open("csm.txt");
    while (!read.eof()) {
        read >> customer.id;
        read.ignore();
        getline(read, customer.name);
        read >> customer.carname;
        read >> customer.price;
        if (customer.id == id) {
            print(customer);
            return id;
        }
    }
}

void deleteData() {
    int id = searchData();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        carshowroom customer;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("csm.txt");
        while (!read.eof()) {
            read >> customer.id;
            read.ignore();
            getline(read, customer.name);
            read >> customer.carname;
            read >> customer.price;
            if (customer.id != id) {
                tempFile << "\n" << customer.id;
                tempFile << "\n" << customer.name;
                tempFile << "\n" << customer.carname;
                tempFile << "\n" << customer.price;
            }
        }
        read.close();
        tempFile.close();
        remove("csm.txt");
        rename("temp.txt", "csm.txt");
        cout << "\n\t Deleted DATA ";
    }
    else {
        cout << "\n\tRecord is not deleted";
    }
}

void updateData() {
    int id = searchData();
    cout << "\n\t update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        carshowroom newData;
        cout << "\n\tEnter the customer name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter the carname : ";
        cin >> newData.carname;
        cout << "\n\tEnter car price : ";
        cin >> newData.price;
        carshowroom customer;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("csm.txt");
        while (!read.eof()) {
            read >> customer.id;
            read.ignore();
            getline(read, customer.name);
            read >> customer.carname;
            read >> customer.price;
            if (customer.id != id) {
                tempFile << "\n" << customer.id;
                tempFile << "\n" << customer.name;
                tempFile << "\n" << customer.carname;
                tempFile << "\n" << customer.price;
            }
            else {
                tempFile << "\n"<< customer.id;
                tempFile << "\n"<< newData.name;
                tempFile << "\n"<< newData.carname;
                tempFile << "\n"<< newData.price;
            }
        }
        read.close();
        tempFile.close();
        remove("csm.txt");
        rename("temp.txt", "csm.txt");
        cout << "\n\tData updated ";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

int main()
{
    ifstream read;
    cout<<"$$$$$$$$$$$   CAR SHOWROOM   $$$$$$$$$$$$$$";
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID = 0;
    }
    read.close();

    while (true) {
        cout << "\n\t1.Add Customer ";
        cout << "\n\t2.view Customer";
        cout << "\n\t3.Search Customer";
        cout << "\n\t4.Delete Customer";
        cout << "\n\t5.Update Customer";
        cout << "\n\t6.exit";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addcustomer();
            break;
        case 2:
            readData();
            break;
        case 3:
            searchData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        default:
            cout<<"invalid option:)";
            exit(0);
        }
    }

}


#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Car {
    int id;
    string model;
    string company;
    double rent;
    double buy;
    bool rented;
    bool sold;
};

vector<Car> cars = {
    {1, "Swift", "Maruti", 1200, 500000, false, false},
    {2, "i20", "Hyundai", 1500, 600000, false, false},
    {3, "City", "Honda", 2000, 900000, false, false},
    {4, "Fortuner", "Toyota", 3500, 3200000, false, false}
};

void printHeader() {
    cout << "Content-Type: text/plain\n\n";
}

void showCars() {
    printHeader();
    for (auto &car : cars) {
        cout << car.id << " | " << car.model << " | " << car.company
             << " | Rent/Day: ₹" << car.rent
             << " | Buy: ₹" << car.buy
             << " | Status: "
             << (car.sold ? "SOLD" : (car.rented ? "RENTED" : "AVAILABLE"))
             << "\n";
    }
}

void rentCar(int id, int days) {
    printHeader();
    for (auto &car : cars) {
        if (car.id == id && !car.rented && !car.sold) {
            car.rented = true;
            cout << "You rented " << car.model << " for " << days
                 << " days. Total: ₹" << (days * car.rent) << "\n";
            return;
        }
    }
    cout << "Car not available or invalid ID.\n";
}

void buyCar(int id) {
    printHeader();
    for (auto &car : cars) {
        if (car.id == id && !car.sold) {
            car.sold = true;
            cout << "Congratulations! You bought " << car.model
                 << " for ₹" << car.buy << "\n";
            return;
        }
    }
    cout << "Car already sold or invalid ID.\n";
}

int main() {
    string query = getenv("QUERY_STRING") ? getenv("QUERY_STRING") : "";
    string action;
    int id = 0, days = 0;

    stringstream ss(query);
    string key, value;
    while (getline(ss, key, '=')) {
        getline(ss, value, '&');
        if (key == "action") action = value;
        else if (key == "id") id = stoi(value);
        else if (key == "days") days = stoi(value);
    }

    if (action == "show")
        showCars();
    else if (action == "rent")
        rentCar(id, days);
    else if (action == "buy")
        buyCar(id);
    else {
        printHeader();
        cout << "Invalid action.\n";
    }

    return 0;
}

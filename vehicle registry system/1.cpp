#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    string year;

    static int vehicleCount;

public:
    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = "";
    }

    Vehicle(int id, string manu, string mod, string yr)
    {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        vehicleCount++;
    }

    void inputVehicleDetails()
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;

        cout << "Enter Manufacturer: ";
        cin >> manufacturer;

        cout << "Enter Model: ";
        cin >> model;

        cout << "Enter Year: ";
        cin >> year;
    }

    void displayVehicleDetails()
    {
        cout << "Vehicle ID: " << vehicleID << endl;
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    static int getVehicleCount()
    {
        return vehicleCount;
    }
};

int Vehicle::vehicleCount = 0;

class VehicleManagementSystem
{
private:
    Vehicle vehicles[100];
    int totalVehicles;

public:
    VehicleManagementSystem()
    {
        totalVehicles = 0;

        vehicles[totalVehicles++] = Vehicle(1, "Toyota", "Camry", "2020");
        vehicles[totalVehicles++] = Vehicle(2, "Honda", "Civic", "2019");
        vehicles[totalVehicles++] = Vehicle(3, "Ford", "Mustang", "2021");
    }

    void addVehicle()
    {
        if (totalVehicles < 100)
        {
            vehicles[totalVehicles].inputVehicleDetails();
            totalVehicles++;

            cout << "Vehicle added successfully!" << endl;
        }
        else
        {
            cout << "Vehicle limit reached! Cannot add more vehicles." << endl;
        }
    }

    void displayAllVehicles()
    {
        if (totalVehicles == 0)
        {
            cout << "No Vehicle Records Available!" << endl;
        }
        else
        {
            cout << "\nDisplaying All Vehicle Records:\n" << endl;

            for (int i = 0; i < totalVehicles; i++)
            {
                vehicles[i].displayVehicleDetails();
                cout << "------------------------" << endl;
            }
        }
    }

    void searchVehicleByID(int id)
    {
        bool found = false;

        for (int i = 0; i < totalVehicles; i++)
        {
            if (vehicles[i].getVehicleID() == id)
            {
                cout << "\nVehicle Found:\n";
                vehicles[i].displayVehicleDetails();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Vehicle with ID " << id << " not found!" << endl;
        }
    }
};

int main()
{
    VehicleManagementSystem vms;
    int choice;

    do
    {
        cout << "\n===== Vehicle Management System =====" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. Display All Vehicles" << endl;
        cout << "3. Search Vehicle by ID" << endl;
        cout << "4. Show Vehicle Count" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            vms.addVehicle();
            break;

        case 2:
            vms.displayAllVehicles();
            break;

        case 3:
        {
            int id;
            cout << "Enter Vehicle ID to Search: ";
            cin >> id;
            vms.searchVehicleByID(id);
            break;
        }

        case 4:
            cout << "Total Vehicles Created: "
                 << Vehicle::getVehicleCount()
                 << endl;
            break;

        case 5:
            cout << "Exiting Program. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid Choice! Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
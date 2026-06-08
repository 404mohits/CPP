#include <iostream>
#include <string>
using namespace std;

class Train
{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;

    static int trainCount;

public:

    Train()
    {
        trainNumber = 0;
        trainName = "";
        source = "";
        destination = "";
        trainTime = "";
    }


    Train(int num, string name, string src, string dest, string time)
    {
        trainNumber = num;
        trainName = name;
        source = src;
        destination = dest;
        trainTime = time;
        trainCount++;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cout << "Enter Train Name: ";
        cin >> trainName;

        cout << "Enter Source: ";
        cin >> source;

        cout << "Enter Destination: ";
        cin >> destination;

        cout << "Enter Train Time: ";
        cin >> trainTime;

        trainCount++;
    }

    void displayTrainDetails()
    {
        cout << "Train Number : " << trainNumber << endl;
        cout << "Train Name   : " << trainName << endl;
        cout << "Source       : " << source << endl;
        cout << "Destination  : " << destination << endl;
        cout << "Train Time   : " << trainTime << endl;
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem()
    {
        totalTrains = 0;

        trains[totalTrains++] =
            Train(101, "OkhaExpress", "Surat", "Mumbai", "10AM");
    }

    void addTrain()
    {
        if (totalTrains < 100)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;

            cout << "\nTrain Record Added Successfully!\n";
        }
        else
        {
            cout << "Train Storage Full!\n";
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "No Train Records Available!\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\n----- Train " << i + 1 << " -----\n";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        bool found = false;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found:\n";
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Train with Number "
                 << number
                 << " Not Found!\n";
        }
    }
};

int main()
{
    RailwaySystem r;
    int choice = 0;

    while (choice != 4)
    {
        cout << "\n========== Railway Reservation System ==========\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train By Number\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            r.addTrain();
            break;

        case 2:
            r.displayAllTrains();
            break;

        case 3:
        {
            int number;
            cout << "Enter Train Number To Search: ";
            cin >> number;

            r.searchTrainByNumber(number);
            break;
        }

        case 4:
            cout << "Thank You For Using Railway Reservation System!\n";
            break;

        default:
            cout << "Invalid Choice! Please Try Again.\n";
        }
    }

    cout << "\nTotal Trains Entered: "
         << Train::getTrainCount() << endl;

    return 0;
}


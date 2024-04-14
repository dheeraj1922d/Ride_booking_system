#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Driver.hpp"
using namespace std;

class DriverManager
{
private:
    static const string filename;

public:
    // Function to save drivers' data to a file
    static void saveDrivers(const Driver &driver)
    {
        ofstream file(filename, ios::app); // Open file in append mode

        if (file.is_open())
        {
            file << driver.getName() << "," << driver.getContactInfo() << "," << driver.getVehicleType() << "," << driver.getLocation() << "\n";
            file.close();
            cout << "Driver data saved successfully.\n";
        }
        else
        {
            cout << "Unable to open file to save driver data.\n";
        }
    }

    // Function to load drivers' data from a file
    static vector<Driver> loadDrivers()
    {
        vector<Driver> drivers;
        ifstream file(filename);
        string name, contact, vehicle, location;

        if (!file.is_open())
        {
            cout << "Unable to open file to load driver data.\n";
            return drivers; // Return empty vector if unable to open file
        }

        while (getline(file, name, ',') && getline(file, contact, ',') && getline(file, vehicle, ',') && getline(file, location, '\n'))
        {
            drivers.push_back(Driver(name, contact, vehicle, location));
        }

        file.close();

        if (drivers.empty())
        {
            cout << "No data loaded from file.\n";
        }
        else
        {
            cout << "Driver data loaded successfully.\n";
        }

        return drivers;
    }
};

const string DriverManager::filename = "drivers.txt";

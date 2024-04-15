#include <iostream>
#include <fstream>
#include <vector>
#include "trip.hpp" // Include the Trip class header file
using namespace std;

class TripManager
{
private:
    Driver assignedDriver; // Store the assigned driver information

    // Function to check driver availability at the pickup location
    bool isDriverAvailable(const string &pickupLocation)
    {
        // Load drivers' data from the driver manager
        vector<Driver> drivers = DriverManager::loadDrivers();

        // Check if any driver is available at the pickup location
        for (const auto &driver : drivers)
        {
            // For simplicity, let's assume driver is available if they are in the same location
            if (driver.getLocation() == pickupLocation)
            {
                assignedDriver = driver; // Assign the driver
                return true;
            }
        }

        return false;
    }

    // Function to calculate trip cost
    double calculateTripCost(const string &pickupLocation, const string &destination)
    {
        // Dummy implementation for now
        // Calculate cost based on distance between pickup and destination
        // This can be replaced with a more accurate calculation based on real-time data
        return 20.0; // Dummy cost
    }

    // Function to display a ticket after the trip is confirmed for the rider
    void displayTicket(const Rider &rider, const Driver &driver, double cost, const Trip &trip)
    {
        // Calculate width for centering
        int width = 60;

        // Print top border
        cout << setw(width) << setfill('=') << "" << endl;
        cout << setfill(' ');

        // Print title
        cout << setw((width + 4) / 2) << "Ticket" << endl;

        // Print rider details
        cout << setw(width) << setfill('-') << "" << endl;
        cout << setfill(' ');
        cout << left << setw(width / 2) << "Rider Details:" << right << endl;
        cout << "Name: "<< rider.getName() << endl;
        cout << "Contact Info: " << rider.getContactInfo() << endl;

        // Print trip details
        cout << setw(width) << setfill('-') << "" << endl;
        cout << setfill(' ');
        cout << left << setw(width / 2) << "Trip Details:" << right << endl;
        cout << "Pickup Location: " << trip.getPickupLocation() << endl;
        cout << "Destination: " << trip.getDestination() << endl;
        cout << "Ride Type: " << trip.getRideType() << endl;
        cout << "Special Instructions: " << trip.getInstructions() << endl;

        // Print driver details
        cout << setw(width) << setfill('-') << "" << endl;
        cout << setfill(' ');
        cout << left << setw(width / 2) << "Driver Details:" << right << endl;
        cout << "Name: "  << driver.getName() << endl;
        cout << "Contact Info: " << driver.getContactInfo() << endl;
        cout << "Vehicle Type: " << driver.getVehicleType() << endl;
        cout << "Cost per Kilometer: " << cost << " rupees" << endl;

        // Print bottom border
        cout << setw(width) << setfill('=') << "" << endl;
        cout << setfill(' ');
    }

    // Getter function to retrieve the assigned driver information
    Driver getAssignedDriver() const
    {
        return assignedDriver;
    }



public:
    TripManager() : assignedDriver("", "", "", "") {}

    // Function to confirm the trip
    void confirmTrip(const Trip &trip, const Rider &rider)
    {
        // Check if a driver is available at the pickup location
        if (!isDriverAvailable(trip.getPickupLocation()))
        {
            cout << "Sorry, no driver available at the pickup location. Trip rejected.\n";
            return;
        }

        // Calculate trip cost
        double tripCost = calculateTripCost(trip.getPickupLocation(), trip.getDestination());

        // Display ticket
        displayTicket(rider, getAssignedDriver(), tripCost, trip);
    }
};

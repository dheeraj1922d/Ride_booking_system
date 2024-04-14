#include <iostream>
#include <fstream>
#include <vector>
// #include "driverMgr.hpp" // Include the Driver class header file
#include "trip.hpp"   // Include the Trip class header file
using namespace std;

class TripManager {
private:
    // Function to check driver availability at the pickup location
    bool isDriverAvailable(const string& pickupLocation) {
        // Load drivers' data from the driver manager
        vector<Driver> drivers = DriverManager::loadDrivers();

        // Check if any driver is available at the pickup location
        for (const auto& driver : drivers) {
            // For simplicity, let's assume driver is available if they are in the same location
            // cout<<"driver report"<<endl;
            // cout<<driver.getName()<<driver.getContactInfo()<<driver.getLocation()<<driver.getVehicleType()<<endl;
            if (driver.getLocation() == pickupLocation) {
                return true;
            }
        }

        return false;
    }

    // Function to calculate trip cost
    double calculateTripCost(const string& pickupLocation, const string& destination) {
        // Dummy implementation for now
        // Calculate cost based on distance between pickup and destination
        // This can be replaced with a more accurate calculation based on real-time data
        return 20.0; // Dummy cost
    }

public:
    // Function to confirm the trip
    void confirmTrip(const Trip& trip) {
        // Check if a driver is available at the pickup location
        if (!isDriverAvailable(trip.getPickupLocation())) {
            cout << "Sorry, no driver available at the pickup location. Trip rejected.\n";
            return;
        }

        // Calculate trip cost
        double tripCost = calculateTripCost(trip.getPickupLocation(), trip.getDestination());

        // Display trip details
        cout << "Trip confirmed!\n";
        cout << "Pickup Location: " << trip.getPickupLocation() << endl;
        cout << "Destination: " << trip.getDestination() << endl;
        cout << "Ride Type: " << trip.getRideType() << endl;
        cout << "Instructions: " << trip.getInstructions() << endl;
        cout << "Trip Cost: " << tripCost << " USD\n";

        // Provide estimated time for pickup (dummy implementation for now)
        cout << "Estimated time for pickup: 10 minutes\n";
    }
};

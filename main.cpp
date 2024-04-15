#include <iostream>
#include <iomanip>
#include <string>
#include "driverMgr.hpp"
#include "riderMgr.hpp"
#include "tripMgr.hpp"
using namespace std;

// Function to take personal details of the user
void takePersonalDetails(string& name, string& contact) {
    cout << "\n===== Personal Details =====\n";
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your contact information: ";
    getline(cin, contact);
}

// Function to take trip details from the rider
void takeTripDetails(string& pickupLocation, string& destination, string& rideType, string& instructions) {
    cout << "\n===== Trip Details =====\n";
    cout << "Where do you want to be picked up? ";
    getline(cin, pickupLocation);
    cout << "Where do you want to go? ";
    getline(cin, destination);
    cout << "What type of ride do you prefer? ";
    getline(cin, rideType);
    cout << "Any special instructions? ";
    getline(cin, instructions);
}

// Function to display driver details for the confirmed trip
void displayDriverDetails(const Driver& driver, double cost) {
    cout << "\n===== Driver Details =====\n";
    cout << "Name: " << driver.getName() << endl;
    cout << "Contact Info: " << driver.getContactInfo() << endl;
    cout << "Vehicle Type: " << driver.getVehicleType() << endl;
    cout << "Cost per Kilometer: " << cost << " rupees" << endl;
}


// Main function
int main() {
    // Take personal details of the user
    string name, contact;
    takePersonalDetails(name, contact);

    // Ask the user whether they are a rider or driver
    cout << "\n===== Welcome to Ride Booking System =====\n";
    cout << "Are you a Rider or a Driver?\n";
    cout << "Enter 'R' for Rider, 'D' for Driver: ";
    char userType;
    cin >> userType;
    cin.ignore(); // Clear the input buffer
    
    if (userType == 'R' || userType == 'r') {
        // Take trip details from the rider
        string pickupLocation, destination, rideType, instructions;
        takeTripDetails(pickupLocation, destination, rideType, instructions);

        // Create a trip object
        Trip trip(pickupLocation, destination, rideType, instructions);

        // Confirm the trip
        TripManager tripManager;
        tripManager.confirmTrip(trip , Rider(name , contact));

        // Stop the program
        cout << "\nThank you for using our service!\n";
    } else if (userType == 'D' || userType == 'd') {
        // Take KYC details from the driver
        string name , contact , vehicle , location ;
        cout << "\n===== Driver Registration =====\n";
        cout<<"Enter your name: ";
        cout<<"\n";
        getline(cin , name );
        cout<<"Enter contact number: ";
        cout<<"\n";
        getline(cin  , contact);
        cout<<"Enter vehicle type: ";
        cout<<"\n";
        getline(cin , vehicle);
        cout<<"Enter your location: ";
        cout<<"\n";
        getline(cin , location);
        
        // Save the driver details using the DriverManager
        DriverManager::saveDrivers(Driver(name, contact, vehicle , location));

        //display driver details 
        displayDriverDetails(Driver(name, contact, vehicle , location) , 50);

        // Inform the user and stop the program
        cout << "\nYou are now part of our service. Thank you!\n";
    } else {
        cout << "\nInvalid input. Please try again.\n";
    }

    return 0;
}

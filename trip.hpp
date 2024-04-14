#include <iostream>
#include <string>
using namespace std;

class Trip {
private:
    string pickupLocation;
    string destination;
    string rideType;
    string instructions;
    // Additional attributes can be added as needed

public:
    Trip(const string& pickupLocation, const string& destination, const string& rideType, const string& instructions)
        : pickupLocation(pickupLocation), destination(destination), rideType(rideType), instructions(instructions) {}

    string getPickupLocation() const {
        return pickupLocation;
    }

    string getDestination() const {
        return destination;
    }

    string getRideType() const {
        return rideType;
    }

    string getInstructions() const {
        return instructions;
    }

    // Additional getter and setter functions can be added as needed
};

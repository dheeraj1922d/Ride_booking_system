#include <iostream>
#include <string>
using namespace std;

class Driver {
private:
    string name;
    string contactInfo;
    string vehicleType;
    string location;

public:
    // Constructor with initialization list
    Driver(const string& driverName, const string& driverContact, const string& driverVehicle, const string& driverLocation)
        : name(driverName), contactInfo(driverContact), vehicleType(driverVehicle), location(driverLocation) {}

    // Getter methods
    const string& getName() const { return name; }
    const string& getContactInfo() const { return contactInfo; }
    const string& getVehicleType() const { return vehicleType; }
    const string& getLocation() const { return location; }

    // Setter methods
    void setName(const string& driverName) { name = driverName; }
    void setContactInfo(const string& driverContact) { contactInfo = driverContact; }
    void setVehicleType(const string& driverVehicle) { vehicleType = driverVehicle; }
};

#include <iostream>
#include <string>
using namespace std;

class Rider {
private:
    string name;
    string contactInfo;
    // Additional attributes can be added as needed

public:
    Rider(const string& riderName, const string& riderContact) : name(riderName), contactInfo(riderContact) {}

    string getName() const {
        return name;
    }

    string getContactInfo() const {
        return contactInfo;
    }

    void setName(const string& riderName) {
        name = riderName;
    }

    void setContactInfo(const string& riderContact) {
        contactInfo = riderContact;
    }
};

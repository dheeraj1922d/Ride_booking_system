#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "riderCls.hpp"
using namespace std;

class RiderManager {
private:
    static const string filename;

public:
    // Function to save riders' data to a file
    static void saveRiders(const vector<Rider>& riders) {
        ofstream file(filename);

        if (file.is_open()) {
            for (const auto& rider : riders) {
                file << rider.getName() << "," << rider.getContactInfo() << "\n";
            }
            file.close();
            cout << "Rider data saved successfully.\n";
        } else {
            cout << "Unable to open file to save rider data.\n";
        }
    }

    // Function to load riders' data from a file
    static vector<Rider> loadRiders() {
        vector<Rider> riders;
        ifstream file(filename);
        string name, contact;

        if (file.is_open()) {
            while (getline(file, name, ',')) {
                getline(file, contact, '\n');
                riders.push_back(Rider(name, contact));
            }
            file.close();
            cout << "Rider data loaded successfully.\n";
        } else {
            cout << "Unable to open file to load rider data.\n";
        }

        return riders;
    }
};

const string RiderManager::filename = "riders.txt";

#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100

class Patient {
public:
    int prior;
    int arr;
    string name;

    void PatientDetail(string n, int p, int a) {
        name = n;
        prior = p;
        arr = a;
    }
};

class Queue {
public:
    Queue() : size(0) {}

    void AddPatient(Patient patient) {
        if (size < MAX_SIZE) {
            patients[size] = patient;
            size++;
            sortPatients();
        } else {
            cout << "Queue is full, cannot add more patients." << endl;
        }
    }

    bool IsEmpty() const {
        return size == 0;
    }

    void PrintQueue() const {
        for (int i = 0; i < size; i++) {
            cout << "Name: " << patients[i].name << ", Priority: " << patients[i].prior << ", Arrival Order: " << patients[i].arr << endl;
        }
    }

    Patient TreatPatient() {
        Patient topPatient;
        if (size > 0) {
            topPatient = patients[0];

            for (int i = 1; i < size; ++i) {
                patients[i - 1] = patients[i];
            }

            size--;
        }
        return topPatient;
    }

    void sortPatients() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (patients[j].prior > patients[i].prior ||
                    (patients[j].prior == patients[i].prior && patients[j].arr < patients[i].arr)) {
                    swap(patients[i], patients[j]);
                }
            }
        }
    }


    Patient patients[MAX_SIZE];
    int size;
};

int main() {
    Queue q;
    int numPatients;

    cout << "Enter the number of patients: ";
    cin >> numPatients;

    for (int i = 0; i < numPatients; ++i) {
        string name;
        int priority, arrival;

        cout << "Enter details for patient " << (i + 1) << endl;
        cout << "Name (single word): ";
        cin >> name;
        cout << "Priority: ";
        cin >> priority;
        cout << "Arrival Order: ";
        cin >> arrival;

        Patient p;
        p.PatientDetail(name, priority, arrival);
        q.AddPatient(p);
    }

    cout << "\nPriority Queue before treatment:" << endl;
    q.PrintQueue();

    cout << "\nTreating patients in order:" << endl;
    while (!q.IsEmpty()) {
        Patient p = q.TreatPatient();
        cout << "Treating: " << p.name << ", Priority: " << p.prior << ", Arrival Order: " << p.arr << endl;
    }

    return 0;
}

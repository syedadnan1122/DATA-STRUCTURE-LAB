#include <iostream>
using namespace std;

struct Node {
    int patientID;
    Node* next;
    Node* prev;
    Node(int id) {
        patientID = id;
        next = nullptr;
        prev = nullptr;
    }
};

class ERQueue {
private:
    Node* head;
    Node* tail;
public:
    ERQueue() {
        head = nullptr;
        tail = nullptr;
    }
    ~ERQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning(int patientID) {
        Node* newNode = new Node(patientID);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int patientID) {
        Node* newNode = new Node(patientID);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(int patientID, int pos) {
        if (pos <= 0) {
            cout << "Invalid position! Position must be positive." << endl;
            return;
        }
        if (pos == 1) {
            insertAtBeginning(patientID);
            return;
        }
        Node* newNode = new Node(patientID);
        Node* current = head;
        int count = 1;
        while (current != nullptr && count < pos - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr) {
            insertAtEnd(patientID);
        } else if (current->next == nullptr) {
            insertAtEnd(patientID);
        } else {
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    bool deleteFromBeginning(int* removedID) {
        if (head == nullptr) {
            return false;
        }
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        if (removedID != nullptr) {
            *removedID = temp->patientID;
        }
        delete temp;
        return true;
    }

    void display() const {
        if (head == nullptr) {
            cout << "No patients in ER queue!" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->patientID;
            if (current->next != nullptr) cout << " <-> ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    ERQueue list;
int choice, id, pos, removed;

    do {
        cout << "\n1. Add critical patient at beginning";
        cout << "\n2. Add normal patient at end";
        cout << "\n3. Add patient at specific position";
        cout << "\n4. Remove treated patient from beginning";
        cout << "\n5. Display all patients";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient ID: ";
                cin >> id;
                list.insertAtBeginning(id);
                cout << "Updated ER Queue:\n";
                list.display();
                break;
            case 2:
                cout << "Enter patient ID: ";
                cin >> id;
                list.insertAtEnd(id);
                cout << "Updated ER Queue:\n";
                list.display();
                break;
            case 3:
                cout << "Enter patient ID: ";
                cin >> id;
                cout << "Enter position: ";
                cin >> pos;
                list.insertAtPosition(id, pos);
                cout << "Updated ER Queue:\n";
                list.display();
                break;
            case 4:
                if (list.deleteFromBeginning(&removed)) {
                    cout << "Patient " << removed << " treated and removed.\n";
                } else {
                    cout << "No patients to remove.\n";
                }
                cout << "Updated ER Queue:\n";
                list.display();
                break;
            case 5:
                cout << "Current ER Queue:\n";
                list.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

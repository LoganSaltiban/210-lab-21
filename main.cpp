#include <iostream>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;
const int AGE_MIN = 1, AGE_MAX = 20, INDEX_MIN = 0, INDEX_MAX = 14;

class DoublyLinkedList {
    private:
        // Goat Class
        class Goat
        {
            private:
                int age;
                string name;
                string color;
                string colors[15] = {"Blue", "Purple", "Cyan", "Red", "Orange", "Yellow", "Coffee", "Tan", "Black", "Transparent", "Pink", "Crimson", "Green", "Forest", "Violet", };
                string names[15] = {"Jake", "Brian", "Alisha", "Cassy", "Taylor", "Logan", "Janelle", "Crystal", "Robert", "Erik", "Nielsen", "Crossley", "David", "Jahmyr", "Gibbs", };
        
            public:
                // Default Constructor
                Goat()
                {
                    age = rand() % (AGE_MAX - AGE_MIN + 1) + AGE_MIN;
                    name = names[rand() % (INDEX_MAX - INDEX_MIN + 1) + INDEX_MIN];
                    color = colors[rand() % (INDEX_MAX - INDEX_MIN + 1) + INDEX_MIN];
                }

                // Parameter Constructor
                Goat(int age, string color, string name)
                {
                    this->age = age;
                    this->color = color;
                    this->name = name;
                }

                // Getters
                int getGoatAge()
                {
                    return age;
                }

                string getGoatColor()
                {
                    return color;
                }

                string getGoatName()
                {
                    return name;
                }
        };

        struct Node {
            Goat goatData;
            Node* prev;
            Node* next;

            Node(Goat& goatObject, Node* p = nullptr, Node* n = nullptr) {
                goatData = goatObject;
                prev = p;
                next = n;
            }
        };


    // Head/Tail Pointers
    Node* head;
    Node* tail;
    public:
        // constructor
        DoublyLinkedList() { head = nullptr; tail = nullptr; }

        void push_back_goat()
        {
            Goat newGoat;
            push_back(newGoat);
        }

        void push_back(Goat& goatObject) {
            Node* newNode = new Node(goatObject);
            if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
            else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            }
        }

        void push_front_goat()
        {
            Goat newGoat;
            push_front(newGoat);
        }

        void push_front(Goat& goatObject) {
            Node* newNode = new Node(goatObject);
            if (!head) // if there's no head, the list is empty
                head = tail = newNode;
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

void insert_after(Goat& goatObject, int position) {
    if (position < 0) {
        cout << "Position must be >= 0." << endl;
        return;
    }

    Node* newNode = new Node(goatObject);

    if (!head) {
        head = tail = newNode;
        return;
    }

    Node* temp = head;

    for (int i = 0; i < position && temp; ++i)
    temp = temp->next;

    if (!temp) {
        cout << "Position exceeds list size. Node not inserted.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next)
        temp->next->prev = newNode;
    else
        tail = newNode; // Inserting at the end
        temp->next = newNode;
}

void delete_node(Goat& goatObject) {
    if (!head) return; // Empty list

    Node* temp = head;

    while (temp && temp->goatData.getGoatName() != goatObject.getGoatName())
        temp = temp->next;
    
    if (!temp) return; // Value not found
    
    if (temp->prev) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next; // Deleting the head
    }

    if (temp->next) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev; // Deleting the tail
    }
        delete temp;
}

void print() {
    Node* current = head;
    if (!current) 
    {
        cout << "List is empty..." << endl;
        return;
    }

    while (current) {
        cout << "Name: " << current->goatData.getGoatName() << endl;
        cout << "Age: " << current->goatData.getGoatAge() << endl;
        cout << "Color: " << current->goatData.getGoatColor() << endl;
        cout << endl;
        current = current->next;
    }
    cout << endl;
}

void print_reverse() {
    Node* current = tail;

    if (!current) 
    {
        cout << "List is empty..." << endl;
        return;
    }

    while (current) {
        cout << "Name: " << current->goatData.getGoatName() << endl;
        cout << "Age: " << current->goatData.getGoatAge() << endl;
        cout << "Color: " << current->goatData.getGoatColor() << endl;
        cout << endl;
        current = current->prev;
    }
    cout << endl;
}

~DoublyLinkedList() {
while (head) {
Node* temp = head;
head = head->next;
delete temp;
}
}
};
// Driver program
int main() {

    srand(time(0));

    DoublyLinkedList goatList;

    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        goatList.push_back_goat();

cout << "List forward: ";
goatList.print();
cout << "List backward: ";
goatList.print_reverse();
cout << "Deleting list, then trying to print.\n";
goatList.~DoublyLinkedList();
cout << "List forward: ";
goatList.print();
return 0;
}
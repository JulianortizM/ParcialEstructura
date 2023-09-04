#include <iostream>
using namespace std;

//Julian David Ortiz Molina
//Parcial Lista Circular
//Estructura de Datos Avanzada

class Node {
private:
    int data;
    Node* next;

    friend class LinkedList;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    int getFront() const;
    void addFront(int va);
    void printForward();
    void update(int oldValue, int newValue);
private:
    Node* header;
};

LinkedList::LinkedList() {
    header = new Node;
    header->next = header;
};

int LinkedList::getFront() const {
    return header->next->data;
};

void LinkedList::addFront(int va) {
    Node* nd = new Node;
    nd->data = va;
    nd->next = header->next;
    header->next = nd;
};

void LinkedList::printForward() {
    Node* current = header->next;

    while (current != header) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
};

void LinkedList::update(int oldValue, int newValue) {
    Node* current = header->next;

    while (current != header) {
        if (current->data == oldValue) {
            current->data = newValue;
        }
        current = current->next;
    }
};

LinkedList::~LinkedList() {
    while (header->next != header)

    delete header;
};

int main() {
    LinkedList myList;

    while (true) {
        cout << "\nEscoja un numero opcion:\n";
        cout << "1. Poner un numero al principio\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Actualizar valor\n";
        cout << "4. Salir\n";
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Ingrese numero que desee para agregar al inicio: ";
            int value;
            cin >> value;
            myList.addFront(value);
        } else if (choice == 2) {
            cout << "Lista: ";
            myList.printForward();
        } else if (choice == 3) {
            int oldValue, newValue;
            cout << "Ingrese el valor que quiere cambiar: ";
            cin >> oldValue;
            cout << "Ingrese el nuevo valor para agregar: ";
            cin >> newValue;
            myList.update(oldValue, newValue);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Algo esta mal, escoja otro numero.\n";
        }
    }
    return 0;
}


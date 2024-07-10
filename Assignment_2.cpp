#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head=nullptr;
    }
    void insertAtBeginning(int val) {
        Node* newNode=new Node(val);
        newNode->next=head;
        head=newNode;
    }
    void insertAtMiddle(int val, int position) {
        Node* newNode=new Node(val);
        Node* temp=head;
        int count=1;
        while (temp!=nullptr && count<position) {
            temp=temp->next;
            count++;
        }
        if (temp!=nullptr) {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node*temp=head;
            while (temp->next!=nullptr) {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"nullptr"<<endl;
    }
};

int main() {
    LinkedList list;
    int choice, value, position;

    do {
        cout<<"1. Insert at the beginning"<<endl;
        cout<<"2. Insert at the middle"<<endl;
        cout<<"3. Insert at the end"<<endl;
        cout<<"4. Display the linked list"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            case 1:
                cout<<"Enter the value to insert at the beginning: ";
                cin>>value;
                list.insertAtBeginning(value);
                break;

            case 2:
                cout<<"Enter the value to insert: ";
                cin>>value;
                cout<<"Enter the position to insert (1-based index): ";
                cin>>position;
                list.insertAtMiddle(value, position);
                break;

            case 3:
                cout<<"Enter the value to insert at the end: ";
                cin>>value;
                list.insertAtEnd(value);
                break;

            case 4:
                cout<<"Linked List: ";
                list.display();
                break;

            case 5:
                cout<<"Exiting the program." <<endl;
                break;

            default:
                cout<<"Invalid choice. Please try again." <<endl;
        }
    } while (choice!=5);

    return 0;
}

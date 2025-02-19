#include <iostream>
using namespace std;

/*
Linked List :-
Collction of Nodes
Linear Dta Structure
Non-Continuous Memory Location

Types of Linked List :-
1) Singly Linked List
2) Doubly Linked List
3) Circular Singly Linked List
4) Circular Doubly Linked List
-> Sorted Linked List
*/

// (I) Singly Linked List

class Node
{
public:
    int data;
    Node* next;

    Node()
    {
        // cout << "I am a default Node Constructor\n";
        this->next = NULL;
    }

    Node(int data)
    {
        // cout << "I am a Parameterized Node Constructor\n";
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Dtor called for : " << this->data << endl;
    }
};

/*
Never use the original Pointer of node, no matters whether
by reference of by value, always make a temp Pointer.
*/

void print(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        // cout << "|" << temp->data << "|";
        // cout << temp->next << "| --> ";

        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head)
{
    Node* temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++ ;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data)//Take head By-Reference
{
    if (head == NULL) // Empty LL
    {
        // Create new Node
        Node *newNode = new Node(data);

        //Update head
        head = newNode;
        tail = newNode;

        // Single Node --> head and tail are on same node
    }
    
    else // Non-Empty LL
    {
        // Create a new Node
        Node *newNode = new Node(data);

        // Attach new node to head
        newNode->next = head;

        // Update head
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data)
{
    if (head == NULL) // Empty LL
    {
        // Create new Node
        Node *newNode = new Node(data);

        //Update head
        head = newNode;
        tail = newNode;

        // Single Node --> head and tail are on same node
    }
    
    else // Non-Empty LL
    {
        // Create a new Node
        Node *newNode = new Node(data);

        // Attach new node to tail
        tail->next = newNode;

        // Update tail
        tail = newNode;
    }
}

void insertNode(Node* &head, Node* &tail, int data, int position)
{
    int length = getLength(head);

    if (position <= 1) // position == 1
    {
        insertAtHead(head, tail, data);
    }
    else if(position > length) // position == length + 1
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        Node *newNode = new Node (data);

        Node* prev = NULL;
        Node* curr = head;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }

        // Attach Prvious to new Node
        prev->next = newNode;

        //Attach new new Node to curr
        newNode->next = curr;


    // By Using a Single prev Pointer :-

        // Node *newNode = new Node (data);
        // Node* prev = head;

        // while (position != 2)
        // {
        //     prev = prev->next;
        //     position--;
        // }

        // newNode->next = prev->next;
        // prev->next = newNode;
    }
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    if (head == NULL) // Empty List
    {
        cout << "Cannot delete, because LL is Empty" << endl;
        return;
    }

    else if (head == tail) // Single Element
    {
        Node* temp = head;
        delete temp;
        head = tail = NULL;
        return;
    }

    int len = getLength(head);

    if (position == 1) // First Node ko Delete karo :-
    {
        Node* temp = head; // Changing Name of headNode (temp)
        head = head->next; // Update next Node (head)
        temp->next = NULL; // Isolate Node
        delete temp; // Deleting the Node
    }

    else if (position == len) // Last Node ko Delete karo :-
    {
        Node* prev = head;
        while (prev->next != tail) // OR (position != 2), (position--)
        {
            prev = prev->next;
        } // Came on Last Node
        prev->next = NULL; // Isolate Node
        delete tail; // Deleting the Node
        tail = prev; // Update previous Node (tail)
    }

    else // In Between Delete karo :-
    {
        Node* prev = NULL;
        Node* curr = head;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = curr->next; // prev pointing to the next Node of curr
        curr->next = NULL; // Isolating the Node
        delete curr; // Deleting the Node


    // By Using a Single prev Pointer :-

        // Node* prev = head;
        // while (position != 2)
        // {
        //     prev = prev->next;
        //     position--;
        // }
        // Node* temp = prev->next; // Naming the Node to Delete
        // prev->next = temp->next; // Isolating the Node
        // delete temp; // Deleting the Node
    }
}

// void deleteNode2(Node* &head, Node* &tail, int data){} // Deleting Node by the data given

int main()
{
    // Creation of Node :-

    // Node a; // Static Allocation (Object)
    // Node* b = new Node(); // Dynamic Allocation (Object)


    // Creating Linked List :-

    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* forth = new Node(40);
    // Node* fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = forth;
    // forth->next = fifth; // Linked List created


    // Node* head = first; // First Node ko head bana diya hai
    // Node* tail = fifth; // Last Node ko tail bana diya hai

    // print(head);

    // cout << getLength(head) << endl;

    // print(head);
    // insertAtHead(head, tail, 0);
    // print(head);

    // print(head);
    // insertAtTail(head, tail, 60);
    // print(head);

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 50);

    // print(head);
    // insertNode(head, tail, 40, 4);
    // print(head);
    
    print(head);
    deleteNode(head, tail, 3);
    print(head);
    
    return 0;
}
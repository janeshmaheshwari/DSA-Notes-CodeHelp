#include <iostream>
using namespace std;

// (II) Doubly Linked List :-

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node()
    {
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Dtor called for : " << this->data << endl;
    }
};

void print(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << "<-" << temp->data << "->";
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
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data)
{
    if (head == NULL)
    {
        Node* newNode = new Node(data);
        head = tail = newNode;
    }
    else
    {
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode; // OR head = head->prev
    }
}

void insertAtTail(Node* &head,Node* &tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode; // OR tail = tail->next
    }
}

void insertNode(Node* &head, Node* &tail, int data, int position)
{
    int length = getLength(head);

    if (position <= 1)
    {
        insertAtHead(head, tail, data);
    }
    else if(position > length)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        Node *newNode = new Node (data);

        Node* prevN = NULL;
        Node* currN = head;

        while (position != 1)
        {
            prevN = currN;
            currN = currN->next;
            position--;
        }

        prevN->next = newNode;
        newNode->prev = prevN;
        newNode->next = currN;
        currN->prev = newNode;
    
    
    // By Using a Single prev Pointer :- Work in Progress

    }
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    if (head == NULL)
    {
        cout << "Cannot delete, because LL is Empty" << endl;
        return;
    }

    else if (head == tail)
    {
        Node* temp = head;
        delete temp;
        head = tail = NULL;
        return;
    }

    int len = getLength(head);

    if (position == 1)
    {
        Node* temp = head; // Changing Name of headNode (temp)
        head = head->next; // Update next Node (head)
        head->prev = NULL;
        temp->next = NULL; // Isolate Node (temp->prev is alredy NULL)
        delete temp; // Deleting the Node
    }

    else if (position == len)
    {
        Node*temp = tail; // Changing Name of tailNode (temp)
        tail = tail->prev; // Update previous Node (tail)
        tail->next = NULL;
        temp->prev = NULL; // Isolate Node (temp->next is already NULL)
        delete temp; // Deleting the Node
    }

    else // In Between Delete karo :-
    {
        Node* currN = head;

        while (position != 1)
        {
            currN = currN->next;
            position--;
        }
        Node* prevN = currN->prev;
        Node* nextN = currN->next;

        prevN->next = nextN;
        currN->next = currN->prev = NULL;
        (nextN)->prev = prevN;
        delete currN;

    
    // By Using a Single curr Pointer :- Work in Progress
    
    }
}

// void deleteNode2(Node* &head, Node* &tail, int data){} // Deleting Node by the data given

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    print(head);
    insertNode(head, tail, 30, 3);
    print(head);
    deleteNode(head, tail, 3);
    print(head);

    return 0;
}


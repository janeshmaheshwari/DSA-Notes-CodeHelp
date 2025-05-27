#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    int children_count;
    Node**children;

    Node(int value)
    {
        this->data = value;
        this->children_count = 0;
        this->children = 0;
    }
};

Node* takeInput()
{
    int data, count;
    cout << "Enter root data : ";
    cin >> data;

    cout << "Enter children count for " << data << " node : ";
    cin >> count;

    Node* root = new Node(data);
    root->children_count = count;
    root->children = new Node*[count]; // Array to store Links to Children

    for (int i = 0; i < count; i++)
    {
        root->children[i] = takeInput();
    }
    return root;
}

void levelOrderprint(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(0); // NULL

    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if (front == NULL)
        {
            cout << endl;
            if (!q.empty()) q.push(0); // NULL
        }
        else // front != NULL
        {
            cout << front->data << " ";
            for (int i = 0; i < front->children_count; i++)
            {
                if((front->children[i])) // != NULL
                {
                    q.push(front->children[i]); // the PUSH
                }
            }
        }
    }
}

int main()
{
    Node* root = takeInput();
    cout << endl;
    levelOrderprint(root);
    // 1 4 2 2 21 0 22 0 3 2 31 0 32 0 4 2 41 0 42 0 5 2 51 0 52 0

    return 0;
}
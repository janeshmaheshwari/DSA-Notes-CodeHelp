#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* bstFromInorder(int inorder[], int s, int e) // Balanced BST
{
    if (s > e) return NULL;
    
    int mid = (s+e)/2;
    Node* root = new Node(inorder[mid]);

    root->left = bstFromInorder(inorder, s, mid-1);
    root->right = bstFromInorder(inorder, mid+1, e);

    return root;
}

void levelOrderTraversal(Node* root)
{
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Convert BST into Sorted Doubly LL
void convertBSTtoDLL(Node* root, Node* &head)
{
    if(!root) return;

    // RNL :- Reverse InOrder

    // R
    convertBSTtoDLL(root->right, head);

    // N
    root->right = head;
    if(head) head->left = root;
    head = root;

    // L
    convertBSTtoDLL(root->left, head);
}

// Solve with LNR(InOrder)

Node* convertDLLtoBST(Node* &head, int n)
{
    if(head == NULL || n <= 0)
    {
        return NULL;
    }

    // L
    Node* leftSubTree = convertDLLtoBST(head, n/2);

    // N
    Node* root = head;
    root->left = leftSubTree;
    // Head Update
    head = head->right;

    // R
    Node* rightSubTree = convertDLLtoBST(head, n - n/2 -1);

    root->right = rightSubTree;

    return root;
}

void printLinkedList(Node* head)
{
    Node* temp = head;

    while(temp)
    {
        cout << temp->data << " <-> ";
        temp = temp->right;
    } cout << endl;
}

int main()
{
    int inOrder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size-1;
    
    Node* root = bstFromInorder(inOrder, start, end);
    Node* head = NULL;
    levelOrderTraversal(root);
    
    convertBSTtoDLL(root, head);
    printLinkedList(head);
    
    Node* root2 = convertDLLtoBST(head, size);
    levelOrderTraversal(root2);

    return 0;
}
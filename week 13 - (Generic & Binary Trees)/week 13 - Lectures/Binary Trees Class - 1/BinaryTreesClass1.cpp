#include <iostream>
#include <queue>
using namespace std;

// Implementation of Binary Trees
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

};

// It Returns Root Node of Created Tree
Node* createTree()
{
    int data;
    cout << "Enter the Value : " << endl;
    cin >> data; 

    // Base Case
    if(data == -1) return NULL; // Leaf Node

    // Step 1 : Create Node
    Node* root = new Node(data); // Parent Node

    // Step 2 : Create Left Sub-Tree
    cout << "Left of Node : " << root->data << endl;
    root->left = createTree(); // Left-Child Node
    
    // Step 3 : Create Right Sub-Tree
    cout << "Right of Node : " << root->data << endl;
    root->right = createTree(); // Right-Child Node

    return root;
}

// Generic Tree OR N-Array Tree

// 3 Types of Traversal in Binary Trees
// Pre, In, Post - Order

// 1. Pre-Order = NLR
void preOrderTraversal(Node* root)
{
    if(root == NULL) return;
    
    // N
    cout << root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

// 2. In-Order = LNR
void inOrderTraversal(Node* root)
{
    if(root == NULL) return;
    
    // L
    inOrderTraversal(root->left);
    // N
    cout << root->data << " ";
    // R
    inOrderTraversal(root->right);
}

// 3. Post-Order Traversal = LRN
void postOrderTraversal(Node* root)
{
    if(root == NULL) return;

    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout << root->data << " ";
}

// Skew-Tree is same as Linked List or Tree
// It is in single Direction
// Either only in left or in right

// TC for all Traversals is O(n)
// SC in worst case for all Traversals is O(n)
// Worst case of SC is for Skew-Tree

// BFS - Breadth First Search
void levelOrderTraversal1(Node* root) // Single Line
{
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();

        cout << front->data << " ";

        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}

void levelOrderTraversal2(Node* root) // Multi Line
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        
        if (front == NULL)
        {
            cout << endl;

        // To prevent from Infinite Loop
        // As there will be a NULL in Queue at Last
        // Means atleast one node other than NULL
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else // Valid Case
        {
            cout << front->data << " ";

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}

// TC = O(n)
// SC = Max Number of Nodes in a Level ~ O(n)

int main()
{
    Node* root = createTree();

    // cout << "preOrderTraversal" << endl;
    // preOrderTraversal(root);
    // cout << endl << "inOrderTraversal" << endl;
    // inOrderTraversal(root);
    // cout << endl << "postOrderTraversal" << endl;
    // postOrderTraversal(root);

    // cout << endl << "levelOrderTraversal in Single Line" << endl;
    // levelOrderTraversal1(root);
    cout << endl << "levelOrderTraversal in Multi Line" << endl;
    levelOrderTraversal2(root);

    // 10 20 40 -1 -1 -1 30 50 -1 -1 60 -1 -1
    return 0;
}
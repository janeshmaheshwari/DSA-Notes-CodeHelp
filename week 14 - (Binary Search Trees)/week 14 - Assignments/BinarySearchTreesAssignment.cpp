#include <iostream>
#include <vector>
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

Node* insertIntoBST(Node* root, int data)
{
    // If it is the first Node
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // Not the first Node
    else if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else // data <= root->data
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root)
{
    cout << "Enter Data :" << endl;
    int data;
    cin >> data;
    
    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter Data :" << endl;
        cin >> data;
    }
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

void printBST(Node* root, vector<int>& bst)
{ // LNR
    if(!root) return;
    printBST(root->left, bst);
    bst.push_back(root->data);
    printBST(root->right, bst);
}

void printReverseBST(Node* root, vector<int>& bst)
{ // RNL
    if(!root) return;
    printReverseBST(root->right, bst);
    bst.push_back(root->data);
    printReverseBST(root->left, bst);
}

int countPairs(Node* root1, Node* root2, int x)
{
    vector<int> bst1;
    vector<int> bst2;

    printBST(root1, bst1);
    printReverseBST(root2, bst2);
    
    int ptr1 = 0, ptr2 = 0, count = 0;
    while(ptr1 < bst1.size() || ptr2 < bst2.size())
    {
        int sum = bst1[ptr1] + bst2[ptr2];

        if(sum < x) ptr1++;
        else if(sum > x) ptr2++;
        // sum == x
        else ptr1++, ptr2++, count++;
    }
    return count;
}

// Flatten BST to Sorted LL :-

void solve(Node* root, Node* &head)
{
    if(!root) return;

    // RNL :- Reverse InOrder
    // R
    solve(root->right, head);

    // N
    root->right = head;
    if(head) head->left = NULL;
    head = root;

    // L
    solve(root->left, head);
}

void BSTtoLL(Node* &root)
{
    Node* head = NULL;
    solve(root, head);
    root = head;
}
/*
void convertBSTtoDLL(Node* root, Node* &head)
{
    if(!root) return;

    convertBSTtoDLL(root->right, head);

    root->right = head;
    if(head) head->left = root;
    head = root;

    convertBSTtoDLL(root->left, head);
}
*/

// Both PTT and IOT will print the same output

void printLinkedList(Node* head)
{
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->right; // move to next
    }
    cout << "NULL" << endl;
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left); // left is always NULL in LL
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// HW :- Use LNR(Inorder) to create the Linked List
// Create a Reverse Sorted Linked List from BST (maybe by RNL)

int main()
{
    Node* root = NULL;
    createBST(root); // 5 3 2 4 7 6 8 -1
    levelOrderTraversal(root);
    
    BSTtoLL(root);
    printLinkedList(root);
    inorderTraversal(root);

    return 0;
}
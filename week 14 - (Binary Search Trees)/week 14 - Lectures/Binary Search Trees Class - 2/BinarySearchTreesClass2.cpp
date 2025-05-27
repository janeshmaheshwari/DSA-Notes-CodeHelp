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

int main()
{
    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int s = 0;
    int e =  6;
    Node* root = bstFromInorder(inorder, s, e);
    levelOrderTraversal(root);

    return 0;
}
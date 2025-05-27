#include <iostream>
#include <queue>
using namespace std;

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

Node* createTree()
{
    cout << "Enter the Value for Node : ";
    int value;
    cin >> value;

    if (value == -1)
    {
        return NULL;
    }
    
    Node* root = new Node(value);

    cout << "Entering in Left Node of " << value << endl;
    root->left = createTree();
    cout << "Entering in right Node of " << value << endl;
    root->right = createTree();
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
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

vector<int> diagonalTraversal(Node* root)
{
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front(); q.pop();
        while(temp)
        {
            ans.push_back(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}

int main()
{
    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    Node* root = createTree();

    cout << endl << "Level Order Traversal :-" << endl;
    levelOrderTraversal(root);
    
    cout << endl << "Diagonal Traversal :-" << endl;
    vector<int> ans = diagonalTraversal(root);
    for(int i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
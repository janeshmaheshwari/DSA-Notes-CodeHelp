#include <iostream>
#include <queue>
#include <map>
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

void preOrder(Node* root)
{
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root)
{
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root)
{
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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

void printLeftView(Node* root, int level, vector<int>& leftView)
{
    if (root == NULL)
    {
        return;
    }
    
    if (level == leftView.size())
    {
        leftView.push_back(root->data);
    }
    
    printLeftView(root->left, level+1, leftView);
    printLeftView(root->right, level+1, leftView);
}

void printRightView(Node* root, int level, vector<int>& rightView)
{
    if (root == NULL)
    {
        return;
    }
    
    if (level == rightView.size())
    {
        rightView.push_back(root->data);
    }
    
    printRightView(root->right, level+1, rightView);
    printRightView(root->left, level+1, rightView);
}

void printTopView(Node* root)
{
    map<int, int> hdToNodeMap;
    queue< pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // If there's no Entry for hd in map, then create a new Entry
        if (hdToNodeMap.find(hd) == hdToNodeMap.end())
        {
            hdToNodeMap[hd] = frontNode->data;
        }
        
        // Child ko dekhna hai
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    
    cout << "Printing Top View :" << endl;
    for(auto element : hdToNodeMap)
    {
        cout << element.second << " ";
    }
}

void printBottomView(Node* root)
{
    map<int, int> hdToNodeMap;
    queue< pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // No Condition so that it can Over Write
        hdToNodeMap[hd] = frontNode->data;
        
        // Child ko dekhna hai
        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd-1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    
    cout << "Printing Bottom View :" << endl;
    for(auto element : hdToNodeMap)
    {
        cout << element.second << " ";
    }
}

void printLeftBoundary(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL) // Leaf Node
    {
        return;
    }
    cout << root->data << " ";

    if (root->left)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoundary(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL) // At Leaf Node
    {
        cout << root->data << " ";
    }
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL) // Leaf Node
    {
        return;
    }

    if (root->right)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
    cout << root->data << " ";
}

void boundaryTraversal(Node* root)
{
    // 1. Left View without Leaf Node
    printLeftBoundary(root);

    // 2. Leaf Nodes from Left to Right
    printLeafBoundary(root);

    // 3. Right View in Reverse Order without Leaf and Root Node
    if (root->right)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
}

int main()
{
    Node* root = createTree();
    vector<int> leftView;
    vector<int> rightView;
    printLeftView(root, 0, leftView);
    printRightView(root, 0, rightView);

    // cout << endl;
    // for (int value : leftView)
    // {
    //     cout << value << " ";
    // }

    // cout << endl;
    // for (int value : rightView)
    // {
    //     cout << value << " ";
    // }

    // printTopView(root);

    // printBottomView(root);

    boundaryTraversal(root);

    return 0;
}
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
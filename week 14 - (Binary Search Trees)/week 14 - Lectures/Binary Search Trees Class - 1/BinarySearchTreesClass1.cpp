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

// NLR
void preOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// LNR
void inOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// LRN
void postOrder(Node* root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
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

Node* minValue(Node* root)
{
    if(!root || !root->left) return root;
    return minValue(root->left);
}

Node* maxValue(Node* root)
{
    if(!root || !root->right) return root;
    return maxValue(root->right);
}

bool searchIntoBST(Node* root, int target)
{
    if(!root)
    {
        cout << "Target Not Found !!!" << endl;
        return false;
    }
    else if (root->data == target)
    {
        cout << "Target Found !!!" << endl;
        return true;
    }
    else if (root->data > target)
    {
        return searchIntoBST(root->left, target);
    }
    else // root->data < target
    {
        return searchIntoBST(root->right, target);
    }
}

// For Doubts 1 & 2 : Can we do directly do that ? Will it help in anyways, And what required changes we need to do ?
// For Doubt 3 : Is that return Necessary
// And this function is not giving correct answer for inputs like : BST = [100(root), 150, 300], Target = 100
Node* deleteFromBST(Node* root, int target)
{
    // Case 1 : Target Not Found, No Deletion
    if(!root) return NULL;

    // Case 2 : Target Found
    if (root->data == target)
    {
        // 4 Cases of Deletion

        // Case 1 : Leaf Node
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        
        // Case 2 : root->left != NULL && root->right == NULL
        else if (root->left && !root->right)
        {
            Node* childSubTree = root->left;
            delete root;
            return childSubTree;
        }
        
        // Case 3 : root->right != NULL && root->left == NULL
        else if (root->right && !root->left)
        {
            Node* childSubTree = root->right;
            delete root;
            return childSubTree;
        }

        // Case 4 : root->right != NULL && root->left != NULL
        else // !root->right && !root->left
        {
            // 1(A). Replace the Left SubTree's Max Value with Root Value
            Node* leftMaxNode = maxValue(root->left);
            root->data = leftMaxNode->data;

            // 1(B). Delete Max Node of Left SubTree
            root->left = deleteFromBST(root->left, leftMaxNode->data);
            // deleteFromBST(leftMaxNode, leftMaxNode->data); --> Doubt 1

        /*    
            // 2(A). Replace the Right SubTree's Min Value with Root Value
            Node* rightMinNode = minValue(root->right);
            root->data = rightMinNode->data;

            // 2(B). Delete Min Node of Right SubTree
            root->right = deleteFromBST(root->right, rightMinNode->data);
            // deleteFromBST(rightMinNode, rightMinNode->data); --> Doubt 2
        */

            return root; // --> Doubt 3
        }
    }
    else if (root->data > target)
    {
        root->left = deleteFromBST(root->left, target);
    }
    else // root->data < target
    {
        root->right = deleteFromBST(root->right, target);
    }

    return root; // Return BST root, After Deletion
}

int main() // 50 30 60 25 40 70 80 55 -1
{
    cout << "---------------------------------------" << endl;
    Node* root = NULL;
    createBST(root);

/*
    cout << "---------------------------------------" << endl << "LevelOrder : " << endl;
    levelOrderTraversal(root);

    cout << "---------------------------------------" << endl << "InOrder : ";
    inOrder(root); // InOrder of BST is always Sorted
    cout << endl << "preOrder : ";
    preOrder(root);
    cout << endl << "postOrder : ";
    postOrder(root);
    cout << endl << "---------------------------------------" << endl;
    
    // No output in case of NULL root
    cout << "Min Value : " << minValue(root)->data << endl;
    cout << "Max Value : " << maxValue(root)->data << endl;

    cout << "---------------------------------------" << endl;
    while (true)
    {
        int target;
        cout << "Enter the target value : ";
        cin >> target;
        if (target == -1) break;
        cout << searchIntoBST(root, target) << endl;
    }
    cout << "---------------------------------------" << endl;
*/

    cout << "---------------------------------------" << endl;
    int target;
    cout << endl << "Enter the target value : ";
    cin >> target;
    while (target != -1)
    {
        deleteFromBST(root, target);

        cout << "Level Order Traversal :" << endl;
        levelOrderTraversal(root);

        cout << endl << "Enter the target value : ";
        cin >> target;
    }
    cout << "---------------------------------------" << endl;

    return 0;
}
/*  
    TC (For Finding Functions --> Searching, Deletion, Max or Min) :-
    1. Skew Tree = O(n) e.g = 1->2->3->4
    2. Balanced Binary Tree = O(log(n))
    NOTE :- At every Iteration we Eliminate Half of Tree
*/
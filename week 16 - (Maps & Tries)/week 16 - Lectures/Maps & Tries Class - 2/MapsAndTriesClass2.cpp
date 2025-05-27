#include <iostream>
using namespace std;

class TrieNode
{
public:
    char value;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(int val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word)
{
    // Base Case
    if (!word.length()) // word.length() == 0
    {
        root->isTerminal = true;
        return;
    }
    
    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;
    if (root->children[index]) // root->children[index] != NULL
    {
        // Value Present
        child = root->children[index];
    }
    else
    {
        // Value Absent
        child = new TrieNode(ch); // Create
        root->children[index] = child; // Link
    }

    // Recursion
    insertWord(child, word.substr(1)); // Remaining Word(Index :- 1 to last)
}

bool searchWord(TrieNode* root, string word)
{
    // Base Case
    if (!word.length()) // word.length() == 0
    {
        return root->isTerminal;
    }
    
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if (root->children[index]) // root->children[index] != NULL
    {
        // Present
        child = root->children[index]; // Travel further
    }
    else
    {
        // Absent
        return false;
    }

    return searchWord(child, word.substr(1));
}

void deleteWord(TrieNode* root, string word)
{
    // Base Case
    if (!word.length()) // word.length() == 0
    {
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;

    if (root->children[index]) // root->children[index] != NULL
    {
        // Present
        child = root->children[index]; // Travel further
    }
    else
    {
        // Absent
        return;
    }

    deleteWord(child, word.substr(1));
}

int main()
{
    // Creating a Root Node
    TrieNode* root = new TrieNode('-');
    insertWord(root, "janesh");
    insertWord(root, "jayant");
    insertWord(root, "babbar");
    insertWord(root, "babar");

    cout << searchWord(root, "babar") << endl;
    deleteWord(root, "babar");
    cout << searchWord(root, "babar") << endl;

    return 0;
}
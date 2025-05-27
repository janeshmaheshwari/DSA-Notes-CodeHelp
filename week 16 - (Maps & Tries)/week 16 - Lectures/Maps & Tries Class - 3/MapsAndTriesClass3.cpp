#include <iostream>
#include <vector>
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

void solve(TrieNode* root, string word, vector<string>& ans)
{
    if (root->isTerminal) // Word Exist
    {
        ans.push_back(word);
    }

    for (int i = 0; i < 26; i++)
    {
        if (root->children[i]) // Children Exist
        {
            char ch = i + 'a';
            word.push_back(ch);
            solve(root->children[i], word, ans);
            word.pop_back();
        }
    }
}

vector<string> prefix(TrieNode* root, string word)
{
    vector<string> ans;
    TrieNode* temp = root;

    // Iterating Prefix
    for (int i = 0; i < word.length(); i++)
    {
        char ch = word[i];
        int index = ch - 'a';

        if (temp->children[index]) // Letter Exist
        {
            temp = temp->children[index];
        }
        else // Letter Not Exist
        {
            return ans;
        }
    }
    
    // Prefix Exist :- Now Find Terminals (Words)
    solve(temp, word, ans);
    return ans;
}

vector<vector<string>> suggestedProducts(TrieNode* root, string word)
{
    vector<vector<string>> ans;
    TrieNode* temp = root;

    for (int i = 0; i < word.length(); i++)
    {
        vector<string> charAns;
        char ch = word[i];
        int index = ch - 'a';

        if (temp->children[index])
        {
            temp = temp->children[index];
            solve(temp, word.substr(0, i + 1), charAns);
        }
        else
        {
            // Push empty lists for the rest of the characters
            while (i++ < word.length())
                ans.push_back({});
            break;
        }
        ans.push_back(charAns);
    }

    return ans;
}

int main()
{
    TrieNode* root = new TrieNode('-');
    insertWord(root, "janesh");
    insertWord(root, "janeshmaheshwari");
    insertWord(root, "jayant");
    insertWord(root, "jayantmaheshwari");
    insertWord(root, "babbar");
    insertWord(root, "babar");

    string word = "babbar";
    vector<string> ans = prefix(root, word);
    for(auto answer : ans)
    {
        cout << answer << endl;
    }

    vector<vector<string>> ans2 = suggestedProducts(root, word);
    for (int i = 0; i < ans2.size(); i++)
    {
        cout << i << " -> ";
        for(string answer : ans2[i])
        {
            cout << answer << ", ";
        }
        cout << endl;
    }

    return 0;
}
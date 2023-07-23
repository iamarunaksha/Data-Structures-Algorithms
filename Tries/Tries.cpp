#include <iostream>
using namespace std;

class TrieNode {
public:
    
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {

        this->data = d;

        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        this->isTerminal = false;
    }
};

void insertWord(TrieNode* root, string word) {

    // Base case
    if (word.length() == 0) {

        root->isTerminal = true;
        return;
    }

    int index = word[0] - 'a';

    TrieNode* child;

    // Present
    if (root->children[index] != NULL)
        child = root->children[index];

    // Not present
    else {

        child = new TrieNode(word[0]);
        root->children[index] = child;
    }

    // Recursive Call
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {

    // Base case
    if (word.length() == 0)
        return root -> isTerminal;

    int index = word[0] - 'a';

    TrieNode* child;

    // Present
    if (root->children[index] != NULL)
        child = root->children[index];

    // Not Present
    else
        return false;

    // Recursive call
    return searchWord(child, word.substr(1));
}

int main() {

    TrieNode *root = new TrieNode('-');

    // root->insertWord("coding");
    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");
    insertWord(root, "shona");

    cout << "Searching" << endl;

    if (searchWord(root, "code"))
        cout << "Present" << endl;

    else
        cout << "Absent" << endl;

    return 0;
}
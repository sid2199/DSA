#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Node {
    public:
        char c;
        int word;
        Node* children[26];
        Node (char c) {
            this->c = c;
            this->word = 0;
            for (int i=0; i<26; i++) this->children[i] = NULL;
        }
};

class Trie {
    public:
        Node* root;
        Trie () {
            this->root = new Node('/');
        }

        void insert (string word) {
            int n = word.length();
            Node *node = this->root;
            for (int i=0; i<n; i++) {
                char nextLetter = word[i] - 'a';
                if (node->children[nextLetter] != NULL) node = node->children[nextLetter];
                else {
                    node->children[nextLetter] = new Node(word[i]);
                    node = node->children[nextLetter];
                }
            }
            node->word++;
        }

        void findWord (string word) {
            int n = word.length();
            Node *node = this->root;
            for (int i=0; i<n; i++) {
                if (node->children[word[i] - 'a'] != NULL) node = node->children[word[i] - 'a'];
                else {
                    cout << word << " is not in the Trie\n";
                    break;
                }
            }
            if (node->word > 0) cout << word << " is in the Trie\n";
        }
};

int main () {
    char para[] = "hey there how you doing";
    char *word = strtok(para, " ");
    
    
    Trie trie;
    while (word != NULL) {
        trie.insert(word);
        word = strtok(NULL, " ");
    }



    // for (int i=0; i<n; i++) if (para[i] != ' ') trie.insert();

    trie.findWord("hey");
    trie.findWord("there");
    trie.findWord("hoe");
    trie.findWord("yoi");
    trie.findWord("you");



    return 0;
}
#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminate;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminate = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(string word, TrieNode *root)
    {
        // Base Case
        if (word.size() == 0)
        {
            root->isTerminate = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(word.substr(1), child);
    }
    void insertWord(string word)
    {
        insertWord(word, root);
    }

    bool searchWord(string word, TrieNode *root)
    {
        if (word.size() == 0)
        {
            if (root->isTerminate)
            {
                return true;
            }
            return false;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
        return false;
        return searchWord(word.substr(1),root->children[index]);
    }
    bool searchWord(string word){
        searchWord(word,root);
    }


    void removeWord(string word,TrieNode *root){
        if(word.size()==0){
            root->isTerminate=false;
            return;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL)
        return;
        TrieNode *child=root->children[index];
        removeWord(word.substr(1),root->children[index]);

        if(child->isTerminate==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL)
                return;
            }
            delete child;
            root->children[index]=NULL;
        }
    }

     
};
#include <iostream>
#include <time.h>
using namespace std;

//跳跃表节点
class Node  
{
public:
    int value;
    int level;
    Node** next;

    Node(int value, int level)
    {
        this->value = value;
        this->level = level;
        this->next = new Node*[level+1];
        while (level >= 0)
        {
            this->next[level] = NULL; 
            level--;
        }
    }

    ~Node()
    {
        delete []next;
    }
};

class SkipList
{
public:
    Node** headNode;
    int maxlevel;

    SkipList()
    {
        headNode = new Node*[100];
        for (int i = 0; i<=100; i++)
        {
            headNode[i] = NULL;
        }
        this->maxlevel = 0;
    }

    ~SkipList()
    {
        delete []headNode;
    }

    int randomLevel()
    {
        srand((int)time(NULL));
        int level = 0;
        while (rand()%2 == 0)
            level++;
        if (level > 100)
            level = 100;
        return level;
    }

    void insert(int key)
    {
        int level = randomLevel();
        
        if (level > this->maxlevel)
        {
            this->maxlevel = level;
        }

        Node* newNode = new Node(key, level);

        for (int i = level; i >= 0; i--)
        {
            if (headNode[i] == NULL)
            {
                headNode[i] = newNode;
                continue;
            }

            Node* node = headNode[i];

            while (node->next[i] != NULL)
            {
                node = node->next[i];
            }
            node->next[i] = newNode;
        }
    }

    Node* find(int key)
    {
        // Node** findNode = headNode;
        // for (int i = maxlevel; i >= 0; i--)
        // {
        //     while (findNode[i]->next[i]->value <= key)
        //     {
        //         findNode = findNode->next[i];
        //     }

        Node* findNode;
        
        for (int i = maxlevel; i >= 0; i--)
        {
            if (headNode[i] != NULL && headNode[i]->value <= key)
                findNode = headNode[i];
                break;
        }

        for (int i = findNode->level; i >= 0; i--)
        {
            while (findNode->next[i] != NULL && findNode->next[i]->value <= key)
            {
                findNode = findNode->next[i];
            }
        }


        if (findNode->value == key)
        {
            return findNode;
        }
        return NULL;
    }

    void deleteNode(int key)
    {
        Node* DNode = find(key);
        for (int i = 0; i <= DNode->level; i++)
        {
            Node* findNode = headNode[i];
            if (findNode == DNode)
            {
                headNode[i] = DNode->next[i];
                continue;
            }
            while (findNode->next[i] != NULL && findNode->next[i] != DNode)
            {
                findNode = findNode->next[i];
            }

            findNode->next[i] = DNode->next[i];
        }
    }
};

int main()
{
    SkipList a;
    a.insert(5);
    a.insert(7);
    cout<<a.find(7)->value<<endl;
    a.deleteNode(7);
    Node* b = a.find(7);
    cout<<b;
}

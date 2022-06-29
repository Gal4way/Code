// #include <iostream>
// using namespace std;

// #define MAX_SIZE 100;

// class TreeNode
// {
// private:
//     int value;
//     int ParentNode;

// public:
//     TreeNode(int value, int ParentNode)
//     {
//         this->value = value;
//         this->ParentNode = ParentNode;
//     }

//     int getValue() const
//     {
//         return value;
//     }

//     int getParentNode() const
//     {
//         return ParentNode;
//     }
// };

// class ParTree
// {
// private:
//     int maxSize;
//     int size;
//     int nodes;
//     TreeNode **treeNodeList;

// public:
//     ParTree()
//     {
//         this->maxSize = MAX_SIZE;
//         this->size = 0;
//         this->nodes = 0;
//         treeNodeList[0] = NULL;
//     }

//     ParTree(int maxSize)
//     {
//         this->maxSize = maxSize;
//         this->size = 0;
//         this->nodes = 0;
//         treeNodeList[0] = NULL;
//     }

//     ParTree(int maxSize, TreeNode treeNode)
//     {
//         this->maxSize = maxSize;
//         this->treeNodeList[0] = new TreeNode(treeNode.getValue(), -1);
//         this->size = 1;
//         this->nodes = 0;
//     }

//     bool isEmpty()
//     {
//         return nodes == 0;
//     }

//     TreeNode *root()
//     {
//         return treeNodeList[0];
//     }

//     void addNode(int nodeValue, int parentNode)
//     {
//         for (int i = 0; i < size; i++)
//         {
//             if (treeNodeList[i] == NULL)
//             {
//                 treeNodeList[i] = new TreeNode(nodeValue, parentNode);
//                 nodes++;
//                 return;
//             }
//         }
//         if (size == maxSize)
//         {
//             throw runtime_error("树已满，无法添加");
//             return;
//         }
//         treeNodeList[size] = new TreeNode(nodeValue, parentNode);
//         size++;
//         nodes++;
//         return;
//     }

//     void deleteNode(const TreeNode* pTreeNode)
//     {
//         for (int i = 0; i < size; i++)
//         {
//             if (treeNodeList[treeNodeList[i]->getParentNode()] == pTreeNode)
//             {
//                 treeNodeList[i] = NULL;
//                 nodes--;
//             }
//         }

//         for (int i = 0; i < size; i++)
//         {
//             if (treeNodeList[i] == pTreeNode)
//             {
//                 treeNodeList[i] = NULL;
//                 nodes--;
//                 return;
//             }
//         }
//         throw runtime_error("该节点不存在于树中");
//     }

//     TreeNode* getParentNode(const TreeNode* node)
//     {
//         return treeNodeList[node->getParentNode()];
//     }// 小bug

//     TreeNode** getChildrenNodes(const TreeNode* node)
//     {
//         TreeNode** childrenNodes = new TreeNode*[nodes];
//         int i = 0;
//         for (int j = 0; j<size; j++)
//         {
//             if (treeNodeList[j] != NULL && treeNodeList[treeNodeList[j]->getParentNode()] == node)
//             {
//                 childrenNodes[i] = treeNodeList[j];
//                 i++;
//             }
//         }
//         return childrenNodes;
//     }

//     int deep()
//     {
//         int max = 0;
//         for (int i = 0; i < size; i++)
//         {
//             if (treeNodeList[i] == NULL)
//             {
//                 continue;
//             }
//             int def = 1;
//             int pIndex = treeNodeList[i]->getParentNode();
//             while (pIndex != -1)
//             {
//                 def++;
//                 pIndex = treeNodeList[pIndex]->getParentNode();

//             }
//             if (def > max)
//             {
//                 max = def;
//             }
//         }
//         return max;
//     }
// };




//1.
// #include <iostream>
// using namespace std;


// class ParTree
// {
//     private:
//     int* nodeArray;
//     int size;
//     int find(int node)
//     {
//         while (nodeArray[node] != node)
//         {
//             node = nodeArray[node];
//         }
//         return node;
//     }
    
//     public:
//     ParTree(int size)
//     {
//         this->size = size;
//         for (int i = 0; i < size; i++)
//         {
//             nodeArray[i] = i;
//         }
//     }
//     void merge(int node1, int node2)
//     {
//         int father1 = find(node1);
//         int father2 = find(node2);
//         if (father1 != father2)
//         {
//             nodeArray[father1] = father2;
//         }
//     }
// };


//2.
// #include <iostream>
// using namespace std;


// class ParTree
// {
//     private:
//     int* nodeArray;
//     int size;
//     int find(int node)
//     {
//         if (nodeArray[node] == node)
//         {
//             return node;
//         }
//         nodeArray[node] = find(nodeArray[node]);
//         return nodeArray[node];
//     }
    
//     public:
//     ParTree(int size)
//     {
//         this->size = size;
//         for (int i = 0; i < size; i++)
//         {
//             nodeArray[i] = i;
//         }
//     }
//     void merge(int node1, int node2)
//     {
//         int father1 = find(node1);
//         int father2 = find(node2);
//         if (father1 != father2)
//         {
//             nodeArray[father1] = father2;
//         }
//     }
// };





//3.
// #include <iostream>
// using namespace std;


// class ParTree
// {
//     private:
//     int* nodeArray;
//     int* treeSize;
//     int size;
//     int find(int node)
//     {
//         while (nodeArray[node] != node)
//         {
//             node = nodeArray[node];
//         }
//         return node;
//     }
    
//     public:
//     ParTree(int size)
//     {
//         this->size = size;
//         for (int i = 0; i < size; i++)
//         {
//             nodeArray[i] = i;
//             treeSize[i] = 1;
//         }
//     }
//     void merge(int node1, int node2)
//     {
//         int father1 = find(node1);
//         int father2 = find(node2);
//         if (father1 != father2)
//         {
//             if (treeSize[father1] >= treeSize[father2])
//             {
//                 nodeArray[father2] = father1;
//                 treeSize[father1] += treeSize[father2];
//             }
//             else
//             {
//                 nodeArray[father1] = father2;
//                 treeSize[father2] += treeSize[father1];
//             }
//         }
//     }
// };


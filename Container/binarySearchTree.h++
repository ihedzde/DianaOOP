//
// Created by Ivan Hedz on 17.05.2022.
//

#ifndef DIANAOOP_BINARYSEARCHTREE_H
#define DIANAOOP_BINARYSEARCHTREE_H
#include "../Container/binarySearchTree.h++"
#include "../DAL/abstraction/conscript.h++"
using namespace DAL;
namespace Container {

    struct Node{
    public:
        struct Node *left = nullptr;
        struct Node *right = nullptr;
        Node();
        Node(Conscript* data);
        Conscript* data = nullptr;
        ~Node();
    };
    class BinarySearchTree {
    private:
        Node* root;
    public:
        Node* RecursiveSearch(Node *root, int rank);
        void RecursiveInsert(Node *&node, Conscript *data);
        void PrintInorder(Node* node);
        void PrintInorderCadet(Node *node);
        void CleanTree(Node* node);
        void PrintTree();
        void Insert(Conscript *data);
        void PrintChildrenByRank(int rank);
        Conscript *Search(int rank);
        void LoadFromFile();
        void LoadIntoFile();
        void LoadIntoFileRecursively(Node * nextNode, ofstream& out);
        virtual ~BinarySearchTree();
    };

} // Container

#endif //DIANAOOP_BINARYSEARCHTREE_H

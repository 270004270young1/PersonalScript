/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

class RBT {
private:
    class Node {
    public:
        Node(int val, Node* parent, bool isBlack) {
            this->val = val;
            this->parent = parent;
            this->isBlack = isBlack;
        }
        void setParent(Node* parent) {
            this->parent = parent;
        }
        Node* getParent() { return parent; }
        void changeColor(bool isBlack) { this->isBlack = isBlack; }
        bool getIsBlack() { return isBlack; }
        Node* left = NULL;
        Node* right = NULL;
        int val;
    private:

        Node* parent = NULL;
        bool isBlack = false;

    };
    void buildTree() {
        root = constructNode(arr->at(0), NULL, true);
        for (int i = 1; i < arr->size(); i++) {

            insert(arr->at(i), i);
        }
    }
    Node* constructNode(int val, Node* parent = NULL, bool isBlack = false) {
        Node* nodeP = new Node(val, parent, isBlack);
        return nodeP;
    }

    void leftRotate(Node* target) {

        Node* node = target->right;
        target->right = node->left;
        if (node->left != NULL)
            node->left->setParent(target);
        node->setParent(target->getParent());
        if (target->getParent() == NULL)
            root = node;
        else if (target == target->getParent()->left)
            target->getParent()->left = node;
        else
            target->getParent()->right = node;
        node->left = target;
        target->setParent(node);

    }
    void rightRotate(Node* target) {

        Node* node = target->left;
        target->left = node->right;
        if (node->right != NULL)
            node->right->setParent(target);
        node->setParent(target->getParent());
        if (target->getParent() == NULL)
            root = node;
        else if (target->getParent()->right == target)
            target->getParent()->right = node;
        else
            target->getParent()->left = node;
        node->right = target;
        target->setParent(node);



    }

    void insert(int val, int curIndex) {
        // height = log2(curIndex);
        Node* nodeP = new Node(val, NULL, false);
        Node* curNode = root;

        while (curNode != NULL) {
            if (curNode->val <= nodeP->val) {
                if (curNode->right == NULL) {
                    curNode->right = nodeP;
                    nodeP->setParent(curNode);
                    break;
                }
                curNode = curNode->right;
            }
            else {
                if (curNode->left == NULL) {
                    curNode->left = nodeP;
                    nodeP->setParent(curNode);
                    break;
                }
                curNode = curNode->left;
            }
        }

        curNode = nodeP->getParent();
        Node* grandParent = curNode->getParent();
        while (!curNode->getIsBlack()) {

            if (grandParent == NULL)
                break;

            if (grandParent->left == curNode) {
                Node* uncle = grandParent->right;
                if (uncle != NULL && !uncle->getIsBlack()) {
                    uncle->changeColor(true);
                    grandParent->changeColor(false);
                    curNode->changeColor(true);
                    nodeP = grandParent;
                }
                else if (nodeP == curNode->right) {
                    nodeP = curNode;
                    leftRotate(nodeP);

                }
                else {

                    grandParent->changeColor(false);
                    curNode->changeColor(true);
                    rightRotate(grandParent);
                }



            }
            else {
                Node* uncle = grandParent->left;
                if (uncle != NULL && !uncle->getIsBlack()) {
                    uncle->changeColor(true);
                    grandParent->changeColor(false);
                    curNode->changeColor(true);
                    nodeP = grandParent;
                }
                else if (nodeP == curNode->left) {
                    nodeP = curNode;
                    rightRotate(nodeP);

                }
                else {

                    grandParent->changeColor(false);
                    curNode->changeColor(true);
                    leftRotate(grandParent);
                }
            }

            curNode = nodeP->getParent();
            grandParent = curNode->getParent();

        }
        root->changeColor(true);


    }
    vector<int>* arr;

public:
    RBT(vector<int>* v) {
        arr = v;
        buildTree();
    }
    void displayTree() {
        queue<Node*> bfs;
        bfs.push(root);
        Node* curNode;
        int layor = 0;
        int index = 0;
        while (!bfs.empty()) {
            if (layor * 2 + 1 == index) {
                layor = index;
                cout << endl;
            }
            index++;
            curNode = bfs.front();
            bfs.pop();
            cout << " " << curNode->val;
            if (curNode->left != NULL)
                bfs.push(curNode->left);
            if (curNode->right != NULL)
                bfs.push(curNode->right);

        }
    }
    Node* root;

};

int main()
{
    vector<int> arr = { 1,2,3,4,5,6 };
    vector<int>* a = &arr;
    RBT tree(a);

    tree.displayTree();
    //cout<<endl;
    //cout << tree.root->val;

    return 0;
}

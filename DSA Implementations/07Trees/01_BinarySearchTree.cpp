/*

1. Define a class BST (Binary Search Tree) with node type pointer root as member variable. Implement Binary Search Tree using linked representation.
2. In question 1, define a constructor to initialise root pointer with NULL.
3. In question 1, define a method to check if the tree is empty.
4. In question 1, define a method to insert a new element in the BST.
5. In question 1, define a method for preorder traversing of BST.
6. In question 1, define a method for inorder traversing of BST.
7. In question 1, define a method for postorder traversing of BST.
8. In question 1, define a method to delete an element from BST.
9. In question 1, define a method to search an item in the BST.
10.In question 1, define a destructor to release memory of all the nodes of BST.
*/


#include<iostream>
#define NOT_FOUND -1;
using namespace std;


// Node
class Node {
private:
    int data;       // Node ka value
    Node* left;     // Left child pointer
    Node* right;    // Right child pointer

public:
    Node() {
        left = nullptr;
        right = nullptr;
    }
    int getData() {
        return data;
    }
    void setData(int value) {
        data = value;
    }
    Node* getLeft() {
        return left;
    }
    void setLeft(Node* node) {
        left = node;
    }
    Node* getRight() {
        return right;
    }
    void setRight(Node* node) {
        right = node;
    }
};

class BST{
private:
    Node *root;
    void preorderTraversal(Node *root);    
    void inorderTraversal(Node *); 
    void postorderTraversal(Node *); 
    int height(Node*);
    bool search(Node*,int value);
public:
    BST(/* args */){root=nullptr;}
    ~BST(){}
    int height();                   
    bool isEmpty();
    void insert(int value); 
    bool search(int value); 
    void deleteNode(int value);     
                    
    void preorder();
    void inorder();
    void postorder();
};

int BST::height(Node* ptr){
    if(ptr==nullptr)return -1;
    int leftHeight=height(ptr->getLeft());
    int rightHeight=height(ptr->getRight());
    return 1+(leftHeight>rightHeight?leftHeight:rightHeight);
}
int BST::height(){
    return height(root);
}

bool BST::isEmpty(){return root==nullptr;}

//Search function
bool BST::search(Node* ptr, int value) {
    if(ptr == nullptr) return false;

    if(ptr->getData() == value) return true;

    bool left  = search(ptr->getLeft(), value);
    bool right = search(ptr->getRight(), value);

    return (left || right);
}

// Search Wrapper function
bool BST::search(int value){
    return search(root,value);
}

void BST::insert(int value){
    Node *ptr;
    Node *temp=new Node;
    temp->setData(value);
    if(isEmpty())
        root=temp;
    else{
        ptr=root;
        while (ptr->getData()!=value){
            if(value<ptr->getData()){
                if(ptr->getLeft()!=nullptr)
                    ptr=ptr->getLeft();
                else{
                    ptr->setLeft(temp);
                    break;
                }
            }else{
                if(ptr->getRight()!=nullptr)
                    ptr=ptr->getRight();
                else{
                    ptr->setRight(temp);
                    break;
                }
            }
        }
        if(ptr->getData()==value)
            delete temp;        
    }
} 

//Internal Preoder,Inorder, Postorder functions
void BST::preorderTraversal(Node *root){
    cout<<root->getData()<<" ";
    if(root->getLeft()!=nullptr)
        preorderTraversal(root->getLeft());
    if(root->getRight()!=nullptr)
        preorderTraversal(root->getRight());
} 
void BST::inorderTraversal(Node *root){
    if(root->getLeft()!=nullptr)
        inorderTraversal(root->getLeft());
    cout<<root->getData()<<" ";
    if(root->getRight()!=nullptr)
        inorderTraversal(root->getRight());
} 
void BST::postorderTraversal(Node *root){
    if(root->getLeft()!=nullptr)
        postorderTraversal(root->getLeft());
    if(root->getRight()!=nullptr)
        postorderTraversal(root->getRight());
    cout<<root->getData()<<" ";
} 

//Wrapper function of preorder,inorder and postorder functions
void BST::preorder(){if(root) preorderTraversal(root);}
void BST::inorder(){if(root) inorderTraversal(root);}
void BST::postorder(){if(root) postorderTraversal(root);}

// Node deletion function
void BST::deleteNode(int value){
    Node *parentPtr = nullptr, *ptr = root;

    //  Search node
    while(ptr != nullptr && ptr->getData() != value){
        parentPtr = ptr;
        if(value < ptr->getData())
            ptr = ptr->getLeft();
        else
            ptr = ptr->getRight();
    }

    //  Not found
    if(ptr == nullptr)
        throw NOT_FOUND;

    //  CASE 1: Leaf node (no child)
    if(ptr->getLeft() == nullptr && ptr->getRight() == nullptr){
        if(ptr == root){
            root = nullptr;
        }
        else if(parentPtr->getLeft() == ptr){
            parentPtr->setLeft(nullptr);
        }
        else{
            parentPtr->setRight(nullptr);
        }
        delete ptr;
    }

    //  CASE 2: One child
    else if(ptr->getLeft() == nullptr || ptr->getRight() == nullptr){
        Node* child;
        if(ptr->getLeft() != nullptr)
            child = ptr->getLeft();
        else
            child = ptr->getRight();

        if(ptr == root){
            root = child;
        }
        else if(parentPtr->getLeft() == ptr){
            parentPtr->setLeft(child);
        }
        else{
            parentPtr->setRight(child);
        }
        delete ptr;
    }

    //  CASE 3: Two children
    else{
        //  inorder predecessor (max in left subtree)
        Node* parentOfPred = ptr;
        Node* traversePtr = ptr->getLeft();

        while(traversePtr->getRight() != nullptr){
            parentOfPred = traversePtr;
            traversePtr = traversePtr->getRight();
        }

        //  copy value (NO SWAP)
        ptr->setData(traversePtr->getData());

        //  now delete predecessor node directly
        if(parentOfPred->getRight() == traversePtr)
            parentOfPred->setRight(traversePtr->getLeft());
        else
            parentOfPred->setLeft(traversePtr->getLeft());

        delete traversePtr;
    }
}





// Driver function
int main() {
    BST tree;

    // Insert nodes
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Traversals
    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << "\nInorder Traversal: ";
    tree.inorder();
    cout << "\nPostorder Traversal: ";
    tree.postorder();

    return 0;
}
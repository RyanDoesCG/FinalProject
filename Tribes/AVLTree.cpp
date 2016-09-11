/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  AVLTree.cpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "AVLTree.hpp"
#include <assert.h>

/** 
 *  Calling getHeight() on am undefined node causes
 *  bad access.
 */

// Recursive Helper Function Signatures
int   probeDepth   (Node* node);
Node* rotateLeft   (Node* node);
Node* rotateRight  (Node* node);
Node* balance      (Node* node);                                  // TO-FIX
Node* put          (AVLTree* tree, Node* node, SDL_Keycode item); // TO-FIX
Node* findSmallest (Node* node);
Node* del          (AVLTree* tree, Node* node, SDL_Keycode item);
bool  isIn         (Node* node, SDL_Keycode item);
void  inorder      (Node* node, std::string* output);
void  preorder     (Node* node, std::string* output);
void  postorder    (Node* node, std::string* output);

// Constructor
AVLTree::AVLTree () {
    root = NULL;
    size = 0;
}

// Destructor
AVLTree::~AVLTree () {
    free(root);
}

// Face Member Functions
bool AVLTree::isEmpty  ()                 { return size==0; }
bool AVLTree::isFull   ()                 { return false; }
int  AVLTree::getSize  ()                 { return size; }
int  AVLTree::getDepth ()                 { return probeDepth(root); }
void AVLTree::insert   (SDL_Keycode item) { if (!contains(item)) put(this, root, item); } // no duplication.
void AVLTree::remove   (SDL_Keycode item) { del(this, root, item); }
bool AVLTree::contains (SDL_Keycode item) { return isIn(root, item); }

// Doth Not Worketh
std::string* AVLTree::toString (TraversalType traversal) {
    std::string* output = new std::string ();
    switch (traversal) {
        case INORDER:
            inorder (root, output);
            break;
        case PREORDER:
            preorder (root, output);
            break;
        case POSTORDER:
            postorder (root, output);
            break;
    }

    return output;
}

// Recursion Functions
int probeDepth (Node* node) {
    int l;
    int r;

    if (!node) return 0;

    l = 1 + probeDepth (node->left);
    r = 1 + probeDepth (node->right);

    return (l > r) ? l : r;
}

Node* rotateLeft (Node* node) {
    Node* temp;

    assert (node!=NULL);
    assert (node->right!=NULL);

    temp = node->right;

    node->right  = temp->left;
    temp->left   = node;
    node->setHeight(1 + (node->left->getHeight() > node->right->getHeight() ? node->left->getHeight() : node->right->getHeight()));
    temp->setHeight(1 + (node->left->getHeight() > node->right->getHeight() ? node->left->getHeight() : node->right->getHeight()));

    return temp;
}

Node* rotateRight (Node* node) {
    Node* temp;

    assert (node!=NULL);
    assert (node->left!=NULL);

    temp = node->left;

    node->left   = temp->right;
    temp->right  = node;
    node->setHeight(1 + (node->left->getHeight() > node->right->getHeight() ? node->left->getHeight() : node->right->getHeight()));
    temp->setHeight(1 + (node->left->getHeight() > node->right->getHeight() ? node->left->getHeight() : node->right->getHeight()));

    return temp;
}

Node* balance (Node* node) {
    if (!node) return node;                         // trivially balanced - return now

    /**
     * ISSUE:
     *      - calling "getHeight()" on a null pointer causes crash.
     */
    node->setHeight(1 + (node->left->getHeight() > node->right->getHeight() ? node->left->getHeight() : node->right->getHeight()));

    if (node->left->getHeight() - node->right->getHeight() > 1) {
        // left-heavy  - rebalance needed
        if (node->left->getHeight() > node->right->getHeight())
            node = rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
    }

     else if (node->right->getHeight() - node->left->getHeight() > 1) {
        // right-heavy - rebalance needed
        if (node->right->right->getHeight() > node->right->left->getHeight())
           node = rotateLeft(node);
        else {
           node->right = rotateRight(node->right);
           node = rotateLeft(node);
        }
    }
    else                                            // balanced - no rebalance needed
        ;

    return node;
}

Node* put (AVLTree* tree, Node* node, SDL_Keycode item) {

    if (!node) {
        node = new Node();
        if (!node) {
            std::cout << "Node Allocation Failed\n";
        }
        node->left   = NULL;
        node->right  = NULL;
        node->item   = item;
        tree->incrementSize();
        
        std::cout << "key inserted\n";
    }

    else if (item < node->item) node->left  = put(tree, node->left, item);
    else if (item > node->item) node->right = put(tree, node->right, item);

    return balance(node);
}

Node* findSmallest (Node* node) {
    if (!node)
        return NULL;
    else if (!node->left)
        return node;
    else
        return findSmallest (node->left);
}

Node* del (AVLTree* tree, Node* node, SDL_Keycode item) {
    Node * n;

    if      (node == NULL) ; // not here at all
    else if (item < node->item) node->left  = del(tree, node->left,  item); // not here, go left
    else if (item > node->item) node->right = del(tree, node->right, item); // not here, go right

    // found with two children
    else if (node->left && node->right) {

        n           = findSmallest(node->right);          // get smallest in right tree
        node->item  = n->item;                            // overwrite the item to be deleted
        node->right = del(tree, node->right, node->item); // del the duplicate item in right tree

        // decrement and free?
    }

    // found with one child
    else {
                                               // found and has at most one child
        n = node;
        if      (!node->left)  node = node->right;
        else if (!node->right) node = node->left;
        
        tree->decrementSize();                           // reduce the size
        free(n);                                // reclaim memory

    }

    return balance(node);
}

bool isIn (Node* node, SDL_Keycode item) {
    if (!node) return false;
    if (node->item < item) isIn (node->right, item);
    if (node->item > item) isIn (node->left, item);

    // if none of the above conditions are met, the
    // value has been found.
    return true;
}

void inorder (Node* node, std::string* output) {
    if (node) {
        inorder(node->left, output);
        std::cout << (int)node->item;
        inorder(node->right, output);
    }
}

void preorder (Node* node, std::string* output) {
    if (node) {
        std::cout << (int)node->item;
        preorder(node->left, output);
        preorder(node->right, output);
    }
}

void postorder (Node* node, std::string* output) {
    if (node) {
        postorder(node->left, output);
        postorder(node->right, output);
        std::cout << (int)node->item;
    }
}

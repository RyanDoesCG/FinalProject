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

// Recursive Helper Function Signatures
int   probeDepth   (Node* node);
Node* rotateLeft   (Node* node);
Node* rotateRight  (Node* node);
Node* balance      (Node* node);                    // TO-DO
Node* put          (AVLTree* tree, Node* node, SDL_Keycode item);  // TO-DO
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

// Face Functions
bool AVLTree::isEmpty  ()                 { return size==0; }
bool AVLTree::isFull   ()                 { return false; }
int  AVLTree::getSize  ()                 { return size; }
int  AVLTree::getDepth ()                 { return probeDepth(root); }
void AVLTree::insert   (SDL_Keycode item) { if (!contains(item)) put(this, root, item); } // no duplication.
void AVLTree::remove   (SDL_Keycode item) { del(this, root, item); }
bool AVLTree::contains (SDL_Keycode item) { return isIn(root, item); }
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
    node->height = 1 + (node->left->height > node->right->height ? node->left->height : node->right->height);
    temp->height = 1 + (node->left->height > node->right->height ? node->left->height : node->right->height);
    
    return temp;
}

Node* rotateRight (Node* node) {
    Node* temp;
    
    assert (node!=NULL);
    assert (node->left!=NULL);
    
    temp = node->left;
    
    node->left   = temp->right;
    temp->right  = node;
    node->height = 1 + (node->left->height > node->right->height ? node->left->height : node->right->height);
    temp->height = 1 + (node->left->height > node->right->height ? node->left->height : node->right->height);
    
    return temp;
}

Node* balance (Node* node) {
    if (!node) return node;                         // trivially balanced - return now

    node->height = 1 + (node->left->height > node->right->height ? node->left->height : node->right->height);
    
    if (node->left->height - node->right->height > 1) {
        // left-heavy  - rebalance needed
        if (node->left->height > node->right->height)
            node = rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
            node = rotateRight(node);
        }
    }
   
     else if (node->right->height - node->left->height > 1) {  // right-heavy - rebalance needed

        if (node->right->right->height > node->right->left->height)
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
        tree->size++;
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
    
    if (node == NULL) {
    
        ; // do nothing - data not in tree
        
    } else if (item < node->item) {
    
        node->left  = del(tree, node->left, item);
        
    } else if (item > node->item) {
    
        node->right = del(tree, node->right, item);
        
    } else if (node->left && node->right) {               // found and has two children
    
        n           = findSmallest(node->right);          // get smallest in right tree
        node->item  = n->item;                            // overwrite the item to be deleted
        node->right = del(tree, node->right, node->item); // del the duplicate item in right tree
        
    } else {
                                               // found and has at most one child
        n = node;
        if (node->left == NULL)
            node = node->right;                 // promote the right tree
        else if (node->right == NULL)           // or...
            node = node->left;                  // promote the left tree
        tree->size--;                           // reduce the count SHIT
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
        output->append(std::to_string((int)node->item));
        inorder(node->right, output);
    }
}

void preorder (Node* node, std::string* output) {
    if (node) {
        output->append(std::to_string((int)node->item));
        preorder(node->left, output);
        preorder(node->right, output);
    }
}

void postorder (Node* node, std::string* output) {
    if (node) {
        postorder(node->left, output);
        postorder(node->right, output);
        output->append(std::to_string((int)node->item));
    }
}

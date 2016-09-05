/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  AVLTree.cpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "AVLTree.hpp"

// Recursive Helper Function Signatures
int   probeDepth   (Node* node);
Node* rotateLeft   (Node* node);
Node* rotateRight  (Node* node);
Node* balance      (Node* node);
Node* put          (Node* node, SDL_Keycode item);
Node* findSmallest (Node* node);
Node* del          (Node* node, SDL_Keycode item);
bool  isIn         (Node* node, SDL_Keycode item);
void  inorder      (Node* node, std::string* output);
void  preorder     (Node* node, std::string* output);
void  postorder    (Node* node, std::string* output);

// Constructor
AVLTree::AVLTree() {
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
void AVLTree::insert   (SDL_Keycode item) { put(root, item); }
void AVLTree::remove   (SDL_Keycode item) { del(root, item); }
bool AVLTree::contains (SDL_Keycode item) { return isIn(root, item); }
    
std::string* AVLTree::toString(TraversalType traversal) {
    std::string* output = new std::string();
    switch (traversal) {
        case INORDER:
            inorder(root, output);
            break;
        case PREORDER:
            preorder(root, output);
            break;
        case POSTORDER:
            postorder(root, output);
            break;
    }
    
    return output;
}

// Recursion Functions
int probeDepth(Node* node) {
    int l;
    int r;
    
    if (!node) return 0;
    
    l = 1 + probeDepth(node->left);
    r = 1 + probeDepth(node->right);
    return (l > r) ? l : r;
}

Node* rotateLeft (Node* node) {

}

Node* rotateRight (Node* node) {

}

Node* balance (Node* node) {

}

Node* put (Node* node, SDL_Keycode item) {

}

Node* findSmallest (Node* node) {
    if (!node)
        return NULL;
    else if (!node->left)
        return node;
    else
        return findSmallest(node->left);
}

Node* del (Node* node, SDL_Keycode item) {

}

bool isIn (Node* node, SDL_Keycode item) {
    if (!node) return false;
    if (node->item < item) isIn(node->right, item);
    if (node->item > item) isIn(node->left, item);
    
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  AVLTree.hpp
 *  Tribes
 *
 *  Created by ryan needham on 05/09/2016.
 *  Copyright © 2016 Dissertation. All rights reserved.
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <SDL2/SDL.h>
#include <iostream>

enum TraversalType {
    INORDER,
    PREORDER,
    POSTORDER
};

struct Node {
    int height;
    SDL_Keycode item;
    Node* left;
    Node* right;

    int getHeight () {
        if (this)
            return height;
        else
            return 0;
    }
    
    void setHeight (int h) {
        this->height = h;
    }
    
};

class AVLTree {
    public:
        AVLTree  ();
        ~AVLTree ();

        bool isEmpty  ();
        bool isFull   ();
        int  getSize  ();
        int  getDepth ();
        void insert   (SDL_Keycode item);
        void remove   (SDL_Keycode item);
        bool contains (SDL_Keycode item); // BROKEN/FUCKED/PLEASE WORK SOON THANKS

        void decrementSize () { size -= 1; }
        void incrementSize () { size += 1; }

        /**
         *  returns an integer representation. Ideally this
         *  will be replaced by a char/string representation.
         */
        std::string* toString(TraversalType traversal);

    private:
        Node* root;
        int   size;
};

#endif /* AVLTree_hpp */

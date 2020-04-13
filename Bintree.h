/***************************************************************************************************
File: Bintree.h
Author : <Jeni Robbie>
Description: header file for Bintree class declaration for a Binary tree and internal TreeNode declaration
Most Code from John Lawrence lecture slides
Date Created: 18/03/20
Last Modified: 20/03/20

/***************************************************************************************************/


#pragma once
#include <iostream>
using namespace std;

// Binary search tree for strings

class Bintree
{
protected:
    class Treenode  
    {
    public:
        string Element;     //holds item value
        Treenode* Left;     //Points to node left of itself
        Treenode* Right;        //Points to node right of itself
        int count = 1;          //hold number of occurences of item in tree

        Treenode() : Left(nullptr), Right(nullptr), count(1) {}     //Constructor
        Treenode(string data, Treenode* leftnode = nullptr,             //Constructor
            Treenode* rightnode = nullptr) :
            Element(data), Left(leftnode), Right(rightnode) {}
    };
    static void Display(Treenode* node);                 //Print tree with count                
    static void Insert(Treenode*& node, const string& Item);     //insert item into tree       
    static bool Bin_tree_search(Treenode* node, const string item);         //Search for item in tree
    static void Destroy(Treenode*& node);           //Delete tree node
    Treenode* Root;             //Pointer to tree root
public:
    Bintree();              //Contrsuctor
    ~Bintree();             //Destructor
    void Insert(const string& item);            //insert item into tree
    bool Bin_tree_search(const string item);        //Search for item in tree
    void Display() const;               //Print tree with count
};

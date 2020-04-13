/***************************************************************************************************
File: Bintree.cpp
Author : <Jeni Robbie>
Description: function definitions for Bintree class
Most code from John Lawerance kecture slides
Date Created: 18/03/20
Last Modified: 20/03/20

/***************************************************************************************************/

#include "Bintree.h"
// Constructor
Bintree::Bintree() : Root(nullptr)  //Set root node as null pointer
{
}

// Destructor
Bintree :: ~Bintree()
{
    Destroy(Root);      
}
//Called by destructor to destroy tree recursively
void Bintree::Destroy(Treenode*& node)
{
    if (node != nullptr)        //Stop if tree is empty
    {
        Destroy(node->Left);
        Destroy(node->Right);
        delete node;
    }
}

// Insert 

void Bintree::Insert(const string& item)
{
    Insert(Root, item); //Calls Insert with node recursively
}

void Bintree::Insert(Treenode*& node, const string& item)
{
    if (node == nullptr)        //Insert into corect position i.e. no where else to traverse
    {
        node = new Treenode(item);      
    }
    else if (item < node->Element)  //Move down left side of tree (item is smaller than node elememt
        Insert(node->Left, item);       //Reursively call until correct position
    else
        Insert(node->Right, item);  ///Move down right  side of tree (item is larger than node elememt 
}

//Print Trees in ascending order and counts
void Bintree::Display(Treenode* node)
{

    
    if (node != nullptr)
    {
        Display(node->Left); // Traverse left subtree             
        cout << node->Element << ", " << node->count <<endl; // Output root and count
        Display( node->Right); // Traverse right subtree
    }
    else
        cout << " ";
}

void Bintree::Display() const
{
    Display(Root);          
}




// Search 

bool Bintree::Bin_tree_search(const string item)
{
    return Bin_tree_search(Root, item);
}

//Searches tree from root node descending
bool Bintree::Bin_tree_search(Treenode* node, const string item)
{
    if (node == nullptr)            //If its not in tree
    {
 
        return false;               //false if not in tree already
    }
    else if (item == node->Element)     //If item foumd
    {
        node->count++;          //Add one to occurence count    
        return true;           
    }
    else if (item < node->Element)              //If not null pointer and not element, continue traversal
        return Bin_tree_search(node->Left, item);       //
    else
        return Bin_tree_search(node->Right, item);
}
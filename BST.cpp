// Ass2Q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Bintree.h"
#include <iostream>
#include <fstream>
using namespace std;

void validateWord(string&);

int main()
{

    string word;        //Word to be read from file
    bool isDuplicate;         //hold whether word is unique
    string fileName;        //Name of file to be opened and read
    Bintree* treePointer= new Bintree;      //Dynamically assign tree pointer
    ifstream readFile;                      


    //Until exit condition is reached
    while (fileName != "0")
    {  
        //Instructions
        cout << "Please enter name of text file user wishes to word count. For Example \"test.txt\"" << endl;
        cin >> fileName;    //get name of file to be opened
        if (fileName == "0")        //If exit condition is reached
            continue;               //leave loop

        readFile.open(fileName);    //Open file
        
        //Check if file has opened correct
        if (!readFile.is_open())
        {
            while ((!readFile.is_open()) && (fileName!="0"))        //Until file can be opened or user wants to exit
            {
            cout << "Error. Could not open file." << endl;  
            cout << "Please enter file name again or 0 to exit." << endl;   


            cin >> fileName;    //get name of file to be opened

            }
            if (fileName == "0")    //break loop if exit condition met
                break;
        }
        else
        {
            //Loop until end of file
            while (!readFile.eof())
            {
                //get string 
                readFile >> word;

                //Convert word to correct format
                validateWord(word);

                //Check if word is already in binary tree
                isDuplicate = treePointer->Bin_tree_search(word);

                //If word is uniqu, insert into tree
                if (isDuplicate == false)
                    treePointer->Insert(word);


            }
            //Print tree
             cout << "Word Count: " << endl;
            treePointer->Display(); //Display all words and counts
            cout << endl;

        } 
        
    //Close the text file
    readFile.close();
    treePointer = new Bintree;  //Create new tree
    }

   

}
void validateWord(string &word){

    //Loop for length of word
    for (int i = 0; i < word.length(); i++)
    {
        //Convert all characters to lower case
        word[i] = tolower(word[i]);

        //Check if character is alphabetical character
        if (!isalpha(word[i]))
        {
            //If not, remove 1 character position i in string
            word.erase(i, 1);
            //Move the back to correct position to account for new length
            i = i - 1;
        }
}
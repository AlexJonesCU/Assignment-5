//still needs to delete node and delete constructors and error checking
//cs.usfca.edu  "Binary search tree visualization"

#include <iostream>

using namespace std;

class TreeNode
{
  public:
    TreeNode(); //constructor
    TreeNode(int key);
    virtual ~TreeNode(); // lookup why is it virtual??

    int key; //key is the value
    TreeNode *left; //pointer to tree node for left and right
    TreeNode *right;
};

//implement it in .cpp//

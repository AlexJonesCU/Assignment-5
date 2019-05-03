
#include "TreeNode.h"
#include <iostream>

using namespace std;

class BST
{
  public:
    BST();
    virtual ~BST();
    void RecursiveDestructor(TreeNode *node);
    void insert(int value);
    bool contains(int value); //AKA search()
    bool deleteNode(int value);
    TreeNode* getSuccessor(TreeNode* d);
    bool deleteR();
    void Tree();


    void write(TreeNode *node);

    void writeNode(TreeNode *node, fstream& file);


    TreeNode* getMin();
    TreeNode* getMax();
    bool isEmpty();
    void printTree();
    void recPrint(TreeNode *node);

    bool TorF;



  private:
    TreeNode *root;

    int facultyID;
    string facultyName;
    string facultyLevel; //lecturer, assistant prof, associate prof, etc
    string facultyDepartment;
    int facultyCorrStudentIDs;

};

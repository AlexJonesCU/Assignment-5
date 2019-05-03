#include "BST.h"
#include "Student.h"

#include <fstream>
#include <iostream>

using namespace std;

Student getData;

BST::BST() //default constructor
{
  root = NULL; //empty tree
}

BST::~BST()
{
  //iterate and delete -- uses the RecursiveDestructor method to use Recursion to iterate through tree
  RecursiveDestructor(root);
}

void BST::RecursiveDestructor(TreeNode *node) //source: https://stackoverflow.com/questions/34170164/destructor-for-binary-search-tree
{
  if (node)
  {
    RecursiveDestructor(node->left);
    RecursiveDestructor(node->right);
    delete node;
  }
}

void BST::printTree() //print entire tree
{
  recPrint(root);
  write(root);
}

void BST::recPrint(TreeNode *node) //creates node to access each key to print it
{
  if(node == NULL)
    return;

  recPrint(node->left);
  cout << node->key << endl;
  getData.displayStudent();
  recPrint(node->right);
}

void BST::write(TreeNode *node) //source: http://www.cplusplus.com/forum/general/32351/
{
  fstream recFile;//("RecordFile.txt");
  recFile.open("RecordFile.txt", std::fstream::in | std::fstream::out | std::fstream::trunc); //source: http://www.cplusplus.com/reference/fstream/fstream/open/
  // trunc clears file for each run source: https://www.daniweb.com/programming/software-development/threads/401713/empty-a-file-in-c
  //^might need to make sure file is empty before starting, it usually works but sometimes is too slow and doesnt clear in time
  {
    writeNode(node, recFile);
    recFile.close();
  }
}
void BST::writeNode(TreeNode *node, fstream& recFile)
{
  if(node == NULL)
    return;

  writeNode(node->left, recFile);
  recFile << node->key << endl;
  writeNode(node->right, recFile);
}


bool BST::isEmpty()
{
  return (root == NULL); //if root is NULL  //returns true or false
}

void BST::insert(int value)
{
  if(contains(value)) //checks for duplicate value
  {
    cout << "Error! Value: " << value << " could not be added because it already exists in tree." << endl;
  }
  else
  {
    TreeNode *node = new TreeNode(value); //create new node

    if(isEmpty()) //empty tree
    {
      root = node;
    }
    else //not an empty tree, continue to add
    {
      TreeNode *current = root;
      TreeNode *parent; //empty node

      while(true) //lets look for our insertion pointer  while curr != NULL
      {
        parent = current;
        if(value < current->key) //go left
        {
          current = current->left;
          if(current == NULL) //we found our location
          {
            parent->left = node; //after NULL node is found set the node equal to it
            break;
          }
        }
        else //go right
        {
          current = current->right;
          if(current == NULL) //we found our new node a home
          {
            parent->right = node;
            break;
          }
        }
      }
    }
  }
}

bool BST::contains(int value) //search
{
  if(isEmpty()) //empty tree with nothing
    return false;

  TreeNode *current = root;

  while(current->key != value)
  {
    if(value < current->key) //if less than go left
      current = current->left;
    else //not left so go right
      current = current->right;

    if(current == NULL) //item not found in tree
      return false;
  }
  getData.displayStudent();
  return true;
}

bool BST::deleteNode(int k)
{
  if(isEmpty()) //node doesn't exist if tree is empty
    return false;

  //checks if key/value exist in the tree
  else if(contains(k)) //checks for duplicate value
  {
    TreeNode *current = root;
    TreeNode *parent = root;
    bool isLeft = true; //either left or right (true or false)

    //now lets iterate and update our pointers
    while(current->key != k)
    {
      parent = current;

      if(k < current->key)
      {
        isLeft = true; //if k is less than current key, go left
        current = current->left;
      }
      else
      {
        isLeft = false; //if k is not less than current key, go right
        current = current->right;
      }

      if(current == NULL)
        return false; //if there is not current (key) return false because k does not exist anywhere in tree
    }
    //at this point we have found our node to be deleteNode because current key must be = k

    if(current->left == NULL && current->right == NULL) //leaf node, no children [easiest case-leaf] CASE 1: k(current) is leaf
    {
      if(current == root)
        root = NULL;
      else if (isLeft)
      {
        parent->left = NULL;
      }
      else
      {
        parent->right = NULL;
      }
     }

    //now we need to check if node to be deleted has one child

    else if(current->right == NULL) //no right child - only left
    {
      if(current == root) //case @ in notes
        root = current->left;
      else if (isLeft) //case # in notes
      {
        parent->left = current->left;
      }
      else //case $ in notes
      {
        parent->right = current->left;
      }
    }

    else if (current->left == NULL) //no left child
    {
      if (current == root)
        root = current->right;
      else if (isLeft)
      {
        parent->left = current->right;
      }
      else //i added this else statement
      {
        parent->right = current->right;
      }
    }
    else //node to be deleted has 2 children [case % in notes]
    {
      //find successor of the node to be deleted (current)
      TreeNode *successor = getSuccessor(current);

      if(current == root)
        root = successor;
      else if(isLeft)
      {
        parent->left = successor;
      }
      else
      {
        parent->right = successor;
      }

      successor->left = current->left;
    }

    cout << "Deleting " << endl;

    return true;
  }

  else
  {
    cout << "Cannot delete " << k << " because it does not exist in tree" << endl;
    return false;
  }
  return true; //deletion was successful
}

TreeNode* BST::getSuccessor(TreeNode *d) //d is the node to be deleted
{
  TreeNode *sp = d; //parent of the successor
  TreeNode *successor = d; //starts at root
  TreeNode *current = d->right;

  while(current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  //we need to check if successor is a descendant of right child
  if(successor != d->right) //if the one to the right does not have children
  {
    sp->left = successor->right;
    successor->right = d->right;
  }

  return successor;
}

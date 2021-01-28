#include <iostream>
#include "node.hpp"

using namespace std;


bool process_number(int num, node*& tree);
void add_to_tree(node*& tree);
void print_tree(node *tree);
node* min_value_node(node* tree);
node* deleteNode(node* root, int key);
void delete_tree(node *node);

int main() {
  

  node *root=nullptr;
  

  int choice;
  bool exit = false;
  while ((cin.eof()==false)&&(exit == false)){
    cout << "Please select an option:\n1: add more numbers to the tree.\n2: Print tree. \n3: find minimum value in a tree. \n4: Delete a node from the tree\n5: Delete tree.\n6: exit." << endl;
    cin >> choice;
    switch(choice) {
      case 1: //add more nodes
        cout << "enter the numbers you would like to add to tree: " << endl;
        add_to_tree(root);
        break;
      case 2: //print tree
        if (root == nullptr){
          cout << "Tree is empty." << endl;
        }else  print_tree(root);
        break;
      case 3: // fin minimum value
        cout << "the minimum value in this tree is: " << min_value_node(root)->data << "." << endl;
        break;
      case 4: // delete a node from the tree
        int node;
        cout << "please enter the data to be deleted" << endl;
        cin >>node;
        root = deleteNode(root, node);
        break;

      case 5: //delete full tree
        delete_tree(root);
        root = nullptr;
        break;
      case 6: //exit
        exit = true;
        cout << "Goodbye" << endl;
        break;
     

    }
  } 
}

// returns true if the word is new, false otherwise
bool process_number(int num, node*& tree) {
   bool response;
   if (tree == nullptr) {
      tree = new node();
      tree->data = num;
      response = true; // it is a new word
   } else {
      if (num == tree->data) {
         tree->count++;
         response = false; // it is not a new word
      } else {
         if (num < tree->data) {
            response = process_number(num, tree->left);
         } else {
            response = process_number(num, tree->right);
         }
      }
   }
   return response;
}

void add_to_tree(node*& tree){
  while (cin.eof()==false){
      int number;
      cin >> number;
      if (cin.fail() == false){
        process_number(number, tree);
    }
  }
  cin.clear();
}

void print_tree(node *tree) {
  if (tree != nullptr) {
    print_tree(tree->left);
    cout << "\"" << tree->data <<"\" " << tree->count << endl;
    print_tree(tree->right);
  }
}

node* min_value_node(node* tree){
  node* current = tree;
 
  // loop down to find the leftmost leaf 
  while (current && current->left != nullptr)
    current = current->left;

  return current;
}

node* deleteNode(node* root, int key){
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node to be deleted
    else if ((key == root->data)&&(root->count >1)){
      root->count-=1;
      return root;
    }
    else {
        // node with only one child or no child
        if (root->left == nullptr) {
            node* temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest in the right subtree)
        node* temp = min_value_node(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void delete_tree(node* node)  {  
    if (node == nullptr) return;  
  
    /* first delete both subtrees */
    delete_tree(node->left);  
    delete_tree(node->right);  
      
    /* then delete the node */
    //cout << "\n Deleting node: " << node->data;  
    delete node; 
}  
  


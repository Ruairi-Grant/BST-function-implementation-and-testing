#include <iostream>
#include "node.hpp"

using namespace std;


bool process_number(int num, node*& tree);
void add_to_tree(node*& tree);
void print_tree(node *tree);
void delete_tree(node *node);

int main() {
  

  node *root=nullptr;
  

  int choice;
  bool exit = false;
  while ((cin.eof()==false)&&(exit == false)){
    cout << "Please select an option:\n1: add more numbers to the tree.\n2: Print tree.\n3: Delete tree.\n4: exit" << endl;
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
      case 3: //delete full tree
        delete_tree(root);
        root = nullptr;
        break;
      case 4: //exit
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

void delete_tree(node* node)  
{  
    if (node == nullptr) return;  
  
    /* first delete both subtrees */
    delete_tree(node->left);  
    delete_tree(node->right);  
      
    /* then delete the node */
    //cout << "\n Deleting node: " << node->data;  
    delete node; 
}  
  


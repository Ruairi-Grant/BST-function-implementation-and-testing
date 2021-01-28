#pragma once                   
//#include<string>                                     
class node/*public std::string*/ {                                                
   public:   
   node();  
   node(int num); 
   int count; 
   int data;
   node *left;   
   node *right;
}; 
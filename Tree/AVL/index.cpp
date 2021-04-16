/*
  失衡的所有情况：
  LL:
    
  RR:

  LR:

  RL:

*/


#include<iostream>
#include<deque>
using namespace std;

struct Node
{
  int data;
  Node *parent;
  Node *left;
  Node *right;
  int bf;
  Node(){
    data = -1;
    parent = NULL;
    left = NULL;
    right = NULL;
    bf = 0;
  }
};

struct AVL
{
  Node *head;
  AVL(){
    head = new Node;
  }
  void createTree( Node *current ){
    cin>>current->data;
    if( current->data == -1 ){
      return;
    }
    current->left = new Node;
    current->right = new Node;
    current->left->parent = current;
    current->right->parent = current;
    createTree( current->left );
    createTree( current->right );
  }
  void printTree(){
    deque<Node*> med;
    med.emplace_back(head);
    while( med.size() !=0 ){
      cout<<med[0]->data<<" ";
      if( med[0]->left != NULL && med[0]->left->data != -1 ){
        med.emplace_back(med[0]->left );
      }
      if( med[0]->right != NULL && med[0]->right->data != -1 ){
        med.emplace_back(med[0]->right);
      }
      med.pop_front();
    }
  }
public:
  void LL_Rotate( Node *target ){
    Node *root = target->parent;
    Node *L = target->left;

    target->left = L->right;
    target->parent = L;

    L->right->parent = target;

    L->parent = root;
    L->right = target;
    
    if(root->left == target){
      root->left = L;
    }else{
      root->right = L;
    }
    
  }
  void RR_Rotate( Node *target ){
    Node *root = target->parent;
    Node *R = target->right;

    target->parent = R;
    target->right = R->left;

    R->left->parent = target;

    R->left = target;
    R->parent = root;

    if(root->left == target){
      root->left = R;
    }else{
      root->right = R;
    }
  }
  void LR_Rotate( Node *target ){
    Node *L = target->left;

    target->left = L->right;
    target->left->parent = target;
    
    L->parent = target->left;
    target->left->left->parent = L;
    L->right = target->left->left;
    target->left->left = L;

    LL_Rotate(target);
  }
  void RL_Rotate( Node *target ){
    Node *R = target->right;

    target->right = R->left;
    R->left->parent = target;

    R->left = target->right->right;
    target->right->right->parent = R;

    target->right->right = R;
    R->parent = target->right;

    RR_Rotate(target);
  }
};


int main(){
  AVL tem;
  tem.createTree(tem.head);
  tem.LR_Rotate(tem.head->right);
  tem.printTree();
}
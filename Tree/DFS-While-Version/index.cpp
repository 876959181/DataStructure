//用一个栈来辅助

#include<iostream>
#include<deque>
#include<stack>
using namespace std;

struct Node{
  int data;
  deque<Node> child;
  Node(){
    data = -1;
    child.clear();
  }
};

class DFS{
  
public:
  Node head;
  void createTree( Node &current ){
    cin>>current.data;
    if(current.data != -1){
      Node left;
      Node right;
      current.child.emplace_back(left);
      current.child.emplace_back(right);
      createTree(current.child[0]);
      createTree(current.child[1]);
    }
  }
  void bfsprint(){
    deque<Node> med;
    med.emplace_back(head);
    while( med.size() ){
      cout<<med[0].data<<" ";
      if(med[0].child[0].data != -1){
        med.emplace_back(med[0].child[0]);
      }
      if(med[0].child[1].data != -1){
        med.emplace_back(med[0].child[1]);
      }
      med.pop_front();
    }
  }
  void dfsprint(){
    stack<Node*> med;
    med.push(&head);
    Node *pre = NULL;
    while( !med.empty() ){
      Node *current = med.top();
      if( pre != NULL && ( pre == &(current->child[0]) || pre == &(current->child[1]) ) ){
        cout<<current->data<<" ";
        pre = current;
        med.pop();
        continue;
      }
      if(current->child[1].data != -1){
        med.push( & ( current->child[1] ) );
      }
      if(current->child[0].data != -1){
        med.push( & ( current->child[0] ) );
      }
      if(current == med.top()){
        cout<<current->data<<" ";
        pre = current;
        med.pop();
      }
    }
  }
};

int main(){
  DFS tem;
  tem.createTree(tem.head);
  tem.dfsprint();
}
#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int data;
    node* lt;
    node* rit;
    node(int data)
    {
        this->data = data;
        lt = NULL;
        rit = NULL;
    }
};
 
void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->rit;
}
 
void inorder(node* curr, node*& prev)
{
    // Base case
    if (curr == NULL)
        return;
    inorder(curr->lt, prev);
    prev->lt = NULL;
    prev->rit = curr;
    prev = curr;
    inorder(curr->rit, prev);
}

node* flatten(node* parent)
{
    
    node* dum = new node(-1);
 
    
    node* prev = dum;
 
    
    inorder(parent, prev);
 
    prev->lt = NULL;
    prev->rit = NULL;
    node* ret = dum->rit;
 
    
    delete dum;
    return ret;
}
 

int main()
{
    node* rt = new node(5);
    rt->lt = new node(3);
    rt->rit = new node(7);
    rt->lt->lt = new node(2);
    rt->lt->rit = new node(4);
    rt->rit->lt = new node(6);
    rt->rit->rit = new node(8);
 
    print(flatten(rt));
 
    return 0;
}
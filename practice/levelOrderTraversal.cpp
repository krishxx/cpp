#include<iostream>
#include<iomanip>
#include<queue>
#include<stack>
//#include "util.h"
using namespace std;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}tree_node;

tree_node *root;
void add_node(int item)
{
        tree_node *temp = new tree_node();
        temp->left=NULL;
        temp->data=item;
        temp->right=NULL;

        cout<<temp->data<<" added"<<endl;
        if(root==NULL)
                root = temp;
        else
        {
                tree_node *curr=root;
                tree_node *prev=NULL;
                while(curr!=NULL)
                {
                        prev=curr;
                        curr=(item<curr->data)?curr->left:curr->right;
                }
                if(item<prev->data)
                        prev->left=temp;
                else
                        prev->right=temp;
        }
}

void lot(tree_node *root) //level order traversal2
{
        tree_node *temp;
        std::queue<tree_node*> q1;
        temp=root;
        q1.push(temp);
        while(!q1.empty())
        {
                temp = q1.front();
		q1.pop();
		if(temp->left != NULL)
			q1.push(temp->left);
		if(temp->right != NULL)
			q1.push(temp->right);
                cout<<"["<<temp->data<<"] ";
        }
}

void zigzag(tree_node *root)
{
	tree_node *temp;
	std::queue<tree_node*> q1;
	std::stack<tree_node*> s1;
	temp=root;
	q1.push(temp);
	while(!q1.empty() || !s1.empty())
	{
		while(!q1.empty())
		{
			temp=q1.front();
			cout<<"["<<temp->data<<"] ";
			q1.pop();
			if(temp->left != NULL)
				s1.push(temp->left);
			if(temp->right != NULL)
				s1.push(temp->right);
		}
		cout<<endl;
		while(!s1.empty())
		{
			temp=s1.top();
			s1.pop();
			cout<<"["<<temp->data<<"] ";
			if(temp->right != NULL)
				q1.push(temp->right);
			if(temp->left != NULL)
				q1.push(temp->left);
		}
		cout<<endl;
	}
}

int main() 
{ 
	add_node(5);
	add_node(3);
	add_node(7);
	add_node(2);
	add_node(4);
	add_node(6);
	add_node(8);

   	cout<<"lelveOrderTraversal"<<endl; 
	lot(root);
	cout<<endl<<"Zigzag Level Order Traversal"<<endl;
	zigzag(root);
	// Empty Queue
   
       /*	
    tree_node *temp;
    temp = root;    
    queue<tree_node *> myqueue; 
    myqueue.push(temp); 
    myqueue.push(temp->left); 
    myqueue.push(temp->right); 
  
    // Printing content of queue 
    while (!myqueue.empty()) { 
        cout << ' ' << myqueue.front(); 
        myqueue.pop(); 
    }*/

   return 0; 
} 

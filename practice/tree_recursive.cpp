#include <iostream>
#include <iomanip>
#include <stack>
#include "utils.h"

using namespace std;

typedef struct node
{
        struct node *left;
        int data;
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

void traverse_inorder(tree_node *node)
{
	if(node!=NULL)
	{
		traverse_inorder(node->left);
		cout<<"["<<node->data<<"] ";
		traverse_inorder(node->right);
	}
}

void traverse_preorder(tree_node *node)
{
	if(node!=NULL)
	{
		cout<<"["<<node->data<<"] ";
		traverse_preorder(node->left);
		traverse_preorder(node->right);
	}
}

void traverse_postorder(tree_node *node)
{
	if(node!=NULL)
	{
		traverse_postorder(node->left);
		traverse_postorder(node->right);
		cout<<"["<<node->data<<"] ";
	}
}

int depth_of_tree(tree_node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int h1=0,h2=0;
		if(root->left != NULL)
			h1=1+depth_of_tree(root->left);
		if(root->right != NULL)
			h2=1+depth_of_tree(root->right);
		return max(h1,h2);
	}	
}

int size_of_tree(tree_node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		return (size_of_tree(root->left)+size_of_tree(root->right)+1);
	}
}

tree_node* closest_ancestor(int a, int b)
{
	return NULL;
}

void tree_mirror(tree_node *root)
{
	tree_node *temp;
	if(root == NULL)
		return;
	else
	{
		tree_mirror(root->left);
		tree_mirror(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

tree_node* closestAncestor(tree_node *root, tree_node *p, tree_node *q)
{
	tree_node *l, *r, *tmp;
	if(root == NULL)
		return NULL;
	if(root->left==p || root->right==p || root->left==q || root->right==q)
	{
		return root;
	}
	else
	{
		l=closestAncestor(root->left, p, q);
		r=closestAncestor(root->right, p, q);
		if(l!=NULL && r!=NULL)
			return root;
		else
		{
			tmp = (l!=NULL)?l:r;
			return tmp;
		}
			
	}
}

void levelOrderTraversal(tree_node *root)
{
	tree_node *q[20]={NULL};
	int size = 0, qp = 0;
	
	while(root!=NULL)
	{
		cout<<"["<<root->data<<"] ";
		if(root->left)
			q[size++]=root->left;
		if(root->right)
			q[size++]=root->right;
		root=q[qp++];		
	}
}

int rootToLeafMaxSum(tree_node *root)
{
	if(root==NULL)
		return 0;
	else
	{
		int l=rootToLeafMaxSum(root->left);
		int r=rootToLeafMaxSum(root->right);
		return ((l>r?l:r)+root->data);
	}
}

bool printMaxSumPath(tree_node *root, int sum)
{
	if(sum==0)
		return true;
	if(root == NULL)
		return false;

	bool leftSum=printMaxSumPath(root->left, sum-root->data);
	bool rightSum=printMaxSumPath(root->right, sum-root->data);

	if(leftSum||rightSum)
		cout<<"["<<root->data<<"] ";

	return leftSum||rightSum;
}

int main()
{
	add_node(4);
	add_node(2);
	add_node(5);
	add_node(3);
	add_node(7);
	add_node(1);
	add_node(6);
	tree_mirror(root);
	cout<<"In Order	:	";
	traverse_inorder(root);
	cout<<endl;
	cout<<"pre Order	:	";
	traverse_preorder(root);
	cout<<endl;
	cout<<"Post Order	:	";
	traverse_postorder(root);
	cout<<endl;
	cout<<"Level Order	:	";
	levelOrderTraversal(root);
	cout<<endl;
	cout<<"Counts"<<endl;
	cout<<"Depth		:	"<<depth_of_tree(root)<<endl;
	cout<<"Size		:	"<<size_of_tree(root)<<endl;
	cout<<"MaxSum From root:	"<<rootToLeafMaxSum(root)<<endl;
	cout<<"Max sum path	:	";
	printMaxSumPath(root, rootToLeafMaxSum(root));
	
	cout<<endl;
	return 0;
}

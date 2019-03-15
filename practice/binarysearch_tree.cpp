#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

typedef struct node
{
	struct node *left;
	int data;
	struct node *right;       	
}tree_node;

class tree
{
	tree_node *tr;
	public:
		//tree();
		void create_tree();
		void add_node(int element);
		void print_iterative_inorder();
		void print_iterative_preorder();
		void print_iterative_postorder();
		//~tree();
};

void tree::create_tree()
{
	for(int i=0; i<10; i++)
	{
		if(i%2==0)
			add_node(i+13);
		else 
			add_node(i-7);
	}		
}

void tree::add_node(int element)
{
	tree_node *temp = new tree_node();
	temp->left=NULL;
	temp->right=NULL;
	temp->data = element;

	if(tr == NULL)
		tr = temp;
	else
	{
		tree_node *curr;
		curr = tr;
		while(curr != NULL) //(curr->left != NULL) && (curr->right != NULL))
		{	
			if((temp->data < curr->data) && (curr->left != NULL))
				curr = curr->left;
			else	
				curr = curr->right;	
		}
		if(temp->data < curr->data)
			curr->left = temp;
		else
			curr->right = temp;
	}
}

/*void tree::print_inorder()
{
	while(tr != NULL)
	{
		print_inorder(tr->left);
		cout<<tr->data<<" ";
		print_inorder(tr->right);
	}
}*/

void tree::print_iterative_inorder()
{
	int n = 10, i=0; //TBD no.of nodes to be derived dynamically
	tree_node *save[n];
	tree_node *root;
	root = tr;

	while(root != NULL)
	{
		while(root != NULL)
		{
			if(root->right != NULL)
				save[i++]=root->right;
			save[i++]=root;
			root=root->left;
		}
		root=save[--i];
		while((i!=0) && (root->right!=NULL))
		{
			cout<<root->data<<" ";
			root=save[--i];
		}
		cout<<root->data<<" ";
		root = (i!=0)?save[--i]:NULL;
	}	
}

void tree::print_iterative_preorder()
{
	int n=20, top=0;
	tree_node *save[20];
	tree_node *root, *temp;
	root = tr;

	if(root != NULL)
		save[top++]=root;
	while(top!=0)
	{
		temp = save[top--];
		cout<<temp->data<<" ";
		if(temp->right != NULL)
			save[top++]=temp->right;
		if(temp->left != NULL)
			save[top++]=temp->left;
	}

}

void tree::print_iterative_postorder()
{
	int n=20, top=0;
	tree_node *save[20];
	tree_node *root, *temp;
	root=tr;

	
}


int main()
{
	tree t1;
	//t1.create_tree();
	//t1.print_inorder();
	t1.add_node(30);
	t1.add_node(20);
	t1.add_node(40);
	//t1.print_iterative_inorder();
	return 0;
}

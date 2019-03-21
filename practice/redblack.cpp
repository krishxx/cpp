#include <iostream>
#include <iomanip>
using namespace std;

enum Color {RED, BLACK};

typedef struct node
{
	int data;
	bool color;
	struct node *left, *right, *parent;
	
	/*node(int data)
	{
		this->data = data;
		left=right=parent=NULL;
	}*/
}rbtree_node;

class RBTree
{
	private:
		rbtree_node *root;
		
	protected:
		void inorderHelper(rbtree_node *root);
	public:
		RBTree(){root=NULL;}
		void insert(const int &n);
		~RBTree(){delete [] root;}
		void inorder();
	/*	
	protected:
		void rotateLeft();
		void rotateRight();
		void fixViolation();
	public:
		RBTree() {root=NULL;}
		void insert(const int &n);
		void inorder();
		void levelOrder();
		*/
};

void RBTree::inorderHelper(rbtree_node *root)
{
	if(root)
	{
		inorderHelper(root->left);
		cout<<" ["<<root->data<<":"<<root->color<<"]";
		inorderHelper(root->right);
	}
}

void RBTree::insert(const int &n)
{
	rbtree_node *temp=new rbtree_node();
	temp->data = n;
	temp->color=RED;

	rbtree_node *curr=NULL, *prev=NULL;
	curr=root;
	
	if(curr == NULL)
	{
		temp->color=BLACK;
		root=temp;
		cout<<root->data<<" is added as root node"<<endl;
	}
	else
	{
		while(curr!=NULL)
		{
			prev=curr;
			curr=(curr->data<temp->data)?curr->left:curr->right;
		}
		curr=prev;
		temp->color=RED;
		cout<<temp->data<<" is added as ";
		if(curr->data<temp->data)
		{
			cout<<"left node"<<endl;
			curr->left=temp;			
		}			
		else
		{
			cout<<"right node"<<endl;
			curr->right=temp;
		}
	}	
}

void RBTree::inorder()
{
	inorderHelper(root);
}

int main()
{
	RBTree rbt;
	rbt.insert(20);
	rbt.insert(18);
	rbt.insert(22);
	cout<<"Inorder-> ";
	rbt.inorder();
	cout<<endl;
	return 0;
}

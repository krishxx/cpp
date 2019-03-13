#include <iostream>
#include <iomanip>

using namespace std;

typedef struct
{
	struct tree_node *left;
	int data;
	struct tree_node *right;       	
}tree_node;

class tree
{
	tree_node *tr;
	public:
		void create_tree();
		void add_node(tree_node *item, int element);
}

void tree::create_tree()
{
	int i=0;
	tree *t1 = new tree(sizeof(tree));
	t1->left = null;
	t2->right = null;	
}

void tree::add_node(tree_node *t, int element)
{
	tree *temp = new tree(sizeof(tree));
	temp->left=null;
	temp->right=null;

	if(tr == null)

}

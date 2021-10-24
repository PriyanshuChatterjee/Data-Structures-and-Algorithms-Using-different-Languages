#include<bits/stdc++.h>

using namespace std;


class node
{
	public:
	int data;
	node* lt;
	node* rit;
	

	node(int data)
	{
		this->data = data;
		this->lt = NULL;
		this->rit = NULL;
		
	}
};


int Util(node* node, int *min_ref, int *max_ref,
					int *msr, bool *ibr);



int largestBST(node* node)
{
	
	int min = INT_MAX; 
	int max = INT_MIN; 
	
	int max_size = 0; 
	bool is_bst = 0;
	
	Util(node, &min, &max,
					&max_size, &is_bst);
	
	return max_size;
}


int Util(node* node, int *min_ref, int *max_ref,
					int *msr, bool *ibr)
{


	if (node == NULL)
	{
		*ibr = 1; 
		return 0; 
	}
	
	int min = INT_MAX;
	

	bool lt_flag = false;
	

	bool rit_flag = false;
	
	int ls, rs;
	
	
	*max_ref = INT_MIN;
	ls = Util(node->lt, min_ref, max_ref,
						msr, ibr);
	if (*ibr == 1 && node->data > *max_ref)
		lt_flag = true;
	
	min = *min_ref;
	*min_ref = INT_MAX;
	rs = Util(node->rit, min_ref,
						max_ref, msr, ibr);
	if (*ibr == 1 && node->data < *min_ref)
		rit_flag = true;
		
	if (min < *min_ref)
		*min_ref = min;
	if (node->data < *min_ref) 
		*min_ref = node->data;
	if (node->data > *max_ref)
		*max_ref = node->data;
	

	if(lt_flag && rit_flag)
	{
		if (ls + rs + 1 > *msr)
			*msr = ls + rs + 1;
		return ls + rs + 1;
	}
	else
	{

		*ibr = 0;
		return 0;
	}
}


int main()
{
	
	
	node *root = new node(50);
	root->lt = new node(10);
	root->rit = new node(60);
	root->lt->lt = new node(5);
	root->lt->rit = new node(20);
	root->rit->lt = new node(55);
	root->rit->lt->lt = new node(45);
	root->rit->rit = new node(70);
	root->rit->rit->lt = new node(65);
	root->rit->rit->rit = new node(80);
	cout<<" Size of the largest BST is "<< largestBST(root);

	return 0;
}
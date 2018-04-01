// convert preorder traversal to bst
#include<iostream>
using namespace std;

struct TreeNode
{
	int data;
	TreeNode *left, *right;
	
	TreeNode(int d):data(d), left(NULL), right(NULL)
	{
		
	}
};


void convertPreorderToBST(int arr[], int start,int end,  TreeNode** root)
{
	if(start>end)
	{
		return;
	}
	cout<<"for "<<arr[start]<<endl;
	*root= new TreeNode(arr[start]);
	
	int i = start;
	for(;i<=end;i++)
	{
		if(arr[i]>arr[start])
		{
			break;
		}
	}
	if(start==end)
	{
		return;
	}
	convertPreorderToBST(arr, start+1,i-1, &(*root)->left);
	convertPreorderToBST(arr, i, end, &(*root)->right);
	
}

void printInorder (TreeNode* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout<<node->data;
    printInorder(node->right);
}
int main()
{
	int preOrder[] = {10, 5, 1, 7, 40, 50};
	
	TreeNode* root;
	convertPreorderToBST(preOrder,0 ,5, &root);
	
	printInorder(root);
}

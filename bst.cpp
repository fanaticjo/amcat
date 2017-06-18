#include<queue>
#include<iostream>
using namespace std;
struct bstnode
{
	int data;
	bstnode *right;
	bstnode *left;
};
bstnode *getnode(int x)
{
	bstnode *temp=new bstnode();
	temp->data=x;
	temp->right=NULL;
	temp->left=NULL;

}
bstnode *insert(bstnode *root,int data)
{
	if(root==NULL)
	{
       root=getnode(data);

	}
	else if(data<=root->data)
	{
		root->left=insert(root->left,data);
	}
	else
	{
		root->right=insert(root->right,data);
	}
	return root;
}
bool search(bstnode *root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	else if(root->data==data)
	{
		return true;
	}
	else if(data<=root->data)
	{
		return search(root->left,data);
	}
	else
	{
		return search(root->right,data);
	}
}
bstnode *findmin1(bstnode *root)
{
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
int findmin(bstnode *root)
{
	if(root==NULL)
	{
		cout<<"tree empty";

	}
	else if(root->left==NULL)
	{
		return root->data;
	}
	return findmin(root->left);
}
int findheight(bstnode *root)
{
	if(root==NULL)
	{
		return -1;
	}
	int left=findheight(root->left);
	int right=findheight(root->right);
	if(left>right)
	{
		return left+1;
	}
	else
		return right+1;
}
void levelorder(bstnode *root)
{   
	if(root==NULL)
	{
		return;
	}
	queue<bstnode*> q;
    q.push(root);
    while(!q.empty())
    {
    	bstnode *current=q.front();
    	cout<<current->data<<"\t";
    	if(current->left!=NULL)
    	{
 				q.push(current->left);
    	}
    	if(current->right!=NULL)
    	{
    		q.push(current->right);
    	}
    	q.pop();
    }
}
bstnode *delete1(bstnode *root,int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data<root->data)
	
		root->left=delete1(root->left,data);
  	else if(data>root->data)
  		  root->right=delete1(root->right,data);
  		else
  		{
  			if(root->left==NULL && root->right==NULL)
  			{
  				delete root;
  				root=NULL;
  			}
  			else if(root->left==NULL)
  			{
  				bstnode *temp=root;
  				root=root->right;
  				delete root;
  				root=NULL;

  			}
  			else
  			{
  				bstnode *temp=findmin1(root->right);
  				root->data=temp->data;
  				root->right=delete1(root->right,temp->data);
  			}
  		}
  		return root;
	
}
int findmax(bstnode *root)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->right==NULL)
	{
		return root->data;
	}
	return findmax(root->right);
}
bool bstcheck(bstnode *root,int min,int max)
{
	if(root==NULL)
	{
		return true;
	}
	else if(root->data<min && root->data<max && bstcheck(root,min,root->data) && bstcheck(root,root->data,max))
	{
		return true;
	}
	else{
		return false;
	}
}
bool check(bstnode *root)
{
    return bstcheck(root,INT_MIN,INT_MAX);
}


int main()
{
	bstnode *root=NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,25);
	root=insert(root,8);
	root=insert(root,12);
	cout<<"enter the number ";
	int x;
	cin>>x;
	if(search(root,x)==true)
	{
		cout<<"searched";
	}
	else
	{
		cout<<"nt";
	}
	cout<<endl;
	cout<<"min";
	cout<<findmin(root);
	cout<<findmax(root);
	cout<<"\nthe height of the tree is "<<findheight(root)<<"\n";
	//delete1(root,20);
	levelorder(root);
	if(check(root)==true)
	{
		cout<<"true";
	}
	else
	{
		cout<<"false";
	}
}
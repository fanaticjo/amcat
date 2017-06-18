#include<iostream>
using namespace std;
struct Node 
{
	int data;
	 struct Node *next;
	struct Node *prev;
};
struct Node *head;
struct Node *getNode(int x)
{
	 Node *createNode=new Node();
	 createNode->data=x;
	 createNode->next=NULL;
	 createNode->prev=NULL;
	 return createNode;
}
void insertAt_head(int x)
{
	Node *temp=getNode(x);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	head->prev=temp;
	temp->next=head;
	head=temp;
}
void insertAt_end(int x)
{
	Node *temp=getNode(x);
	if(head==NULL)
	{
		head=temp;
		return;
	}
	Node *pointer=head;
	while(pointer->next!=NULL)
	{
		pointer=pointer->next;
	}
	pointer->next=temp;
	temp->prev=pointer;
}
void delete_athead()
{
	if(head==NULL)
	{
		return;
	}
    head=head->next;
    head->prev=NULL;

}
void print()
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}
void reverse()
{
	Node *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->prev;

	}
}
int main()
{
	head=NULL;
	insertAt_head(9);
	insertAt_head(10);
	insertAt_head(11);
	insertAt_head(13);
	insertAt_end(1);
	insertAt_end(2);
	delete_athead();
	cout<<"printing the elements are :";
	print();
	cout<<"\nthe reverse elemets are :";
	reverse();
}



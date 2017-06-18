#include<iostream>
using namespace std;
Node *circular(Node *head,Node *new_node)
{
	Node *current=head;
	if(current==NULL)
	{
		new_node->next=new_node;
		head=new_node;
	}
	else if(current->data >= new_node->data)
	{
		while(current->next!=head)
		{
			current=current->next;
			current->next=new_node;
			new_node->next=head;
			head=new_node;
		}
	}
	else
	{
		while(current->next!=NULL && current->data<new_node->data)
		{
			current=current->next
			new_node->next=current->next;
			current->next=new_node;
		}
	}
	return head
}
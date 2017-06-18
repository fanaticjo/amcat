#include<iostream>
#include<stack>
using namespace std;
struct Node 
{
	int data;
	Node *next;
};
Node *head;

Node *getnode(int data)
{
	Node *temp=new Node();
	temp->next=NULL;
	temp->data=data;
	head=temp;
	return head;

}
Node *insertnode(Node *head,int data,int pos)
{  
	Node *temp=getnode(data);
	if(pos==0)
	{
       temp->next=head;
       head=temp;
       return head;
	}
	Node *temp1=head;
	for(int i=0;i<pos-1;i++)
	{
		temp1=temp1->next;
	}
	temp->next=temp1->next;
	temp1->next=temp;
	return head;
}
Node *display(Node *head)
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
}
void reverse(Node *head)
{   
	stack<int> s;
	Node *temp=head;
	Node *prev=NULL;
	int c=1;
	while(temp!=NULL)
	{
      c++;
      s.push(temp->data);
      temp=temp->next;
	}
	int mid=0;
	if((c%2)==0)
	{
       mid=c/2;
	}
	else
	{
		mid=(c+1)/2;
	}
	cout<<"\n"<<mid<<endl;
	temp=head;
	for(int i=1;i<mid;i++)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	if(mid%2==0)
	{
	while(mid>1)
	{
		cout<<s.top()<<"\t";
		s.pop();
		mid--;
	}
    }
    else
    {
    	while(mid>=1)
	{
		cout<<s.top()<<"\t";
		s.pop();
		mid--;
	}
    }
	cout<<"\n"<<mid<<endl;
}
int main()
{  
	head=NULL;
	head=insertnode(head,10,0);
	head=insertnode(head,11,1);
	head=insertnode(head,12,2);
	head=insertnode(head,13,3);
	head=insertnode(head,1,0);
	display(head);
	cout<<"\n";
	reverse(head);
}
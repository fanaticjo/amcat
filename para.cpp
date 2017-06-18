#include<iostream>
#include<stack>
#include<string>
using namespace std;
int count(char ch[],int c1)
{
	string s;
	stack<char> r;
	int c=0;
	s=ch;
	
	for(int j=0;j<1;j++)
	{
		bool check=true;;
	for(int i=0;i<s.length();i++)
	{   
		check=true;
		if(s[i]=='(' || s[i]=='[' || s[i]=='{')
		{
		   r.push(s[i]);
		   continue;
		}
		if(r.empty())
		{
			check=false;
			break;
		}
		if(s[i]=='}' && r.top()=='{')
		{
			c++;
			r.pop();
		}
		else if(s[i]==']' && r.top()=='[')
		{
			c++;
			r.pop();
		}
		else if(s[i]==')' && r.top()=='(')
		{
			c++;
			r.pop();
		}

		else
		{
			check=false;
			break;
		}
	}
	if(check && r.empty())
	{
		return c;
	}
	else
	{
		return -1;
	}
}
}
int main()
{
	char ch []="{[[][][][][][][][][][][][][][][][][][][][][]]([][][][][][][][][[][][]])}";
	string s=ch;
	cout<<count(ch,s.length());
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
char a[1000];
string s1,s2;
stack<char> T;
int co;
void prin()
{
	for(int i=0;i<co;i++)
		printf("%c ",a[i]);
	printf("\n");
}
void dfs(int p,int q)
{
	char c;
	if(q==s2.length())
	{
		prin();
		return ;
	}
	
	if(p <s1.length())
	{
		c=s1[p];
		T.push(c);
		a[co++]='i';
		//cout<<"i"<<endl;
		dfs(p+1,q);
		T.pop();
		co--;
	}
	if(!T.empty())
	{
		c=T.top();
		if(c==s2[q])
		{
			T.pop();
			a[co++]='o';
		//	cout<<"o"<<endl;
			dfs(p,q+1);
			co--;
			T.push(c);
		} 
	} 
}
int main()
{
	while(cin>>s1>>s2)
	{
		co=0;
		while(T.empty()==0)
			T.pop();
		cout<<"["<<endl;
		dfs(0,0);
		cout<<"]"<<endl; 
	} 
	return 0;
} 

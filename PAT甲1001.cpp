#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int a,b,i;
	int s[100];
	cin>>a>>b;
	a=a+b;
	b=abs(a);
	i=1;
	if(b==0) cout<<"0";
	while(b)
	{
		s[i]=b%10;
		b=b/10;
		i++;
	}
	if(a<0) cout<<"-";
	for(int j=i-1;j>=1;j--)
	{
		cout<<s[j];
		if(j%3==1&&j!=1) cout<<",";	
	}
		
}

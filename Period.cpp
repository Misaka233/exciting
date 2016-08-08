#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=1000010;
char s[maxn];
int Next[maxn];
void getnext()
{
	memset(Next,0,sizeof(Next));
	int j=0,k=-1;
	Next[0]=-1;
	while(s[j])
	{
		if(-1==k||s[j]==s[k]) Next[++j]=++k;
		else k=Next[k];
	}
}
void kmp()
{
	for(int i=2;s[i-1];i++)
	{
		int t=i-Next[i];
		if(0==i%t&&i/t>1) printf("%d %d\n",i,i/t);	 
	}
}
int main()
{
	int Case=1;  
    int n;  
    while(scanf("%d",&n),n)  
    {  
        scanf("%s",s);  
        printf("Test case #%d\n",Case++);  
        getnext();  
        kmp();  
        printf("\n");  
    }  
}

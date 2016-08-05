#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/*
* next[]的含义：x[i-next[i]...i-1]=x[0...next[i]-1]
* next[i]为满足x[i-z...i-1]=x[0...z-1]的最大z值（就是x的自身匹配）
*/
int Next[1010];
void kmp_pre(char x[],int m)
{
    int i,j;
    j=Next[0]=-1;
    i=0;
    while(i<m)
    {
        while(-1!=j && x[i]!=x[j])j=Next[j];
        Next[++i]=++j;
    }
}



int KMP_Count(char x[],int m,char y[],int n)
{//x是模式串，y是主串
    int i,j;
    int ans=0;
    //preKMP(x,m,next);
    kmp_pre(x,m);
    i=j=0;
    while(i<n)
    {
        while(-1!=j && y[i]!=x[j])j=Next[j];
        i++;j++;
        if(j>=m)
        {
            ans++;
            //j=next[j];
            j=0;
        }
    }
    return ans;
}
int main()
{
    char a[1007],b[1007];
    while(scanf("%s",a)&&a[0]!='#')
    {
        int la=strlen(a);
        scanf("%s",b);
        int lb=strlen(b);
        cout<<KMP_Count(b,lb,a,la)<<endl;
    }
}

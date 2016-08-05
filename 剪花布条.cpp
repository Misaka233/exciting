#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/*
* next[]�ĺ��壺x[i-next[i]...i-1]=x[0...next[i]-1]
* next[i]Ϊ����x[i-z...i-1]=x[0...z-1]�����zֵ������x������ƥ�䣩
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
{//x��ģʽ����y������
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

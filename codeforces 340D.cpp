#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
int a[100005];
int b[100005];
int n;

int findd(int len,int p)   //���ֲ���<=p��λ��
{
    int l,r,mid;
    l=1,r=len,mid=(l+r)>>1;
    while(l<=r)
    {
        if(p>b[mid]) l=mid+1;
        else if(p<b[mid]) r=mid-1;
        else return mid;
        mid=(l+r)>>1;
    }
    return l;
}

int LIS()
{
    int i,j,len=1;
    b[1]=a[0];
    for(i=1;i<n;i++)
    {
        j=findd(len,a[i]);
        b[j]=a[i];  //b[j]��ָ����Ϊj���Ԫ�ص�ֵ
        if(j>=len) len=j;
    }
    return len;
}

int main()
{

    int i;
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",LIS());
    }
    return 0;
}

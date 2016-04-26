#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 41000;
int a[N];       //a[i] ԭʼ����
int d[N];       //d[i] ����Ϊi�ĵ��������е���Сֵ

int BinSearch(int key, int* d, int low, int high)
{
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(key>d[mid] && key<=d[mid+1])
            return mid;
        else if(key>d[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return 0;
}

int LIS(int* a, int n, int* d)
{
    int i,j;
    d[1] = a[1];
    int len = 1;        //���������г���
    for(i = 2; i <= n; i++)
    {
        if(d[len]<a[i])
            j = ++len;
        else
            j = BinSearch(a[i],d,1,len) + 1;
        d[j] = a[i];
    }
    return len;
}

int main()
{
    int t;
    int p;
        scanf("%d",&p);
        for(int i = 1; i <= p; i++)
            scanf("%d",&a[i]);
        int length=LIS(a,p,d);
        for(int i=1;i<=length;i++)
        {
            cout<<d[i]<<" ";
        }
    return 0;
}

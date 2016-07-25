#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=200007;
int a[maxn],b[maxn];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    bool aa=1,bb=1;
    for(int i=0;i<(n/2+1);i++)
    {
        if(a[n+i-n/2-1]<=b[i])
            aa=false;
        if(b[n+i-n/2-1]<=a[i])
            bb=false;
    }
    if(aa&&bb)
        cout<<"Both"<<endl;
    else if(aa)
        cout<<"First"<<endl;
    else if(bb)
        cout<<"Second"<<endl;
    else
        cout<<"None"<<endl;
    return 0;
}

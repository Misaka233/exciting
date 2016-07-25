#include<bits/stdc++.h>
using namespace std;
int n,mmax,mmin;
const int maxn=200007;
int a[maxn];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    mmax=a[0]+a[1];
    mmin=a[n-1]-a[0];
    if(mmax-1<=mmin) printf("NO\n");
    else printf("YES\n%d",mmin+1);
    return 0;
}

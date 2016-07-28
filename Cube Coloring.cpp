#include<bits/stdc++.h>
using namespace std;
int n,x,y,z,a,b,c;
long long ans[1005],xy[3][1005];
int main()
{
    cin>>x>>y>>z>>a>>b>>c>>n;
    for(int i=0;i<x;i++) xy[0][abs(i-a)%n]++;
    for(int i=0;i<y;i++) xy[1][abs(i-b)%n]++;
    for(int i=0;i<z;i++) xy[2][abs(i-c)%n]++;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[(i+j)%n]+=xy[0][i]*xy[1][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        xy[0][i]=ans[i];
        ans[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ans[(i+j)%n]+=xy[0][i]*xy[2][j];
        }
    }
    for(int i=0;i<n-1;i++) cout<<ans[i]<<" ";
    cout<<ans[n-1]<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int f(int x)
{
    int i=2;
    while(x/i!=0)
    {
        x-=x/i;
        i++;
    }
    return x;
}
int main()
{
    int l,r;
    cin>>l>>r;
    cout<<f(r)-f(l-1)<<endl;
    return 0;
}

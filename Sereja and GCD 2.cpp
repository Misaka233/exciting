#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

vector<int>f;
int p[20];
int main()
{
    int t,n,m,u,v,ans;
    bool vis;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(m>10) cout<<0<<endl;
        else
        {
            p[0]=n;
            for(int i=1;i<n;i++) p[i]=p[i-1]*(n-i)%mod;
            ans=1;
            for(int i=1;i<(1<<(m-1));i++)
            {
                f.clear();
                for(int j=0;j<m-1;j++)
                {
                    if((1<<j)&i) f.push_back(j+2);
                }
                vis=0;
                for(u=0;u<f.size();u++)
                {
                    for(v=u+1;v<f.size();v++)
                    {
                        if(__gcd(f[v],f[u])>1) vis=1;
                    }
                }
                if(!vis) ans+=p[f.size()-1];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

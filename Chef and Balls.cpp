#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=1;i<=5;i++)
    {
        for(int j=i+2;j<=5;j++)
        {
            cout<<1<<endl;
            cout<<1<<" "<<i<<endl;
            cout<<1<<" "<<j<<endl;
            fflush(stdout);
            int re;
            cin>>re;
            if(re!=0)
            {
                cout<<2<<endl;
                if(re==-1) cout<<j<<endl;
                else cout<<i<<endl;
                fflush(stdout);
                return 0;
            }
        }
    }
    return 0;
}

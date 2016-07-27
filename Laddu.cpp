#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,co,num,ans;
    string s;
    cin>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>s;
        if("INDIAN"==s) co=200;
        else co=400;
        while(n--)
        {
            cin>>s;
            if("CONTEST_WON"==s)
            {
                cin>>num;
                ans+=300+max(0,20-num);
            }
            else if("TOP_CONTRIBUTOR"==s)
                ans+=300;
            else if("BUG_FOUND"==s)
            {
                cin>>num;
                ans+=num;
            }
            else if("CONTEST_HOSTED"==s)
                ans+=50;
        }
        printf("%d\n",ans/co);
    }
}

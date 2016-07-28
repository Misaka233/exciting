#include<bits/stdc++.h>
using namespace std;
const int maxn=107;
string s[maxn];
int l[maxn],r[maxn];
int hass[maxn];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(hass,0,sizeof(hass));
        memset(l,0,sizeof(l));
        memset(r,0,sizeof(r));
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            int len=s[i].length();
            for(int j=0;j<len;j++)
            {
                if(s[i][j]=='(')
                    l[i]++;
                else if(s[i][j]==')')
                {
                    if(0==l[i]) r[i]++;
                    else l[i]--;
                }
            }
        }
        int flag=0,sum=0,tmp,tmp1,tmp2;
        for(int c=1;c<=n;c++)
        {
            tmp=tmp1=tmp2=-1;
            for(int i=1;i<=n;i++)
            {
                if(hass[i]) continue;
                if(sum>=r[i])
                {
                    if(tmp1<l[i])
                    {
                        tmp=i;
                        tmp1=l[i];
                        tmp2=r[i];
                    }
                    else if(tmp1==l[i]&&tmp2>r[i])
                    {
                        tmp=i;
                        tmp1=l[i];
                        tmp2=r[i];
                    }
                }
            }
            if(tmp==-1)
            {
                flag=1;
                break;
            }
            hass[tmp]=1;
            sum=sum-tmp2+tmp1;
        }
        if(flag) cout<<"No"<<endl;
        else if(0==sum) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}


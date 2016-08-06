/*
���⣺����n���������������ĳ˻���Լ���ĳ˻���MOD��һ����
��Ԫ
a^n%m= a^(n mod(m-1))%m;
*/
#include<bits/stdc++.h>
using namespace std;
typedef __int64 LL;
const   LL maxn = 200010;
const  LL mod= (1e9+7);
LL rec[maxn];
LL c[maxn];
LL l[maxn];
LL r[maxn];
LL _mod(LL  a, LL  b)
{
 LL  ans =1;
    while(b)
    {
        if(b&1)
        {
            ans = (ans%mod)*(a%mod)%mod;

        }
        b>>=1;
        a= (a%(mod))*(a%(mod))%mod;
    }
    return ans ;
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(c,0,sizeof(c));
    int cot = 1;
    int x;
    for(int i = 1; i<=n; i++)
    {
        scanf("%d",&x);
        if(!c[x])
        {
            rec[cot++] = x;
            c[x]++;
        }
        else
        {
            c[x]++;
        }
    }
    cot--;
    l[0]= 1;
    r[cot+1] =1;
    for(int i = 1; i<=cot; i++)
    {
        l[i] = (l[i-1]%(mod-1)*(c[rec[i]]+1)%(mod-1))%(mod-1);//l[i]��1--i֮�����ӵ��������
    }
    for(int i = cot; i>=1; i--)
    {
        r[i] = ((r[i+1]%(mod-1))*(c[rec[i]]+1)%(mod-1))%(mod-1);//r[i]��i--r֮������ӵ��������
    }
    long long ans = 1;
    for(int i =1 ; i<=cot; i++)
    {
        if(c[rec[i]])
        {
            LL num =(l[i-1]*r[i+1])%(mod-1)*(((c[rec[i]]+1)*(c[rec[i]])/2)%(mod-1))%(mod-1);//����ÿ�����������Ĺ���
             num = num%(mod-1);
            ans = (ans%(mod)*(_mod(rec[i],num))%mod)%mod;
        }
    }
    cout<<ans%mod<<endl;
    return 0;
}

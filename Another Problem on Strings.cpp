#include<bits/stdc++.h>
using namespace std;
long long num[1000010];
string s;
int main()
{
    int k,co=0;
    long long ans=0;
    cin>>k;
    cin>>s;
    num[0]=1;
    int length=s.size();
    for(int i=0;i<length;i++)
    {
        if(s[i]=='1') co++;
        if(co>=k) {ans+=num[co-k];}//����iλ���� co-k ��1ǰ���м���0�𰸾��м��ֿ���
        num[co]++;//��co-1��1ǰ��0����
    }
    cout<<ans<<endl;
    return 0;
}

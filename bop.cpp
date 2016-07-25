#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
long long int start,end,temp;
long long int i,j,co,flag;
string s;
int judge1()//p-au
{
    flag=0;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='A'&&s[i+1]=='u'&&s[i+2]=='I'&&s[i+3]=='d')
        {
            flag=1;
            temp=0;co=0;
            for(j=i+6;;j++)
            {
                if(s[j]-'0'>=0&&s[j]-'0'<=9)
                    {
                        temp=temp*10+s[j]-'0';
                        co++;
                    }
                else
                    break;
            }
            if(temp==end) return 1;
            i+=co;
        }
    }
    if(flag==0)
    {
        return 2;
    }
    return 0;
}
int judge2()//p-p
{
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='R'&&s[i+1]=='I'&&s[i+2]=='d')
        {
            temp=0;co=0;
            for(j=i+6;;j++)
            {
                if(s[j]-'0'>=0&&s[j]-'0'<=9)
                {
                        temp=temp*10+s[j]-'0';
                        if(temp==end) return 1;

                }
                else if(s[j+2]-'0'>=0&&s[j+2]-'0'<=9)
                {
                    j+=2; temp=0;
                }
                else break;
            }

        }
    }
    return 0;

}
int main()
{

    start=2140251882;end=2012580531;
    //https://oxfordhk.azure-api.net/academic/v1.0/evaluate?expr=Id=start&attributes=RId,Id,AA.AuId,AA.AfId,C.CId&conut=10&offset=0&subscription-key=f7cc29509a8443c5b3a5e56b0e38b5a6
    getline(cin,s);


    int t=judge1();
    if(t==2)
    {
        swap(start,end);

        //https://oxfordhk.azure-api.net/academic/v1.0/evaluate?expr=Id=start&attributes=RId,Id,AA.AuId,AA.AfId,C.CId&conut=10&offset=0&subscription-key=f7cc29509a8443c5b3a5e56b0e38b5a6
        getline(cin,s);
        t=judge1();
    }
    if(t==0) t=judge2();
    cout<<t;
    return 0;
}

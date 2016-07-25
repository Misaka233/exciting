#include<bits/stdc++.h>
using namespace std;
int a[3],b[3];
bool judge(int A,int B)
{
    return((A<=a[0]&&B<=b[0])||(A<=b[0]&&B<=a[0]));
}
int main()
{
    for(int i=0;i<3;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(judge((a[1]+a[2]),max(b[1],b[2])))
        cout<<"YES"<<endl;
    else if(judge((a[1]+b[2]),max(b[1],a[2])))
        cout<<"YES"<<endl;
    else if(judge((b[1]+a[2]),max(a[1],b[2])))
        cout<<"YES"<<endl;
        else if(judge((b[1]+b[2]),max(a[1],a[2])))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}

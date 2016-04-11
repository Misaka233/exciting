#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int co=0;
    int x=2015;
    while(x)
    {
        co++;
        return x&(x-1);
    }
    cout<<x;
    return 0;
}

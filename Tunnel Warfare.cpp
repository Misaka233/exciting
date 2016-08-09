#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
const int N=2000000;
set<int> ms;
set<int>::iterator it;
stack<int>s;
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        while(!s.empty())
            s.pop();
        ms.clear();
        ms.insert(0);
        ms.insert(n+1);
        char x;
        int y;
        for(int i=0; i<m; i++)
        {
            scanf(" %c",&x);
            if(x=='D')
            {
                scanf("%d",&y);
                s.push(y);
                ms.insert(y);
            }
            else if(x=='Q')
            {
                scanf("%d",&y);
                it=ms.lower_bound(y);
                int t1=*it;
                if(t1==y)
                {
                    printf("0\n");
                    continue;
                }
                it--;
                int t2=*it;
                printf("%d\n",t1-t2-1);
            }
            else
            {
                y=s.top();
                s.pop();
                ms.erase(y);
            }
        }
    }
    return 0;
}


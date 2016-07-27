#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b,c,d,k,p;
    scanf("%d%d%d%d%d",&b,&c,&d,&k,&p);
    double tot=1.0*k*c+0.5*k*(k+1)*d;
    double ans1=b+tot;
    double ans2=tot*(1.0+p/100.0);
    if(ans1<ans2)
    {
        printf("Cash\n%.2f\n",ans2-ans1);
    }
    else
    {
        printf("Insurance\n%.2f\n",ans1-ans2);
    }
    return 0;
}

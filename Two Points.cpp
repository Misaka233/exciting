#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define esp 0.00000000001
const int N=2e5+10,M=1e6+10,inf=1e9;
int main()
{
    double x1,x2,y1,y2,vx1,vx2,vy1,vy2;
    cin>>x1>>y1>>x2>>y2;
    cin>>vx1>>vy1>>vx2>>vy2;
    double a=vx1-vx2;
    double b=x1-x2;
    double c=vy1-vy2;
    double d=y1-y2;
    double t=-(a*b+c*d)/(a*a+c*c);
    double ans=(a*a+c*c)*t*t+(2*a*b+2*c*d)*t+b*b+d*d;
    if(t>0)
        printf("%.6lf\n",sqrt(ans));
    else
        printf("%.6lf\n",sqrt((x1-x2)*(x1-x2)-(y1-y2)*(y1-y2)));
    return 0;
}

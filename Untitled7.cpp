#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x,y,a,b,z,i,t;
    double vx,vy,va,vb;
    cin>>x>>y>>a>>b;
    cin>>vx>>vy>>va>>vb;
    double fa,fb,fc;
    fa=(vx-va)*(vx-va)+(vy-vb)*(vy-vb);
    fb=2.0*((vb-vy)*(b-y)+(va-vx)*(a-x));
    fc=(a-x)*(a-x)+(b-y)*(b-y);
    double ans=(4*fa*fc-fb*fb)/(4*fa);
    double zuo=-fb/(2.0*fa);
    if(zuo>=0.0)
    printf("%.6f\n",sqrt(ans));
    else
    printf("%.6f\n",sqrt(fc));
    return 0;
}


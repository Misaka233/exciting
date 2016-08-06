#include<bits/stdc++.h>
using namespace std;
#define INF 10000000
using namespace std;
const int MAX_N=1e6+10;
const double PI=acos(-1.0);

struct Point
{
    double a,b;
}p[MAX_N];

double getl(Point X,Point Y)
{
    double d1=(X.a-Y.a)*(X.a-Y.a);
    double d2=(X.b-Y.b)*(X.b-Y.b);
    return sqrt(d1+d2);
}

double getlength(Point A,Point B,Point C,double &temp)/// C to A-B
{
    double a=getl(A,C);
    double b=getl(B,C);
    double c=getl(A,B);
    temp=max(a,b);

    if(a*a>=b*b+c*c)/// B or A >=90
        return b;
    if(b*b>=a*a+c*c)
        return a;

    double pp=(a+b+c)/2;
    double s=(pp-a)*(pp-b)*(pp-c)*pp;
    s=sqrt(s);
    double d=s*2/c;
    return d;
}

int main()
{
    int n;
    scanf("%d",&n);
    Point T;
    scanf("%lf%lf",&T.a,&T.b);
    for(int i=0;i<n;i++)    scanf("%lf%lf",&p[i].a,&p[i].b);
    double maxx=-(double)INF;
    double minn=(double)INF;
    double temp;
    for(int i=0;i<n;i++)
    {
        minn=min(minn,getlength(p[i],p[(i+1)%n],T,temp));
        maxx=max(maxx,temp);
    }
    double ans=maxx*maxx-minn*minn;
    ans*=PI;
    printf("%.10lf\n",ans);
    return 0;
}

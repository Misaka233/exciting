#include<bits/stdc++.h>
using namespace std;
#define zero(x) (((x)>0?(x):-(x))<eps)
#define sqr(x) (x)*(x)
const double eps=1e-5;
struct point3{double x,y,z;}a,b,c,d;
struct line3{point3 a,b;};
struct plane3{point3 a,b,c;};
bool t;
void init()
{
    scanf("%lf%lf%lf",&a.x,&a.y,&a.z);
    scanf("%lf%lf%lf",&b.x,&b.y,&b.z);
    scanf("%lf%lf%lf",&c.x,&c.y,&c.z);
    scanf("%lf%lf%lf",&d.x,&d.y,&d.z);
}
double dmut(point3 u , point3 v)
{
    return u.x*v.x+u.y*v.y+u.z*v.z;
}
point3 xmult(point3 u,point3 v)
{
    point3 co;
    co.x=u.y*v.z-u.z*v.y;
    co.y=u.z*v.x-u.x*v.z;
    co.z=u.x*v.y-u.y*v.x;
    return co;
}
point3 subt(point3 u,point3 v)
{
    point3 co;
    co.x=u.x-v.x;
    co.y=u.y-v.y;
    co.z=u.z-v.z;
    return co;
}
double len(point3 p)
{
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
point3 find_mid(point3 a,point3 b,point3 c,point3 d)
{
    double t=dmut(subt(c,a),subt(b,a))/(sqr(len(subt(b,a))));
    point3 mid=a;
    point3 x=subt(b,a);
    mid.x+=t*x.x;
    mid.y+=t*x.y;
    mid.z+=t*x.z;
    return mid;
}
bool check()
{
    return zero(dmut(subt(a,b),subt(c,d)));
}
bool dotin(point3 p,point3 l1,point3 l2)
{
    return zero(len(xmult(subt(p,l1),subt(p,l2))))&&(l1.x-p.x)*(l2.x-p.x)<eps&&(l1.y-p.y)*(l2.y-p.y)<eps&&(l1.z-p.z)*(l2.z-p.z)<eps;
}
bool check_mid()
{
    point3 mid=find_mid(a,b,c,d);
    if(!dotin(b,a,mid)) return 0;
    if(!dotin(c,mid,d)) return 0;
    return 1;
}
bool fuck()
{
    return zero(dmut(xmult(subt(a,b),subt(a,c)),subt(d,a)));
}
bool doit()
{
    if(!check()) return 0;
    if(!fuck()) return 0;
    if(!check_mid()) return 0;
    return 1;
}
void prin()
{
    if(t) printf("Valid\n");
    else printf("Invalid\n");
}
int main()
{
    init();
    t=doit();
    prin();
}

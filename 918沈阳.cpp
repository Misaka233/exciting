#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
typedef long long  LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
const double esp=1e-7;
const int Maxn=1e6+10;
int main()
{
    long long  n,m;
    while(cin>>n) {
        m=(n/log(n));
        printf("%I64d\n",(m+1));
    }
    return 0;
}

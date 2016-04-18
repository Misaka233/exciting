#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

int X,Y,cnt;

double DFS(double x,double y,int step)
{
	if(step == 1) {
		if(x < y)	swap(x,y);
		return x / y;
	}
	double _x = x / step,re = 10000.0;
	for(int i = 1;i < step; ++i) {
		double temp = DFS(_x * i,y,i);
		temp = max(temp,DFS(x - _x * i,y,step - i));
		re = min(re,temp);
	}
	double _y = y / step;
	for(int i = 1;i < step; ++i) {
		double temp = DFS(x,_y * i,i);
		temp = max(temp,DFS(x,y - _y * i,step - i));
		re = min(re,temp);
	}
	return re;
}

int main()
{
	cin >> X >> Y >> cnt;
	cout << fixed << setprecision(6) << DFS(X,Y,cnt) << endl;
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 30000 + 10;
int a[MAX];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d,",&a[i]);
    }
    cin>>a[n-1];
    int b = a[0], len = 1;
    int flag=1;
    for (int i=1; i < n; i++)
    {
        if (flag&& b > a[i])
        {
            flag= 0;
            len++;
        }
        else if(!flag&& b < a[i])
        {
            flag= 1;
            len++;
        }
        b = a[i];
    }
    cout << len+1<< endl;
}


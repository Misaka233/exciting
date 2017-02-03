#include<iostream>

using namespace std;

const int MAX = 1024;

int N;
int p[MAX], phi[MAX];

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)	// 初始化
    { p[i] = 1; phi[i] = i; }
    p[1] = 0;	// 1不是素数
    for(int i = 2; i <= N; i++)	// 筛素数
    {
        if(p[i])
        {
            for(int j = i * i; j <= N; j += i)
            { p[j] = 0; }
        }
    }
    for(int i = 2; i <= N; i++)	// 求欧拉函数
    {
        if(p[i])
        {
            for(int j = i; j <= N; j += i)	// 处理素因子p[i]
            {
                phi[j] = phi[j] / i * (i - 1);	// 先除后乘，防止中间过程超出范围
            }
        }
    }
    cout << "Primes: " << endl;
    for(int i = 1; i <= N; i++)
    { if(p[i]) { cout << i << " "; } }
    cout << endl;
    cout << "Euler Phi Function: " << endl;
    for(int i = 1; i <= N; i++)
    { cout << phi[i] << " "; }
    return 0;
}

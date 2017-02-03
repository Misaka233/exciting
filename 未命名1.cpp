#include<iostream>

using namespace std;

const int MAX = 1024;

int N;
int p[MAX], phi[MAX];

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)	// ��ʼ��
    { p[i] = 1; phi[i] = i; }
    p[1] = 0;	// 1��������
    for(int i = 2; i <= N; i++)	// ɸ����
    {
        if(p[i])
        {
            for(int j = i * i; j <= N; j += i)
            { p[j] = 0; }
        }
    }
    for(int i = 2; i <= N; i++)	// ��ŷ������
    {
        if(p[i])
        {
            for(int j = i; j <= N; j += i)	// ����������p[i]
            {
                phi[j] = phi[j] / i * (i - 1);	// �ȳ���ˣ���ֹ�м���̳�����Χ
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

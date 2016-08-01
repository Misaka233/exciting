#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long fact[100000], pf;


long long Euler ( long long n )
{
    long long ret = n, i;
    for ( i = 2; i * i <= n; i++ )
    {
        if ( n % i == 0 )
        {
            n /= i;
            ret = ret - ret / i;
            while ( n % i == 0 )
                n /= i;
        }
    }
    if ( n > 1 )
        ret = ret - ret / n;
    return ret;
}

long long gcd ( long long a, long long b )
{
    long long c;
    while ( b != 0 )
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long mod_mult ( long long a, long long b, long long n )
{
    long long ret = 0;
    a = a % n;
    while ( b >= 1 )
    {
        if ( b & 1 )
        {
            ret += a;
            if ( ret >= n ) ret -= n;
        }
        a <<= 1;
        if ( a >= n ) a -= n;
        b >>= 1;
    }
    return ret;
}

long long mod_exp ( long long a, long long b, long long n )
{
    long long ret = 1;
    a = a % n;
    while ( b >= 1 )
    {
        if ( b & 1 )
            ret = mod_mult(ret,a,n);
        a = mod_mult(a,a,n);
        b >>= 1;
    }
    return ret;
}

void factor ( long long x )
{
    pf = 0;
    for ( long long i = 2; i * i <= x; i++ )
        if ( x % i == 0 )
            fact[pf++] = i, fact[pf++] = x / i;
}

int main()
{
    long long eul;
    long long p, q, d, cnt, cs = 0;
    while ( scanf("%I64d/%I64d",&p,&q) != EOF )
    {
        if(!p){ printf("Case #%I64d: 1,1 \n",++cs);continue; }
        d = gcd(p,q);
        p /= d; q /= d;
        cnt = 1;
        while ( q % 2 == 0 ) { q >>= 1; cnt++; }

        eul = Euler(q);
        factor(eul);
        sort(fact,fact+pf);
        fact[pf++] = eul; long long i;
        for ( i = 0; i < pf; i++ )
            if ( mod_exp (2, fact[i], q) == 1 ) break;
        printf("Case #%I64d: %I64d,%I64d\n",++cs,cnt,fact[i]);
    }
    return 0;
}
/*
���ǿ��Թ۲�һ��1/10�������ݣ����ն�����ת����(�˶���)�����ǿ��Եõ���
1/10  2/10 4/10 8/10 16/10 32/10 ...
Ȼ�󶼷��Ӷ������ܼ�ȥ10���õ���
1/10  2/10 4/10 8/10 6/10 2/10 ...
��ʱ�򣬷��ֳ������ظ�����ô����ظ���������Ҫ�����Сѭ����
�����ģ�����£���p/q
����p'=p/gcd(p,q)
q'=q/gcd(p,q);

Ȼ�����Ǿ�����p'*2^i == p'*2^j (mod q')   (��==����ʾͬ��,i<j)
�����任�õ���
p'*2^i*(2^(j-i)-1) ==0 (mod q')
Ҳ���� q' | p'*2^i*(2^(j-i)-1)
����gcd(p',q')=1,
�õ��� q' | 2^i*(2^(j-i)-1)
��Ϊ2^(j-i)-1Ϊ����������q'�ж��ٸ�2���ݣ�i���Ƕ��٣�����i����ѭ����ʼλ�õ�ǰһλ��
��ô��q''Ϊq'��ȥ2����֮�����
��ʱ q'' | 2^(j-i)-1
Ҳ�������x,ʹ�� 2^x ==1 (mod q'')

ŷ��������a��p���ʣ���a^��(p) == 1 (modp)

����2^x ==1 (mod q'')   �ض����ڽ⡣

������Ҫ�������Сѭ���ڡ�����֪����a,p���ʣ���a^x == 1 (mod p)�� ��ô�ض���a | ��(p)��

���ˣ�ֻ��Ҫ��С����ö�٦�(p�������Ӽ��ɡ�
*/

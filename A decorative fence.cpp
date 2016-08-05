/*
1) 设 A[i] 为i根木棒所组成的合法方案数目。看看能否找出A[i]和A[i-1]
或A[i-j]之间的递推关系(所有木棒总数是i)。称i根木棒的合法方案集合
为S(i)
 2) 在选定了某根木棒x作为第一根木棒的情况下,剩下i-1根木棒的合法
方案数是A[i-1]。但是，这A[i-1]种方案，并不是每种都能和x形成新的
合法方案。将第一根比第二根长的方案称为DOWN方案，第一根比第
二根短的称为UP方案，则，S(i-1)中，第一根木棒比x长的DOWN方
案，以及第一根木棒比x短的UP方案，才能和x构成S(i)中的方案。
111
动归解题思路
 3) 置A[i] = 0。先枚举x。然后针对每个x，枚举x后面的那根木棒y。如果 y >
x(x<y的情况类推），则:
A[i] += 以y打头的DOWN方案数
 但以y打头的DOWN方案数，又和y的长短有关。
 于是难以直接从 A[i-1]或 A[i-j]推出 A[i]
 4) 考虑将A[i]这种粗略的状态描述方式细化，即加上限制条件后分类。设
A[i] = ∑ B[i][k] k = 1….i
B[i][k] 是S(i)中以第k短的木棒打头的方案数。尝试对 B 进行动归。第k短
，指的是i根木棒中第k短。
112
动归解题思路
 5) B[i][k] = ∑ B[i-1][M](DOWN) + ∑ B[i-1][N](UP)
M = k ... i-1 , N = 1… k-1
还是没法直接推。于是把B再分类细化：
B[i][k] = C[i][k][DOWN] + C[i][k][UP]
C[i][k][DOWN] 是S(i)中以第k短的木棒打头的DOWN方案数。然后试图对C进行动
归
C[i][k][UP] = ∑ C[i-1][M][DOWN]
M = k ... i -1
C[i][k][DOWN] = ∑ C[i-1][N][UP]
N = 1… k-1
初始条件：C[1][1][UP]=C[1][1][DOWN] = 1
113
动归解题思路
 经验：当选取的状态，难以进行递推时（分解出的子问题和原
问题形式不一样，或不具有无后效性），考虑将状态增加限制
条件后分类细化，即增加维度，然后在新的状态上尝试递推
114
排序计数
 如1，2，3，4的全排列，共有4！种，求第10个的排列是（从1计
起）？
 先试首位是1，后234有3！=6种<10,说明首位1偏小，问题转换成
求2开头的第（10-6=4）个排列，而3！=6 >= 4，说明首位恰是2。
 第二位先试1（1没用过），后面2！=2个<4,1偏小，换成3（2用过
了）为第二位，待求序号也再减去2！，剩下2了。而此时2!>=2，
说明第二位恰好是3。
 第三位先试1，但后面1！<2，因此改用4。末位则是1了。
 这样得出，第10个排列是2-3-4-1。
115
排序计数
本题待求方案的序号为C
本题就是先假设第1短的木棒作为第一根，看此时的方案数
P(1)是否>=C,如果否，则应该用第二短的作为第一根，C 减去P(1)
，再看此时方案数P(2)和C比如何。如果还 < C ，则应以第三短的
作为第一根,C再减去P(2) ….
若发现 第 i短的作为第一根时，方案数已经不小于C，则确定
应该以第i短的作为第一根， C减去第 i短的作为第一根的所有方案
数，然后再去确定第二根….
微调：以第i短的木棒作第k根时，有UP和DOWN两类方案，
先用DOWN的方案数和C比较
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int UP =0; const int DOWN =1;
const int MAXN = 205;
const int M=210;
int n;
long long C[MAXN][MAXN][2]; //C[i][k][DOWN] 是S(i)中以第k短的木棒打头的DOWN方案数,C[i][k][UP] 是S(i)中以第k短的木棒打头的UP方案数,第k短指i根中第k短
void Init(int x)
{
    memset(C,0,sizeof(C));
    C[1][1][UP] = C[1][1][DOWN] = 1;
    for( int i = 2 ;i <= x; ++ i )
        for( int k = 1; k <= i; ++ k )
        { //枚举第一根木棒的长度
            for( int M = k; M <i ; ++M ) //枚举第二根木棒的长度
                C[i][k][UP] += C[i-1][M][DOWN];
                for( int N = 1; N <= k-1; ++N ) //枚举第二根木棒的长度
                    C[i][k][DOWN] += C[i-1][N][UP];
        }
//总方案数是 Sum{ C[n][k][DOWN] + C[n][k][UP] } k = 1.. n;
}
void Print(long long cc)
{
    int used[M]; //木棒是否用过
    int seq[M]; //最终要输出的答案
    memset(used,0,sizeof(used));
    for(int i = 1; i<=n; ++i)
    {//依次确定每一个位置i的木棒序号
        int No = 0; //位置i的木棒k是剩下的木棒里的第No短的,No从1开始算
        long long skipped = 0; //已经跳过的方案数
        int k;
        for( k = 1; k <=n; ++k)
        {
            if( !used[k])
            { //长度为k的木棒没有用过
                ++No; //k是剩下的木棒里的第No短的
                if( i == 1)
                skipped = C[n][No][UP]+C[n][No][DOWN];
                else
                {
                    if( k > seq[i-1] && ( i <= 2 ||seq[i-2] > seq[i-1])) //合法放置
                        skipped = C[n-i+1][No][DOWN];
                    else if( k < seq[i-1] && (i <= 2 ||seq[i-2] < seq[i-1]))
                        skipped = C[n-i+1][No][UP];
                } //if( i == 1)
                if( skipped >= cc)
                    break;
                else cc-= skipped;
            } // if( !used[k])
        }// for( k = 1; k <=n; ++k)
        used[k] = 1;
        seq[i] = k;
    }
    for(int i = 1;i <= n;++i)
        cout << seq[i] << " ";
    cout << endl;
}

int main()
{
    int T;
    long long c;
    Init(20);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %lld",&n,&c);
        Print(c);
    }
 return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=200007;
int n,cont;
int a[maxn];
int ans[maxn];
int main()
{
    cont=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i==a[i])
        {
            cont++;
            ans[cont]=i;
        }

    }
    if(cont%2==0)
    {
        printf("%d\n",cont/2);
        for(int i=1;i<cont;i+=2)
        {
            printf("%d %d\n",ans[i],ans[i+1]);
        }
    }
    else
    {
        printf("%d\n",cont/2+1);
        for(int i=1;i<cont;i+=2)
        {
            printf("%d %d\n",ans[i],ans[i+1]);
        }
        if(1==ans[cont]) printf("1 2\n");
        else printf("%d %d\n",ans[cont]-1,ans[cont]);
    }
    return 0;
}
//adfasdasd

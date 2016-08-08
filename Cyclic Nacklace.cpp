#include <iostream>  
#include <cstring>  
#include <cstdio>  
  
using namespace std;  
  
char str[100005];  
int Next[100005];  
  
void getnext(int len)  
{  
    int i = 0,j = -1;  
    Next[0] = -1;  
    while(i<len)  
    {  
        if(j == -1 || str[i] == str[j])  
        {  
            i++;  
            j++;  
            Next[i] = j;  
        }  
        else  
            j = Next[j];  
    }  
}  
  
int main()  
{  
    int n;  
    cin >> n;  
    getchar();  
    while(n--)  
    {  
        gets(str);  
        memset(Next,0,sizeof(Next));  
        int len = strlen(str);  
        int ans;  
        getnext(len);  
        ans = len - Next[len];  
        if(ans!=len && len%ans == 0)  
        cout << 0 << endl;  
        else  
        cout << ans-Next[len]%ans << endl;  
  
    }  
  
    return 0;  
}  

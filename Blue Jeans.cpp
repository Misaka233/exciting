#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int Max = 62;

char text[10][Max], pat[Max];
int n, ma, lenp, Next[Max];

void get_next()
{
    int i = 0, j = -1;
    Next[0] = -1;
    while(i < lenp)
    {
        if(j == -1 || pat[i] == pat[j])
        {
            i ++; j ++;
            Next[i] = j;
        }
        else j = Next[j];
    }
}

void KMP()
{
    int k, m, i, j;
    get_next();
    ma = 100;
    for(k = 1; k < n; k ++)
    {
        i = 0; j = 0; m = 0;
        while(i < 60 && j < lenp)
        {
            if(j == -1 || text[k][i] == pat[j])
            {
                i ++; j ++;
            }
            else j = Next[j];
            if(j > m) m = j;
        }
        if(m < ma) ma = m;
    }
}


int main()
{
    int t, i;
    char result[Max];
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i ++)
        scanf("%s", text[i]);
        int ans = 0;
        for(i = 0; i <= 57; i ++)
        {
            strcpy(pat, text[0] + i);    
            //cout<<pat<<endl;
            lenp = 60 - i;
            KMP();                       
            if(ans < ma)
            {
                ans = ma;
                strncpy(result, text[0] + i, ans);
                result[ans] = '\0';
            }
            else if(ans == ma)
            {         

                char tmp[Max];
                strncpy(tmp, text[0] + i, ans);    //  复习: strncpy()没有复制最后的'\0'。
                tmp[ans] = '\0';
                if(strcmp(tmp, result) < 0)
                strcpy(result, tmp);
            }
        }
        if(ans >= 3)
        printf("%s\n", result);
        else
        printf("no significant commonalities\n");
    }
    return 0;
}


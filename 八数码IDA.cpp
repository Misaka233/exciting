#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

void initial(int *maze,int &space)
{
    char grid;
    for(int i=0; i<9; i++)
    {
        cin>>grid;
        if(grid!='x')maze[i]=grid-'1'+1;
        else
        {
            space=i;
            maze[i]=9;
        }
    }
}

bool isResolve(int *maze,int space)
{
    int s=abs(double(2-space/3))+abs(double(2-space%3));
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(maze[i]>maze[j])s++;
        }
    }
    if(s&1)return false;
    else return true;
}
int h(int *maze)
{
    int h=0;
    for(int i=0; i<9; i++)
    {
        if(maze[i]!=9) h+=abs(double((maze[i]-1)/3-i/3))+abs(double( (maze[i]-1)%3-i%3));
    }
    return h;
}

int next[9][4]=
{
    {-1,3,1,-1},
    {0,4,2,-1},
    {1,5,-1,-1},
    {-1,6,4,0},
    {3,7,5,1},
    {4,8,-1,2},
    {-1,-1,7,3},
    {6,-1,8,4},
    {7,-1,-1,5}
};

bool isAns(int *maze)
{
    for(int i=0; i<8; i++)if(maze[i+1]-maze[i]!=1)return false;
    return true;
}
int pathLimit;
int path[362890],pathLen;

bool IDAStar(int *maze,int len,int space)
{
    if(len==pathLimit)
    {
        if(isAns(maze))
        {
            pathLen=len;
            return true;
        }
        return false;
    }
    for(int i=0; i<4; i++)
    {
        if(next[space][i]!=-1)
        {
            if(len>0&&abs(double(i-path[len-1]))==2)continue;//!!不考虑相反的方向
            swap(maze[space],maze[next[space][i]]);

            path[len]=i;
            if(h(maze)+len<=pathLimit&&IDAStar(maze,len+1,next[space][i]))
                return true;
            swap(maze[space],maze[next[space][i]]);

        }
    }
    return false;
}
char dir[4]= {'l','d','r','u'};
void output()
{
    for(int i=0; i<pathLen; i++)
    {
        switch(path[i])
        {
        case 0:
            cout<<'l';
            break;
        case 1:
            cout<<'d';
            break;
        case 2:
            cout<<'r';
            break;
        case 3:
            cout<<'u';
        }
    }
}
int main()
{
    int maze[9],space;
    initial(maze,space);

    pathLimit=h(maze);
    if(isResolve(maze,space))
    {
        while(!IDAStar(maze,0,space))pathLimit++;
        output();
    }
    else cout<<"unsolvable";
    cout<<endl;
    return 0;
}

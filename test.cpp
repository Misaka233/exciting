
#include <iostream>
#include <string>
#include <vector>
using namespace std;
char str[200];
int co;
void fun(int l,int r,char[],int count)
{
        if(l<0 || r<l) return ;
        if(l==0&&r==0){
            cout<<str<<endl;
            co++;
        }else{
            if(l>0){
                str[count]='(';
                fun(l-1, r, str, count+1);
            }
            if(r>l){
                str[count]=')';
                fun(l, r-1, str, count+1);
            }
        }
}
int main()
{
    co=0;
    int count;
    cin>>count;
    char str[count*2];
    fun(count,count,str,0);
    cout<<co;
}

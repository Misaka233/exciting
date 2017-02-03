#include <stdio.h>
#include <cstring>
#include <string>
const int MAX_T=30005,MAX_W=30000;
int next[MAX_W],plen,tlen;
char tstr[MAX_T];
struct Phrase
{
	int fir;
	char str[200];
}Tstr[26000];
void Build_next(char pstr[])
{
	int i=1,t=0;plen=strlen(pstr+1);
	next[1]=0;
	while(i<=plen)
	{
		//更新f(i+1);t表示f(i+1)
		while(t>0&&pstr[i]!=pstr[t])t=next[t];

		t++;
		i++;

		//更新next[i+1]
		if (pstr[i]==pstr[t])next[i]=next[t];
		else next[i]=t;
	}
}
int kmp_count(char pstr[])
{
	Build_next(pstr);
	int k=1,j=1,ans=0;tlen=strlen(tstr+1);
	while(j<=tlen)
	{
		if (pstr[k]==tstr[j])
		{
			k++;
			j++;
			if (k==plen+1)
			{
				ans++;
				k=next[k];
			}
		}
		else
		{
			k=next[k];
			if (k==0)
			{
				k++;
				j++;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("test.txt","r",stdin);
	while(1)
	{
		for (int i=1;1;i++)
		{
			if(scanf("%c",&tstr[i])!=EOF)
			{
				if (tstr[i-1]==' '&&tstr[i]==' ')
				{
					i--;
					continue;
				}
				if(tstr[i]=='#'&&tstr[i-1]=='#'&&tstr[i-2]=='#'&&tstr[i-3]=='#')
				{
					tstr[i-3]=0;
					break;
				}
			}
			else return 0;
		}

		int ans=0,lk=0;
		int pplen=strlen(tstr+1);int k=0,p=1;

		while(p<=pplen)
		{
			Tstr[k].fir=p;
			int i;
			for(i=p;tstr[i]!=' '&&tstr[i]!=','&&tstr[i]!='\n'&&tstr[i]!='.'&&tstr[i]!=0;i++);
			while(tstr[i]==' ')i++;
			if(tstr[i]=='\n'||tstr[i]==','||tstr[i]=='.'||tstr[i]==0)
			{
				Tstr[k++].str[1]=0;
				p=i+1;
				continue;
			}
			else
			{
				p=i;
				for(i;tstr[i]!=' '&&tstr[i]!=','&&tstr[i]!='\n'&&tstr[i]!='.';i++);

				for(int j=Tstr[k].fir;j<i;j++)
					Tstr[k].str[j-Tstr[k].fir+1]=tstr[j];
				Tstr[k].str[i-Tstr[k].fir+1]=0;
				k++;
			}
		}
		for (int i=0;i<k;i++)
		{
			if(Tstr[i].str[1]==0)continue;

			int sum=kmp_count(Tstr[i].str);
			if(sum>ans)
			{
				lk=i;
				ans=sum;
			}
			else if (sum==ans)
			{
				if(strcmp(Tstr[lk].str+1,Tstr[i].str+1)>0)
				{
					lk=i;
					ans=sum;
				}
			}
		}
		printf("%s:%d\n",Tstr[lk].str+1,ans);
	}
	return 0;
}

#include<cstdio>
#include<cstring>

const int MAX=200005;
int n,st,cnt,ans,p[MAX],dfn[MAX];

void Find(int i){
	dfn[i]=++cnt;
	while(!dfn[p[i]]){
		dfn[i]=cnt;
		i=p[i];
	}
	if(dfn[p[i]]==cnt){
		if(st==0) st=i;
		p[i]=st;
	}
	else ans--;
}

int main(){
	scanf("%d",&n);
	st=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(i==p[i]) st=i;
	}
	memset(dfn,0,sizeof(dfn));
	cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			ans++;
			Find(i);
		}
	}
	printf("%d\n",ans-1);
	for(int i=1;i<=n;i++){
		if(i!=1) printf(" ");
		printf("%d",p[i]);
	}
	printf("\n");
	return 0;
}

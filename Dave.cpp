#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int x,y;
}cd[1010];

int y[1010];
bool cmp1(node a,node b){
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;

}
int main(){

	int n,r,i,j,k,l;
	int ans,count,limx,limy;
	while(cin>>n>>r){

		ans=0;
		for(i=0;i<n;i++)
			cin>>cd[i].x>>cd[i].y;

		sort(cd,cd+n,cmp1);

		for(i=0;i<n;i++){
			limx=cd[i].x+r;
			count=0; k=0;

			for(j=i;j<n;j++){
				if(cd[j].x>=cd[i].x&&cd[j].x<=limx)
					y[k++]=cd[j].y;
				else break;
			}
			sort(y,y+k);

			for(j=0;j<k;j++){
				limy=y[j]+r;

				count=0;

				for(l=j;l<k;l++){
					if(y[l]>=y[j]&&y[l]<=limy)
						count++;
				}
				if(count>ans) ans=count;
			}

		}
		cout<<ans<<endl;
	}
	return 0;
}

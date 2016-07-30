#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int > pi;

const int maxn = 1000 + 5;
const int dr[4][2] = {1,0, -1,0, 0,1, 0,-1};
const int di[8][2] = {1,2, 2,1, -1,2, -2,1, 1,-2, 2,-1, -1,-2, -2,-1};

char str[maxn], num[maxn];
int main()
{
	memset(str,0,sizeof(str));
	scanf(" %s", str);
	int len = strlen(str), pos_d = -1, pos_e = -1, be = -1, en = -1, ans = 0, pos = 501;

	for(int i = 0; i < len; ++i){
		if(str[i] == '.') pos_d = i;
		if(str[i] == 'e') pos_e = i;
	}
	for(int i = 0; i < maxn; ++i) num[i] = '0';
	for(int i = 500, j = pos_d - 1; j >= 0; --j, --i){
		num[i] = str[j];
	}
	for(int i = 501, j = pos_d + 1; j < pos_e; ++j, ++i){
		num[i] = str[j];
	}
	for(int i = pos_e + 1; i < len; ++i){
		ans *= 10;
		ans += str[i] - '0';
	}
	pos += ans;
	for(int i = maxn - 1; i >= pos; --i){
		if(num[i] != '0'){
			en = i;
			break;
		}
	}
	for(int i = 0; i < pos; ++i){
		if(num[i] != '0'){
			be = i;
			break;
		}
	}
	if(en == -1) en = pos - 1;
	if(be == -1) be = pos - 1;
	for(int i = be; i <= en; ++i){
		if(i == pos) printf(".");
		printf("%c", num[i]);
	}
	puts("");
	return 0;
}

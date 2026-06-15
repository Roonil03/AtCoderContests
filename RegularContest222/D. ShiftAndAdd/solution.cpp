#include<bits/stdc++.h>
#define ll long long
#define pr pair<int,int>
#define mk make_pair
using namespace std;
template<typename T>void in(T &x){
	int f=1;char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){c=getchar();f=-1;}
	for(x=0;isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
void cmn(ll &x,ll y){y<x&&(x=y);}
const int N=20015;
const ll inf=1e18;
int n,a[N],b[N];
ll P[15];
ll dp[512][2],f[512][2];
int main(){
	in(n);
	P[0]=1;for(int i=1;i<=10;++i) P[i]=P[i-1]*10;
	for(int i=10;i<=n+9;++i) in(a[i]);
	for(int i=10;i<=n+9;++i) in(b[i]);
	for(int s=0;s<512;++s) for(int o=0;o<2;++o) dp[s][o]=o;
	memset(f,0x3f,sizeof(f));
	for(int i=10;i<=n+9;++i){
		for(int s=0;s<512;++s){
			ll x=0;
			for(int j=i-9;j<=i-1;++j) x=x*10+(s&(1<<(i-1-j))?b[j]:a[j]);
			x%=P[9];
			for(int o=0;o<2;++o) for(int p=0;p<2;++p){
				ll nx=x*10+(o?b[i]:a[i])+(p?P[9]:0);
				cmn(f[((s<<1)&511)|o][p],dp[s][nx>=P[10]]+(nx/P[9])%10);
			}
		}
		for(int j=0;j<512;++j) for(int o=0;o<2;++o) dp[j][o]=f[j][o],f[j][o]=inf;
		ll ans=inf;
		for(int s=0;s<512;++s){
			ll x=0,res=dp[s][0];
			for(int j=i-8;j<=i;++j) x=x*10+(s&(1<<(i-j))?b[j]:a[j]);
			for(int j=0;j<9;++j) res+=x%10,x/=10;
			cmn(ans,res);
		}
		printf("%lld ",ans);
	}
	printf("\n");
	return 0;
}

// Code by https://atcoder.jp/users/studyyyzz
/*
This algorithm processes two sequences, a and b, to maintain a rolling window of choices over the last 
9 elements using a dynamic programming state representation. It tracks these choices with a 9-bit mask 
s (representing whether element a_j or b_j was chosen for the last 9 positions) and an overflow flag 
o (which indicates whether a carry or threshold was exceeded in the previous step). As the algorithm 
iterates through each position i, it reconstructs the numerical value formed by the selected sequence 
choices, tests both options (a_i or b_i) for the current position alongside a potential carry-over flag 
p, and computes the transition cost based on the digits of the resulting number. The DP table dp[s][o] 
is updated at each step to minimize the cumulative digit-based cost, and the algorithm prints the minimum 
total cost achievable within the active sliding window for every prefix of the sequence.
*/
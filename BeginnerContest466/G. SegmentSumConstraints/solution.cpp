#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")
// #pragma GCC target("avx2, bmi, bmi2, popcnt")

#define sz(x) ((int)x.size())
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<long long>

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
    for (T& x : v) is >> x;
    return is;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    for (int i = 0; i < v.size(); i++){
        os << v[i];
        if (i + 1 < v.size()) os << " ";
    }
    return os;
}

void precomp(){}

void solve(){
    ll n,m,INF=1LL<<60;
    cin>>n>>m;
    vector<vll>D(n+1, vll(n+1,INF));
    auto ch=[&](ll u,ll v,ll s)->bool{
        if(D[u][v]!=INF&&D[u][v]!=s){
            return false;
        }
        D[u][v]=s;
        return true;
    };
    for(ll i=0;i<m;i++){
        ll l,r,s;
        cin>>l>>r>>s;
        l--;
        s-=r-l;
        ch(l,r,s);
        ch(r,l,-s);
    }
    for(ll j=0;j<=n;j++){
        for(ll i=0;i<=n;i++){
            for(ll k=0;k<=n;k++){
                if(D[i][j]<INF&&D[j][k]<INF){
                    if(!ch(i,k,D[i][j]+D[j][k])){
                        cout<<"0\n";
                        return;
                    }
                }
            }
        }
    }
    vector<tuple<ll,ll,ll>>constr;
    for(ll l=0;l<n;l++){
        ll r=l+1;
        while(r<=n&&D[l][r]==INF){
            r++;
        }
        if(r<=n){
            constr.push_back({l,r,D[l][r]});
        }
    }
    for(auto[l,r,w]:constr){
        if(w<0){
            cout<<"0\n";
            return;
        }
    }
    vector<ll>ha(n);
    for(auto[l,r,w]:constr){
        for(ll i=l;i<r;i++){
            ha[i]=1;
        }
    }
    auto f=[&](ll N,vector<tuple<ll,ll,ll>>c,bool q)->ll{
        ll M=c.size();
        vector<ll>wt={1};
        for(auto[l,r,w]:c){
            wt.push_back(wt.back()*(r-l+1)*2);
        }
        vector<ll>H(N);
        for(ll i=0;i<N;i++){
            for(ll j=0;j<M;j++){
                auto[l,r,w]=c[j];
                if(l<=i&&i<r){
                    H[i]+=wt[j];
                }
            }
        }
        vector<ll>tw={0};
        for(auto[l,r,w]:c){
            ll z=tw.size();
            for(ll t=1;t<(r-l+1);t++){
                for(ll i=0;i<z;i++){
                    tw.push_back(tw[i]>=0?z*2*t+tw[i]:-1);
                }
            }
            for(ll t=0;t<(r-l+1);t++){
                for(ll i=0;i<z;i++){
                    tw.push_back(-1);
                }
            }
        }
        vector<ll>dp(wt.back());
        dp[0]=1;
        for(ll t=0;t<30;t++){
            ll off=0;
            for(ll j=0;j<c.size();j++){
                if((get<2>(c[j]))&(1LL<<t)){
                    off+=wt[j];
                }
            }
            for(ll h:H){
                for(ll k=wt.back()-1;k>=h;k--){
                    dp[k]=(dp[k]+dp[k-h])%998244353;
                }
            }
            vector<ll>nx(wt.back());
            for(ll i=0;i<wt.back();i++){
                if(tw[i]>=0){
                    nx[i]=dp[tw[i]+off];
                }
            }
            swap(dp,nx);
            if(!q){
                for(auto&x:dp){
                    if(x){
                        x=1;
                    }
                }
            }
        }
        return dp[0];
    };
    for(ll i=0;i<n;i++){
        if(ha[i]==0){
            if(f(n,constr,false)){
                cout<<"Infinity\n";
            } else{
                cout<<"0\n";
            }
            return;
        }
    }
    cout<<f(n,constr,true)<<"\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t {1};
    precomp();
    while(t--){
        solve();
    }
    return 0;
}

// Solution referenced from https://atcoder.jp/users/Nachia

/*
The algorithm utilizes the Floyd-Warshall algorithm to deduce implicit constraints among prefix sums, interpreting given 
segment sums as weighted directed edges. It identifies continuous restricted maximal segments and halts if any inconsistencies 
(like negative cycles or conflicting constraints) are detected. To calculate the number of valid arrays modulo 998244353, 
it applies a bit-by-bit dynamic programming (DP) technique across 30 binary bits to trace permutations and carrying of 
subsets of sequence elements over valid state sizes. If there's an unconstrained element and a valid sequence exists, 
there are infinitely many combinations, so the algorithm leverages a boolean fallback within the same DP function to 
verify viability and output "Infinity". The time complexity is $O(N^3 + 30 . N . W)$, where $W$ is the product 
of modified subset interval sizes (maximum state space). The space complexity is $O(N^2 + W)$ for storing prefix graph 
representations and generating the necessary DP arrays.
*/
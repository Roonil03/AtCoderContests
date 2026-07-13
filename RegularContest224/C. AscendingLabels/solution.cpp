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

void precomp(){

}

void dfs(int u, int d, vector<vi>& adj, vi& res){
    res[u] = d;
    for(int v : adj[u]){
        if(res[v] == -1){
            dfs(v, d + 1, adj, res);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    // vector<int>arr(n);
    // cin >> arr;
    vector<vi> adj(n);
    for(int i {0}; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi res(n, -1);
    dfs(0, 0, adj, res);
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    precomp();
    while(t--){
        solve();
    }
    return 0;
}
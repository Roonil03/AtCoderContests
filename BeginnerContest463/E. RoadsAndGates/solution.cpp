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

void solve(){
    int n, m;
    ll y;
    cin >> n >> m >> y;
    vector<vector<pair<int, ll>>> adj(n+1);
    for(int i {0}; i < m; i++){
        int u, v;
        ll t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v].push_back({u, t});
    }
    vector<int>x(n);
    cin >> x;
    for(int i {1}; i <= n; i++){
        adj[i].push_back({0, x[i-1] + y});
        adj[0].push_back({i, x[i-1]});
    }
    vector<ll>dist(n+1, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        auto[d, u] = pq.top();
        pq.pop();
        if(d > dist[u]){
            continue;
        }
        for(auto&[v, w] : adj[u]){
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    // dist.erase(dist.begin());
    // dist.erase(dist.begin());
    // cout << dist << endl;
    for(int i {2}; i <= n; i++){
        cout << dist[i] << (i == n ? "" : " ");
    }
    cout << endl;
    // cout << arr;
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
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
    for (int i = 0; i < (int)v.size(); i++){
        os << v[i];
        if (i + 1 < (int)v.size()) os << " ";
    }
    return os;
}

int mod = 998244353;
const int D = 1000005;
ll fact[D], ifact[D];

ll h1(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void precomp() {
    fact[0] = 1;
    ifact[0] = 1;
    for (int i = 1; i < D; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    ifact[D - 1] = h1(fact[D - 1], mod - 2);
    for (int i = D - 2; i >= 1; i--){
        ifact[i] = (ifact[i + 1] * (i + 1)) % mod;
    }
}

ll nCr(ll n, ll k) {
    if (k < 0 || n < k){
        return 0;
    }
    if (k == 0){
        return 1;
    }
    ll num {1};
    ll nn = n % mod;
    for (ll i {0}; i < k; i++) {
        ll t = (nn - i) % mod;
        if (t < 0){
            t += mod;
        }
        num = (num * t) % mod;
    }
    return (num * ifact[k]) % mod;
}

void solve(){
    int n;
    cin >> n;    
    vector<vi> adj(n);
    for(int i {1}; i < n; i++){
        int p;
        cin >> p;
        adj[p - 1].push_back(i);
    }    
    vll c(n), d(n);
    cin >> c >> d;
    vi o;
    o.push_back(0);
    int head {0};
    while(head < sz(o)) {
        int u = o[head++];
        for(int v : adj[u]){
            o.push_back(v);
        }
    }
    reverse(o.begin(), o.end());
    vll w(n, 0), ss(n, 0);
    ll res = 1;
    for(int u : o) {
        ll ww = c[u];
        ll q {0};
        for(int v : adj[u]) {
            ww += w[v];
            q += ss[v];
        }
        w[u] = ww;
        ss[u] = q + d[u];        
        ll aa = ww - q;
        if(aa < d[u]) {
            cout << 0 << endl;
            return;
        }
        res = (res * nCr(aa, d[u])) % mod;
    }    
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    precomp();
    int t {1};
    while(t--){
        solve();
    }
    return 0;
}
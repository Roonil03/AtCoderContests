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

ll mod = 998244353;
const ll maxn = 50;
ll fact[maxn], inv[maxn];

ll pow1(ll base, ll exp){
    ll res = 1;
    base %= mod;
    while (exp > 0){
        if (exp % 2 == 1){
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n){
    return pow1(n, mod - 2);
}

void precomp(){
    fact[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= 45; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv[45] = modInverse(fact[45]);
    for (int i = 44; i >= 1; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

void solve(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll>arr(n);
    cin >> arr;
    ll w {0};
    for(ll v : arr){
        w = (w + v) % mod; 
    }
    int n1 = n / 2;
    int n2 = n - n1;
    vector<vll> lm(n1 + 1);
    for(int i {0}; i < (1 << n1); i++){ 
        ll sum {0};
        int bits {0};
        for(int j {0}; j < n1; j++){
            if((i >> j) & 1){
                sum += arr[j];
                bits++;
            }
        }
        lm[bits].push_back(sum);
    }
    vector<vll> rr(n2 + 1);
    for(int i {0} ; i < (1 << n2); i++){
        ll sum {0};
        int bits {0};
        for(int j {0}; j < n2; j++){
            if((i >> j) & 1){
                sum += arr[n1 + j];
                bits++;
            }
        }
        rr[bits].push_back(sum);
    }
    for(int i {0}; i <= n1; i++){
        sort(lm[i].begin(), lm[i].end());
    }
    vector<vll> r1(n2 + 1);
    for(int i {0}; i <= n2; i++){
        sort(rr[i].begin(), rr[i].end());
        r1[i].assign(rr[i].size(), 0);
        if(!rr[i].empty()){
            r1[i][0] = rr[i][0] % mod;
            for(int j {1}; j < rr[i].size(); j++){
                r1[i][j] = (r1[i][j - 1] + rr[i][j] % mod) % mod; 
            }
        }
    }
    vll c(n + 1, 0), t(n + 1, 0);
    for(int i {0}; i <= n1; i++){
        for(int j {0}; j <= n2; j++){
            int k = i + j;
            int p = sz(rr[j]) - 1;
            for(ll u : lm[i]){
                while(p >= 0 && u + rr[j][p] >= x){
                    p--;
                }
                if(p < 0){
                    break;
                }
                ll count = p + 1;
                c[k] = (c[k] + count) % mod;
                ll um = u % mod;
                ll sr = r1[j][p];
                t[k] = (t[k] + (count % mod) * um % mod + sr) % mod;
            }
        }
    }
    ll res {0};
    for(int i {0}; i < n; i++){
        ll t1 = (w * c[i] % mod - t[i] + mod) % mod;
        ll prob = fact[i] * fact[n - 1 - i] % mod * inv[n] % mod;
        res = (res + t1 * prob) % mod;
    }
    cout << res << endl;
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
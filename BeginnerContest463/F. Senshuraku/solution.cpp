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
const ll max1 = 1000005;
ll fact[max1], inv[max1], invn[max1];

ll pow1(ll base, ll exp){
    ll res {1};
    base %= mod;
    while(exp > 0){
        if(exp % 2 == 1){
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

void precomp(){
    fact[0] = 1;
    inv[0] = 1;
    invn[1] = 1;
    for(int i {1}; i < max1; i++){
        fact[i] = (fact[i - 1] * i) % mod;
        if(i > 1){
            invn[i] = invn[mod % i] * (mod - mod / i) % mod;
        }
    }
    inv[max1 - 1] = pow1(fact[max1 - 1], mod - 2);
    for(int i = max1 - 2; i >=  1; i--){
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

ll nCr(int n, int r){
    if(r < 0 || r > n){
        return 0;
    }
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

ll calc(int p, int q){
    ll res {0};
    for(int i {0}; i <= q; i++){
        ll t = nCr(q, i) * invn[p + i + 1] % mod;
        res = (res + t) % mod;
    }
    return res;
}
void solve(){
    int n;
    cin >> n;
    vector<int>arr(2 * n);
    cin >> arr;
    int m = 0;
    for(int v : arr){
        m = max(m, v);
    }
    int a {0}, b {0}, c {0}, d {0}, e {0};
    for(int i {0}; i < n; i++){
        int u = 2 * i, v = 2 * i + 1;
        int su = arr[u], sv = arr[v];
        if (su < sv){
            swap(su, sv);
        }
        if(su == m && sv == m){
            a++;
        } else if(su == m && sv == m - 1){
            b++;
        } else if(su == m && sv < m - 1){
            c++;
        } else if(su == m - 1 && sv == m - 1){
            d++;
        } else if(su == m - 1 && sv < m - 1){
            e++;
        }
    }
    int p = a;
    int q = b + c;
    int py = 2 * b + c + d;
    int qy = e;
    ll inv2 = pow1(2, mod - 2);
    ll kx = pow1(inv2, q);
    ll ky = pow1(inv2, b + c + e);
    ll ix {0}, jx {0}, iy {0}, iy2{0}, jy {0};
    if(p >= 1){
        ix = kx * inv2 % mod * calc(p - 1, q) % mod;
    }
    if(q >= 1){
        jx = kx * calc(p, q - 1) % mod;
    }
    if(a == 0){
        if(py >= 1){
            iy = ky * calc(py - 1, qy) % mod;
            iy2 = iy * inv2 % mod;
        }
        if(qy >= 1){
            jy = ky * calc(py, qy - 1) % mod;
        }
    }
    vector<ll> res(2 * n, 0);
    for (int i {0}; i < n; i++){
        int u = 2 * i, v = 2 * i + 1;
        int su = arr[u], sv = arr[v];
        if (su < sv){
            swap(su, sv);
            swap(u, v);
        }        
        if (su == m && sv == m){
            res[u] = (res[u] + ix) % mod;
            res[v] = (res[v] + ix) % mod;
        } else if (su == m && sv == m - 1){
            res[u] = (res[u] + jx) % mod;
            if (p == 0){
                res[u] = (res[u] + iy) % mod;
                res[v] = (res[v] + iy) % mod;
            }
        } else if (su == m){
            res[u] = (res[u] + jx) % mod;
            if (p == 0){
                res[u] = (res[u] + iy) % mod;
            }
        } else if (su == m - 1 && sv == m - 1){
            if (p == 0){
                res[u] = (res[u] + iy2) % mod;
                res[v] = (res[v] + iy2) % mod;
            }
        } else if (su == m - 1){
            if (p == 0){
                res[u] = (res[u] + jy) % mod;
            }
        }
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
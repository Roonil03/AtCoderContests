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
const int maxn = 200005;
ll fact[maxn], inv[maxn];

void precomp(){
    fact[0] = 1;
    for(int i {1}; i < maxn; i++){
        fact[i] = (fact[i-1] * i) % mod;
    }
    inv[maxn - 1] = 1;
    ll base = fact[maxn - 1], exp = mod - 2;
    while(exp > 0){
        if(exp % 2 == 1){
            inv[maxn - 1] = (inv[maxn - 1] * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    for(int i = maxn - 2;i >= 0; i--){
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int>arr(n);
    cin >> arr;
    ll res {1};
    for(int i {0}; i < n;){
        int j = i, p = arr[i] % k;
        p = min(p, (k - p) % k);
        while(j < n){
            int np = arr[j] % k;
            np = min(np, (k - np) % k);
            if(np != p){
                break;
            }
            j++;
        }
        int len = j - i;
        if(p == 0 || (k % 2 == 0 && p == k / 2)){
            sort(arr.begin() + i, arr.begin() + j);
            ll w = fact[len];
            int count {1};
            for(int l = i + 1; l <= j; l++){
                if(l == j || arr[l] != arr[l - 1]){
                    w = (w * inv[count]) % mod;
                    count = 1;
                } else{
                    count++;
                }
            }
            res = (res * w) % mod;
        } else{
            int count {0};
            for(int l = i; l < j; l++){
                if(arr[l] % k == p){
                    count++;
                }
            }
            ll w = fact[len] * inv[count] % mod * inv[len - count] % mod;
            res = (res * w) % mod;
        }
        i = j;
    }
    cout << res << endl;
    // cout << arr;
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
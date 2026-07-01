#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize ("O3")

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

const int MOD = 998244353;
const int MAX = 20000010;
int fac[MAX], finv[MAX], inv_arr[MAX];

void precomp(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv_arr[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = 1ll * fac[i-1] * i % MOD;
        inv_arr[i] = MOD - 1ll * inv_arr[MOD % i] * (MOD / i) % MOD;
        finv[i] = 1ll * finv[i-1] * inv_arr[i] % MOD;
    }
}

ll binom(int n, int k){
    if(n < k || n < 0 || k < 0) return 0;
    return 1ll * fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}

ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

void solve(){
    ll a, b, k;
    cin >> a >> b >> k;
    swap(a, b);
    
    ll s = 0, ans = 0;
    for (ll i = k; i <= a; i++) {
        if (i - k <= b) {
            ll v = (binom(2 * i - k - 1, i - 1) - binom(2 * i - k - 1, i - k - 1) + MOD) % MOD;
            v = v * binom(a - i + b - i + k, a - i) % MOD;
            ans = (ans + v * i) % MOD;
            s = (s + v) % MOD;
        }
    }
    
    ans = (ans + a * ((binom(a + b, a) - s + MOD) % MOD)) % MOD;
    ans = ans * modInverse(binom(a + b, a)) % MOD;
    cout << ans << "\n";
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

//Solution referenced from https://atcoder.jp/users/PCTprobability

/*
The algorithm computes an expected value by iterating over all possible halting scenarios of a random walk (or game state 
transition). It utilizes combinations and Catalan-like path counting techniques. For a given state transitioning up to `A` 
and `B` under a threshold `K`, the code counts the exact number of valid paths reaching a halting state (`v`) using 
combinations (`binom`), avoiding invalid prefixes via reflection principle equivalent logic. It accumulates the exact path 
contributions into `ans` and total halting probabilities into `s`. The residual non-halting paths default to taking `a` 
steps, which are added at the end. Finally, it divides the accumulated expectations by the total possible combinations 
`C(A+B, A)` using modular inverse to evaluate the required expectation modulo 998244353.

Time Complexity: O(MAX + T * A) where MAX = 2 * 10^7 is the precomputation bound for factorials and inverses, and evaluating 
each query loops roughly A times (where A is bounded by the constraints).

Space Complexity: O(MAX) because of the three arrays of integers (`fac`, `finv`, and `inv_arr`) sizing up to 2 * 10^7 elements 
each, taking approximately ~240 MB of memory.
*/
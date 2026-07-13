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

void precomp(){}

void solve(){
    ll N, K;
    cin >> N >> K;
    vll A(N);
    cin >> A;
    ll MOD = 998244353;
    auto p = [&](ll b, ll e){
        ll r = 1; b %= MOD;
        while(e){
            if(e&1) r = r * b % MOD;
            b = b * b % MOD;
            e >>= 1;
        }
        return r;
    };
    vll f(N + 15, 1), iF(N + 15, 1);
    for(ll i = 1; i <= N + 10; i++){
        f[i] = f[i-1] * i % MOD;
    }
    iF[N+10] = p(f[N+10], MOD-2);
    for(ll i = N + 9; i >= 1; i--){
        iF[i] = iF[i+1] * (i + 1) % MOD;
    }
    auto c = [&](ll nn, ll rr){
        if(nn < 0 || rr < 0 || nn < rr){
            return 0LL;
        }
        return f[nn] * iF[rr] % MOD * iF[nn-rr] % MOD;
    };
    ll tg = 0;
    for(int i = 0; i < N; i++){
        if(N - i <= K){
            tg |= A[i];
        } else{
            tg &= A[i];
        }
    }
    ll tgf = tg, req = 0, ans = 0;
    ll sum = 1, cn = 0, ck = 1, i2 = p(2, MOD - 2);
    auto g = [&](ll nn, ll kk){
        if(kk <= 0){
            return 0LL;
        }
        while(cn < nn){
            cn++;
            sum = (sum * 2 % MOD - c(cn-1, ck-1) + MOD) % MOD;
        }
        while(cn > nn){
            sum = (sum + c(cn-1, ck-1)) * i2 % MOD;
            cn--;
        }
        while(ck < kk){
            sum = (sum + c(cn, ck)) % MOD;
            ck++;
        }
        while(ck > kk){
            ck--;
            sum = (sum - c(cn, ck) + MOD) % MOD;
        }
        return sum;
    };
    for(ll i = N - 1; i >= 0; i--){
        if((tgf & A[i]) == tgf){
            ans = (ans + g(i, K - req)) % MOD;
        } else{
            req++;
            tgf -= tgf & A[i];
        }
    }
    if(tg == 0){
        ans = (ans + 1) % MOD;
    }
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

// Solution referenced from https://atcoder.jp/users/Nachia

/*
The algorithm computes the valid subset distributions by primarily leveraging bitwise logic and dynamic combinatorics to process 
sequences backwards. It first establishes the immutable target bitwise sequence result, $tg$, by utilizing the observation that 
the final $K$ alterations default to an OR-operation sequence, while prior indices are fixed through an AND-operation baseline. 
Stepping backwards from the end of the array, the solution checks the feasibility of the active bit-mask requirement relative to 
the sequence values, adding all valid combinations to the total arrangements whenever a target is met without expending all 
operations. The combinatorial logic mimics Mo's algorithm by sliding the state pointers $(n, k)$ for binomial summation $O(1)$ 
incremental updates to eliminate continuous re-computations of combinations. The time complexity per testcase is $O(N)$ because 
the state variables $(n, k)$ cumulatively shift across limits proportional to sequence sizes alongside factorials precomputation, 
bounding the runtime optimally. The space complexity is $O(N)$ for retaining the sequence array alongside standard factorial and 
inverse arrays required to facilitate constant-time modular arithmetic calculations.
*/

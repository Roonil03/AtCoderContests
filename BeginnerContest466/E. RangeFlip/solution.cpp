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
    int n, k;
    cin >> n >> k;
    // vector<int>arr(n);
    // cin >> arr;
    vll dp1(k + 1, LLONG_MIN), dp2(k + 1, -1e18);
    dp1[0] = 0;
    for(int i {0}; i < n; i++){
        ll a, b;
        cin >> a >> b;
        vll ndp1(k + 1, LLONG_MIN), ndp2(k + 1, LLONG_MIN);
        for(int j {0}; j <= k; j++){
            ndp1[j] = max(dp1[j], dp2[j]) + a;
            ndp2[j] = dp2[j] + b;
            if(j > 0){
                ndp2[j] = max(ndp2[j], dp1[j - 1] + b);
            }
        }
        dp1 = move(ndp1);
        dp2 = move(ndp2);
    }
    ll res {0};
    for(int i {0}; i <= k; i++){
        res = max({res, dp1[i], dp2[i]});
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
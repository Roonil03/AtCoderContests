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
    vector<pll>lr;
    ll l, r;
    for(int i {0}; i < n; i++){
        cin >> l >> r;
        lr.push_back({l, r});
    }
    sort(lr.begin(), lr.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });
    ll res {0};
    for(ll i = 1LL << 30; i > 0; i>>=1){
        ll m = res + i, c {0}, t = -2e18;
        for(auto& it : lr){
            if(it.first >= t + m){
                c++;
                t = it.second;
            }
        }
        if(c >= k){
            res += i;
        }
    }
    cout << (res ? res : -1) << endl;
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
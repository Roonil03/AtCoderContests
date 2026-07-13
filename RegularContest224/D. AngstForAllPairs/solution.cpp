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
    if(n < 20 && k > (1 << n)){
        cout << -1 << endl;
        return;
    }
    vll t;
    ll c {1};
    for(int i {0}; i <= n; i++){
        ll a = min((ll)k - sz(t), c);
        for(ll j {0}; j < a; j++){
            t.push_back(i);
        }
        if(sz(t) == k){
            break;
        }
        if(i < n){
            c = c * (n - i) / (i + 1);
            if(c > k){
                c = k + 1;
            }
        }
    }
    ll res {0}, len {1}, d {10};
    for(int i {1}; i <= k; i++){
        if(i == d){
            len++;
            d *= 10;
        }
        res += len * t[k - i];
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
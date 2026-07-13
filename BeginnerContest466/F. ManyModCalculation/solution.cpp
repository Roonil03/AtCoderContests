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

ll h1(ll v, int sid, vll& b, vll& s){
    ll res {0};
    ll cur = v;
    int cid = sid;
    int k = sz(b);
    while(cid < k){
        auto it = lower_bound(b.begin() + cid, b.end(), cur, greater<ll>());
        if(it == b.end()){
            break;
        }
        int m = it - b.begin();
        res += (cur / b[m]) * s[m];
        cur  %= b[m];
        cid = m + 1;
    }
    return res + 1;
}

void precomp(){

}

void solve(){
    int n;
    ll x;
    cin >> n >> x;
    vector<ll>arr(n);
    cin >> arr;
    vll b;
    b.push_back(arr[0]);
    for(int i {1}; i < n; i++){
        if(arr[i] < b.back()){
            b.push_back(arr[i]);
        }
    }
    int k = sz(b);
    vll s(k);
    for(int i = k - 1; i >= 0; i--){
        s[i] = h1(b[i] - 1, i + 1, b, s);
    }
    cout << h1(x, 0, b, s) - 1 << endl;
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
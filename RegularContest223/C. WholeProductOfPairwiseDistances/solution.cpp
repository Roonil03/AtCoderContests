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
    int n;
    cin >> n;
    vector<int>arr(n);
    cin >> arr;
    bool fg = true;
    for(int i {2}; i * i <= n; i++){
        if(n % i == 0){
            fg = false;
            break;
        }
    }
    if (!fg){
        cout << 0 << endl;
        return;
    }
    sort(arr.begin(), arr.end());
    vi r(n);
    vector<bool> vis(n, false);
    for(int i {0}; i < n; i++){
        r[i] = arr[i] % n;
        if(vis[r[i]]){
            cout << 0 << endl;
            return;
        }
        vis[r[i]] = true;
    }
    fill(vis.begin(), vis.end(), false);
    int c {0};
    for(int i {0}; i < n; i++){
        if(!vis[i]){
            c++;
            int cur = i;
            while(!vis[cur]){
                vis[cur] = true;
                cur = r[cur];
            }
        }
    }
    ll res {1};
    for(int i {1}; i < n; i++){
        ll b = i, e = n - i, temp {1};
        while(e){
            if(e & 1){
                temp = temp * b % n;
            }
            b = b * b % n;
            e >>= 1;
        }
        res = res * temp % n;
    }
    if((n - c) % 2){
        res = (n - res) % n;
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
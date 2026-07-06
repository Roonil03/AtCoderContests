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
    // vector<int>arr(n);
    // cin >> arr;
    string s;
    cin >> s;
    deque<int>dq;
    // vi res(n);
    bool fg = false;
    // for(int i {0}; i < n; i++){
    //     dq.push_back(i + 1);
    // }
    for(int i {0}; i < n; i++){
        // if(!fg){
        //     if(s[i] == 'o'){
        //         res[i] = dq.front();
        //         dq.pop_front();
        //         fg = !fg;
        //     } else{
        //         res[i] = dq.back();
        //         dq.pop_back();
        //     }
        // } else{
        //     if(s[i] == 'o'){
        //         res[i] = dq.back();
        //         dq.pop_back();
        //         fg = !fg;
        //     } else{
        //         res[i] = dq.front();
        //         dq.pop_front();
        //     }
        // }
        int k = i + 1;
        if(!fg){
            dq.push_back(k);
            if(s[i] == 'o'){
                fg = !fg;
            }
        } else{
            dq.push_front(k);
            if(s[i] == 'o'){
                fg = !fg;
            }
        }
    }
    vi res(dq.begin(), dq.end());
    if(fg){
        reverse(res.begin(), res.end());
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
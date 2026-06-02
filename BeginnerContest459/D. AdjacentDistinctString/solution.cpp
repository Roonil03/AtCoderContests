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
    for (int i = 0; i < (int)v.size(); i++){
        os << v[i];
        if (i + 1 < (int)v.size()) os << " ";
    }
    return os;
}

void solve(){
    string s;
    cin >> s;
    int n = sz(s);
    vi count(26, 0);
    for(char c : s){
        count[c - 'a']++;
    }
    int f1 {0};
    int c1 {0};
    for(int i {0}; i < 26; i++){
        if(count[i] > f1){
            f1 = count[i];
            c1 = i;
        }
    }
    if(f1 > (n + 1) / 2){
        cout << "No" << "\n";
        return;
    }
    string res(n, ' ');
    int id {0};
    while(count[c1] > 0){
        res[id] = c1 + 'a';
        id += 2;
        count[c1]--;
    }
    for(int i {0}; i < 26; i++){
        while(count[i] > 0){
            if(id >= n){
                id = 1;
            }
            res[id] = i + 'a';
            id += 2;
            count[i]--;
        }
    }
    cout << "Yes\n" << res << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
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

ll A[12][12][12][12][12][12];

void precomp(){

}

void solve(){
    int n;
    if (!(cin >> n)) return;
    memset(A, 0, sizeof(A));
    for (int i = 0; i < n; i++){
        string s;
        ll v;
        cin >> s >> v;
        int b[6];
        for (int j = 0; j < 6; j++){
            b[j] = s[j] - '0' + 1;
        }
        A[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]] += v;
    }
    for (int a = 0; a < 11; a++){
        for (int b = 0; b < 11; b++){
            for (int c = 0; c < 11; c++){
                for (int d = 0; d < 11; d++){
                    for (int e = 0; e < 11; e++){
                        for (int f = 0; f < 11; f++){
                            A[a + 1][b][c][d][e][f] += A[a][b][c][d][e][f];
                        }
                    }
                }
            }
        }
    }
    for (int a = 0; a < 11; a++){
        for (int b = 0; b < 11; b++){
            for (int c = 0; c < 11; c++){
                for (int d = 0; d < 11; d++){
                    for (int e = 0; e < 11; e++){
                        for (int f = 0; f < 11; f++){
                            A[a][b + 1][c][d][e][f] += A[a][b][c][d][e][f];
                        }
                    }
                }
            }
        }
    }
    for (int a = 0; a < 11; a++){
        for (int b = 0; b < 11; b++){
            for (int c = 0; c < 11; c++){
                for (int d = 0; d < 11; d++){
                    for (int e = 0; e < 11; e++){
                        for (int f = 0; f < 11; f++){
                            A[a][b][c + 1][d][e][f] += A[a][b][c][d][e][f];
                        }
                    }
                }
            }
        }
    }
    for (int a = 0; a < 11; a++){
        for (int b = 0; b < 11; b++){
            for (int c = 0; c < 11; c++){
                for (int d = 0; d < 11; d++){
                    for (int e = 0; e < 11; e++){
                        for (int f = 0; f < 11; f++){
                            A[a][b][c][d + 1][e][f] += A[a][b][c][d][e][f];
                        }
                    }
                }
            }
        }
    }
    for (int a = 0; a < 11; a++){
        for (int b = 0; b < 11; b++){
            for (int c = 0; c < 11; c++){
                for (int d = 0; d < 11; d++){
                    for (int e = 0; e < 11; e++){
                        for (int f = 0; f < 11; f++){
                            A[a][b][c][d][e + 1][f] += A[a][b][c][d][e][f];
                        }
                    }
                }
            }
        }
    }
    for (int a = 0; a < 11; a++){
        for (int b = 0; b < 11; b++){
            for (int c = 0; c < 11; c++){
                for (int d = 0; d < 11; d++){
                    for (int e = 0; e < 11; e++){
                        for (int f = 0; f < 11; f++){
                            A[a][b][c][d][e][f + 1] += A[a][b][c][d][e][f];
                        }
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--){
        string s, t;
        cin >> s >> t;
        int x[6], y[6];
        bool ng = false;
        for (int i = 0; i < 6; i++){
            x[i] = s[i] - '0';
            y[i] = t[i] - '0' + 1;
            if (x[i] >= y[i]){
                ng = true;
            }
        }
        if (ng){
            cout << 0 << "\n";
            continue;
        }
        ll res = 0;
        for (int mask = 0; mask < (1 << 6); mask++){
            int id[6];
            int p = 0;
            for (int i = 0; i < 6; i++){
                if ((mask >> i) & 1){
                    id[i] = y[i];
                    p++;
                } else{
                    id[i] = x[i];
                }
            }
            ll val = A[id[0]][id[1]][id[2]][id[3]][id[4]][id[5]];
            if ((6 - p) % 2 == 1){
                res -= val;
            } else{
                res += val;
            }
        }
        cout << res << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(nullptr);
    int t = 1;
    precomp();
    while(t--){
        solve();
    }
    return 0;
}
// Solution referenced from https://atcoder.jp/users/maspy

/*
The algorithm utilizes multi-dimensional prefix sums (also known as Sum Over Subsets or a 6D prefix sum array) combined with 
the Principle of Inclusion-Exclusion (PIE) to efficiently handle range sum queries over a 6-dimensional space of tiny dimensions 
($11 \times 11 \times 11 \times 11 \times 11 \times 11$). During the update phase, it maps each character of the 6-digit input 
string into coordinates, increments the designated cell with value $v$, and propagates the prefix sums along each of the 6 
dimensions sequentially. For each of the $Q$ range queries defined by bounding strings $S$ and $T$, the sum of elements within 
the hyper-rectangle $[S_i, T_i)$ is computed by executing a PIE iteration over all $2^6 = 64$ corners of the hyper-rectangle 
via bitmasking. The time complexity per testcase is $O(N + D \cdot K^D + Q \cdot 2^D)$ where $D = 6$ is the number of dimensions 
and $K = 11$ is the size of each dimension, rendering the execution extremely fast. The auxiliary space complexity is $O(K^D)$, 
which corresponds to the static multi-dimensional storage allocation of approximately $12^6 \times 8$ bytes $\approx 23.5$ MB.
*/
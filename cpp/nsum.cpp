#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define sz(container) ((int)container.size())
#define all(x) begin(x),end(x)

void fast() { ios::sync_with_stdio(0); cin.tie(0); }


int main() {
    fast();

    int n;
    cin >> n;

    ll res = 0;
    rep(i, n) {
        int val;
        cin >> val;
        res += val;
    }
    
    cout << res << '\n';

    return 0;
}

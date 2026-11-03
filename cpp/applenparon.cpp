#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll a, p;

    cin >> a >> p;

    if (7 * a > 13 * p) {
        cout << "Axel\n";
    } else if (7 * a < 13 * p) {
        cout << "Petra\n";
    } else {
        cout << "lika\n";
    }
}

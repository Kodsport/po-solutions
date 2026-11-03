#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;

#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define sz(x) ((ll)(x).size())
#define all(x) begin(x), end(x)

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;

    vector<string> lines(n);

    rep(i, 0, n) {
        cin >> lines[i];
    }

    // vanligtvis skriver man reverse(lines.begin, lines.end())
    // men tack vare makrot "all" på rad 9 kan vi förenkla det till:
    reverse(all(lines));

    rep(i, 0, n) {
        cout << lines[i] << '\n';
    }
}

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

    ll res = 0; // Notera att om n är stort så kan Pelle göra så många armhävningar så att det inte får plats i ett 32 bitars heltal.
    // Detta är för att svaret kan vara så stort som N^2. 32-bitars heltal hanterar tal upp till ~2*10^9, och (10^6)^2=10^12 > 2 * 10^9
    rep(i, 1, n+1) {
        res += i;
    }
    
    cout << res << '\n';
}

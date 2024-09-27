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

    ll res = 0; // Notera att om n är stort så kan Pelle göra så många armhävningar så att det inte får plats i ett 32 bitars heltal.
    repp(i, 1, n+1) {
        res += i;
    }
    
    cout << res << '\n';

    return 0;
}

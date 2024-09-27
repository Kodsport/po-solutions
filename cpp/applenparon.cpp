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

    int a, p;

    cin >> a >> p;

    if (7 * a > 13 * p) {
        cout << "Axel\n";
    } else if (7 * a < 13 * p) {
        cout << "Petra\n";
    } else {
        cout << "lika\n";
    }
    
    return 0;
}

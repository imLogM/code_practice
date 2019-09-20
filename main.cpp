#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>

using namespace std;


typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1e9 + 7;

matrix multiply(matrix & a, matrix & b, ll MOD)
{
    matrix c(a.size(), vector<ll>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int k = 0; k < a[0].size(); k++)
        {
            for (int j = 0; j < b[0].size(); j++)
            {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return c;
}

matrix pow(matrix & a, ll n, ll MOD)
{
    matrix res(a.size(), vector<ll>(a[0].size()));
    for (int i = 0; i < a.size(); i++) res[i][i] = 1;
    while (n > 0)
    {
        if (n & 1) res = multiply(res, a, MOD);
        a = multiply(a, a, MOD);
        n >>= 1;
    }
    return res;
}

int main()
{
    ll a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    matrix p(4, vector<ll>(4, 0));
    p[0][0] = p[0][2] = p[0][3] = 1;
    p[1][0] = p[2][1] = p[3][2] = 1;
    matrix q = pow(p, n - 4, MOD);
    matrix x(4, vector<ll>(1, 0));
    x[0][0] = d; x[1][0] = c; x[2][0] = b; x[3][0] = a;
    matrix y = multiply(q, x, MOD);
    cout << y[0][0] << endl;
    return 0;
}
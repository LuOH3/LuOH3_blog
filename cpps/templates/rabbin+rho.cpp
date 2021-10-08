ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll qmul(ll a, ll b, ll p)
{
    a %= p;
    b %= p;
    ll ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % p;
        }
        a = (a <<= 1) % p;
        b >>= 1;
    }
    return ans % p;
}
ll ksm(ll a, ll b, ll p)
{
    ll rtn = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
            rtn = qmul(rtn, a, p);
        a = qmul(a, a, p);
        b >>= 1;
    }
    return rtn;
}
#define C 2730
#define S 3
ll n, m;
vector<ll> ans;

bool check(ll a, ll p)
{
    ll m = p - 1, x, y;
    int i, j = 0;
    while (!(m & 1))
        m >>= 1, j++;
    x = ksm(a, m, p);
    for (i = 1; i <= j; x = y, i++)
    {
        y = qmul(x, x, p);
        if ((y == 1) && (x != 1) && (x != p - 1))
            return 1;
    }
    return y != 1;
}
bool miller_rabin(int times, ll n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (!(n & 1))
        return 0;
    while (times--)
        if (check(rand() % (n - 1) + 1, n))
            return 0;
    return 1;
}
ll pollard_rho(ll n, int c)
{
    ll i = 1, k = 2, x = rand() % n, y = x, d;
    while (1)
    {
        i++, x = (qmul(x, x, n) + c) % n, d = gcd((ll)fabs(double(y - x)), n);
        if (d > 1 && d < n)
            return d;
        if (y == x)
            return n;
        if (i == k)
            y = x, k <<= 1;
    }
}
void findfac(ll n, int c)
{
    if (n == 1)
        return;
    if (miller_rabin(S, n))
    {
        ans.push_back(n);
        return;
    }
    ll m = n;
    while (m == n)
        m = pollard_rho(n, c--);
    findfac(m, c), findfac(n / m, c);
}
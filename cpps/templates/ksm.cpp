ll myabs(ll x) { return x >= 0 ? x : -x; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll ksm(ll a, ll b, ll p)
{
    ll rtn = 1;
    a %= p;
    while (b)
    {
        if (b & 1)
            rtn = rtn * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return rtn;
}

//for long long
ll qmul(ll a, ll b, ll p)
{
    a %= p;
    b %= p;
    ll ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % p;
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
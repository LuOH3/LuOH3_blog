ll bit[maxn + 1];

ll sum(int i)
{
    ll s = 0;
    while (i > 0)
    {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int v)
{
    while (i <= N)
    {
        bit[i] += v;
        i += i & -i;
    }
}

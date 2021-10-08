#define ls rt << 1
#define rs rt << 1 | 1

void pushup(int rt, int l, int r)
{
    //叶节点更新根节点
}

void pushdown(int rt, int l, int r)
{
    //懒惰标记下传并清空
}

void build(int rt, int l, int r)
{
    //某些变量赋初值
    if (l + 1 == r)
    {
        //叶节点赋值
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid, r);
    pushup(rt, l, r);
}

void upd(int rt, int l, int r, int lll, int rrr)
{
    if (lll <= l && rrr >= r)
    {
        //
        return;
    }
    pushdown(rt, l, r);
    int mid = l + r >> 1;
    if (lll < mid)
        upd(ls, l, mid, lll, rrr);
    if (rrr > mid)
        upd(rs, mid, r, lll, rrr);
    pushup(rt, l, r);
}

ll query(int rt, int l, int r, int lll, int rrr)
{
    if (lll <= l && rrr >= r)
    {
        return 0; //
    }
    pushdown(rt, l, r);
    int mid = l + r >> 1;
    ll ans = 0;
    if (lll < mid)
        ans += query(ls, l, mid, lll, rrr);
    if (rrr > mid)
        ans += query(rs, mid, r, lll, rrr);
    return ans;
}
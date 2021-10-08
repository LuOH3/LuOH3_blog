//point
int num[maxn], low[maxn];
int ptr = 0, res;
bool vis[maxn], flag[maxn];
vector<int> edge[maxn];
void Tarjan(int u, int fa)
{
    vis[u] = true;
    low[u] = num[u] = ++ptr;
    int child = 0;
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if (!vis[v])
        {
            child++;
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (fa != u && low[v] >= num[u] && !flag[u])
            {
                flag[u] = true;
                res++;
            }
        }
        else if (v != fa)
            low[u] = min(low[u], num[v]);
    }
    if (fa == u && child >= 2 && !flag[u])
    {
        flag[u] = true;
        res++;
    }
}

//edge
int num[maxn], dfn[maxn], father[maxn];
int ptr = 0;
bool vis[maxn], isbridge[maxn]; //i and fa[i]
vector<int> edge[maxn];

void tarjan(int u, int fa)
{
    vis[u] = true;
    father[u] = fa;
    low[u] = dfn[u] = ++ptr;
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if (!vis[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u])
                isbridge[v] = true;
        }
        else if (dfn[v] < dfn[u] && v != fa)
            low[u] = min(low[u], dfn[v]);
    }
}
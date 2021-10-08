const int inf = 1e8;
struct node
{
    int to;
    int cap;
    int rev;
};

vector<node> edge[maxn];
int level[maxn];
int vis[maxn];

void add_edge(int from, int to, int cap)
{
    edge[from].push_back({to, cap, (int)edge[to].size()});
    edge[to].push_back({from, 0, (int)edge[from].size() - 1});
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < edge[v].size(); i++)
        {
            if (edge[v][i].cap > 0 && level[edge[v][i].to] < 0)
            {
                level[edge[v][i].to] = level[v] + 1;
                q.push(edge[v][i].to);
            }
        }
    }
}

int dfs(int v, int t, int f)
{
    if (v == t)
        return f;
    for (; vis[v] < edge[v].size(); vis[v]++)
    {
        node &e = edge[v][vis[v]];
        if (e.cap > 0 && level[v] < level[e.to])
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                edge[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    for (;;)
    {
        bfs(s);
        if (level[t] < 0)
            return flow;
        memset(vis, 0, sizeof(vis));
        int f;
        while ((f = dfs(s, t, inf)) > 0)
            flow += f;
    }
}
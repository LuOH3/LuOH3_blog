//negative edges only, not allowed negative circles
const int inf = 1e8;
struct node
{
    int to;
    int cap;
    int cost;
    int rev;
};

vector<node> edge[maxn];
int h[maxn];
int dis[maxn];
pair<int, int> pre[maxn];
int vis[maxn];

void add_edge(int from, int to, int cap, int cost)
{
    edge[from].push_back({to, cap, cost, (int)edge[to].size()});
    edge[to].push_back({from, 0, -cost, (int)edge[from].size() - 1});
}

void spfa(int s)
{
    memset(vis, 0, sizeof(vis));
    memset(h, 0x7f, sizeof(h));
    queue<int> q;
    h[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        vis[v] = 0;
        for (int i = 0; i < edge[v].size(); i++)
        {
            node e = edge[v][i];
            if (e.cap && h[e.to] > h[v] + e.cost)
            {
                h[e.to] = h[v] + e.cost;
                if (!vis[e.to])
                {
                    vis[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
}

bool dijkstra(int s, int t)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    fill(dis, dis + maxn, inf);
    memset(vis, 0, sizeof(vis));
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty())
    {
        int v = q.top().second;
        q.pop();
        if (vis[v])
            continue;
        vis[v] = 1;
        for (int i = 0; i < edge[v].size(); i++)
        {
            node e = edge[v][i];
            if (e.cap && dis[e.to] > dis[v] + e.cost + h[v] - h[e.to])
            {
                dis[e.to] = dis[v] + e.cost + h[v] - h[e.to];
                pre[e.to] = make_pair(v, i);
                if (!vis[e.to])
                    q.push(make_pair(dis[e.to], e.to));
            }
        }
    }
    return dis[t] != inf;
}

pair<int, int> min_cost_max_flow(int s, int t)
{
    spfa(s);
    int maxf = 0, minc = 0;
    while (dijkstra(s, t))
    {
        int minf = inf;
        for (int i = 0; i < maxn; i++)
            h[i] += dis[i];
        for (int i = t; i != s; i = pre[i].first)
            minf = min(minf, edge[pre[i].first][pre[i].second].cap);
        for (int i = t; i != s; i = pre[i].first)
        {
            edge[pre[i].first][pre[i].second].cap -= minf;
            edge[i][edge[pre[i].first][pre[i].second].rev].cap += minf;
        }
        maxf += minf;
        minc += minf * h[t];
    }
    return make_pair(maxf, minc);
}
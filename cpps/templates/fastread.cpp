namespace IStream
{
    const int L = 1 << 15;
    char buffer[L], *S, *T;
    inline char Get_Char()
    {
        if (S == T)
        {
            T = (S = buffer) + fread(buffer, 1, L, stdin);
            if (S == T)
                return EOF;
        }
        return *S++;
    }
    inline int Get_Int()
    {
        char c;
        int re = 0, w = 1;
        for (c = Get_Char(); c < '0' || c > '9'; c = Get_Char())
            if (c == '-')
                w = -1;
        while (c >= '0' && c <= '9')
            re = re * 10 + (c - '0'), c = Get_Char();
        return re * w;
    }
}
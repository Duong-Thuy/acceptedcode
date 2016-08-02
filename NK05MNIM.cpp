/*__ _(_) __ _  ___  ___ _   _  __| | __ _ _   _| |_ ___
 / _` | |/ _` |/ _ \/ __| | | |/ _` |/ _` | | | | __/ _ \
| (_| | | (_| | (_) \__ \ |_| | (_| | (_| | |_| | || (_) |
 \__, |_|\__,_|\___/|___/\__,_|\__,_|\__,_|\__,_|\__\___/
 |___/                                  Accepted Code  */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    for (scanf("%d",&T); T--;)
    {
        int N, M, C;
        int next[222][222], w[222][222];
        memset(next,0,sizeof(next));
        scanf("%d%d%d",&N,&M,&C);
        for (int i=1; i<=M; i++)
        {
            int x,y,l;
            scanf("%d%d%d",&x,&y,&l); // Biểu diễn đồ thì bàng danh sách kề
            next[x][++next[x][0]]=y; // next[x][0] là số đỉnh kề với đỉnh x
            next[y][++next[y][0]]=x; // next[x][i] là các đỉnh kề với x (0<=i<=next[x][0])
            w[x][y]=w[y][x]=l; // Độ dài đường đi nối giữa x,y và y,x
        }

        bool visited[222];
        memset(visited,false,sizeof(visited));
        int dp[222];
        for(int i=0; i<222; i++) dp[i]=INT_MAX;

        dp[N]=0;
        while (true)
        {
            int u=1; // tìm nơi cần ít nước nhất, ban đầu giả sử là 1
            for(int i=2; i<=N; i++)
                if(visited[i]==false && dp[u]>dp[i]) u=i;
            visited[u]=true; // đánh dấu đỉnh này đã thăm
            if(u==1) break; // Khi đã về đến 1 thì dừng lại
            for(int i=1; i<=next[u][0]; i++)
            {
                int v=next[u][i]; // đỉnh kề với đỉnh u
                if(visited[v])continue; // nếu đã thăm rồi thì bỏ qua
                int need=dp[u]; // lượng nước cần mang tới đỉnh u
                int L=w[u][v]; // Độ dài đoạn đường nối từ u đến v
                int water; // Lượng nước mà đỉnh v tối thiểu cần có
                if(need+L<=C) water=need+L;
                else
                {
                    if(C<=2*L)continue; //Nếu không đủ sức mang nước đi và về thì coi như không có cạnh nối đỉnh u và v
                    int t=(need+L-C)/(C-2*L); //Số luợt đi và về
                    if((need+L-C)%(C-2*L)>0) t++;
                    water=(2*t+1)*L+need;
                }
                dp[v]=min(dp[v],water); //Tối ưu lại lượng nước tối thiểu cần dùng ở đỉnh v
            }
        }
        printf("%d\n",dp[1]);
    }
    return 0;
}

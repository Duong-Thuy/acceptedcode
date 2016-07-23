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
    scanf("%d",&T);
    while(T--)
    {
        int n;
        bool ok;
        scanf("%d",&n);

        vector<int> a;
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            a.push_back(x);
        }
        for(int i=n; i<4; i++) a.push_back(0);

        int r[4];
        memset(r,0,sizeof(r));
        for(int i=0; i<n; i++)
            scanf("%d",r+i);
        // kiem tra trang thai ban dau da thoa man chua?
        ok=true;
        for(int i=0; i<n; i++)
            if(a[i]!=r[i]) ok=false;
        // nếu đã thỏa mãn rồi thì không cần biến đổi gì thêm
        if(ok)
        {
            printf("%d\n",0);
            continue;
        }


        int exist[50][50][50][50];
        memset(exist,0,sizeof(exist));

        queue<vector<int>> lq;
        // Tiến hành duyệt theo chiều rông BFS
        for(lq.push(a), exist[a[0]][a[1]][a[2]][a[3]]=1; !lq.empty(); lq.pop())
        {
            vector<int> cur=lq.front();
            //Do nuoc tu i sang j
            vector<int> w;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    if(i!=j && cur[i]<=a[j]-cur[j])
                    {
                        // Tien hanh do
                        w=cur;
                        w[j]+=w[i];
                        w[i]=0;
                        // kiem tra da thoa man chua?
                        ok=true;
                        for(int k=0; k<n; k++)
                            if(r[k]!=w[k])
                            {
                                ok=false;
                                break;
                            }
                        // Neu da thoa man roi
                        if(ok)
                        {
                            printf("%d\n",exist[cur[0]][cur[1]][cur[2]][cur[3]]);
                            break;
                        }
                        if(exist[w[0]][w[1]][w[2]][w[3]]==0)
                        {
                            exist[w[0]][w[1]][w[2]][w[3]]=exist[cur[0]][cur[1]][cur[2]][cur[3]]+1;
                            lq.push(w);

                        }
                    }
                if(ok) break;
            }
            if(ok) break;
            // Do day binh j bang nuoc tu i;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    if(i!=j && cur[j]!=a[j] && cur[i]>a[j]-cur[j])
                    {
                        //Tien hành đổ nước
                        w=cur;
                        w[i]=cur[i]-(a[j]-cur[j]);
                        w[j]=a[j];
                        // kiem tra da thoa man chua?
                        ok=true;
                        for(int k=0; k<n; k++)
                            if(r[k]!=w[k])
                            {
                                ok=false;
                                break;
                            }
                        // Neu da thoa man roi
                        if(ok)
                        {
                            printf("%d\n",exist[cur[0]][cur[1]][cur[2]][cur[3]]);
                            break;
                        }
                        if(exist[w[0]][w[1]][w[2]][w[3]]==0)
                        {
                            exist[w[0]][w[1]][w[2]][w[3]]=exist[cur[0]][cur[1]][cur[2]][cur[3]]+1;
                            lq.push(w);

                        }
                    }
                if(ok) break;
            }
            if(ok) break;

            //Do nuoc ra cong.
            for(int i=0; i<n; i++)
                if(cur[i]>0)
                {
                    w=cur;
                    w[i]=0;
                    // kiem tra da thoa man chua?
                    ok=true;
                    for(int k=0; k<n; k++)
                        if(r[k]!=w[k])
                        {
                            ok=false;
                            break;
                        }
                    // Neu da thoa man roi
                    if(ok)
                    {
                        printf("%d\n",exist[cur[0]][cur[1]][cur[2]][cur[3]]);
                        break;
                    }
                    if(exist[w[0]][w[1]][w[2]][w[3]]==0)
                    {
                        exist[w[0]][w[1]][w[2]][w[3]]=exist[cur[0]][cur[1]][cur[2]][cur[3]]+1;
                        lq.push(w);

                    }
                }
            if(ok) break;
        }
        if(lq.empty()) printf("NO\n");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int64_t mu(int64_t a, int64_t b)
{
    int res=1;
    for (int i=1; i<=b; i++)
        res*=a;
    return res;
}

int main()
{
#ifdef gsdt
    freopen("input.txt","r",stdin);
#endif // gsdt

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int64_t k,m;
        cin>>k>>m;

        int64_t a=k;
        int64_t pos=0;

        while(1)
        {
            pos+=a-mu(10,int(log10(a)))+1;
            a/=10;
            if(a==0)break;
        }
        if(m<pos)
        {
            printf("0\n");
            continue;
        }
        if(m==pos)
        {
            cout<<k<<endl;
            continue;
        }
        if(k==mu(10,int(log10(k))))
        {
            printf("0\n");
            continue;
        }
        a=k-1;
        while(1)
        {
            if(pos+a*10+9-mu(10,int(log10(a*10+9)))+1<=m)
            {
                a=a*10+9;
                pos+=a-mu(10,int(log10(a)))+1;
                if(pos==m)
                {
                    cout<<a<<endl;
                    break;
                }
            }
            else
            {
                a=mu(10,int(log10(a*10)))+m-pos-1;
                cout<<a<<endl;
                break;
            }
        }
    }

    return 0;
}


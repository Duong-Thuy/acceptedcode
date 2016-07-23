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
        int k,m;
        cin>>k>>m;

        int a=k;
        int pos=0;

        while(1)
        {
            pos+=a-pow(10,int(log10(a)))+1;
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
            printf("%d\n",k);
            continue;
        }
        if(k==pow(10,int(log10(k))))
        {
            printf("0\n");
            continue;
        }
        a=k-1;
        while(1)
        {
            if(pos+a*10+9-pow(10,int(log10(a*10+9)))+1<=m)
            {
                a=a*10+9;
                pos+=a-pow(10,int(log10(a)))+1;
                if(pos==m)
                {
                    printf("%d\n",a);
                    break;
                }
            }
            else
            {
                a=pow(10,int(log10(a*10)))+m-pos-1;
                printf("%d\n",a);
                break;
            }
        }
    }
    return 0;
}

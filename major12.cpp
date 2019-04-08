/*******************written by ABHISHEK CHAUHAN a.k.a abhishekcg98 ***************************************************************/

#include<bits/stdc++.h>
#define floop(a,b,c) for(lli i=a;i<b;i=i+c)
#define rloop(a,b,c) for(lli i=a;i>b;i=i-c)
#define trav(c,itr) for(__typeof((c).begin())::iterator itr=(c).begin();itr!=(c).end();itr++)
#define _abs(x) ((x)>0?(x):-(x))
#define mx 6

using namespace std;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;
typedef vector < long long int> vll;
typedef pair <long long int, long long int> pll;
typedef pair <int, int> pii;
typedef vector < int > vii;

typedef struct node{
int loadval;
int degree;
vector < pair< pair< int , int>, int > > col;
int availcol=0;
}nd;

typedef struct colorset
{
    vector< pair< pair < int, int >, int> > cset;
}colorset;

int main()
{
    int gp[6][6]={
    {0,1,0,0,0,1},
    {1,0,1,0,1,1},
    {0,1,0,1,1,0},
    {0,0,1,0,1,0},
    {0,1,1,1,0,1},
    {1,1,0,0,1,0},
    };
    nd *ndarr=new nd [6];
    ndarr[0].degree=2;
    ndarr[1].degree=4;
    ndarr[2].degree=3;
    ndarr[3].degree=2;
    ndarr[4].degree=4;
    ndarr[5].degree=3;
    ndarr[0].loadval=4;
    ndarr[1].loadval=4;
    ndarr[2].loadval=6;
    ndarr[3].loadval=6;
    ndarr[4].loadval=2;
    ndarr[5].loadval=3;

    vii tvec;
    int maxl=0,coun=0;
    int m=0;
    for(int i=0;i<6;i++)
    {
        if(ndarr[i].loadval>maxl)
        {
            tvec.push_back(i);
            maxl=ndarr[i].loadval;
            coun++;
        }
    }
    map < int ,int> usecolcount;
    int maxdeg=0;
    int target=0;
    if(coun>1)
    {
        while(!tvec.empty())
        {
            if(maxdeg<ndarr[tvec.front()].degree)
            {
                target=tvec.front();
                maxdeg=ndarr[tvec.front()].degree;
            }
            tvec.erase(tvec.begin());
        }
    }
    //ndarr[target].col
    ndarr[target].col.push_back(make_pair(make_pair(m,1),(++m)*10+1));
    int flag=1;
    int targetcol=m*10+1;
   //cout<<ndarr[target].col.front().second;
    int newcol=m*10+1;
    usecolcount.insert(make_pair(m*10+1,1));
    colorset *colset= new colorset[6];
     ndarr[target].loadval=0;
int k=0;

//cout<<ndarr[target].col.front().second;
k++;
while(k<6)
{
    if(flag==1)
    {
        for(int i=0;i<6;i++)
        {
            colset[i].cset.push_back(make_pair(make_pair(m*10+1,ndarr[target].loadval),0));
            ndarr[i].availcol++;
        }
        vector< pair< pair < int, int >, int> >::iterator it;
        for(it=colset[target].cset.begin();it!=colset[target].cset.end();it++)
            {
                if((it->first.first==(targetcol)) && it->second!=1)
                {
                    it->second=1;
                    --ndarr[target].availcol;
                break;
                }

            }

        ndarr[target].loadval=0;
    }

    for(int i=0;i<6;i++)
    {
        if(gp[target][i]==1)
        {
            vector< pair< pair < int, int >, int> >::iterator it;
            for(it=colset[i].cset.begin();it!=colset[i].cset.end();it++)
            {
                if((it->first.first==(targetcol)) && it->second!=1)
                {
                    it->second=1;


                    --ndarr[i].availcol;
                }

            }
        }
    }
//    colset[target].cset.push_back(make_pair(make_pair(m*10+1,ndarr[target].loadval),0));
//            ndarr[i].availcol++;
    int minc=6;
    int maxload=0;
    for (int i=0;i<6;i++)
    {
        if(ndarr[i].availcol==minc && ndarr[i].loadval!=0)
        {
            if(ndarr[i].loadval>maxload)
            {
                minc=ndarr[i].availcol;
                maxload=ndarr[i].loadval;
                target=i;
            }
        }
        else if(ndarr[i].availcol<minc && ndarr[i].loadval!=0)
        {
            minc=ndarr[i].availcol;
            target=i;
        }

    }
    if(ndarr[target].availcol==0)
    {
        ndarr[target].col.push_back(make_pair(make_pair(m,1),(++m)*10+1));
            usecolcount[m*10+1]=1;
            flag=1;
            targetcol=m*10+1;
            k++;
        /*for(int i=0;i<6;i++)
            {
                colset[i].cset.push_back(make_pair(make_pair(ndarr[target].col.front().second,ndarr[target].loadval),0));
                ndarr[i].availcol++;
            }*/
    }
     else
  {
      flag=0;
      int targetload=0;
       vector< pair< pair < int, int >, int> >::iterator it;
       int mincol=6;
    for(it=colset[target].cset.begin();it!=colset[target].cset.end();it++)
    {
        if(usecolcount[it->first.first]<mincol && it->second!=1)
        {
            mincol=usecolcount[it->first.first];
            targetcol=it->first.first;
            targetload=it->first.second;

        }

    }

    if(ndarr[target].loadval==targetload)
    {
        k++;
        ndarr[target].col.push_back(make_pair(make_pair(targetcol/10,targetcol%10),targetcol));
            usecolcount[targetcol]++;
             vector< pair< pair < int, int >, int> >::iterator it;
            for(it=colset[target].cset.begin();it!=colset[target].cset.end();it++)
            {
                if((it->first.first==(targetcol)) && it->second!=1)
                {
                    it->second=1;
                    --ndarr[target].availcol;
                break;
                }

            }
                        ndarr[target].loadval=0;
    }
    else if(ndarr[target].loadval>targetload)
    {
        ndarr[target].loadval-=targetload;
        ndarr[target].col.push_back(make_pair(make_pair(targetcol/10,targetcol%10),targetcol));
        vector< pair< pair < int, int >, int> >::iterator it;
            for(it=colset[target].cset.begin();it!=colset[target].cset.end();it++)
            {
                if((it->first.first==(targetcol)) && it->second!=1)
                {
                    it->second=1;
                    --ndarr[target].availcol;
                break;
                }

            }
            usecolcount[targetcol]++;
    }
    else
    {
        //ndarr[target].loadval=0;
        newcol=(targetcol/10)*10+(targetcol%10)+1;
        ndarr[target].col.push_back(make_pair(make_pair(targetcol/10,targetcol%10),targetcol));
                 usecolcount[targetcol]++;
                 usecolcount.insert(make_pair(newcol,0));
      //  ndarr[target].availcol++;
    for(int i=0;i<6;i++)
    {
            vector< pair< pair < int, int >, int> >::iterator it;
        for(it=colset[i].cset.begin();it!=colset[target].cset.end();it++)
        {
            if(it->first.first==targetcol)
            {
                if(it->second!=1)
                {
                colset[i].cset.push_back(make_pair(make_pair(newcol,it->first.second-ndarr[target].loadval),0));
                ndarr[i].availcol++;
                it->first.second=ndarr[target].loadval;
                break;
                }
                else
                {
                    colset[i].cset.push_back(make_pair(make_pair(newcol,it->first.second-ndarr[target].loadval),1));
                    it->first.second=ndarr[target].loadval;
                    vector < pair< pair< int , int>, int > >::iterator itt;
                    for(itt=ndarr[i].col.begin();itt!=ndarr[i].col.end();itt++)
                    {
                        if(itt->second==targetcol)
                        {
                        ndarr[i].col.push_back(make_pair(make_pair(targetcol/10,(targetcol%10)+1),newcol));
                        break;
                        }

                    }
                    for(it=colset[target].cset.begin();it!=colset[target].cset.end();it++)
                    {
                    if((it->first.first==(targetcol)) && it->second!=1)
                    {
                        it->second=1;
                        --ndarr[target].availcol;
                        break;
                    }

                    }
                    ndarr[target].loadval=0;
                    break;
                }
            ndarr[target].loadval=0;
            }
        }
   }

  }
  }
}
for(int i=0;i<6;i++)
{
    cout<<"node"<<" "<<i<<" "<<"colors ";
    vector < pair< pair< int , int>, int > >::iterator it;
    for(it=ndarr[i].col.begin();it!=ndarr[i].col.end();it++)
    {
        cout<<"C"<<it->second<<" ";
    }
    cout<<endl;
}




}

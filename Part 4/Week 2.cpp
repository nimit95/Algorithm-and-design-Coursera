#include<iostream>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include <algorithm>
using namespace std;
vector< vector<int> > temp;
long int pos=0;
map< vector<int>, int > s;
vector<int> removej(vector<int> vec, int j)
{

    vec.erase(std::remove(vec.begin(), vec.end(), j), vec.end());
    return vec;
}
void subset(vector<int> v, vector<int> v1, int i,int m)
{
    if(m==0||i>=v.size()){
        v1.insert(v1.begin(), 1);
        temp.push_back(v1);
       //for(int j=0;j<v1.size();j++)
         //   cout<<v1[j];
        //cout<<endl;
        s[v1] = pos;
        pos++;

        return;
    }
    if(i!=v.size()-m)
        subset(v, v1, i+1, m);
    v1.push_back(v[i]);
    subset(v, v1, i+1, m-1);
}
void tsp(vector< vector<double> > &c, int n){
    vector<int> v;
    vector< vector<double> > a(pow(2,n-1) -1 + n,vector<double>(n,0) );
    for(int i=2;i<=n;i++){
           // cout<<i;
        v.push_back(i);
    }
    for(int i=1;i<=n;i++){
        vector<int> v2(1);
        v2[0]=i;
       // cout<<i;
       // cout<<v2[i];
        s[v2] = pos;

        pos++;
        if(i==1)
            a[s[v2]][0] = 0.0;
        else
            a[s[v2]][0] =100000.0;
    }


    for(int m=2;m<=n;m++){
       // cout<<m;
        temp.clear();
        vector<int> v1;

        subset(v, v1, 0, m-1);
      //  cout<<endl<<s[{1}];

        for(int i=0;i<temp.size();i++)
        {
            a[s[temp[i]]][0] = 100000.0;
            double mini=111111;
           // cout<<s[temp[i]];
            for(int j=0;j<temp[i].size();j++)
            {


                if(temp[i][j]!=1)
                {
                    //cout<<temp[i][j];
                    for(int k:temp[i])
                    {

                        if(a[s[removej(temp[i], temp[i][j])]][k-1] + c[k-1][temp[i][j]-1]<mini && k!=temp[i][j]){
                                // cout<<k;
                             //  cout<<i<<j<<k<<"   ";
                               // cout<<a[s[removej(temp[i], k)]][k-1] + c[k-1][temp[i][j]-1]<< "  ";

                            mini = a[s[removej(temp[i], temp[i][j])]][k-1] + c[k-1][temp[i][j]-1] ;
                            //cout<< removej(temp[i], k)]<<"-"<<mini;
                          //  cout<<removej(temp[i], k)[0];
                            //cout<<mini;
                            //vector<int> y= removej(temp[i], temp[i][j]-1);
                            //for(int f=0;f<y.size();f++);
                             //   cout<<y[f];
                            // cout<<removej(temp[i], k)];

                        }
                    }
                    a[s[temp[i]]][temp[i][j]-1] = mini;
                    //cout<<a[s[temp[i]]][temp[i][j]-1];
                    //cout<<mini<<" ";
                    //cout<<s[{1}];
                }

            }
          //  cout<<endl;
        }
    }
    for(int i=0;i<a[a.size()-1].size();i++)
        cout<<a[a.size()-1][i]<<" ";
}
int main(){
    int n;
    cin>>n;
    vector<pair<double, double>> xy;
    vector<vector<double>> a(n,vector<double>(n));
    while(n--){
        double x,y;
        cin>>x>>y;
        xy.push_back({x,y});
    }
    for(int i=0;i<xy.size();i++){
        a[i][i] = 0;
        for(int j=i+1;j<xy.size();j++){
            a[i][j]= sqrt(pow(xy[i].first - xy[j].first , 2) + pow(xy[i].second - xy[j].second, 2));
            a[j][i] = a[i][j];
        }
    }
    /*for(int i = 0;i<xy.size();i++){
        for(int j=0;j<xy.size();j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }*/
    tsp(a, xy.size());
}

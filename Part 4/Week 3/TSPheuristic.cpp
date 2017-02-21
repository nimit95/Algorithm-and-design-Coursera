#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    long int siz,n;
    cin>>siz;
    vector<pair<long double,long double>> points;
    vector<bool> visited(siz,false);
    for(int i=0;i<siz;i++){
        double a,b;
        cin>>n>>a>>b;
        points.push_back({a,b});
        visited[i]=false;
    }
    long int selected =0;
    visited[selected] = true;
    long double weightSum = 0 ;
    for(int i=0;i<siz-1;i++)
    {
        long double mini=1000000000.0;
         visited[selected] = true;
         long int selected2=selected;
        for(int j=0;j<siz;j++)
        {

            long double yo = pow(points[selected2].first - points[j].first,2);
            long double yo2 = pow(points[selected2].second - points[j].second,2);

            long double temp = yo+yo2;
            if(temp<mini && visited[j]==false )
            {
                selected = j;
                mini = temp;
            }
        }
        weightSum += sqrt(mini);
    }
    weightSum += sqrt(pow(points[0].first - points[selected].first,2) + pow(points[0].second - points[selected].second,2));
    cout<<(long long int)weightSum;
}

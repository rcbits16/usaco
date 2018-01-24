/*
ID: rohitch1
PROG: milk
LANG: C++
*/

// This solution sorts by price offered, and buys all from the cheapest farmer before moving on, A "greedy" solution.
// Also, since we knew there's  bound on prices (1000), we could have used counting sort to store the amount of milk we can get at a price,
//that wouid've been O(n).


#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)


int main(void)
{
    int total_milk, n_farmers, total_cost=0 ;
    ii temp; vii farmer_data;

    ifstream fin;
    fin.open("milk.in");
    fin >> total_milk >> n_farmers;

    for(int i=0; i<n_farmers; i++)
    {
        fin >> temp.first >> temp.second;
        farmer_data.push_back(temp);
    }
    sort(all(farmer_data));

    tr(farmer_data,i)
    {
        if(i->second<total_milk)
        {
            total_milk -= i->second;
            total_cost += i->first*i->second;
        }
        else
        {
            total_cost += i->first*total_milk;
            break;
        }
    }

    ofstream fout;
    fout.open("milk.out");
    fout << total_cost <<'\n';

return 0;
}

















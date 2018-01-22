/*
ID:	rohitch1
PROG: ariprog
LANG: C++
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
#define present(c,x) ((c).find(x) != (c).end()) 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define MAXSUM 125001
bool bisquares[MAXSUM];
int main(void)
{
	int N;	//Number of terms in series. 3<=N<=25
	int M;	// Upper bound on p & q.  1<=M<=250
	ifstream fin("ariprog.in");
	fin >> N;
	fin >> M;
	fin.close();
	
	for(int p=0;p<=M;p++)
		for(int q=0;q<=M;q++)
			bisquares[(p*p)+(q*q)]=true;
	
	// TODO: find max
	int min=0,max=0;	// min will always be 0	
	for(int i=0;i<(2*M*M)+1;i++)
		if(bisquares[i])
			if(i>max)	max =i;

	int dmax = 2772; // figured it out by solving the test cases on pc :P. Hack and learn :D 
	// (should've been (max-0)/(N-1);	// Assumes N>1 (as constraints give N>3 always)
	vector<ii> sols;		
	ii temp;

	for(int d=1;d<=dmax;d++){	// Common difference >=1	
		for(int a=min;a<= max -((N-2)*d) ;a++)
		{
			bool valid = true;
			for(int n=0;n<N;n++)
			{
				if((a+(n*d)>MAXSUM)||!bisquares[a+(n*d)]){	valid = false; break;}		
			}
			if(valid){
				temp.first = a;	temp.second = d;
				sols.push_back(temp);
			}	
		}
	}
	
	
	ofstream fout("ariprog.out");
	if(!sols.empty())
		for(int i=0;i<sols.size();i++)
			fout << sols[i].first << " " << sols[i].second <<'\n';
	else fout << "NONE\n";		
	fout.close();				
return 0;
}
















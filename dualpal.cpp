/*
ID: rohitch1
PROG: dualpal
LANG: C++
*/
// Dude you SUCK at C. Stick to C++ and it's inbuilt stuff until you have learned more of C and undefined behaviour and stuff :(

#include<bits/stdc++.h>


using namespace std;

string ireversed(int x, int base);
string istraight(string reversed);

int main(void)
{

    ifstream fin;
    fin.open("dualpal.in");
    int N,S;
    fin >> N >> S;
    fin.close();


    ofstream fout;  fout.open("dualpal.out");
    int found=0;
    S++;
    string curr;
    while(found<N)
    {
        int count=0;
        for(int i=2;i<=10;i++)
        {
            curr = ireversed(S,i);
            if(curr==istraight(curr))  count++;
        }
        if(count>=2)
        {
            found++;
            fout << S <<'\n';
        }
        S++;
    }
return 0;
}


string ireversed(int x, int base)
{
    int sz=0; string a;  // 20 won't be ever needed but who cares :p
    string syms = "0123456789ABCDEFGHIJ";
//Building the reversed integer (as a string)
    if(x==0){
        a ="0"; sz=1;
    }
    else{
        while(x>0){
            a += syms[(x%base)];
            x/=base;
        }
    }
return a;
}

string istraight(string str)
{
    reverse(str.begin(),str.end());
    return str;
}

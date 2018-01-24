/*
ID: rohitch1
PROG: palsquare
LANG: C++
*/

// Print all numbers 1 <= N <= 300, whose squares are palindromic in base b;
// Instead of checking palindromicity conventionally, i just compared the two strings. (Easier to code :p)
// For some reason, 1 1 doesn't get printed on grader, but does on my system.



#include<bits/stdc++.h>

using namespace std;

char* ireversed(int x, int base);
char* istraight(int x, int base);

int main(void)
{
//Taking input "base"

    ifstream fin;
    fin.open("palsquare.in");
    int base;
    fin >> base;
    fin.close();

//Output
    ofstream fout;
    fout.open("palsquare.out");

    for(int i=1;i<=300;i++)
    {
        if( strcmp(istraight(i*i,base), ireversed(i*i,base)) == 0)
        {
            fout << istraight(i,base) << " " <<istraight(i*i,base) <<"\n";
        }
    }
    return 0;

}


char* ireversed(int x, int base)
{
    int sz=0; char a[20];  // 20 won't be ever needed but who cares :p
    char syms[] = "0123456789ABCDEFGHIJ";
//Building the reversed integer (as a string)
    if(x==0){
        a[0]='0';sz=1;
    }
    else{
        while(x>0){
            a[sz++]= syms[(x%base)];
            x/=base;
        }
    }
    a[sz]='\0';
    char* revs = (char*)malloc(sz);
    memcpy(revs,a,sz);
return revs;
}


char* istraight(int x, int base)
{
// First building the reversed int string
    char *rev = ireversed(x,base);
    int sz = strlen(rev);
    char *s =  (char*)malloc(sz+1);

    for(int i=0;i<sz;i++)
    {
        s[i] = rev[sz-(i+1)];
    }
    s[sz] = '\0';

return s;
}

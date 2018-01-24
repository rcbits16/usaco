/*
ID: rohitch1
PROG: crypt1
LANG: C++
*/

// Only n^5 cases are possible, filtering is feasible. ( n max is 9 {1,2,3,4,5,6,7,8,9} )
// So we just checked all possible combinations. :)
// But the way i wrote it is WAAY dumb :/, I could have just made a function, see problem analysis on USACO
/*
          a b c     <-- number 'abc'
        x   d e     <-- number 'de'; the 'x' means 'multiply'
     -----------
                             p11                   p12              p13
p1                           (ae+prev/10)%10       (be+prev/10)%10  (ce%10)     <-- product of e * abc; first star might be 0 (absent)
p2     (ad+prev/10)%10       (bd+prev/10)%10       (cd%10)                      <-- product of d * abc; first star might be 0 (absent)
     ------------------------------------------------------------------------------
0      (p21+prev/10)%10  (p11+p22+prev/10)%10  (p12+p23)%10     (p13)       <-- sum of p1 and p2 (e*abc + 10*d*abc) == de*abc
*/


#include<bits/stdc++.h>

using namespace std;

#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())


int main(void)
{
    int N;
    set<int> s;

    ifstream fin;
    fin.open("crypt1.in");
    fin >> N;
    for(int i=0;i<N;i++)
    {
        int temp;
        fin >> temp;
        s.insert(temp);
    }
    fin.close();

    int p11,p12,p13,p21,p22,p23,s1,s2,s3,s4,count=0;     //s0 should always be zero

    tr(s,A){
     tr(s,B){
      tr(s,C){
       tr(s,D){
        tr(s,E){
                    int a= *A, b= *B, c= *C, d= *D, e= *E;

                    p13 = (c*e)%10;
                    p12 = (b*e+((c*e)/10))%10;
                    p11 = (a*e + (b*e+((c*e)/10))/10)%10;

                    p23 = (c*d)%10;
                    p22 = (b*d+((c*d)/10))%10;
                    p21 = (a*d + (b*d+((c*d)/10))/10)%10;

                    s4 = p13;
                    s3 = (p12+p23)%10;
                    s2 = (p11+p22+((p12+p23)/10))%10;
                    s1 = (p21+((p11+p22+((p12+p23)/10))/10))%10;

                    // Unneccsarily nesting if's cuz i hate a long conditional!!
                    if( ((p21+((p11+p22+((p12+p23)/10))/10))/10==0)
                        && ((a*e + (b*e+((c*e)/10))/10)/10==0)
                        && ((a*d + (b*d+((c*d)/10))/10)/10==0) ){
                        if(present(s,s1)&&present(s,s2)&&present(s,s3)&&present(s,s4)){
                            if(present(s,p21)&&present(s,p22)&&present(s,p23)){
                                if(present(s,p11)&&present(s,p12)&&present(s,p13))
                                    {
                                        count++;
                                        printf(" %d%d%d\n",a,b,c);
                                        printf("x %d%d\n",d,e);
                                        printf("------\n");
                                        printf(" %d%d%d\n",p11,p12,p13);
                                        printf("%d%d%d\n",p21,p22,p23);
                                        printf("-------\n");
                                        printf("%d%d%d%d\n\n",s1,s2,s3,s4);
                                    }
                                }
                            }
                    }
               }
              }
             }
            }
           }

    ofstream fout;
    fout.open("crypt1.out");

    fout << count <<'\n';

return 0;
}
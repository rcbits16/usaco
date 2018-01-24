/*
ID: rohitch1
PROG: beads
LANG: C
*/
//Naive solution O(n^2), but it works! so this is the best soln in a contest :P
// Because you have more time to focus on harder problems. :P :P

//See the solutions given in analysis, one is O(n) with D.P., another one is also O(n^2) but neater.

#include<stdio.h>

int main(void)
{

    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");

    int n,max=0;
    int before=0, after=0;
    char prev,next,pdif,ndif;

    fscanf (fin, "%d\n",&n);
    char necklace[2*n];
    fscanf (fin, "%s",necklace);
    for(int i=0;i<n;i++)
    {
        necklace[n+i]=necklace[i];
    }

    //Calculations
    for(int i=0;i<n;i++)
    {
        prev = necklace[i];
        next = necklace[i+1];
        before=0;after=0;

        if(prev=='w')
        {
            int j;
            for(j=i;j>=0;j--)
            {
                if(necklace[j]=='w') before++;
                else
                {
                    pdif = necklace[j];
                    break;
                }
            }
            for(int k=j;k>=0;k--)
            {
                if(necklace[k]=='w'||necklace[k]==pdif) before++;
                else break;
            }

        }
        else
        {
            for(int j=i;j>=0;j--)
            {
                if(necklace[j]=='w'||necklace[j]==prev) before++;
                else break;
            }
        }


        if(next=='w')
        {
            int j;
            for(j=i+1;j<=(i+n);j++)
            {
                if(necklace[j]=='w') after++;
                else
                {
                    ndif = necklace[j];
                    break;
                }
            }
            for(int k=j;k<=(i+n);k++)
            {
                if(necklace[k]=='w'||necklace[k]==ndif) after++;
                else break;
            }

        }
        else
        {
            for(int j=i+1;j<(i+n);j++)
            {
                if(necklace[j]=='w'||necklace[j]==next) after++;
                else break;
            }
        }

        if((before+after)>max) max = (before +after);

    }
    if (max>n) max =n;
     fprintf (fout, "%d\n",max);

}
/*
ID: rohitch1
LANG: C
PROG: ride
*/

#include <stdio.h>
#include <stdlib.h>

int main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char a[7],b[7];
    fscanf (fin, "%s\n%s",a,b);
    int xa=1,xb=1,i=0;
    while(a[i]!='\0')
    {
        xa = (xa%47)*(a[i]-'A'+1);
        i++;
    }
    i=0;
    while(b[i]!='\0')
    {
        xb = (xb%47)*(b[i]-'A'+1);
        i++;
    }
    if((xa%47)==(xb%47))
    {
        fprintf (fout, "GO\n");
    }
    else    fprintf (fout, "STAY\n");
    exit (0);
}
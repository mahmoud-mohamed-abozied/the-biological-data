#include<iostream>
#include "Sequence.h"
#include <bits/stdc++.h>
using namespace std;

Sequence::Sequence()
{
    seq=new char ();
}

Sequence:: ~Sequence()
{
    delete[] seq;

}

void Sequence :: Print()
{
    for(int i=0 ; i<strlen(seq) ; i++)
    {
        cout<<seq[i];
    }

}


char* Align(Sequence* s1,Sequence* s2)
{
    int m = strlen(s1->seq);
    int n = strlen(s2->seq);
    char* x = new char[m+1];
    char* y = new char[n+1];
    x[m+1]='\0';
    y[m+1]='\0';
    x = s1->seq;
    y = s2->seq;

    int** L = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        L[i] = new int[n + 1];
    }

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    int index = L[m][n];


    char* lcs = new char[index + 1];
    lcs[index] =' ';
    int c = 0;

    int i = m, j = n;
    while (i > 0 && j > 0)
    {

        if (x[i - 1] == y[j - 1])
        {
            lcs[index - 1] = x[i - 1];
            c++;
            i--;
            j--;
            index--;
        }

        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

#include<iostream>
#include "Protein.h"
#include"Sequence.h"
#include <bits/stdc++.h>
using namespace std;

Protein::Protein() {}
Protein::Protein(char * p)
{
    for(int i=0 ; i<strlen(seq) ; i++)
    {
        seq[i]=p[i];
    }
}
Protein::~Protein()
{
    delete [] seq;
}
// return an array of DNA sequences that can possibly
// generate that protein sequence
//    DNA* Protein:: GetDNAStrandsEncodingMe(const DNA & bigDNA);

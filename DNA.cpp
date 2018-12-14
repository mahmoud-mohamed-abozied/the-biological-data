#include<iostream>
#include "DNA.h"
#include"Sequence.h"
#include <bits/stdc++.h>
using namespace std;

DNA::DNA() {}
DNA::DNA(char *seq, DNA_Type atype)
{
    for(int i=0 ; i<strlen(seq) ; i++)
    {
        this->seq[i]=seq[i];
    }
    type=atype;
}

DNA::~DNA()
{
    delete [] seq;
}

// function printing DNA sequence information to user
void DNA :: Print()
{
    cout<<"The DNA sequence is : " ;
    for(int i=startIndex ; i<endIndex ; i++)
    {
        cout<<seq[i];
    }
    cout<<endl;
}

// function to build the second strand/pair of DNA sequence
// To build a complementary_strand (starting from the startIndex to
// the endIndex), convert each A to T, each T to A, each C to G, and
// each G to C. Then reverse the resulting sequence.
void DNA :: BuildComplementaryStrand()
{
    complementary_strand->seq = new char {strlen(seq)};
    for (int i=startIndex ; i<endIndex ; i++)
    {
        if(seq[i]=='T')
        {
            complementary_strand->seq[i]='A';
        }
        else if(seq[i]=='A')
        {
            complementary_strand->seq[i]='T';
        }
        else if(seq[i]=='C')
        {
            complementary_strand->seq[i]='G';
        }
        else if(seq[i]=='G')
        {
            complementary_strand->seq[i]='C';
        }

    }

    cout<<"The ComplementaryStrand is : ";

    for (int j=endIndex-1 ; j>=startIndex ; j--)
    {
        cout<<complementary_strand->seq[j];

    }
    cout<<endl;
}

RNA DNA :: ConvertToRNA()
{
    char *temp = new char[strlen(seq)];
    complementary_strand->seq = new char [strlen(seq)];

    cout<<"RNA is : ";
    for (int i=startIndex ; i<=endIndex ; i++)
    {
        if(complementary_strand->seq[i]=='T')
        {
            temp[i]='U';
        }
        else
        {
            temp[i]=complementary_strand->seq[i];
        }

    }

   cout<<"RNA is : ";
    for (int i=startIndex ; i<=endIndex ; i++)
    {
        cout<<temp[i];
    }

    RNA r;

    return r;
}


void DNA :: set_startIndex(int startIndex)
{
    this->startIndex=startIndex;
}

int DNA :: get_startIndex()
{
    return startIndex;
}

void DNA ::set_endIndex(int endIndex)
{
    this->endIndex=endIndex;
}

int DNA :: get_endIndex()
{
    return endIndex;
}

DNA operator+ (DNA d1, DNA d2)
{
    DNA d3;
    d3.seq=new char [strlen(d1.seq)+strlen(d2.seq)+1];
    d3.seq[strlen(d1.seq)+strlen(d2.seq)]='\0';
    int x=0;
    for(int i=0 ; i<strlen(d1.seq); i++)
    {
        d3.seq[i]=d1.seq[i];
    }
    for(int i=strlen(d1.seq) ; i<(strlen(d1.seq)+strlen(d2.seq)) ; i++)
    {
        d3.seq[i]=d2.seq[x];
        x++;
    }
    return d3;
}

bool operator== (DNA d1, DNA d2)
{
    if(strlen(d1.seq)==strlen(d2.seq))
    {
        int counter=0;
        for(int i=0 ; i<strlen(d1.seq) ; i++)
        {
            if(d1.seq[i]==d2.seq[i])
            {
                counter++;
            }
            else
                break;
        }
        if(counter==strlen(d1.seq))
            return true;
        else
            return false;
    }
    else
        return false;
}
bool operator!= (DNA d1, DNA d2)
{
    if(strlen(d1.seq)==strlen(d2.seq))
    {
        int counter=0;
        for(int i=0 ; i<strlen(d1.seq) ; i++)
        {
            if(d1.seq[i]!=d2.seq[i])
            {
                return true;
                break;
            }
            else
                counter++;
        }
        if(counter !=0)
            return false;
        else
            return true;
    }
    else
        return true;
}

istream& operator>> (istream& in, DNA& d)
{
    int length ;
    string s="Invalid Sequence of DNA.";
    cout<<"Please, Enter the length of DNA : ";
    cin>>length;
    d.seq =  new char [length+1];
    d.seq[length]='\0';
    for(int i=0 ; i<length ; i++)
    {
        in>>d.seq[i];
        if(d.seq[i]!='A'&&d.seq[i]!='U'&&d.seq[i]!='C'&&d.seq[i]!='G')
            throw s;
    }
}


ostream& operator<< (ostream& out, DNA& d)
{
    for(int i=0 ; i<strlen(d.seq) ; i++)
    {
        out<<d.seq[i];
    }
}


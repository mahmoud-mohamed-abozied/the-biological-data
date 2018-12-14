#include<iostream>
#include "RNA.h"
#include "Sequence.h"
#include <bits/stdc++.h>
using namespace std;

RNA::RNA() {}
RNA::RNA(char * seq, RNA_Type atype)
{
    for (int i=0 ; i<strlen(seq) ; i++)
    {
        this->seq[i]=seq[i];
    }
    type=atype;
}

RNA::~RNA()
{
    delete [] seq;
}

// function to be overridden to print all the RNA information
void RNA :: Print()
{
    cout<<"The RNA sequence is : ";
    for(int i=0 ; i<strlen(seq) ; i++)
    {
        cout<<seq[i];
    }
    cout<<endl;
}

// function to convert the RNA sequence into protein sequence
// using the codonsTable object
//ana        Protein ConvertToProtein(const CodonsTable & table);
// function to convert the RNA sequence back to DNA
DNA RNA :: ConvertToDNA()
{
    char *temp = new char[strlen(seq)];

    for (int i=startIndex ; i<=endIndex ; i++)
    {
        if(seq[i]=='U')
        {
            temp[i]='T';
        }
        else
        {
            temp[i]=seq[i];
        }

    }

    for (int i=startIndex ; i<endIndex ; i++)
    {
        if(temp[i]=='T')
        {
            temp[i]='A';
        }
        else if(temp[i]=='A')
        {
            temp[i]='T';
        }
        else if(temp[i]=='C')
        {
            temp[i]='G';
        }
        else if(temp[i]=='G')
        {
            temp[i]='C';
        }

    }

    cout<<"DNA is : ";
    for (int j=endIndex-1 ; j>=startIndex ; j--)
    {
        cout<<temp[j];
    }

    DNA d(temp,tail);

    return d;



}

void RNA ::set_startIndex(int startIndex)
{
    this->startIndex=startIndex;
}

int RNA :: get_startIndex()
{
    return startIndex;
}

void RNA :: set_endIndex(int endIndex)
{
    this->endIndex=endIndex;
}

int RNA :: get_endIndex()
{
    return endIndex;
}

RNA operator+ (RNA r1 , RNA r2)
{
    RNA r3;
    r3.seq=new char [strlen(r1.seq)+strlen(r2.seq)];
    int x=0;
    for(int i=0 ; i<strlen(r1.seq); i++)
    {
        r3.seq[i]=r1.seq[i];
    }
    for(int i=strlen(r1.seq) ; i<strlen(r1.seq)+strlen(r2.seq) ; i++)
    {
        r3.seq[i]=r2.seq[x];
        x++;
    }
    return r3;
}

bool operator== (RNA r1, RNA r2)
{
    if(strlen(r1.seq)==strlen(r2.seq))
    {
        int counter=0;
        for(int i=0 ; i<strlen(r1.seq) ; i++)
        {
            if(r1.seq[i]==r2.seq[i])
            {
                counter++;
            }
            else
                break;
        }
        if(counter==strlen(r1.seq))
            return true;
        else
            return false;
    }
    else
        return false;
}
bool operator!= (RNA r1 , RNA r2)
{
    if(strlen(r1.seq)==strlen(r2.seq))
    {
        int counter=0;
        for(int i=0 ; i<strlen(r1.seq) ; i++)
        {
            if(r1.seq[i]!=r2.seq[i])
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

istream& operator>> (istream& in, RNA& r)
{
    int length ;
    string s="Invalid Sequence of RNA.";
    cout<<"Please, Enter the length of RNA : ";
    cin>>length;
    r.seq =  new char [length+1];
    r.seq[length]='\0';
    for(int i=0 ; i<length ; i++)
    {
        in>>r.seq[i];
        if(r.seq[i]!='A'&&r.seq[i]!='U'&&r.seq[i]!='C'&&r.seq[i]!='G')
            throw s;
    }
}


ostream& operator<< (ostream& out, RNA& r)
{
    for(int i=0 ; i<strlen(r.seq) ; i++)
    {
        out<<r.seq[i];
    }
}

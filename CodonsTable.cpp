#include<iostream>
#include <fstream>
#include "CodonsTable.h"
using namespace std;

CodonsTable::CodonsTable()
{
    //ctor
}


CodonsTable::~CodonsTable()
{

}
// function to load all codons from the given text file
void CodonsTable :: LoadCodonsFromFile(string codonsFileName)
{
    ifstream fileInput;

    fileInput.open (codonsFileName.c_str());
    int i=0;
    if (fileInput.fail())
    {
        cout<<"failure opening file"<<endl;
    }
    else
    {
        while (fileInput>>codons[i].value,fileInput>>codons[i].AminoAcid)
        {
            i++;
        }
        fileInput.close();
    }
}

Codon CodonsTable::getAminoAcid(char* value)
{
    for (int i = 0; i < 64; i++)
    {
        if (codons[i].value == value)
            return codons[i];
    }
}

void CodonsTable :: setCodon(char * value, char AminoAcid, int index)
{
    Codon temp;
    for (int i = 0; i < 4; i++)
    {
        temp.value[i] = value[i];
    }
    temp.AminoAcid = AminoAcid;
    codons[index] = temp;
}

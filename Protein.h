#ifndef PROTEIN_H
#define PROTEIN_H
#include<iostream>
#include "DNA.h"
#include "Sequence.h"
using namespace std;

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
class DNA;
class RNA;
class Protein : public Sequence
{
public:
    // constructors and destructor
    Protein();
    Protein(char * p);
    ~Protein();

    // return an array of DNA sequences that can possibly
    // generate that protein sequence
    DNA* GetDNAStrandsEncodingMe(const DNA & bigDNA);

protected:

private:
    Protein_Type type;
};

#endif // PROTEIN_H

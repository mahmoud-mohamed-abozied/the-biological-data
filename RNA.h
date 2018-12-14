#ifndef RNA_H
#define RNA_H
#include<iostream>
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include "Sequence.h"
using namespace std;

class DNA;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
class RNA : public Sequence
{
public:
    // constructors and destructor
    RNA();
    RNA(char * seq, RNA_Type atype);
    RNA(RNA& rhs);
    ~RNA();

// function to be overridden to print all the RNA information
    void Print();

    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
    //Protein ConvertToProtein(const CodonsTable & table);

    // function to convert the RNA sequence back to DNA
    DNA ConvertToDNA();

    //function to overload operator +
    friend RNA operator+ (RNA r1, RNA r2);

    //function to overload operator ==
    friend bool operator== (RNA r1, RNA r2);

    //function to overload operator !=
    friend bool operator!= (RNA r1, RNA r2);


    //function to overload operator >>
    friend istream& operator>> (istream& in, RNA& r);

    //function to overload operator >>
    friend ostream& operator<< (ostream& out, RNA& r);

    // function to  allow accessing to private variable startIndex
    void set_startIndex(int startIndex);

    // function to  allow accessing to private variable endIndex
    void set_endIndex(int endIndex);
    //function to get variable startIndex
    int get_startIndex();

    //function to get variable endIndex
    int get_endIndex();


protected:

private:
    RNA_Type type;
    int startIndex;
    int endIndex;
};

#endif // RNA_H

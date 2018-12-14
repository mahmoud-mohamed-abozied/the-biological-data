#ifndef DNA_H
#define DNA_H
#include<iostream>
#include "RNA.h"
#include "Sequence.h"
using namespace std;

class RNA;
enum DNA_Type {promoter, motif, tail, noncoding};
class DNA : public Sequence
{
public:
    // constructors and destructor
    DNA();
    DNA(char * seq, DNA_Type atype);
    DNA(DNA& rhs);
    ~DNA();

    // function printing DNA sequence information to user
    void Print();

    // function to convert the DNA sequence to RNA sequence
    // It starts by building the complementary_strand of the current
    // DNA sequence (starting from the startIndex to the endIndex), then,
    // it builds the RNA corresponding to that complementary_strand.
    RNA ConvertToRNA();

    // function to build the second strand/pair of DNA sequence
    // To build a complementary_strand (starting from the startIndex to
    // the endIndex), convert each A to T, each T to A, each C to G, and
    // each G to C. Then reverse the resulting sequence.
    void BuildComplementaryStrand();

    // function to  allow accessing to private variable startIndex
    void set_startIndex(int startIndex);

    // function to  allow accessing to private variable endIndex
    void set_endIndex(int endIndex);

    //function to get variable startIndex
    int get_startIndex();

    //function to get variable endIndex
    int get_endIndex();

    //function to overload operator +
    friend DNA operator+ (DNA d1, DNA d2);

    //function to overload operator ==
    friend bool operator== (DNA d1, DNA d2);

    //function to overload operator !=
    friend bool operator!= (DNA d1, DNA d2);

    //function to overload operator >>
    friend istream& operator>> (istream& in, DNA& d);

    //function to overload operator <<
    friend ostream& operator<< (ostream& out, DNA& d);

protected:

private:
    DNA_Type type;
    DNA * complementary_strand;
    int startIndex;
    int endIndex;
};

#endif // DNA_H

#include <iostream>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "Protein.h"
#include "CodonsTable.h"

using namespace std;
/*
cout<<"enter the seq"<<endl;
    char *str1 =new char[5];
    for(int i=0 ; i<5 ; i++)
    {
        cin>>str1[i];
    }*/

int main()
{
    while(int x=1)
    {
        int choice;
        cout<<"Enter your choice"<<endl
            <<"1-Display the first strand of DNA "<<endl
            <<"2-Display the second strand of DNA (complementary_strand) "<<endl
            <<"3-Convert DNA to RNA sequence"<<endl
            <<"4-Display th RNA sequence"<<endl
            <<"5-convert RNA to DNA sequence"<<endl;
        cin>>choice;



        if(choice==1)
        {
            int length;
            cout<<"Please, Enter the length of DNA : ";
            cin>>length;

            cout<<"Enter the seq"<<endl;
            char *str =new char[length];
            for(int i=0 ; i<length ; i++)
            {
                try
                {
                    cin>>str[i];
                }
                catch(string s)
                {
                    cout<<s<<endl;
                }
            }
            DNA d(str,tail);
            int start_index, end_index;
            cout<<"Please enter start index"<<endl;
            cin>>start_index;
            d.set_startIndex(start_index);
            cout<<"Please enter end index"<<endl;
            cin>>end_index;
            d.set_endIndex(end_index);
            d.Print();

        }

        if(choice==2)
        {
            int length;
            cout<<"Please, Enter the length of DNA : ";
            cin>>length;
            cout<<"Enter the seq"<<endl;
            char *str =new char[length];
            for(int i=0 ; i<length ; i++)
            {
                cin>>str[i];
            }
            DNA d(str,tail);
            int start_index, end_index;
            cout<<"Please enter start index"<<endl;
            cin>>start_index;
            d.set_startIndex(start_index);
            cout<<"Please enter end index"<<endl;
            cin>>end_index;
            d.set_endIndex(end_index);
            d.BuildComplementaryStrand();

        }

        if(choice==3)
        {
            int length;
            cout<<"Please, Enter the length of DNA : ";
            cin>>length;
            cout<<"Enter the DNA seq"<<endl;
            char *str =new char[length];
            for(int i=0 ; i<length ; i++)
            {
                cin>>str[i];
            }
            DNA d(str,tail);
            int start_index, end_index;
            cout<<"Please enter start index"<<endl;
            cin>>start_index;
            d.set_startIndex(start_index);
            cout<<"Please enter end index"<<endl;
            cin>>end_index;
            d.set_endIndex(end_index);
            d.ConvertToRNA();

        }

        if(choice==4)
        {
            int length;
            cout<<"Please, Enter the length of DNA : ";
            cin>>length;
            cout<<"Enter the RNA seq"<<endl;
            char *str =new char[length];
            for(int i=0 ; i<length ; i++)
            {
                cin>>str[i];
            }
            RNA r(str,mRNA);
            int start_index, end_index;
            cout<<"Please enter start index"<<endl;
            cin>>start_index;
            r.set_startIndex(start_index);
            cout<<"Please enter end index"<<endl;
            cin>>end_index;
            r.set_endIndex(end_index);
            r.Print();

        }

        if(choice==5)
        {
            int length;
            cout<<"Please, Enter the length of DNA : ";
            cin>>length;
            cout<<"Enter the RNA seq"<<endl;
            char *str =new char[length];
            for(int i=0 ; i<length ; i++)
            {
                cin>>str[i];
            }
            RNA r(str,mRNA);
            int start_index, end_index;
            cout<<"Please enter start index"<<endl;
            cin>>start_index;
            r.set_startIndex(start_index);
            cout<<"Please enter end index"<<endl;
            cin>>end_index;
            r.set_endIndex(end_index);
            r.ConvertToDNA();

        }


    if ( choice == 6)
    {

        Codon c1;
        CodonsTable c;
        c.LoadCodonsFromFile("RNA_codon_table.txt");
        int x ;
        cout << "1- If Your Want AminoAcid Function.\n";
        cout << "2- IF you Want SetCodon Function.";
        cin>> x ;

        if (x == 1)
        {
            char Value[3];
            cout << "Enter Your Value from Three Char :";
            for(int i = 0 ; i < 3 ; i++)
            {
                cin >> Value[i];
            }
            c1 = c.getAminoAcid(Value);
            cout <<endl <<"The AminoAcid is : "<< c1.AminoAcid;
        }
        else if  (x == 2)
        {
            char Value[3];
            cout << "Enter Your Value from Three Char :";
            for(int i = 0 ; i < 3 ; i++)
            {
                cin >> Value[i];
            }
            char AminoAcid_char;
            cout << "Enter Your AminoAcid char :";
            cin >> AminoAcid_char;
            int index;
            cout << "Enter index to store it in array Codon :";
            cin >> index;
            c.setCodon(Value, AminoAcid_char, index);
            cout << "Success .";
        }
    }
    }

    return 0;
}

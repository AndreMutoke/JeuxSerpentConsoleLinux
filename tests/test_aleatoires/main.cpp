#include <iostream>

using namespace std;

int aleaNumber(int borne)
{
    srand((unsigned int)time(0));
    int  valeur = rand()%borne ;
}

int main()
{
   
    for   (int  i  =  0;  i   <  10;  i++)
    {
        int  valeur = rand()%6   +1;
        cout<< "valeur rand est " << valeur << endl;
    }
    return 0;
}


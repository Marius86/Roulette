//
//  Roulette.cpp
//  
//
//  Created by Marius Andreassen on 08/01/14.
//
//

#include "Roulette.h"               //trenger jeg denne linjen??
#include <iostream>
#include <cstdlib>                  //rand //atoi
#include <vector>

using namespace std;                // for at den skal finne cout

int main(int argc, char* argv[])
{
    if (argc != 2)                  // kontrollerer at det er sendt med ett parameter
    {
        cout << "Send med ett parameter!" << endl;
        return 0;
    }
    
    cout << endl << "Roulette\n" << endl;

    cout << "Parameter sendt med fra terminal: " << argv[1] << endl;
    
    int n = atoi(argv[1]);          //antall trekninger. atoi() konverterer til int
    int teller = 0;
    int sekvensteller = 0;
    int temp = -1;
    int forrige = -1;

    int farge [2] = {};
    vector<int> sekvensVector(10, 0); // {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    
    srand (time(NULL));             //initialize random seed
    temp = rand() % 2;
    
    farge[temp]++;
    
    teller++;
    sekvensteller++;
    
    while(teller < n)
    {
        forrige = temp;
        temp = rand() % 2;
        farge[temp]++;
        teller++;
        
        if(forrige == temp)         //hvis de er like økes sekvenstelleren
        {
            sekvensteller++;
            
            if(teller == n)         //hvis det er siste trekning må sekvens vector oppdatteres
            {
                sekvensVector[sekvensteller-1]++;
            }
        }
        else                        //hvis de ikke er like skal sekvensen lagres
        {
            sekvensVector[sekvensteller-1]++;
            
            sekvensteller = 1;      //sekvenstelleren starter på nytt
            
            if(teller == n)         //var det siste tall må siste sekvens også lagres
            {
                sekvensVector[sekvensteller-1]++;
            }
        }
    }
    
    cout << "Sekvenser:" << endl;
    for(int i = 0; i < n; i++)
    {
        if(sekvensVector[i] != 0)
            cout << (i+1) << "x: " << sekvensVector[i] << endl;
    }
    
    cout << "Sorte: " << farge[0] << endl << "Røde: " << farge[1] << endl;
}

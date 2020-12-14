#include<bits/stdc++.h>
using namespace std;

char* addParity(int bitsq_length, char* bitsq){
    
    char static pariadded_array[1000000]={}; //assigning null to all positions of the array
    int no_of_parities,pos,position,count = 0;
    
    while(bitsq_length > (int)pow(2,pos)-(pos+1)) { no_of_parities++;  pos++; }  // checking the number of parity positions using the ineqality

    int parityPos = 0; int nonarityPos =0;
    for(int i=0;i < no_of_parities + bitsq_length; i++)
    {
        if(i==((int)pow(2,parityPos)-1))
        {   pariadded_array[i] = '0';  // assigning zeros to the indexes of powers of two
            parityPos++; }
        else
        {   pariadded_array[i]=bitsq[nonarityPos];
            nonarityPos++;   }
    }
    
// checking even parity and assigning the relevent bit to the indexes of powers of two
    for(int i=0;i<no_of_parities;i++) {
    position = (int)pow(2,i);
    int s,count = 0;
    s = position-1;
    while(s < no_of_parities + bitsq_length)
    {
        for(int j = s; j < s+position; j++)
        {     if(pariadded_array[j] == '1')
                {count++; }
        }
        s = s + 2*position;    
    }
        
    if(count%2 == 0)
        pariadded_array[position-1] = '0';
    else
        pariadded_array[position-1] = '1'; 
    }
    return pariadded_array;
}



/* This code has three parts
      1. Identifying whether the sequence has errors
      2. Navigating to the error, correcting them & removing the parity bits to get the original sequence
      3. If there is no error removing the parity bits to get the original sequence
*/

char* parityRemove(int no_of_extra, int ltot,char* encyptedRedBitsq){
    char static rem[1000000]={};
    int ss,sss,error,pos_of_orisig, pos_of_redsig = 0;
    
// checking whether there are any errors
    for(int i=0;i<no_of_extra;i++)
    {   int count,value = 0;
        int position = (int)pow(2,i);
        ss=position-1;
        while(ss<ltot)
        {
            for(sss = ss; sss < ss+position; sss++)
            {
                if(encyptedRedBitsq[sss] == '1')
                    count++;   }
            ss = ss + 2*position;
        }
        if(count%2 != 0) { error+=position; }
    }

// navigating to the errornous bits & correct them

    if (error != 0){
        printf("Error detected and corrected!\n");
        if (encyptedRedBitsq[error - 1] == '1') {encyptedRedBitsq[error - 1] = '0';}
        else {encyptedRedBitsq[error - 1] = '1';}
        for(int i=0;i < ltot; i++)
        {
        if(i==((int)pow(2,pos_of_orisig)-1))
        { pos_of_orisig++; }
        else
        {   rem[pos_of_redsig]=encyptedRedBitsq[i];
            pos_of_redsig++;}
        }}

// removing the excessive parity bits of the sequences without the errors
    else {
    for(int i=0;i < ltot; i++)
    {
        if(i==((int)pow(2,pos_of_orisig)-1))
        { pos_of_orisig++; }
        else
        {   rem[pos_of_redsig]=encyptedRedBitsq[i];
            pos_of_redsig++;} 
    }}
    return rem;
}
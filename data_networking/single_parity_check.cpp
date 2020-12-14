/* to check if the given message has error or not considering last bit as parity bit and for even parity */

#include<bits/stdc++.h>
using namespace std;

int convertBinaryToDecimal(int n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}

bool get_parity(int n)
{
    bool parity =0;
    while (n)
    {
        parity=!parity;
        n=n&(n-1);
    }
    return parity;
}

int main()
{
    int n;
    cin>>n;
    int curr_parity=n&1;
    n=convertBinaryToDecimal(n-curr_parity);
    int actual_parity=get_parity(n);
    cout<<"message has "<<(curr_parity==actual_parity?"no error":"error");

    return 0;
}
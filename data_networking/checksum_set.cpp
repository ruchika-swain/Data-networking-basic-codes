/* Take 2 binary input strings.
Do their binary sum to find out the checksum which will be sent to the destination or to the receiver.
In binary sum there are 6 cases:-
If both bits are 0 and carry is 0, sum=0 and carry=0
If both bits are 0 and carry is 1,sum=1 and carry=0
If both bits are 1 and carry is 0,sum=0 and carry=1
If both bits are 1 and carry is 1,sum=1 and carry=1
If either bit is 1 and carry is 0,sum=1 and carry=0
If either bit is 1 and carry is 1,sum=0 and carry=1
While doing the addition we have to add the binary strings from rightmost end i.e LSB to MSB.
When binary sum is done 1’s complement of it is taken by reversing 1’s to 0’s and vice versa.
The resulting 1’s complement is the Checksum.
Stop. */

#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    char a[20],b[20];
    char sum[20],complement[20];
    int i;
    
	cout<<"Enter first binary string\n";
    cin>>a;
    cout<<"Enter second binary string\n";
    cin>>b;
    
	if(strlen(a)==strlen(b))
    {
        char carry='0';
        int length=strlen(a);
        
		for(i=length-1;i>=0;i--)
        {
            if(a[i]=='0' && b[i]=='0' && carry=='0')
            {
                sum[i]='0';
                carry='0';
            }
            else if(a[i]=='0' && b[i]=='0' && carry=='1')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='0' && b[i]=='1' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='0')
            {
                sum[i]='1';
                carry='0';
 
            }
            else if(a[i]=='1' && b[i]=='0' && carry=='1')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='0')
            {
                sum[i]='0';
                carry='1';
 
            }
            else if(a[i]=='1' && b[i]=='1' && carry=='1')
            {
                sum[i]='1';
                carry='1';
 
            }
            else
                break;
        }
        cout<<"\nSum="<<carry<<sum;
 
        for(i=0;i<length;i++)
        {
            if(sum[i]=='0')
                complement[i]='1';
            else
                complement[i]='0';
        }
        
		if(carry=='1')
            carry='0';
        else
            carry='1';
     
	    cout<<"\nChecksum="<<carry<<complement;
    }
    else
        cout<<"\nWrong input strings";
        
    return 0;
}
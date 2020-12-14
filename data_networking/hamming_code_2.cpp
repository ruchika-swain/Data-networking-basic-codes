//this is for 7 bit message transfer [4 bits of message and 3 bits of parity]

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[10],b[10],c1,c2,c3;
  cout<<"Enter the 4 data bits"<<endl;
  cin>>a[3];
  cin>>a[5];
  cin>>a[6];
  cin>>a[7];
  a[1]=a[3]^a[5]^a[7];
  a[2]=a[3]^a[6]^a[7];
  a[4]=a[5]^a[6]^a[7];
  // print the data
  for(int i=1;i<8;i++){
      cout<<a[i]<<" ";
  }
  cout<<endl<<"Enter the 7 bits"<<endl;
    for(int i=1;i<8;i++){
        cin>>b[i];
    }
    c1=b[1]^b[3]^b[5]^b[7];
    c2=b[2]^b[3]^b[6]^b[7];
    c3=b[4]^b[5]^b[6]^b[7];
    //converting into decimal
    int p=c1*1+c2*2+c3*4;
    if(p==0){
        cout<<"there is no error in the code"<<endl;
    }
    else {
        cout<<"there is error in the code at position p"<<p<<endl;
        if(b[p]==0){
            b[p]=1;
        }
        else {
            b[p]=0;
        }
        //no error code
        for(int i=1;i<8;i++){
            cout<<b[i]<<" ";
        }
    }
return 0;
}

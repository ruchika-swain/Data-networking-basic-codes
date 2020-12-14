// C++ program to find parity 
// of an integer 
# include <iostream> 
# define bool int 
using namespace std; 

// Function to get parity of number n. It returns 1 
// if n has odd parity, and returns 0 if n has even 
// parity 
int findParity(int n, char ch) {
   int count = 0;
   int temp = n;

   while (temp> 0) {
      if(temp% 10 == 1)    //when LSb is 1, increase count
         count++;
      temp = temp/ 10;    //right shift number by 1 bit
   }  
   int x = 0; 

   if(ch == 'A')  {
       x = (count)%2 ;
   }  
   else{
       x = (count+1)%2 ;
   } 
   return x;
   
}

int main() {
    char ch;
   int n, m;
   cout << "Enter whether" << endl << "A) Even Parity" << endl << "B) Odd Parity" << endl;
    cin >> ch;
   cout << "Enter a number to be sent: "; 
   cin >>n;
   cout << "Parity of " << n << " is " << findParity(n, ch);
   cout << "Enter the code received by the receiver";
   cin >> m;
   cout << "Parity of " << m << " is " << findParity(m,ch);
   if(findParity(n,ch) == findParity(m,ch)){
       cout << "The parity check succeeded" << endl;
   }
   else{
        cout << "The parity check says wrong data received" << endl;
   }
}

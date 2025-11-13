#include <iostream>
using namespace std;
int recfibo(int n)
{
    if(n<=1)
      return n;
      
      
      return recfibo(n-1)+recfibo(n-2);
     
}

int main() {
    
    int nf,t,t1=0,t2=1;
    cout<<"For Non-Recursive\n";
    cout<<"ENter the terms for not-rec\n";
    cin>>nf;
    for(int i=0;i<nf;i++)
    {
        cout<<t1<<" ";
      t=t1+t2;
      t1=t2;
      t2=t;
    }
    
    
    int n;
cout<<"\n\nFibo series\n";
cout<<"Enter the N \n";
cin>>n;
for(int i=0;i<n;i++){
cout<<recfibo(i)<<" ";
}

    return 0;
}

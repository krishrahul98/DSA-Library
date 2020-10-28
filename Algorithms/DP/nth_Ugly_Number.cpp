/*Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
Given a number n, the task is to find n’th Ugly number.*/

#include <iostream>
using namespace std;

int Div(int x, int y){
    while(x%y==0){
        x=x/y;
    }
    return x;
}

int uglyNo(int n){
    int i=1;
    int count=1;

    while(n>count){
        i++;
        int p=i;
        p=Div(p,2);
        p=Div(p,3);
        p=Div(p,5);
        if(p==1){
            count++;
        }
    }
    return i;
}
int main(){
    int n;
    cout<<"Enter the no to find it's nth ugly No"<<endl;
    cin>>n;
    cout<<uglyNo(n);
    return 0;
}

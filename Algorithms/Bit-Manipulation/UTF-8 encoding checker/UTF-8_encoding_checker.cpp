#include<bits/stdc++.h>
using namespace std;
bool byteCompare(bitset<8> a, string b, string c){
    //Compare a and c in b digits
    return ((a & bitset<8>(b)) == bitset<8>(c));
}
int UTF8EncodingCheck(string s){

    // incomplete byte
    if((s.length() % 8) != 0)   return 1;

    // string conversion to bits
    long long n = s.length();
    bitset<8> byte[n/8];
    int count = 0;
    for(auto x : s){
        byte[count/8][7-(count%8)] = x - '0';
        ++count;
    }
    for(int i = 0; i < n/8; i++){
        // unexpected continuation byte
        if(byteCompare(byte[i], "11000000", "10000000")){    
            return 2;
        }

        //1 byte
        else if(byteCompare(byte[i], "10000000", "00000000")){
            continue;
        }

        //2 bytes
        else if(byteCompare(byte[i], "11100000", "11000000")){
            // string ends before end of character
            if(i == n / 8){
                return 3;
            }

            // non-continuation byte
            else if(!byteCompare(byte[i+1], "11000000", "10000000")){
                return 4;
            }

            // overlong
            else if(byteCompare(byte[i], "00011110", "00000000")){
                return 5;
            }

            else{
                i++;
            }
        }

        // 3 bytes
        else if(byteCompare(byte[i], "11110000", "11100000")){
            // string ends before end of character
            if(i >= (n / 8) - 1){
                return 3;
            }

            // non-continuation bytes
            else if(!byteCompare(byte[i+1], "11000000", "10000000") || !byteCompare(byte[i + 2], "11000000", "10000000")){
                return 4;
            }

            // overlong
            else if(byteCompare(byte[i], "00001111", "00000000") && byteCompare(byte[i+1], "00100000", "00000000")){
                return 5;
            }

            // invalid code points
            else if(byteCompare(byte[i], "00001111", "00001101") && byteCompare(byte[i+1], "00100000", "00100000")){
                return 6;
            }

            else{
                i += 2;
            }
        }

        // 4 bytes
        else if(byteCompare(byte[i], "11111000", "11110000")){
            // string ends before end of character
            if(i >= (n / 8) - 2){
                return 3;
            }

            // non-continuation bytes
            else if(!byteCompare(byte[i+1], "11000000", "10000000") || !byteCompare(byte[i + 2], "11000000", "10000000") || !byteCompare(byte[i + 3], "11000000", "10000000")){
                return 4;
            }

            // overlong
            else if(byteCompare(byte[i], "00000111", "00000000") && byteCompare(byte[i+1], "00110000", "00000000")){
                return 5;
            }

            // invalid code points
            else if(byteCompare(byte[i], "00000100", "00000100") && !byteCompare(byte[i], "00000011", "00000000") && !byteCompare(byte[i+1], "00000011", "00000000")){
                return 6;
            }

            else{
                i += 3;
            }
        }

        // invalid character pattern
        else{
            return 6;
        }
    }

    return 0;
}
int main(){

    // input-output
    string str;
    cin >> str;
    cout << UTF8EncodingCheck(str);

    return 0;
}
#include <iostream>
#include <stdexcept>
#include <string>
#include "mat.hpp"
#include <vector>

using namespace std;

string ariel::mat(int col, int row, char ch1, char ch2) {

    //throwing exception if the col or row is not valid
    if(col%2==0 || row%2==0 || col<=0 ||row<=0) {throw "the size of the mat is not valid";}
    
    //declaring variables
    std::string ans;
    int c=col;
    int r=row;
    int i=0;
    char ch=ch1;
    float mid = float(c)/2.0;
    //vector<vector<char>> m( row , vector<char> (col));
    char m[row][col];
    
    //iterating over all the mat, and assigning the right char
    while(i <= mid){
        for(int j=i; j<r; j++){
            m[j][i]=ch;
        }
        if(col==1) {break;}

        for(int j=i; j<c-1; j++){
            m[i][j]=ch;
        }
        for(int j=row-i-1; j>=i; j--){
            m[j][col-i-1]=ch;
        }
        for(int j=col-i-1; j>=i; j--){
            m[row-i-1][j]=ch;
        }

        r--;
        c--;
        i++;
        
        //changing to the other char
        if(ch==ch1){ ch=ch2;}
        else {ch=ch1;}
    }
    
    for(int i=0; i<row; i++){
       for(int j=0; j<col; j++){
       ans=ans+string(1,m[i][j]);
      }
      if(i<row-1)ans=ans+"\n";
      }
    

    return ans;
}

// int main()
// {
//     string s = ariel::mat(13, 5, '@', '-'); 
//     cout<<s<<endl;
//     return 0;
// }


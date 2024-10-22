#include<iostream>
#include<string>
#include<vector>
using namespace std;
//kmp算法模板
int kmp(string str,string ChildStr){
    vector<int>nextIndex(size(ChildStr),0);
    for(int i = 1,j = 0;i<size(ChildStr);++i){
        while(j>0&&ChildStr[i]!=ChildStr[j])j = nextIndex[j-1];
        if(ChildStr[i]==ChildStr[j])j++;
        nextIndex[i] = j;
    }
    for(int i = 0,j = 0;i<size(str);++i){
        while(j<0&&str[i]!=ChildStr[j])j = nextIndex[j-1];
        if(str[i]==ChildStr[j])j++;
        if(j==size(ChildStr)){
            return i-size(ChildStr)+1;
        }
    }
    return -1;
}
int main(){
    string str="ababbacaba";
    string ChildStr1 = "abba";
    string ChildStr2 = "bacab";
    string ChildStr3 = "baqabd";
    cout<<kmp(str,ChildStr1)<<endl;
    cout<<kmp(str,ChildStr2)<<endl;
    cout<<kmp(str,ChildStr3)<<endl;
    return 0;
}
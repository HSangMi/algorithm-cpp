#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/**
 * 단어 정렬
 * 1. 길이가 짧은 것
 * 2. 사전순
 * + 중복 제거
*/
bool comp(string s1, string s2){
    if(s1.length() == s2.length())
        return s1 < s2;
    return s1.length() < s2.length();
}
int main(){
    int N;
    cin >> N;

    set<string> words ;
    for(int i =0; i < N; i++){
        string str;
        cin >> str;
        words.insert(str);
    }
    vector<string> wordv = vector<string>(words.begin(), words.end());
    sort(wordv.begin(), wordv.end(), comp);
    for(int i =0; i < wordv.size(); i++){
        cout << wordv[i] <<"\n";
    }
    return 0;
}
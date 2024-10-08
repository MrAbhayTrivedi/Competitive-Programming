/*
C1. Message Transmission Error (easy version)
time limit per test2 seconds
memory limit per test256 megabytes
This is a simplified version of the problem. It differs from the difficult one only in its constraints.

At the Berland State University, the local network between servers does not always operate without errors. When transmitting two identical messages consecutively, an error may occur, resulting in the two messages merging into one. In this merging, the end of the first message coincides with the beginning of the second. Of course, the merging can only occur at identical characters. The length of the merging must be a positive number less than the length of the message text.

For example, when transmitting two messages "abrakadabra" consecutively, it is possible that it will be transmitted with the described type of error, resulting in a message like "abrakadabrabrakadabra" or "abrakadabrakadabra' (in the first case, the merging occurred at one character, and in the second case, at four).

Given the received message t, determine if it is possible that this is the result of an error of the described type in the operation of the local network, and if so, determine a possible value of s.

A situation where two messages completely overlap each other should not be considered an error. For example, if the received message is "abcd", it should be considered that there is no error in it. Similarly, simply appending one message after another is not a sign of an error. For instance, if the received message is "abcabc", it should also be considered that there is no error in it.

Input
The input consists of a single non-empty string t, consisting of lowercase letters of the Latin alphabet. The length of the string t does not exceed 100 characters.

Output
If the message t cannot contain an error, output "NO" (without quotes) in a single line of output.

Otherwise, in the first line, output "YES" (without quotes), and in the next line, output the string s — a possible message that could have led to the error. If there are multiple possible answers, any of them is acceptable.

Examples
Input
abrakadabrabrakadabra
Output
YES
abrakadabra
Input
acacacaca
Output
YES
acaca
Input
abcabc
Output
NO
Input
abababab
Output
YES
ababab
Input
tatbt
Output
NO
Note
In the second example, a suitable answer could also be the string "acacaca".
*/
#include<bits/stdc++.h>
using namespace std;

void f(){
  string s; cin>>s;
  unordered_map<string,int> m;
  int n = s.length();
  string x = "";
  for(int i = 0; i < n; i++){
    x += s[i];
    m[x] = 1;
  }
  string y = "";
  for(int i = n - 1; i >= 0; i--){
    y = s[i] + y;
    if(y.length() > n / 2 && y.length() != n && m[y]){
      cout<<"YES"<<endl;
      cout<<y;
      return;
    }
  }
  cout<<"NO";
}

int main(){
    f();
    return 0;
}
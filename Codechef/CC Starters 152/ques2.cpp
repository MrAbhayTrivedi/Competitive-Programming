/*
Winning World Finals
Chef's team is participating in the ICPC World Finals.
The contest is 300 minutes long, of which M minutes have passed already Chef's team has only one problem left to solve. Their time penalty so far is P.

At any minute strictly before the 300-th, the team can make a submission When making a submission at minute X, one of two things can happen:

1. The submission is correct.
    In this case, X (the time of the submission) gets added to the team's time penalty. No more submissions can be made after this.
2. The submission is wrong.
    In this case, 20 gets added to the team's time penalty. The team must then wait at least one minute before making the next submission

Chef believes that as long as his team solves the problem and has a final penalty of ≤1000, they will place first.

Find the maximum number of wrong submissions that Chef's team can make, while still ensuring that they win the contest.
The first submission can be made immediately at minute M.

Input Format
The first line of input will contain a single integer T, denoting the number of test cases 
The first and only line of each test case will contain two space-separated integers M and P — the number of minutes that have already passed, and the team's initial penalty 

Output Format
For each test case, output on a new line the maximum number of wrong submissions Chef can make while still winning the contest.

Constraints
1≤T≤10^4
0≤M<300
0≤P≤700

Sample 1:
Input
4
294 40
10 598
0 0
299 678

Output
5
18
47
0
Explanation:
Test case 1: Chef can make wrong submissions at minutes 294,295,296,297,298, and then a correct submission at minute 299 
This will make the penalty 40+20×5+299=439, which is ≤1000 
Note that Chef has to wait for a minute after making a wrong submission, and also must make a correct submission before the 300-th minute in order to solve the problem.

Test case 2: Chef can make 18 wrong submissions, at minutes 10,11,12,…,27.
This will make his penalty 598+18×20=958.
He can then make a correct submission at minute 35, adding 35 to the penalty and making it 993, which is good enough.

Test case 4: Since it's the last minute of the contest, Chef has no choice but to make a correct submission.
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * Solves the problem of finding the maximum number of wrong submissions that Chef's team can make while still ensuring they win the contest.
 * The first submission can be made immediately at minute M.
 * The team's initial penalty is P.
 * Chef believes that as long as the final penalty is <= 1000, they will place first.
 * 
 * @param m The number of minutes that have already passed.
 * @param p The team's initial penalty.
 * @return The maximum number of wrong submissions Chef can make while still winning the contest.
 */
int getMaxWrongSubmissions(int m, int p) {
    int w = (1000 - m - p) / 21;
    return min(299 - m, w);
}
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int m,p;
        cin>>m>>p;
        //Solving the inequality
        //P+(W*20)+(M+W)<=1000
        //W<=((1000-M-P)/21)
        int w=(1000-m-p)/21;
        //Also W<=299-M
        //So the answer is min(299-M,W)
        cout<<min(299-m,w)<<endl;
    }
}

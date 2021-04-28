/*
Author: Lucas Cardoso dos Santos
Date: 28/04/2021
URL: https://www.urionlinejudge.com.br/judge/en/problems/view/3042

Text:
Santa Claus loves mobile games, especially if they have a Christmas theme. Santa
has just installed a new game for his smartphone. The game is basically a 
character running endlessly on a track consisting of three lanes, having to 
change lanes to deflect obstacles (Christmas trees) appearing on the way. The 
character always starts a game on the middle lane. Santa needs tapping once on 
the left side of the smartphone screen so the character moves a lane to the 
left, or a touch on the right side to move a lane to the right. That is, if the
character is on the leftmost lane, he needs 2 touches on the right side of the
screen to get to the rightmost lane.
Although it sounds easy, Santa is having a hard time staying alive for a long 
time. One thing he noticed during the game is that whenever there are obstacles, 
only one track is free to cross, while the other two have Christmas trees 
blocking paths. As you guys are great friends, he asked you to write a program 
that minimizes the number of touches on the smartphone, so that he can walk M 
meters through the game.

Input
The input consists of several test cases. The first line of a test case contains 
an integer M (0 ≤ M < 10000), representing the distance, in meters, that Santa 
wants to play. The next M lines contain 3 integers L, C, R each, representing 
the left, center and right lane, respectively where 0 ≤ L,C,R ≤ 1. The lanes 
contain only the number 0, if there is no obstacle, and the number 1, if there 
is a Christmas tree on the lane. It is guaranteed at least one lane will be free 
for crossing. Assume Santa can always play fast enough to go left to right, or 
right to left from one entrance to the next. The end of the input is indicated 
by a line containing only one zero.

Output
For each test case, your program should print a single line containing the 
fewest touches on the smartphone Santa must make to travel the desired distance 
by deflecting all obstacles.

Input Sample                            Output Sample
5                                       2
0 0 0
1 1 0
0 0 0
0 0 0
1 0 1
0
*/

#include <bits/stdc++.h>

#define LEFT 0
#define CENTER 1
#define RIGHT 2

using namespace std;

int findVoidLane(int lanes[3]) {
    if (lanes[LEFT] == 0) {
        return LEFT;
    }
    else if (lanes[CENTER] == 0) {
        return CENTER;
    }
    else {
        return RIGHT;
    }
}

int main () {
    int meters; // How much meters Santa wants to run;

    cin >> meters;

    while (meters > 0) {
        int moves = 0; // How much moves Santa must do;
        int santaLane = CENTER; // Lane Santa currently is
        int lanes[3] = {0, 0, 0}; // info about left, center and right lanes

        for (int i = 0; i < meters; i++) {
            cin >> lanes[LEFT] >> lanes[CENTER] >> lanes[RIGHT];

            if (lanes[santaLane] == 1) {
                int newLane = findVoidLane(lanes);
                moves += abs(santaLane - newLane);
                santaLane = newLane;
            }
        }

        cout << moves << endl;

        cin >> meters;
    }

    return 0;
}
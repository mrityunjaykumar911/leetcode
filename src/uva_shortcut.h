//
// Created by mrityunjay kumar on 2019-06-01.
//

#ifndef SHUVA_UVA_SHORTCUT_H
#define SHUVA_UVA_SHORTCUT_H

#include "../common.h"

// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;


// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B

//memset(dist, MEMSET_INF, sizeof dist); // useful to initialize shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); // useful to clear array of integers

/*
 * SH => Steven Halim
 *
 * Some useful Abbreviations from SH UVA
 */

/*
ACM : Association of Computing Machinery
CS : Computer Science
ICPC : International Collegiate Programming Contest
IOI : International Olympiad in Informatics
LA : Live Archive [11]
OJ : Online Judge
PE : Presentation Error
UVa : University of Valladolid [17]
WF : World Finals

AC : Accepted
TLE : Time Limit Exceeded
WA : Wrong Answer


APSP : All-Pairs Shortest Paths
AVL : Adelson-Velskii Landis (BST)
BNF : Backus Naur Form
BFS : Breadth First Search
BST : Binary Search Tree
CC : Coin Change
CCW : Counter ClockWise
DAG : Directed Acyclic Graph
DAT : Direct Addressing Table
D&C : Divide and Conquer
DFS : Depth First Search
DP : Dynamic Programming
ED : Edit Distance
GCD : Greatest Common Divisor
LCM : Lowest Common Ancestor
LCM : Lowest Common Multiple
LCS : Longest Common Subsequence
LIS : Longest Increasing Subsequence
MCM : Matrix Chain Multiplication
MCMF : Min-Cost Max-Flow
MLE : Memory Limit Exceeded
MST : Minimum Spanning Tree
MWIS : Maximum Weighted Independent Set
RB : Red-Black (BST)
RMQ : Range Minimum Query
RSQ : Range Sum Query
RTE : Run Time Error
SSSP : Single-Source Shortest Paths

*/


#endif //SHUVA_UVA_SHORTCUT_H

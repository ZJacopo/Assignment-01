//this file is the header that resumes all funcions
#ifndef ASSIG_1_FCTS_H
#define ASSIG_1_FCTS_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;

vector<int> string_lengths(const vector<string>& v);
string shortest_string(const vector<string>& v);
string longest_string(const vector<string>& v);
void print(const vector<string>& v);
void print(const vector<int>& v);
string abc(const string a, const string b);
string alpha_first_string(const vector<string>& v);
string cba(const string a, const string b);
string alpha_last_string(const vector<string>& v);

#endif


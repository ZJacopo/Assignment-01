//In this file are resumed all functions for this assignment, so we have all in just one header
//the next lines are in the header
//#include <iostream>
//using std::vector;
//using std::string;
//using std::cout;

#include "assig_1_fcts.h"

using std::cout;//is used in print fct

///////////////////////////////////
//-----------LONGEST-------------//
///////////////////////////////////
//this fct returns the longest word in the vectror or a string containing all the words with the same (maximum in the vector) length
string longest_string(const vector<string>& v){

	//in case of a void vector
	if(v.begin() == v.end()){return "this vector contains nothing \n";}

	//if the vector contains something we have to find the longest word and if there are multiple of them (with the same size)
        vector<string>::const_iterator pos; //const is because this iterator doesn't change the vector
	bool x = 0; //this bool is used to divide the cases: only one longer than the other or more at the same length (which is also the maximum)

        string str_max = v.front();

        for(pos = v.begin()+1; pos != v.end(); ++pos){

	        if((*pos).length() > str_max.length()) {str_max = *pos; x = 0;} //str_max saves the longest word and x (=0) registers that there is only one
        	else if((*pos).length() == str_max.length()){x = 1;}//the length is already saved in str_max so if there is one with the same size we register this information for the future in x (=1)
	}
        if(x == 0){return str_max;}//if x==0 it means that there is only one word longer than the other
	
	string ext = "";

	for(pos = v.begin(); pos != v.end(); ++pos){

		if((*pos).length() == str_max.length()) {ext = ext + *pos + " ";}
	}
	return ext;
}

//////////////////////////////////
//----------SHORTEST------------//
//////////////////////////////////
//this fct returns the shortest word in the vector or a string with all the shortest words
string shortest_string(const vector<string>& v){

	if(v.begin() == v.end()){return "this vector is void \n";}

	//if the vector contains something we have to find the longest word and if there are multiple of them (with the same size)
        vector<string>::const_iterator pos; //const is because this iterator doesn't change the vector
	bool x = 0; //this bool is used to divide the cases: only one longer than the other or more at the same length (which is also the maximum)

        string str_min = v.front();

        for(pos = v.begin()+1; pos != v.end(); ++pos){

		if((*pos).length() < str_min.length()) {str_min = *pos; x = 0;} //---------HERE is the only real difference between this fct and longest
        	else if((*pos).length() == str_min.length()) {x = 1;}//the length is already saved in str_max so if there is one with the same size we register this information for the future in x (=1)
	}
        if(x == 0){return str_min;}//if x==0 it means that there is only one word longer than the other
	
	string ext = "";

	for(pos = v.begin(); pos != v.end(); ++pos){

		if((*pos).length() == str_min.length()) {ext = ext + *pos + " ";}
	}
	return ext;

}

/////////////////////////////////////////
//--------PRINT_VECTOR<STR>------------//
/////////////////////////////////////////
//this fct print all the strings in a vector in order of position
void print(const vector<string>& v){

	//in case of a void vector
	if(v.begin() == v.end()) {cout<<"this vector is void \n";}

        vector<string>::const_iterator pos;

        for(pos = v.begin(); pos != v.end(); ++pos)
	        cout<<*pos<<" ";

        cout<<"\n";
}

////////////////////////////////////////
//--------PRINT_VECTOR<INT>-----------//
////////////////////////////////////////
//this fct prints all the integers in a vector in order of position
void print(const vector<int>& v){

	//in case of a void vector
	if(v.begin() == v.end()) {cout<<"this vector contains nothing \n";}

        vector<int>::const_iterator pos;

        for(pos = v.begin(); pos != v.end(); ++pos)
                cout<<*pos<<" ";

        cout<<"\n";
}

////////////////////////////////////////
//-------STRING_LENGTH----------------//
////////////////////////////////////////
//this fct returns a vector with the length of all the strings in the vector it is applied, position by position
vector<int> string_lengths(const vector<string>& v){

        vector<string>::const_iterator pos;
        vector<int> vct;

        for(pos = v.begin(); pos != v.end(); ++pos){

                vct.push_back(static_cast<int>((*pos).length()));
        }
        return vct;
}

////////////////////////////////////////
//----------ABC-----------------------//
////////////////////////////////////////
//this is an helper fct, it receives two strings and returns the one that comes first 
string abc(const string a, const string b){
	//it initialize an answer
	int size = a.length();
	string str_first = a;
	//here it searches which is shortest because if they are equal the shortest comes first
	if(b.length() < a.length()) {size = b.length(); str_first = b;}
	//in this for cycle the fct searches letter by letter which is first
	//if it finds a difference it returns the word with the i-th smallest letter
	for(int i = 0; i < size; ++i){
		if(a.at(i) < b.at(i)){return a;}
		else if(a.at(i) > b.at(i)){return b;}
	}//if it exit the for cycle it means that the two words are identical from the beginning to the end of the sortest
	 //in that case the shortest comes first 
	return str_first;
}

///////////////////////////////////////
//-------FIRST-----------------------//
///////////////////////////////////////
//this fct uses the helper fct 'abc' and returns the string that comes first in the dictionary
string alpha_first_string(const vector<string>& v){

	//in case of a void vector
	if(v.begin() == v.end()) {return "this vector contains nothing \n";}

        vector<string>::const_iterator pos;
        string str_first = v.front();

        for(pos = v.begin()+1; pos != v.end(); ++pos){
	       str_first = abc(str_first,*pos);
	}
        return str_first;
	
}

/////////////////////////////////////////
//--------------CBA--------------------//
/////////////////////////////////////////
//this is the exact copy of 'abc' but reversed so it return the last word in the dictionary
string cba(const string a, const string b){

	int size = a.length();
	string str_last = a;
	//the longest is the last if they are equal so is unnecessary to set str_last = b like the fct 'abc'
	//this passage is used only to define an end to the for cycle
	if(b.length() < a.length()){size = b.length();}
	//the only difference is in the returns but the logic is identical
	for(int i = 0; i < size; ++i){
		if(a.at(i) < b.at(i)){return b;}
		else if(a.at(i) > b.at(i)){return a;}
	}
	return str_last;
}

//////////////////////////////////////////
//----------LAST------------------------//
//////////////////////////////////////////
//this is the exact copy of 'alpha_first_..' but with diffrent name and with 'cba' fct
string alpha_last_string(const vector<string>& v){

	//in case of a void vector
	if(v.begin() == v.end()){return "this vector contains nothing \n";}

        vector<string>::const_iterator pos;
        string str_last = v.front();

        for(pos = v.begin()+1; pos != v.end(); ++pos){
	       str_last = cba(str_last,*pos);
	}
        return str_last;
	
}


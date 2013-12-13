//
//  main.cpp
//  CodeJam
//
//  Created by wang senhong on 11/12/13.
//  Copyright (c) 2013 sam. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string map[]={
    "2","22","222","3","33","333","4","44","444","5","55","555","6",
    "66","666","7","77","777","7777","8","88","888","9","99","999","9999"
};

string convert(string text){
    string ret="";
    for(int i=0;i<text.size();i++){
        string tmp;
        if(text[i]==' '){
            tmp="0";
        }else
            tmp=map[text[i]-'a'];
        if(tmp[0]==ret.back())
            ret+=(" "+tmp);
        else
            ret+=tmp;
    }
    return ret;
}
int main(int argc, const char * argv[])
{
    string input_path="/Users/senhong/CodeBag/CodeJam/T9 Spelling/C-large-practice.in";
    string output_path="/Users/senhong/CodeBag/CodeJam/T9 Spelling/spelling_output.txt";
    ifstream infile(input_path);
    ofstream outfile(output_path);
    
    if (infile.is_open() && outfile.is_open())
    {
        int cases=0;
        infile>>cases;
        infile.ignore(1);
        for(int i=0;i<cases;i++){
            string text;
            getline(infile,text);
            outfile<<"Case #"<<(i+1)<<": ";
            outfile<<convert(text)<<endl;
        }
    }
    return 0;
}

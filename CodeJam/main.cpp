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
#include <vector>

using namespace std;


int main(int argc, const char * argv[])
{
    string path="/Users/senhong/CodeBag/CodeJam/";
    string input_path=path+"";
    string output_path=path+"";
    ifstream infile(input_path);
    ofstream outfile(output_path);
    
    if (infile.is_open() && outfile.is_open())
    {
        int cases=0;
        infile>>cases;
        for(int i=0;i<cases;i++){

             outfile<<"Case #"<<(i+1)<<": ";
        }
    }else{
        cout<<"fail to open files"<<endl;
    }
    return 0;
}

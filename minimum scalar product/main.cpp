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

long long getMinProduct(vector<long long> va,vector<long long> vb){
    int n=va.size();
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    long long ret=0;
    for(int i=0;i<n;i++){
        ret+=(va[i]*vb[n-1-i]);
    }
    return ret;
}

int main(int argc, const char * argv[])
{
    string path="/Users/senhong/CodeBag/CodeJam/";
    string input_path=path+"minimum scalar product/A-large-practice.in";
    string output_path=path+"minimum scalar product/output.txt";
    
    ifstream infile(input_path);
    ofstream outfile(output_path);
    
    if (infile.is_open() && outfile.is_open())
    {
        int cases=0;
        infile>>cases;
        for(int i=0;i<cases;i++){
            int n;
            infile>>n;
            vector<long long> va(n);
            vector<long long> vb(n);
            for(int i=0;i<n;i++)
                infile>>va[i];
            for(int i=0;i<n;i++)
                infile>>vb[i];
            long long min=getMinProduct(va,vb);
            outfile<<"Case #"<<(i+1)<<": ";
            outfile<<min<<endl;
        }
    }else{
        cout<<"fail to open files"<<endl;
    }
    return 0;
}

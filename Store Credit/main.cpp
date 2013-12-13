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

typedef pair<int,int> Pair;

bool cmp(const Pair& p1,const Pair& p2){
    return p1.first<p2.first;
}
Pair getIndices(int C,vector<Pair> P){
    sort(P.begin(),P.end(),cmp);
    int i=0;
    int j=P.size()-1;
    while(true){
        int tmp=P[i].first+P[j].first;
        if(tmp==C)
            break;
        else if(tmp<C)
            i++;
        else
            j--;
    }
    if(P[i].second<P[j].second)
        return Pair(P[i].second,P[j].second);
    else
        return Pair(P[j].second,P[i].second);
}

int main(int argc, const char * argv[])
{
    
    string input_path="/Users/senhong/CodeBag/CodeJam/Store Credit/A-large-practice.in";
    string output_path="/Users/senhong/CodeBag/CodeJam/Store Credit/credit_output.txt";
    ifstream infile(input_path);
    ofstream outfile(output_path);
    
    if (infile.is_open() && outfile.is_open())
    {
        int cases=0;
        infile>>cases;
        for(int i=0;i<cases;i++){
            int C,l;
            infile>>C>>l;
            vector<Pair> P(l);
            for(int i=0;i<l;i++){
                infile>>P[i].first;
                P[i].second=i+1;
            }
            Pair indices=getIndices(C,P);
            outfile<<"Case #"<<(i+1)<<": ";
            outfile<<indices.first<<" "<<indices.second<<endl;
        }
    }else{
        cout<<"open file failed."<<endl;
    }
    return 0;
}

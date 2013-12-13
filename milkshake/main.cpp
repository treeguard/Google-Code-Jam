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

void dfs(vector<int>& flavors,const vector<vector<int> >& customers,int d,int m,int& malted,string& ret){
    if(m>=malted)
        return;
    if(d==customers.size()){
        int m=0;
        for(int i=1;i<flavors.size();i++)
            if(flavors[i]==1)
                m++;
        if(m<malted){
            malted=m;
            ret="";
            for(int i=1;i<flavors.size();i++)
                if(flavors[i]==1)
                    ret+="1 ";
                else
                    ret+="0 ";
            ret.resize(ret.size()-1); //delete the last empty space
        }
        return;
    }
    bool found=false;
    for(int i=0;i<customers[d].size() && !found;i++){
        int f=customers[d][i];
        if( (f>0 && flavors[f]==1) || (f<0 && flavors[-f]==0))
            found=true;
    }
    if(found)
        dfs(flavors,customers,d+1,m,malted,ret);
    else{
        for(int i=0;i<customers[d].size();i++){
            int f=customers[d][i];
            if(f>0 && flavors[f]==-1){
                flavors[f]=1;
                dfs(flavors,customers,d+1,m+1,malted,ret);
                flavors[f]=-1;
            }else if(f<0 && flavors[-f]==-1){
                flavors[-f]=0;
                dfs(flavors,customers,d+1,m,malted,ret);
                flavors[-f]=-1;
            }
        }
    }
}

string getPlan(int N,const vector<vector<int> >& customers){
    vector<int> flavors(N+1,-1); //based from 1
    string ret="IMPOSSIBLE";
    int malted=INT_MAX;
    int m=0;
    dfs(flavors,customers,0,m,malted,ret);
    return ret;
}
int main(int argc, const char * argv[])
{
    string path="/Users/senhong/CodeBag/CodeJam/";
    string input_path=path+"milkshake/B-large-practice.in";
    string output_path=path+"milkshake/output.txt";
    ifstream infile(input_path);
    ofstream outfile(output_path);
    
    if (infile.is_open() && outfile.is_open())
    {
        int cases=0;
        infile>>cases;
        for(int i=0;i<cases;i++){
            int N,M;
            infile>>N>>M;
            vector<vector<int> > customers(M);
            for(int i=0;i<M;i++){
                int n;
                infile>>n;
                for(int j=0;j<n;j++){
                    int f,m;
                    infile>>f>>m;
                    if(m)
                        customers[i].push_back(f);
                    else
                        customers[i].push_back(-f);
                }
            }
            string ret=getPlan(N,customers);
            outfile<<"Case #"<<(i+1)<<": ";
            outfile<<ret<<endl;
            cout<<ret<<endl;
        }
    }else{
        cout<<"fail to open files"<<endl;
    }
    return 0;
}

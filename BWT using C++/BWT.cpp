#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string burrowsWheelerTransform(const string&text) 
{
    vector<string>rotations;
    string transformedText;

    // Generate all cyclic rotations of the text
    for(size_t i=0;i<text.size();++i)
	{
        rotations.push_back(text.substr(i)+text.substr(0,i));
    }

    // Sort the rotations lexicographically
    sort(rotations.begin(),rotations.end());

    // Extract the last characters of each rotation
    for(size_t i=0;i<rotations.size();++i) 
	{
        transformedText.push_back(rotations[i][rotations[i].size()-1]);
    }
    return transformedText;
}

int main() 
{
    int choice;
    cout<<"Choose input option:"<<endl;
    cout<<"1. Enter text manually"<<endl;
    cout<<"2. Input text from file"<<endl;
    cin>>choice;
    string text;
    if(choice==1) 
	{
        cout<<"Enter the text: ";
        cin.ignore();//Ignore the newline character left by previous cin
        getline(cin,text);
    } 
	else if(choice==2) 
	{
        string filename;
        cout<<"Enter the filename containing the text: ";
        cin>>filename;
        ifstream file(filename.c_str());
        if(!file) 
		{
            cerr<<"Error: Unable to open file."<<endl;
            return 1;
        }
        string line;
        while(getline(file,line)) 
		{
            text+=line;
        }
    }
	else 
	{
        cerr<<"Invalid choice."<<endl;
        return 1;
    }
    string bwt=burrowsWheelerTransform(text);
    cout<<"Burrows-Wheeler Transform: "<<bwt<<endl;
    return 0;
}


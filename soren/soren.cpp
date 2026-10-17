
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> names;
    string name;
    int i = 0;
    
    cin >> name;
    names[i].push_back(name[i]);
    i++;
    while(names[i] != " "){
        char c;
        cin >> c;
        names.push_back(c); 
        i++;
    }
    int totalLength;
    totalLength = names.length() * 3;
    
    for(int i = 0; i < totalLength; i++) {
        cout << names[i] << " ";
    }
    
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector<string> vstring , string Delim)
{
    string S1 = " ";
    for(string& s : vstring)
    {
        S1 = S1 + s + Delim;
    }
    return S1.substr(0, S1.length()-Delim.length());
}

int main() {
   vector<string> vstring = { "Mohammed","Faid","Ali","Maher" };

    cout << "\nVector after join: \n";
    cout << JoinString(vstring, " ");
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

short CountWords(string S1)
{
    string delim = " ";
    cout << "\nYour string words are: \n\n";

    short pos = 0;
    short Count = 0;
    string sWord;

    while ((pos = S1.find(delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);

        if (sWord != "")
        {
           Count++;
        }

        S1.erase(0, pos + delim.length());
    }

    if (S1 != "")
    {
       Count++;
    }
    return Count;
}

int main()
{
    string S1 = ReadString();
   cout << "\nThe number of words in your string is: ";
   cout << CountWords(S1);

    return 0;
}

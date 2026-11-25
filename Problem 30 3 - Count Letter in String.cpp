#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}

char ReadChar()
{
    char Ch;
    cout << "Please Enter a Character? \n";
    cin >> Ch;

    return Ch;
}
short CountLetter(string S1 , char Letter)
{
    short Counter = 0;
    for(short i = 0; i < S1.length();i++)
    {
        if(S1[i] == Letter)
        {
            Counter++;
        }


    }
    return Counter;
}


int main()
{
    string S1 = ReadString();

    char Ch = ReadChar();

    cout << "\nLetter \'" << Ch << "\' Count = " <<CountLetter(S1, Ch);
    return 0;
}

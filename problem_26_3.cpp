#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
    string S1;
    cout << "Please Enter Your String : \n";
    getline(cin, S1);

    return S1;
}

string LowerFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = tolower(S1[i]);
        }


    }

    return S1;
}

string UpperFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = toupper(S1[i]);
        }


    }

    return S1;
}

int main()
{

    string S1 = ReadString();

    cout << "\nString after Lowering first letters:\n";
    cout << LowerFirstLetterOfEachWord(S1) << endl;

    cout << "\nString after Uppering first letters:\n";
    cout << UpperFirstLetterOfEachWord(S1) << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string CLIENTS_FILE_PATH = "Clients.txt";
const string FIELD_SEPARATOR = "#//#";

struct ClientRecord
{
    string accountNumber;
    string pinCode;
    string fullName;
    string phoneNumber;
    double balance;
    bool isMarkedForDeletion = false;
};

vector<string> SplitString(string text, const string& delimiter)
{
    vector<string> tokens;
    size_t delimiterPos = 0;
    string word;

    while ((delimiterPos = text.find(delimiter)) != string::npos)
    {
        word = text.substr(0, delimiterPos);
        if (!word.empty())
        {
            tokens.push_back(word);
        }
        text.erase(0, delimiterPos + delimiter.length());
    }

    if (!text.empty())
    {
        tokens.push_back(text);
    }

    return tokens;
}

ClientRecord ParseLineToRecord(const string& line, const string& separator = FIELD_SEPARATOR)
{
    ClientRecord record;
    vector<string> parsedData = SplitString(line, separator);

    if (parsedData.size() >= 5)
    {
        record.accountNumber = parsedData[0];
        record.pinCode = parsedData[1];
        record.fullName = parsedData[2];
        record.phoneNumber = parsedData[3];
        record.balance = stod(parsedData[4]);
    }

    return record;
}

string ConvertRecordToLine(const ClientRecord& record, const string& separator = FIELD_SEPARATOR)
{
    return record.accountNumber + separator +
           record.pinCode + separator +
           record.fullName + separator +
           record.phoneNumber + separator +
           to_string(record.balance);
}

vector<ClientRecord> LoadClientsFromFile(const string& filePath)
{
    vector<ClientRecord> clientsList;
    ifstream inputFile(filePath);

    if (inputFile.is_open())
    {
        string currentLine;
        while (getline(inputFile, currentLine))
        {
            if (!currentLine.empty())
            {
                clientsList.push_back(ParseLineToRecord(currentLine));
            }
        }
        inputFile.close();
    }

    return clientsList;
}

void DisplayClientCard(const ClientRecord& client)
{
    cout << "\n----------------------------------------";
    cout << "\nClient Details:";
    cout << "\n----------------------------------------";
    cout << "\nAccount Number  : " << client.accountNumber;
    cout << "\nPIN Code        : " << client.pinCode;
    cout << "\nName            : " << client.fullName;
    cout << "\nPhone           : " << client.phoneNumber;
    cout << "\nAccount Balance : " << fixed << setprecision(2) << client.balance;
    cout << "\n----------------------------------------\n";
}

bool FindClientByAccountNumber(const string& accountNumber, const vector<ClientRecord>& clientsList, ClientRecord& targetClient)
{
    for (const ClientRecord& currentClient : clientsList)
    {
        if (currentClient.accountNumber == accountNumber)
        {
            targetClient = currentClient;
            return true;
        }
    }
    return false;
}

ClientRecord ReadUpdatedClientData(const string& accountNumber)
{
    ClientRecord updatedRecord;
    updatedRecord.accountNumber = accountNumber;

    cout << "\n\nEnter PIN Code: ";
    getline(cin >> ws, updatedRecord.pinCode);

    cout << "Enter Name: ";
    getline(cin, updatedRecord.fullName);

    cout << "Enter Phone: ";
    getline(cin, updatedRecord.phoneNumber);

    cout << "Enter Account Balance: ";
    cin >> updatedRecord.balance;

    return updatedRecord;
}

void SaveClientsToFile(const string& filePath, const vector<ClientRecord>& clientsList)
{
    ofstream outputFile(filePath);

    if (outputFile.is_open())
    {
        for (const ClientRecord& currentClient : clientsList)
        {
            if (!currentClient.isMarkedForDeletion)
            {
                outputFile << ConvertRecordToLine(currentClient) << "\n";
            }
        }
        outputFile.close();
    }
}

bool UpdateClientByAccountNumber(const string& accountNumber, vector<ClientRecord>& clientsList)
{
    ClientRecord targetClient;

    if (FindClientByAccountNumber(accountNumber, clientsList, targetClient))
    {
        DisplayClientCard(targetClient);

        char confirmation = 'n';
        cout << "\nAre you sure you want to update this client? (y/n): ";
        cin >> confirmation;

        if (confirmation == 'y' || confirmation == 'Y')
        {
            for (ClientRecord& currentClient : clientsList)
            {
                if (currentClient.accountNumber == accountNumber)
                {
                    currentClient = ReadUpdatedClientData(accountNumber);
                    break;
                }
            }

            SaveClientsToFile(CLIENTS_FILE_PATH, clientsList);
            cout << "\nClient updated successfully.\n";
            return true;
        }
        else
        {
            cout << "\nUpdate cancelled.\n";
            return false;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << accountNumber << ") was not found!\n";
        return false;
    }
}

string ReadAccountNumber()
{
    string accountNumber;
    cout << "Please enter Account Number: ";
    cin >> accountNumber;
    return accountNumber;
}

int main()
{
    vector<ClientRecord> clientsList = LoadClientsFromFile(CLIENTS_FILE_PATH);
    string accountNumber = ReadAccountNumber();

    UpdateClientByAccountNumber(accountNumber, clientsList);

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
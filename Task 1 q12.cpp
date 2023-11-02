#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> phishingKeywords;
    phishingKeywords["name"] = 1;
    phishingKeywords["password"] = 3;
    phishingKeywords["credit card"] = 2;
    phishingKeywords["security"] = 3;
    phishingKeywords["payment"]=2;
    phishingKeywords["account"]=2;
    phishingKeywords["alert"]=1;
    phishingKeywords["bank"]=3;
    phishingKeywords["click"]=2;
    phishingKeywords["confirm"]=2;
    phishingKeywords["deactivate"]=2;
    phishingKeywords["email"]=1;
    phishingKeywords["financial"]=2;
    phishingKeywords["free"]=1;
    phishingKeywords["important"]=2;
    phishingKeywords["information"]=2;
    phishingKeywords["login"]=2;
    phishingKeywords["please"]=1;
    phishingKeywords["suspicious"]=2;
    phishingKeywords["urgent"]=2;
    phishingKeywords["verify"]=2;
    phishingKeywords["virus"]=2;
    phishingKeywords["win"]=1;
    phishingKeywords["your"]=1;
    phishingKeywords["unusual"]=2;
    phishingKeywords["update"]=2;
    phishingKeywords["verification"]=2;
    phishingKeywords["lottery"]=1;
    phishingKeywords["inheritance"]=2;
    phishingKeywords["confidential"]=3;
    phishingKeywords["urgency"]=2;



    cout<<"Enter the name of the text file: ";
    string fileName;
    cin>>fileName;
    ifstream inputFile(fileName);
    if (!inputFile) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    string line;
    int totalPoints = 0;

    while (getline(inputFile, line)) {
        int lineTotalPoints = 0;  // Total points for this line

        for (auto& map : phishingKeywords) {
            string keyword = map.first;
            int pointVal = map.second;
            int found = line.find(keyword);
            while (found != -1) {
                lineTotalPoints += pointVal;
                found = line.find(keyword, found + 1);
            }
        }

        for (auto& map : phishingKeywords) {
            string keyword = map.first;
            int pointVal = map.second;
            int keywordCount = 0;
            int pos = 0;

            while ((pos = line.find(keyword, pos)) !=-1) {
                ++keywordCount;
                pos += keyword.length();
            }

            if (keywordCount > 0) {
                cout << "Keyword: " << keyword << ", Occurrences: " << keywordCount << ", Point Total: " << keywordCount * pointVal << endl;
            }


        }

        totalPoints += lineTotalPoints;
    }

    inputFile.close();

    cout << "Total Points: " << totalPoints << endl;

    return 0;
}

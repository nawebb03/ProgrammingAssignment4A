

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    //Declare needed variables, including filestream
    char a;
    ifstream inData;
    int aVowel = 0;
    int eVowel = 0;
    int iVowel = 0;
    int oVowel = 0;
    int uVowel = 0;
    int tCount = 0;
    int pCount = 0;
    int dCount = 0;
    int totalLetters = 0;

    //Check that a filename is specified by user
    if (argc < 2)
    {
        cout << "No filename has been specified. Exiting...";
        system("pause");
        return -1;
    };

    //Check that specified filename is correct/exists
    if (!inData)
    {
        cout << "Error opening file. File name is wrong or does not exist. Exiting..." << endl;
        system("pause");
        return -1;
    };

    //Assign the passed filename into filestream and open
    inData.open(argv[1]);

    //Read file character by character and increment corresponding letter counts
    while (!inData.eof() && inData >> a)
    {
        if (a == 'a' || a == 'A')
            aVowel++;
        else if (a == 'e' || a == 'E')
            eVowel++;
        else if (a == 'i' || a == 'I')
            iVowel++;
        else if (a == 'o' || a == 'O')
            oVowel++;
        else if (a == 'u' || a == 'U')
            uVowel++;
        else if (a == 't' || a == 'T')
            tCount++;
        else if (a == 'p' || a == 'P')
            pCount++;
        else if (a == 'd' || a == 'D')
            dCount++;
    };

    //Add up all counts for the total
    totalLetters = aVowel + eVowel + iVowel + oVowel + uVowel + tCount + pCount + dCount;

    //Produce output with iomanip formatting
    cout << "**************************************************************" << endl;
    cout << "************* Welcome to my Letter Count Program *************" << endl;
    cout << "**************************************************************" << endl;
    cout << endl;
    cout << "Analyzing file '" << argv[1] << "'..." << endl;
    cout << endl;
    cout << "The number of A's: " << setw(45) << right << setfill('.') << aVowel << endl;
    cout << "The number of E's: " << setw(45) << right << setfill('.') << eVowel << endl;
    cout << "The number of I's: " << setw(45) << right << setfill('.') << iVowel << endl;
    cout << "The number of O's: " << setw(45) << right << setfill('.') << oVowel << endl;
    cout << "The number of U's: " << setw(44) << right << setfill('.') << uVowel << endl;
    cout << "The number of T's: " << setw(45) << right << setfill('.') << tCount << endl;
    cout << "The number of P's: " << setw(44) << right << setfill('.') << pCount << endl;
    cout << "The number of D's: " << setw(44) << right << setfill('.') << dCount << endl;
    cout << "The letter count is: " << setw(44) << right << setfill('.') << totalLetters << endl;

    //Close the file
    inData.close();

    system("pause");
    return 1;

}

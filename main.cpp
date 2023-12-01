#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int extractDigits(string str);

int main() {

    // Open File
    ifstream in;
    in.open("C:\\Users\\pfarl\\OneDrive\\Documents\\Personal\\AoC_2023\\1.1\\input.txt");
    if(in.fail())
    {
        cout << "File failed to open." << endl;
        return -1;
    }

    // Read each line to a string, and extract digits
    string text;
    int totalCount = 0;
    while(getline(in, text))
    {
        totalCount += extractDigits(text);
    }

    // Print Totals
    cout << totalCount << endl;

    return 0;
}

int extractDigits(string str)
{
    // Loop through all characters
    char posFirst;
    char posLast;
    bool firstFound = false;
    for(int i=0; i<str.length(); i++)
    {
        // If the char is a digit, change posFirst and posLast
        if(isdigit(str[i]))
        {
            // Change both if neither has been added
            if(!firstFound)
            {
                posFirst = posLast = str[i];
                firstFound = true;
            }
                // Change the last one if the first already exists.
            else
            {
                posLast = str[i];
            }
        }
        // Check for words
        else
        {
            // If first letter of one of the number words, check them
            switch(str[i])
            {
                case 'e':
                    if(str.substr(i, 5) == "eight")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '8';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '8';
                        }
                    }
                    break;
                case 'f':
                    if(str.substr(i, 4) == "four")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '4';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '4';
                        }
                    }
                    else if(str.substr(i, 4) == "five")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '5';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '5';
                        }
                    }
                    break;
                case 'n':
                    if(str.substr(i, 4) == "nine")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '9';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '9';
                        }
                    }
                    break;
                case 'o':
                    if(str.substr(i, 3) == "one")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '1';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '1';
                        }
                    }
                    break;
                case 's':
                    if(str.substr(i, 3) == "six")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '6';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '6';
                        }
                    }
                    else if(str.substr(i, 5) == "seven")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '7';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '7';
                        }
                    }
                    break;
                case 't':
                    if(str.substr(i, 3) == "two")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '2';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '2';
                        }
                    }
                    else if(str.substr(i, 5) == "three")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '3';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '3';
                        }
                    }
                    break;
                case 'z':
                    if(str.substr(i, 4) == "zero")
                    {
                        if(!firstFound)
                        {
                            posFirst = posLast = '0';
                            firstFound = true;
                        }
                        else
                        {
                            posLast = '0';
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }

    // Concatenate, cast as int, and return
    auto digits = string(1, posFirst) + posLast;
    return stoi(digits);
}

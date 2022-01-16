#include <iostream>
#include <string>
using namespace std;

/**
* PURPOSE:
*   sort out new words by their prefixes and incorporate them into the dictionary
* PARAMETER:
*   input, a string array of words, and the array length
* RETURN VALUE
*   a string consisting of the prefix or a blank string ("")
*/
string getLargestPrefix(string strs[], int length)
{
    /**
    * with the number of words in the array known, need to find a way to iterate
    * through all of them and check for similar prefixes
    */
    string prefix;

    // determines the number of times the loop runs based on the number of array instances
    // length - 1 as the last instance of the array will not have another word
    for (int i = 0; i < length - 1; i++)
    {
        int prefixLength;
        if(strs[i].length() < strs[i + 1].length())
        {
            prefixLength = strs[i].length();
        }
        else
        {
            prefixLength = strs[i + 1].length();
        }
        // checks to see which characters make up the prefix or not
        string prefixTemp;
        for(int j = 0; j < prefixLength; j++)
        {
                if(strs[i].at(j) == strs[i + 1].at(j))
                {
                    prefixTemp += strs[i].at(j);
                }
                else
                {
                    j = prefixLength;
                }
        // This is the assignment statement that I'm referring to
        prefix = prefixTemp;
        }
    }
    return prefix;
}

int main()
{
    string words[] = {"cate","cat","category"};
    int array_length = sizeof(words) / sizeof(words[0]);
    cout << getLargestPrefix(words, array_length);
    return 0;
}

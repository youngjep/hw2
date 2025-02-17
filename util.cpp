#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment
    -> taking a string of many words and splitting them into individual keywords
**/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> keywords;

    size_t lastIndex = 0;

    for (size_t i = 0; i < rawWords.length(); i++) 
    {
        if ((rawWords[i] >= 48 && rawWords[i] <= 57)
            || (rawWords[i] >= 65 && rawWords[i] <= 90)
                || (rawWords[i] >= 97 && rawWords[i] <= 122))
        {
            
        }
        else 
        {
            if (lastIndex != i && i - lastIndex > 1)
            {
                keywords.insert(rawWords.substr(lastIndex, i - lastIndex));
            }
            lastIndex = i + 1;
        }
    }
    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

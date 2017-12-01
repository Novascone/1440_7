// http://www.cplusplus.com/reference/regex/regex_search/

/*
 * This program demonstrates how the C++ regular expression library works.
 *
 * It searches for the substring "sub" within a large string that contains many
 * occurrences. This is similar to what you'll do to search for hyperlinks
 * within an HTML document.
 */

#include <iostream>
#include <string>
#include <regex>

int main () {
    std::string haystack("this subject has a submarine as a subsequence\n"
            "subbing. submitting\n"
            "submission, substitute\n"
            "semper ubi? sub! ubi subversion"
            );

    std::string regexSourceCode("\\b(sub)([^ \n\t]*)");   // matches words beginning by "sub"
    std::regex needle(regexSourceCode);
    std::smatch match;

    std::cout << "Regex source code (the needle):" << regexSourceCode  << std::endl;
    std::cout << "Target sequence (the haystack): " << haystack << std::endl << std::endl;
    std::cout << "The following matches and submatches were found:" << std::endl;

    while (std::regex_search(haystack, match, needle)) {
        for (auto submatch : match)
            std::cout << "\t" << submatch << " ";
        std::cout << std::endl;
        haystack = match.suffix().str();
    }
    std::cout << std::endl;
}

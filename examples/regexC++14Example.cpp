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
	std::string s("this subject has a submarine as a subsequence\n"
			"subbing submitting\n"
			"submission substitute\n"
			"semper ubi sub ubi subversion"
			);

	std::string re("\\b(sub)([^ \n\t]*)");   // matches words beginning by "sub"
	std::regex e(re);

	std::cout << "Target sequence: " << s << std::endl << std::endl;
	std::cout << "Regular expression: /\\b(sub)([^ ]*)/" << std::endl << std::endl;
	std::cout << "The following matches and submatches were found:" << std::endl;

	std::smatch m;

	while (std::regex_search (s, m, e)) {
		for (auto x : m) std::cout << "\t" << x << " ";
		std::cout << std::endl;
		s = m.suffix().str();
	}

	return 0;
}

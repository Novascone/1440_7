#include <iostream>
#include <map>
#include <regex>
#include <sstream>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>



int main(int argc, char** argv) {
    std::string there = "http://www-cs-faculty.stanford.edu/~knuth/faq.html";
    int maxDepth = 3;

    if (argc > 1)
        there = argv[1];

    if (argc > 2)
        maxDepth = atoi(argv[2]);

    std::cout << "Recursively crawling the web to a depth of " << maxDepth << " links beginning from " << there << std::endl;

    //  _____ ___  ___   ___  
    // |_   _/ _ \|   \ / _ (_)
    //   | || (_) | |) | (_) |
    //   |_| \___/|___/ \___(_)
    //                        
    // 0. Define a recursive function that will, given a URL and a maximum
    //    depth, follow all hyperlinks found until the maximum depth is
    //    reached. You may define a wrapper function to make calling this
    //    recursive function from main() easier.
    //
    // 1. Your recursive function will create a new curlpp::Easy object each
    //    time it's called.  it should also clean up after itself.
    //
    // 2. Your recursive function needs to account for relative URLs. For
    //    example, the address of Don Knuth's FAQ page is
    //    http://www-cs-faculty.stanford.edu/~knuth/faq.html. If you inspect
    //    the contents of the page with your browser's developer tools
    //    (Ctrl-Shift-I) or view the source (Ctrl-U), you'll see that many of
    //    the links therein do not begin with
    //    http://www-cs-faculty.stanford.edu/.
    //
    //    Your recursive function needs to account for this by remembering what
    //    the current domain name is, and being prepared to prepend that to the
    //    URL it parses out of any given hyperlink.
    //
    // 3. Your recursive function should skip hyperlinks beginning with # -
    //    they refer to locations on the same page.
    //
    // 4. Your recursive function must also keep track of all pages it's
    //    visited so that it doesn't waste time visiting the same one again and
    //    again. This is where the std::map comes in handy. Your recursive
    //    function takes it as an argument, and returns it, possibly modified,
    //    after each invocation.


    return 0;
}

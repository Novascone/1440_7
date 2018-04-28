#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>
#include <set>

#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <curlpp/Exception.hpp>

void crawl(std::string, int);
std::vector<std::string> URLs(std::string);
std::string HTMLsource(std::string);


int main(int argc, char** argv) 
{
    std::string there;

    int maxDepth = 1;

    if (argc > 1)
        there = argv[1];

    if (argc > 2)
        maxDepth = atoi(argv[2]);

    std::cout << "enter url ";
    std::cin >> there;
    std::cout << "enter depth 1-3 ";

    do {
        std::cin >> maxDepth;

    if( maxDepth != 1 && maxDepth != 2 && maxDepth != 3)
    {
        std::cout << "enter valid depth " << std::endl;
    }
  
    } while (maxDepth < 1 || 3 < maxDepth);


    std::cout << "Recursively crawling the web to a depth of " << maxDepth << " links beginning from " << there << std::endl;

    

    crawl(there, maxDepth);

    return 0;
}

void crawl(std::string url, int depth)
{
    int count = depth;

    std::string html;
    int i = 0;

    std::vector<std::string> links;
    
    std::set<std::string> URLseen;

    if(depth == 0 || URLseen.count(url) == 1 )
    {
        return;
    }
    
    else 
    {
        html = HTMLsource(url);

        links = URLs(html);

    for (auto e : links) 
    {
        if (!URLseen.count(links[i])) 
        {
    
            if (links[i] != "") 
            {
            int var = depth;
                    std::string indent = "";
          
                if (var == 1)
                {
                    indent = "      ";
                }
                if(var == 2)
                {
                    indent = "  ";
                }
                if(var == 3)
                {
                     indent = "";
                }
                 std::cout<< indent << links[i] << std::endl;

                crawl(links[i], count - 1);
            }
        }

        i++;
    }
  }
}


std::vector<std::string> URLs(std::string html)
{
    std::string haystack(html);

    std::vector<std::string> links;

    std::string hrefRegexSource("<[ \n\t]*a[ \n\t]+.*href=\"(https*://)*([^/]+)*\\/*([^\"]+)\"");
  

    std::string regexSourceCode("<a .*?href=\"((https?://?[^\"]+)([^\"#]*)?)\".*?>");
   
    std::regex needle(regexSourceCode);
    std::smatch match;

    while (std::regex_search(haystack, match, needle)) 
    {
        

        if (match[2] == "")
        {
            haystack = match.suffix().str();
        }
        else 
        {
           

            links.push_back(match[2]);

            haystack = match.suffix().str();
        }
    }

    return links;
}


std::string HTMLsource(std::string there) 
{
   

    std:: string str(there);

    str = there;

    try 
    {
        curlpp::Cleanup cleaner;

        curlpp::Easy request;

        curlpp::options::Url curlUrl(str);

        request.setOpt(curlUrl);

        curlpp::options::FollowLocation follow(true);
        request.setOpt(follow);

        std::ostringstream os;
        os << request << std::endl;

        std::string html(os.str());
    

        return html;
        
    }
    catch ( curlpp::LogicError & e ) 
    {
      
        return "";
    }
    catch ( curlpp::RuntimeError & e )
    {
      
        return "";
    }


}

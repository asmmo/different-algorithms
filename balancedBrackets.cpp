#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
template<typename seq>
bool balancedBrackets(seq const & forwardContainers){
    std::stack<char> brackets;
    std::string openings {"({[<"};
    std::string closings {")}]>"};
    for( auto it = std::cbegin(forwardContainers); it != std::cend(forwardContainers); ++it)
    {
        if( std::any_of(openings.begin(), openings.end(), [&](const char & c){ return c == *it;}))
            brackets.push(*it);
        else if( std::any_of(closings.begin(), closings.end(), [&](const char & c){ return c == *it;}))
        {
            if (!brackets.empty() && closings.find(*it) == openings.find(brackets.top()))
                brackets.pop();
            else return false;
        }
    }
    return brackets.empty();
}
int main(){
    std::cout << balancedBrackets(std::string("[<ttttt>]"));
}

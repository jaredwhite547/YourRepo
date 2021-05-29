#include "Parser.hpp"

#include <boost/spirit/home/x3.hpp>

#include <string>
#include <vector>

using namespace CMakeExample;

bool Parse(const std::string& str, std::vector<int>& out){
    namespace x3 = boost::spirit::x3;

    return x3::phrase_parse(
            str.begin(),
            str.end(),
            x3::lit('[') >> -(x3::int_ % ',') >> ']' >> x3::eoi,
            x3::ascii::space,
            out
        );
}

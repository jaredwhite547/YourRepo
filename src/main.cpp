#include "MathUtils/DotProduct.hpp"

#include <fmt/format.h>

#include <boost/spirit/home/x3.hpp>

#include <iostream>
#include <string>
#include <vector>

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

std::string usage = "@@TODO";

int main(int argc, char* argv[]){
    if(argc != 3){
        std::cerr << "Requires two arguments, usage:\n";
        std::cerr << usage;
        return 1;
    }

    std::vector<int> a;
    std::vector<int> b;

    if(!Parse(std::string{argv[1]}, a)){
        std::cerr << "Error parsing the first vector\n";
        return 2;
    }

    if(!Parse(std::string{argv[2]}, b)){
        std::cerr << "Error parsing the second vector\n";
        return 2;
    }

    fmt::print("[{}] DOT ", fmt::join(a, ", "));
    fmt::print("[{}] = ",   fmt::join(b, ", "));
    fmt::print("{}\n", MathUtils::DotProduct(a, b));
    return 0;
}

#ifndef CMAKEEXAMPLE_PARSER_HPP
#define CMAKEEXAMPLE_PARSER_HPP

#include <string>
#include <vector>

namespace CMakeExample{

    /**Attempts to parse a comma separated list of ints enclosed in square brackets, i.e.:
     * []
     * [1, 2]
     * \param   str     The string to parse
     * \param   out     The vector to write the result to.
     * \retval  true    The parsing succeeded 
     * \retval  false   The parsing failed 
     */
    bool Parse(const std::string& str, std::vector<int>& out);
}

#endif //CMAKEEXAMPLE_PARSER_HPP

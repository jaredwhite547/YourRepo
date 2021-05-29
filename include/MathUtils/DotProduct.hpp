#ifndef MATHUTILS_DOTPRODUCT_HPP    //Good practice to prefix include guards with project/lib name to reduce collisions
#define MATHUTILS_DOTPRODUCT_HPP

//Keep includes to minimum in header files
#include <vector>

namespace MathUtils{

    /*Computes the dot product of two vectors containing ints.
     * \param a         The first vector
     * \param b         The second vector
     * \return          The dot product of `a` and `b`.
     * \throws std::invalid_argument if `a` and `b` do not have the same length.
     */
    int DotProduct(const std::vector<int>& a, const std::vector<int>& b);
}

#endif //MATHUTILS_DOTPRODUCT_HPP

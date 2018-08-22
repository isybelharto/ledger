#pragma once

/* The class defined in this file implements the equivalent of
 * following Python code:
 *
 * import numpy as np
 * import copy
 *
 * def gemv_n(alpha, A, x, n, beta, y, m):
 *   leny = A.shape[0]
 *   lenx = A.shape[1]
 *   if m >= 0 and n >= 0:
 *     y[::m] = alpha * np.dot(A, x[::n]) + beta * y[::m]
 *   elif m < 0 and n >= 0:
 *     y[-(leny -1)*m::m] = alpha * np.dot(A, x[::n]) + beta * y[-(leny -1)*m::m]
 *   elif m >= 0 and n < 0:
 *     y[::m] = alpha * np.dot(A, x[-(lenx -1)*n::n]) + beta * y[::m]
 *   else:
 *     y[-(leny -1)*m::m] = alpha * np.dot(A, x[-(lenx -1)*n::n]) + beta * y[-(leny -1)*m::m]
 *
 *   return y
 *
 * Authors:
 *  - Fetch.AI Limited             (C++ version)
 *  - Univ. of Tennessee           (Fortran version)
 *  - Univ. of California Berkeley (Fortran version)
 *  - Univ. of Colorado Denver     (Fortran version)
 *  - NAG Ltd.                     (Fortran version)
 */

#include "math/linalg/blas/base.hpp"
#include "math/linalg/matrix.hpp"
#include "math/linalg/prototype.hpp"

namespace fetch {
namespace math {
namespace linalg {

template <typename S, uint64_t V>
class Blas<S, Signature(_y <= _alpha, _A, _x, _n, _beta, _y, _m),
           Computes(_y = _alpha * _A * _x + _beta * _y), V>
{
public:
  using type                 = S;
  using vector_register_type = typename Matrix<type>::vector_register_type;

  void operator()(type const &alpha, Matrix<type> const &a, ShapeLessArray<type> const &x,
                  int const &incx, type const &beta, ShapeLessArray<type> &y,
                  int const &incy) const;
};

}  // namespace linalg
}  // namespace math
}  // namespace fetch
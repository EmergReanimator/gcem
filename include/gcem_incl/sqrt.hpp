/*################################################################################
  ##
  ##   Copyright (C) 2016-2024 Keith O'Hara
  ##
  ##   This file is part of the GCE-Math C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

/*
 * compile-time square-root function
 */

#ifndef _gcem_sqrt_HPP
#define _gcem_sqrt_HPP

namespace internal
{

template<typename T>
constexpr
T
sqrt_recur(const T x, const T xn, const int count)
noexcept
{
    return( abs(xn - x/xn) / (T(1) + xn) < GCLIM<T>::min() ? \
            // if
                xn :
            // else
                count < GCEM_SQRT_MAX_ITER ? \
                // if
                    sqrt_recur(x, T(0.5)*(xn + x/xn), count+1) :
                // else
                    xn );
}

template<typename T>
constexpr
T
sqrt_simplify(const T x, const T m_val)
noexcept
{
    return( x > T(1e+08) ? \
                sqrt_simplify(x / T(1e+08), T(1e+04) * m_val) :
            x > T(1e+06) ? \
                sqrt_simplify(x / T(1e+06), T(1e+03) * m_val) :
            x > T(1e+04) ? \
                sqrt_simplify(x / T(1e+04), T(1e+02) * m_val) :
            x > T(100) ? \
                sqrt_simplify(x / T(100), T(10) * m_val) :
            x > T(4) ? \
                sqrt_simplify(x / T(4), T(2) * m_val) :
                m_val * sqrt_recur(x, x / T(2), 0) );
}

template<typename T>
constexpr
T
sqrt_check(const T x)
noexcept
{
    return( is_nan(x) ? \
                GCLIM<T>::quiet_NaN() :
            //
            x < T(0) ? \
                GCLIM<T>::quiet_NaN() :
            //
            is_posinf(x) ? \
                x :
            // indistinguishable from zero or one
            GCLIM<T>::min() > abs(x) ? \
                T(0) :
            GCLIM<T>::min() > abs(T(1) - x) ? \
                x :
            // else
            sqrt_simplify(x, T(1)) );
}

} /* internal */


namespace embedded
{

template<typename T>
constexpr
T
sqrt_iter(const T x)
noexcept
{
    T xn = x / T(2);
    for (int count = 0; count < GCEM_SQRT_MAX_ITER; ++count)
    {
        T next_xn = T(0.5)*(xn + x/xn);
        if (abs(xn - x/next_xn) / (T(1) + xn) < GCLIM<T>::min())
        {
            break;
        }
        xn = next_xn;
    }
    return xn;
}

template<typename T>
constexpr
T
sqrt_simplify_iter(const T x)
noexcept
{
    T m_val = T(1);
    T x_val = x;
    while (x_val > T(4))
    {
        if (x_val > T(1e+08))
        {
            x_val /= T(1e+08);
            m_val *= T(1e+04);
        }
        else if (x_val > T(1e+06))
        {
            x_val /= T(1e+06);
            m_val *= T(1e+03);
        }
        else if (x_val > T(1e+04))
        {
            x_val /= T(1e+04);
            m_val *= T(1e+02);
        }
        else if (x_val > T(100))
        {
            x_val /= T(100);
            m_val *= T(10);
        }
        else if (x_val > T(4))
        {
            x_val /= T(4);
            m_val *= T(2);
        }
    }
    return m_val * sqrt_iter(x_val);
}

template<typename T>
constexpr
T
sqrt_check(const T x)
noexcept
{
    return( internal::is_nan(x) ? \
                GCLIM<T>::quiet_NaN() :
            //
            x < T(0) ? \
                GCLIM<T>::quiet_NaN() :
            //
            internal::is_posinf(x) ? \
                x :
            // indistinguishable from zero or one
            GCLIM<T>::min() > abs(x) ? \
                T(0) :
            GCLIM<T>::min() > abs(T(1) - x) ? \
                x :
            // else
            sqrt_simplify_iter(x) );
}

} /* embedded */

/**
 * Compile-time square-root function
 *
 * @param x a real-valued input.
 * @return Computes \f$ \sqrt{x} \f$ using a Newton-Raphson approach.
 */

template<typename T>
constexpr
return_t<T>
sqrt(const T x)
noexcept
{
#if defined(__cpp_lib_is_constant_evaluated)
    if (std::is_constant_evaluated())
        return internal::sqrt_check( static_cast<return_t<T>>(x) );
    else
        return embedded::sqrt_check( static_cast<return_t<T>>(x) );
#else
    return embedded::sqrt_check( static_cast<return_t<T>>(x) );
#endif
}

#endif

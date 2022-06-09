#ifndef MATH_H
#define MATH_H

// Chebyshev functions are WAYYYYYYY faster with around 0.1% error
#include<cmath>

namespace CEGUI {
    namespace MATH {
        constexpr float pi = 3.14159265358979323846;
        constexpr float twopi = pi*2.0;
        constexpr float pi2 = pi/2.0;
        constexpr float pi3 = (3.0*pi)/2.0;

        //CHEBYSHEV POLYNOMIALS (very fast and decently acccurate :D )
        // https://www.embeddedrelated.com/showarticle/152.php
        inline float cpsin(float x) {
            float neg = 1;
            if (x<0) {
                x *= -1.0;
                x = (x - twopi * std::floor(x/twopi));
                
                if (x > pi3) {x -= twopi;}
                else {neg = -1;}
            }
            else {x = (x - twopi * std::floor(x/twopi));}
            

            float x2 = x * x;
            /* previous failed attempts
            float u = (2*x)/pi;
            //return ( (c1*u) + (c3*(4*(u*u*u) - 3*u) ) + (c5 * ( 16*(u*u*u*u*u) - 10*(u*u*u) + 5*u)) );
            return (u * (c1 + (16*x2*c3)/(pi*pi) - 6*c3 + (256*x2*x2*c5)/(pi*pi*pi*pi) - (160*x2*c5)/(pi*pi) + 5*c5 ) );*/
            return 2.2672*x - 4.41824*x2*x + 0.82842*x + 2.3339008*x2*x2*x - 0.729344*x2*x + 0.045584*x;
        }

        inline float cpcos(float x) {
            using namespace CEGUI::MATH;

            x = fabs(x); // cos(-x) = cos(x)
            x = (x - twopi*std::floor(x/twopi));

            if (pi2 < x && x < pi3) {
                x = std::fabs(pi - x)/pi;

                float x2 = x*x;
                return -(0.472 - 0.4994*(8*x2 - 1) + 0.027985*(128*x2*x2 - 32*x2 + 1));
            }
            
            
            float x2 = x*x;
            return 0.472 - 0.4994*(8*x2 - 1) + 0.027985*(128*x2*x2 - 32*x2 + 1);
        }

        inline float cpatan(float x) {
            float x2 = x*x;
            return CEGUI::MATH::pi2*( 0.5274*x + -0.030213*(4*x2*x - 3*x) + 0.0034855*(16*x2*x2*x - 20*x2*x + 5*x) );
        }

        inline float cpatan2(float y, float x) {
            float temp = y/x;
            if (temp > 1.0 || temp < -1.0) {
                return CEGUI::MATH::pi2 - cpatan(1.0/temp);
            }

            return cpatan(temp);
        }
    };
};



#endif
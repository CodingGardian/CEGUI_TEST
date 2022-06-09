#ifndef GUTIL_H
#define GUTIL_H

#include <application/window.h>

namespace CEGUI {
    namespace RENDERING {
        // Top left of screen is (0,0)

        // Brasenhams line algorithm has many uses in the optimization of polygon drawing.
        // This structure stores the algorithms "position" and is incremented via a Brasenham function
        

        struct BresenhamAlgorithm {
            unsigned int x,y;
            int dx, dy;
            int sy, sx;
            int ey, ex;
        };

        void FillBHAlgorithm(BresenhamAlgorithm& ba, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);
        void iterate(BresenhamAlgorithm& ba);

        void drawline(const CEGUI::APP::Framebuffer& framebuff, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2);

        void drawRect(const CEGUI::APP::Framebuffer& framebuff, unsigned int x, unsigned int y, unsigned int width, unsigned int height); // x,y from top left corner

        void drawIRect(const CEGUI::APP::Framebuffer& framebuff, unsigned int x1, unsigned int x2, unsigned int y[]);
        /* y array (size of 4):
            4-----------------3
            |                 |
            |                 |
            1-----------------2
        */

    };
};

#endif
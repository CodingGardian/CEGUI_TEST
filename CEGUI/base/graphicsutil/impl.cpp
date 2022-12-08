#include <base/graphicsutil/gutil.h>
#include <base/graphicsutil/ScreenMap.h>

#include <iostream>
#include <utility>
#include <cmath>

using namespace CEGUI;
// Brasenham's algorithm (one of the fastest in town) TODO: derrive shorter method...
void DRAWING::DrawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {

    int dx = x2 - x1; int sx = x1 < x2 ? 1 : -1;
    int dy = y2 - y1; int sy = y1 < y2 ? 1 : -1;

    int ex = 0, ey = 0;

    dx *= sx;
    dy *= sy;
    while (true) {
        videobuffer->m_memory[framebuff->m_width*y1+x1] = 0xFFFFFFFF;
        if (x1 == x2 && y1 == y2) {break;}

        ex += dx;
        ey += dy;
        
        if ((ex << 1) >= dy) {x1 += sx; ex -= dy;}
        if ((ey << 1) >= dx) {y1 += sy; ey -= dx;}
    }

    
   /* if (dx == 0) {
        if (dy < 0) {y = p2[1]; dy = abs(dy);}
        else {y = p1[1];}
        int* start = &framebuff.m_memory[framebuff.m_width*y+p1[0]];
        for (int i=0; i<dy; i++) {
            *start = 0xFFFFFFFF;
            start += framebuff.m_width;
        }
    }

    if (dy == 0) {
        if (dx < 0) {x = p2[0]; dx = abs(dx);}
        else {x = p1[0];}
        int* start = &framebuff.m_memory[framebuff.m_width*p1[1] + x];
        for (int i=0; i<dx; i++) {
            *start = 0xFFFFFFFF;
            start += 1;
        }
    }

    // swap x and y if m>1
    if (abs(dy) > abs(dx)) { std::swap(p1[0], p1[1]); std::swap(p2[0],p2[1]);
        dy = p2[1]-p1[1];
        dx = p2[0]-p1[0];

        // swap points if x2 < x1, check if m is negative, or not (don't forget to plot (y,x))
        if (p2[0] < p1[0]) {
            std::swap(p1[0], p2[0]);
            std::swap(p1[1],p2[1]);
            dy *= -1;
        }

        if (dy < 0) {
            // slope is negative
            x = p1[0];
            y = p1[1];
            int e = 0;

            for (;x<=p2[0]; x++) {
                // plot (y,x)
                framebuff.m_memory[framebuff.m_width*x+y] = 0xFFFFFFFF;
                e += dy;
                if ( (e << 1) <= -dx ) {
                    y--; e += dx;
                }
            }
        }
        else {
            x = p1[0];
            y = p1[1];
            int e = 0;

            for (;x<=p2[0]; x++) {
                // plot (y,x)
                std::cout << y << x << std::endl;
                framebuff.m_memory[framebuff.m_width*x+y] = 0xFFFFFFFF;
                e += dy;
                if ( (e << 1) >= dx ) {
                    y++; e -= dx;
                }
            }
        }

    }
    else {
        // swap points if x2 < x2, check if m is negative or not
        if (p2[0] < p1[0]) {
            std::swap(p1[0], p2[0]);
            std::swap(p1[1],p2[1]);
            dy *= -1;
        }
        
        if (dy < 0) {
            // slope is negative
            x = p1[0];
            y = p1[1];
            int e = 0;

            for (;x<=p2[0]; x++) {
                framebuff.m_memory[framebuff.m_width*y+x] = 0xFFFFFFFF;
                e += dy;
                if ( (e << 1) <= -dx ) {
                    y--; e += dx;
                }
            }
        }
        else {
            x = p1[0];
            y = p1[1];
            int e = 0;

            for (;x<=p2[0]; x++) {
                framebuff.m_memory[framebuff.m_width*y+x] = 0xFFFFFFFF;
                e += dy;
                if ( (e << 1) >= dx ) {
                    y++; e -= dx;
                }
            }
        }
 
    }*/

}

void DRAWING::DrawRect(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    int* start = videobuffer->m_memory[framebuff.m_width*y+x];
    int* ptr = start;

    for (int i=0; i<height; i++) {
        start += videobuffer->m_width;
        ptr = start;
        for (int j=0; j<width; j++) {
            *ptr = 0xFFFFFFFF;
            ptr++;
        }
    }

}

void d_DrawScreenline4b(scrline, scrpos);

#include <base/graphicsutil/gutil.h>

using namespace CEGUI::DRAWING;

void FillBHAlgorithm(BresenhamAlgorithm& ba, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) {
    ba.x = x1; ba.y = y1;
    ba.dx = x2 - x1; ba.dy = y2 - y1;
    ba.sx = x1 < x2 ? 1 : -1;  ba.sy = y1 < y2 ? 1 : -1;

    ba.ex = 0; ba.ey = 0;
    
    ba.dx *= ba.sx; ba.dy *= ba.sy;
}

void iterate(BresenhamAlgorithm& ba) {
    ba.ex += ba.dx;
    ba.ey += ba.dy;
        
    if ((ba.ex << 1) >= ba.dy) {ba.x += ba.sx; ba.ex -= ba.dy;}
    if ((ba.ey << 1) >= ba.dx) {ba.y += ba.sy; ba.ey -= ba.dx;}
}
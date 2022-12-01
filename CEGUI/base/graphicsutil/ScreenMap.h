#ifndef SCREENMAP_H
#define SCREENMAP_H

#include <base/graphicsutil/gutil.h>

namespace CEGUI {
	namespace DRAWING {
		// KEEP EVERYTHING ALIGNED TO 8 BYTES!!!!!

		struct scrmask_header {
			char* data;
			int width, height;
		};

		struct scrpos {
			int x, y;
		};

		void d_DrawScreenMask(scrmask_header s, scrpos pos);
	};
};


#endif
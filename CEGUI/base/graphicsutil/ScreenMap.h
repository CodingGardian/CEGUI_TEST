#ifndef SCREENMAP_H
#define SCREENMAP_H

#include <base/graphicsutil/gutil.h>


namespace CEGUI {
	namespace DRAWING {
		// KEEP EVERYTHING ALIGNED TO 8 BYTES!!!!!

		struct scrmask_header {
			char* data;
			char __pad1[3], __pad2[4];
			int width, height;
		};

		struct scrline {
			char* data;
			bool vertical; // is the row vertical or horizontal?
			char __pad[2];
			int len;
		};

		struct theader {
			theader* next;
			int len;
			char __pad[4];
		};


		struct texture {
			theader* data;
			int len;
			scrnpos bounds; // add these to position of texture to see if it is clipped by screen
			bool vertical; // is it arranged vertically or horizontally
			char __pad[3];
		};

		struct scrpos {
			int x, y;
		};

		void d_DrawScreenline4b(scrline, scrpos);
		//void d_DrawScreenline3b(scrline, scrpos);
		void d_DrawScreenline2b(scrline, scrpos);
		void d_DrawScreenline1b(scrline, scrpos);

		void d_DrawScreenMask4b(scrmask, scrpos);
		//void d_DrawScreenMask3b(scrmask, scrpos);
		void d_DrawScreenMask2b(scrmask, scrpos);
		void d_DrawScreenMask1b(scrmask, scrpos);
	};
};


#endif
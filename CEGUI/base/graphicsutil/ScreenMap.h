#ifndef SCREENMAP_H
#define SCREENMAP_H

#include <base/graphicsutil/gutil.h>


namespace CEGUI {
	namespace DRAWING {
		// KEEP EVERYTHING MEMORY ALIGNED TO 8 BYTES!!!!!

		struct scrline {
			char* data;
			bool vertical; // is the row vertical or horizontal?
			char __pad[2];
			int len;
		};

		struct bheader {
			bheader* next;
			int len;
			char __pad[4];
		};

		struct bitmap {
			bheader* data;
			int len;
			scrpos bounds; // add these to position of texture to see if it is clipped by screen
			bool vertical; // is it arranged vertically or horizontally
			char __pad[3];
		};
		
		/*void d_DrawScreenline4b(scrline, scrpos);
		//void d_DrawScreenline3b(scrline, scrpos);
		void d_DrawScreenline2b(scrline, scrpos);
		void d_DrawScreenline1b(scrline, scrpos);*/

		void d_DrawBitMap4b(bitmap, scrpos);
		//void d_DrawScreenMask3b(scrmask, scrpos);
		void d_DrawBitMap2b(bitmap, scrpos);
		void d_DrawBitMap1b(bitmap, scrpos);

		//typedef (void)(*LineDrawFunc)(scrline, scrpos);
		//typedef (void)(*MaskDrawFunc)(scrmask, scrpos);
	};
};


#endif
#ifndef APPLICATION_H
#define APPLICATION_H

#include <application/window.h>

#ifndef __PRETTY_FUNCTION__
#define __PRETTY_FUNCTION__
#endif

namespace CEGUI {
    namespace APP {
			void _Error(const char* error, const char* function);
			void _Warning(const char* war, const char* function);

			void ProgramFail();
    };
};

#define Error(str) CEGUI::APP::_Error(str, __PRETTY_FUNCTION__)
#define Warning(str) CEGUI::APP::_Warning(str, __PRETTY_FUNCTION__)

#endif
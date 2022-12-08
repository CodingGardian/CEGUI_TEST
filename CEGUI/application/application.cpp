#include <application/application.h>
#include <stdio.h>
#include <stdlib.h>

using namespace CEGUI::APP;



void CEGUI::APP::_Error(const char* error, const char* function) {
	printf("Error: %s in function %s\n", error, function);
	ProgramFail();
}

void CEGUI::APP::_Warning(const char* war, const char* function) {
	printf("Warning: %s in functio n %s\n", war, function);
}

void CEGUI::APP::ProgramFail() {
	// clean things up (and exit with proper code?)
	CEGUI_CLOSE();
	printf("Shutting down CEGUI\n");

	printf("Terminating\n");
	exit(-1);
}
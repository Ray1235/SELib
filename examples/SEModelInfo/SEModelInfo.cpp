// SEModelInfo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define SELIB_DEBUG_PRINT
#include "../../SELib.h"
#include <time.h>

time_t startClock = 0;
time_t endClock = 0;


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Drag and drop a SEModel on the exe to print info\n");
		return 0;
	}

	SEModel_File_t mdl;
	memset(&mdl, 0, sizeof(SEModel_File_t));
	FILE* f;
	fopen_s(&f, argv[1], "rb");
	startClock = clock();
	int r = LoadSEModel(&mdl, f);
	endClock = clock();
	fclose(f);
	if (r != 0)
	{
		printf("Error: %d\n", r);
		return 1;
	}
	else
	{
		printf("data: %d\nbone: %d\nmesh: %d\nbone count: %d\nmesh count: %d\nmat count: %d\n",
			mdl.header.dataPresenceFlags, mdl.header.boneDataPresenceFlags, mdl.header.meshDataPresenceFlags,
			mdl.header.boneCount, mdl.header.meshCount, mdl.header.matCount);
	}
    return 0;
}


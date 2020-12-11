#include <windows.h>
#include <string>
#include <iostream>

int main(int argc, char** argv) {
	std::string path = argv[1];
	HANDLE fileHandleRes = CreateFileA((path + "\\res.txt").c_str(), // open Two.txt
		FILE_APPEND_DATA,         // open for writing
		FILE_SHARE_READ,          // allow multiple readers
		NULL,                     // no security
		OPEN_ALWAYS,              // open or create
		FILE_ATTRIBUTE_NORMAL,    // normal file
		NULL);                    // no attr. template

	for (int i = 2; i < argc; ++i) {
		HANDLE HandleFile1 = CreateFileA((path + "\\" + argv[i]).c_str(),
			GENERIC_READ,             // open for reading
			0,                        // do not share
			NULL,                     // no security
			OPEN_EXISTING,            // existing file only
			FILE_ATTRIBUTE_NORMAL,    // normal file
			NULL);
		char buf[1000] = {};
		DWORD resize;
		ReadFile(HandleFile1, buf, sizeof(buf), &resize, 0);
		WriteFile(fileHandleRes, buf, resize, &resize, 0);
		CloseHandle(HandleFile1);
	}
	return 0;
}
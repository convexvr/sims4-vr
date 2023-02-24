#include "pch.h"
#include "Util.h"

#include <windows.h>
#include <stdarg.h>

namespace vireio
{
	std::string retprintf(const char *fmt, ...)
	{
		va_list args;
		va_start(args, fmt);
		char buf[8192];
		vsnprintf_s(buf, 8192, fmt, args);
		va_end(args);
		return std::string(buf);
	}
	
	void debugf(const char *fmt, ...)
	{
		
		va_list args;
		va_start(args, fmt);
		char buf[8192];
		vsnprintf_s(buf, 8192, fmt, args);
		va_end(args);
		OutputDebugStringA(buf);
		FILE* fp;
		fopen_s(&fp, "C:\\s4\\output.txt", "a");
		if (fp) {
			fputs(buf, fp);
			fputs("\n", fp);
			fclose(fp);
		}
	}

	void deb(const char* fmt, ...)
	{

		va_list args;
		va_start(args, fmt);
		char buf[8192];
		vsnprintf_s(buf, 8192, fmt, args);
		va_end(args);
		OutputDebugStringA(buf);
		FILE* fp;
		fopen_s(&fp, "C:\\s4\\n_debug.txt", "a");
		if (fp) {
			fputs(buf, fp);
			fputs("\n", fp);
			fclose(fp);
		}
	}
}
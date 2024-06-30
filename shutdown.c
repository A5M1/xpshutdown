#include <windows.h>

int main() {
    const char* vbscriptContent =
        "dim objShell\n"
        "set objShell = CreateObject(\"Shell.Application\")\n"
        "objShell.ShutdownWindows\n"
        "set objShell = nothing\n";

    HANDLE hFile = CreateFile("temp.vbs", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD bytesWritten;
        WriteFile(hFile, vbscriptContent, strlen(vbscriptContent), &bytesWritten, NULL);
        CloseHandle(hFile);
    }

    ShellExecute(NULL, "open", "wscript.exe", "temp.vbs", NULL, SW_HIDE);
    Sleep(100); 
    DeleteFile("temp.vbs");

    return 0;
}

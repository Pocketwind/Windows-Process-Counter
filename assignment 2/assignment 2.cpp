#include <iostream>
#include<time.h>
#include<Windows.h>
#include<TlHelp32.h>

using namespace std;

int main()
{
    while (1)
    {
        int n = 0;
        HANDLE hProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        PROCESSENTRY32 entry;
        bool counter;
        entry.dwSize = sizeof(PROCESSENTRY32);
        counter = Process32First(hProcess, &entry);
        while (counter)
        {
            counter = Process32Next(hProcess, &entry);
            ++n;
        }
        CloseHandle(hProcess);

        time_t t = time(NULL);
        struct tm timer;
        localtime_s(&timer, &t);
        cout << "현재 시간 : " << timer.tm_year + 1900 << '/' << timer.tm_mon + 1 << '/' << timer.tm_mday << ' ' << timer.tm_hour << "시 " << timer.tm_min << "분 " << timer.tm_sec << "초";
        cout << " - 실행중인 프로세스 : " << n <<"\n";
        Sleep(1000);
    }
    return 0;
}


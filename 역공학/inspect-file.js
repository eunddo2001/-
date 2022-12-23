var createFile = Module.findExportByName("kernel32.dll", "CreateFileW");

Interceptor.attach(createFile, {
    onEnter: function(args)
    {
        // HANDLE CreateFile(
        //     [in]           LPCSTR                lpFileName,
        //     [in]           DWORD                 dwDesiredAccess,
        //     [in]           DWORD                 dwShareMode,
        //     [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
        //     [in]           DWORD                 dwCreationDisposition,
        //     [in]           DWORD                 dwFlagsAndAttributes,
        //     [in, optional] HANDLE                hTemplateFile
        //   );

        console.log("=== CreateFile's lpFileName ===");
        console.log(Memory.readUtf16String(args[0]));

        console.log("=== CreateFile's dwDesiredAccess ===");
        console.log(args[1]);
        if (args[1] == 0x10000000){
            console.log("-> GENERIC_ALL");
        }
        else if (args[1] == 0x20000000){
            console.log("-> GENERIC_EXECUTE");
        }
        else if (args[1] == 0x40000000){
            console.log("-> GENERIC_READ");
        }
        else if (args[1] == 0x80000000){
            console.log("-> GENERIC_WRITE");
        }

        console.log("=== CreateFile's dwShareMode ===");
        console.log(args[2]);
        if (args[2] == 0x0){
            console.log("-> 0");
        }
        else if (args[2] == 0x1){
            console.log("-> FILE_SHARE_READ");
        }
        else if (args[2] == 0x2){
            console.log("-> FILE_SHARE_WRITE");
        }
        else if (args[2] == 0x4){
            console.log("-> FILE_SHARE_DELETE");
        }

        console.log("=== CreateFile's lpSecurityAttributes ===");
        console.log(args[3]);

        console.log("=== CreateFile's dwCreationDisposition ===");
        console.log(args[4]);
        if (args[4].and(0x1) != 0x0){
            console.log("-> CREATE_NEW");
        }
        else if (args[4].and(0x2) != 0x0){
            console.log("-> CREATE_ALWAYS");
        }
        else if (args[4].and(0x3) != 0x0){
            console.log("-> OPEN_EXISTING");
        }
        else if (args[4].and(0x4) != 0x0){
            console.log("-> OPEN_ALWAYS");
        }
        else if (args[4].and(0x5) != 0x0){
            console.log("-> TRUNCATE_EXISTING");
        }

        console.log("=== CreateFile's dwFlagsAndAttributes ===");
        console.log(args[5]);
        if (args[5].and(0x1) != 0x0){
            console.log("-> FILE_ATTRIBUTE_READONLY");
        }
        else if (args[5].and(0x2) != 0x0){
            console.log("-> FILE_ATTRIBUTE_HIDDEN");
        }
        else if (args[5].and(0x4) != 0x0){
            console.log("-> FILE_ATTRIBUTE_SYSTEM");
        }
        else if (args[5].and(0x32) != 0x0){
            console.log("-> FILE_ATTRIBUTE_ARCHIVE");
        }
        else if (args[5].and(0x128) != 0x0){
            console.log("-> FILE_ATTRIBUTE_NORMAL");
        }
        else if (args[5].and(0x256) != 0x0){
            console.log("-> FILE_ATTRIBUTE_TEMPORARY");
        }
        else if (args[5].and(0x4096) != 0x0){
            console.log("-> FILE_ATTRIBUTE_OFFLINE");
        }
        else if (args[5].and(0x16384) != 0x0){
            console.log("-> FILE_ATTRIBUTE_ENCRYPTED");
        }

        console.log("=== CreateFile's hTemplateFile ===");
        console.log(args[6]);
        console.log("")
    },
    onLeave: function(retval) 
    {
    }
});

var writeFile = Module.findExportByName("kernel32.dll", "WriteFile");

Interceptor.attach(writeFile, {
    onEnter: function(args)
    {
        // BOOL WriteFile(
        //     [in]                HANDLE       hFile,
        //     [in]                LPCVOID      lpBuffer,
        //     [in]                DWORD        nNumberOfBytesToWrite,
        //     [out, optional]     LPDWORD      lpNumberOfBytesWritten,
        //     [in, out, optional] LPOVERLAPPED lpOverlapped
        //   );
        
        console.log("=== WriteFile's hFile ===");
        console.log(args[0]);

        console.log("=== WriteFile's lpBuffer ===")
        console.log("Buffer dump:\n" + hexdump(args[1], { length: 128, ansi: true }));
        console.log(Memory.readUtf8String(args[1]));
        Memory.writeAnsiString(args[1],"manipulated contents");

        console.log("=== WriteFile's nNumberOfBytesToWrite ===");
        console.log(args[2]);

        console.log("=== WriteFile's lpNumberOfBytesWritten ===");
        console.log(args[3]);

        console.log("=== WriteFile's lpOverlapped ===");
        console.log(args[4]);
        console.log("")
    },
    onLeave: function(retval) 
    {
    }
});

var createProcess = Module.findExportByName("kernel32.dll", "CreateProcessA");

Interceptor.attach(createProcess, {
    onEnter: function(args)
    {
        // BOOL CreateProcessA(
        //     [in, optional]      LPCSTR                lpApplicationName,
        //     [in, out, optional] LPSTR                 lpCommandLine,
        //     [in, optional]      LPSECURITY_ATTRIBUTES lpProcessAttributes,
        //     [in, optional]      LPSECURITY_ATTRIBUTES lpThreadAttributes,
        //     [in]                BOOL                  bInheritHandles,
        //     [in]                DWORD                 dwCreationFlags,
        //     [in, optional]      LPVOID                lpEnvironment,
        //     [in, optional]      LPCSTR                lpCurrentDirectory,
        //     [in]                LPSTARTUPINFOA        lpStartupInfo,
        //     [out]               LPPROCESS_INFORMATION lpProcessInformation
        //   );
        
        console.log("=== CreateProcess's lpApplicationName ===");
        console.log(Memory.readUtf16String(args[0]));

        console.log("=== CreateProcess's lpCommandLine ===");
        console.log(Memory.readCString(args[1]));
        console.log(args[1]);
        
        console.log("=== CreateProcess's lpProcessAttributes ===");
        console.log(args[2]);

        console.log("=== CreateProcess's lpThreadAttributes ===");
        console.log(args[3]);

        console.log("=== CreateProcess's bInheritHandles ===");
        console.log(args[4]);
        if (args[4].and(0x0) != 0x0){
            console.log("-> False");
        }
        else if (args[4].and(0x1) != 0x0){
            console.log("-> True");
        }

        console.log("=== CreateProcess's dwCreationFlags ===");
        console.log(args[5]);
        if (args[5] == 0x1000000){
            console.log("-> CREATE_BREAKAWAY_FROM_JOB");
        }
        else if (args[5] == 0x4000000){
            console.log("-> CREATE_DEFAULT_ERRORMODE");
        }
        else if (args[5] == 0x10){
            console.log("-> CREATE_NEW_CONSOLE");
        }

        else if (args[5] == 0x200){
            console.log("-> CREATE_NEW_PROCESS_GROUP");
        }

        else if (args[5] == 0x8000000){
            console.log("-> CREATE_NO_WINDOW");
        }

        else if (args[5] == 0x40000){
            console.log("-> CREATE_PROTECTED_PROCESS");
        }

        else if (args[5] == 0x2000000){
            console.log("-> CREATE_PRESERVE_CODE_AUTHZ_LEVEL");
        }

        else if (args[5] == 0x400000){
            console.log("-> CREATE_SECURE_PROCESS");
        }

        else if (args[5] == 0x800){
            console.log("-> CREATE_SEPARATE_WOW_VDM");
        }

        else if (args[5] == 0x1000){
            console.log("-> CREATE_SHARED_WOW_VDM");
        }

        else if (args[5] == 0x4){
            console.log("-> CREATE_SUSPENDED");
        }

        else if (args[5] == 0x2){
            console.log("-> DEBUG_ONLY_THIS_PROCESS");
        }

        else if (args[5] == 0x1){
            console.log("-> DEBUG_PROCESS");
        }

        else if (args[5] == 0x8){
            console.log("-> DETACHED_PROCESS");
        }

        else if (args[5] == 0x80000){
            console.log("-> EXTENDED_STARTUPINFO_PRESENT");
        }

        else if (args[5] == 0x10000){
            console.log("-> INHERIT_PARENT_AFFINITY");
        }

        console.log("=== CreateProcess's lpEnvironment ===");
        console.log(Memory.readUtf16String(args[6]));

        console.log("=== CreateProcess's lpCurrentDirectory ===");
        console.log(args[7]);

        console.log("=== CreateProcess's lpStartupInfo ===");
        console.log("Buffer dump:\n" + hexdump(args[8], { length: 128, ansi: true }));

        console.log("=== CreateProcess's lpProcessInformation ===");
        console.log("Buffer dump:\n" + hexdump(args[9], { length: 128, ansi: true }));
        console.log("")
    },
    onLeave: function(retval) 
    {
    }
});
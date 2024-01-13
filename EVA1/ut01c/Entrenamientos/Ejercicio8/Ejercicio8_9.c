#define _POSIX_SOURCE 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/utsname.h>

#define FALSE -1

int main(int args, char *argv[]){
   #ifdef _WIN32
	    #ifdef _WIN64
	        char *cmds[] = {"ipconfig",NULL};
            if(execvp(cmds[0],cmds) == FALSE){
                perror("Error de ejecucion de comando linux");
                return(EXIT_FAILURE);
            }
	    #else 
	        char *cmds[] = {"ipconfig",NULL};
            if(execvp(cmds[0],cmds) == FALSE){
                perror("Error de ejecucion de comando linux");
                return(EXIT_FAILURE);
            }
	    #endif
    #else 
        #ifdef __linux__
        char *cmds[] = {"ifconfig",NULL};
        if(execvp(cmds[0],cmds) == FALSE){
            perror("Error de ejecucion de comando linux");
            return(EXIT_FAILURE);
        }
        #endif
    #endif

    return 0;

    // Sistemas operativos :Windows 32 bit + 64 bit	_WIN32	for all Windows OS
        // Windows 64 bit	_WIN64	Only for 64 bit Windows
        // Apple	__APPLE__	for all Apple OS
        // Apple	__MACH__	alternative to above
        // iOS embedded	TARGET_OS_EMBEDDED	include TargetConditionals.h
        // iOS stimulator	TARGET_IPHONE_SIMULATOR	include TargetConditionals.h
        // iPhone	TARGET_OS_IPHONE	include TargetConditionals.h
        // MacOS	TARGET_OS_MAC	include TargetConditionals.h
        // Android	__ANDROID__	subset of linux
        // Unix based OS	__unix__	
        // Linux	__linux__	subset of unix
        // POSIX based	_POSIX_VERSION	Windows with Cygwin
        // Solaris	__sun	
        // HP UX	__hpux	
        // BSD	BSD	all BSD flavors
        // DragonFly BSD	__DragonFly__	
        // FreeBSD	__FreeBSD__	
        // NetBSD	__NetBSD__	
        // OpenBSD	__OpenBSD__
}
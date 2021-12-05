#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[]) {
	printf("Hello world!\n");
	Sleep(1500); // полторы секунды прога спит
	printf("Goodbye!\n\n");
	
	if (argc > 1) {
        printf("Argumens be\n");
        printf("%s\n", argv[1]);
        printf("%s\n", argv[2]);
    } else {
    	printf("Argumens not be\n");
    }
	
	char cmdd[122] = "nichuia";
	printf("%s\n", cmdd);
	sprintf(cmdd+strlen(cmdd), " zalupa");
	printf("%s\n", cmdd);
	
	
	return 0;
}

#include <stdio.h>
#include <windows.h>

int main(int argc, char* argv[]) {
	printf("Hello world!\n");
	Sleep(1000); // секунду прога спит
	printf("Goodbye!\n\n");
	
	if (argc > 1) {
        printf("Argumens be\n");
        printf("%s\n", argv[1]);
        printf("%s\n", argv[2]);
        printf("%s\n", argv[3]);
        printf("%s\n", argv[4]);
    } else {
    	printf("Argumens not be\n");
    }
	
	char cmdd[122] = "nichuia";
	printf("%s\n", cmdd);
	sprintf(cmdd+strlen(cmdd), " zalupa");
	printf("%s\n\n\n", cmdd);
	

	for(unsigned long i = 0; i < 1000000; i++) {
		printf("$ ");
	}


	system("pause");
	
	return 0;
}

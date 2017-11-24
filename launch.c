#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

#include <stdio.h>
// #include <resource.h>

int println(char* s){
	printf("%s\n",s);
	return 0;
}
int main(int argc, char* args[]) {
	
	int i;
	char prefix[] = "7z x ";
	for(i=1;i<argc;++i){
		char cmd[1024];
		char folder[1024];
		int folderIndex = strlen(args[i])-strlen(strrchr(args[i],'.'));
		strcpy(cmd,"7z x \"");
		strcat(cmd,args[i]);
		strcat(cmd,"\" -y -aos -o\"");
		strncat(cmd,args[i],folderIndex);
		strcat(cmd,"\\\"");
		println(cmd);
		strcpy(folder,"explorer \"");
		strncat(folder,args[i],folderIndex);
		strcat(folder,"\"");
		system(cmd);
		system(folder);
	}
	return 0;
}
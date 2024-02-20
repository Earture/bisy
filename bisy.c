/*
 * @Earture 喜欢小包
 */

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>

static char buffer[2048];

char* readline(char* prompt) {
		fputs(prompt,stdout);
		fgets(buffer,2048,stdin);
		char* cpy = malloc(strlen(buffer)+1);
		strcpy(cpy,buffer);
		cpy[strlen(cpy)-1]='\0';

		return cpy;
}

void add_history(char* unused) {}

#else
#include <editline/readline.h>
#endif


void DisplayVersion(char* ver) {
		printf("Bisy Version %s\n",ver);
		puts("Press Ctrl+c to Exit\n");
}
int main(int argc, char** argv) {

		DisplayVersion("0.0.0.1");

		while(1) {

				char* BYinput = readline("bisy> ");
				add_history(BYinput);

				printf("%s\n",BYinput);

				free(BYinput);
		}
		return 0;
}

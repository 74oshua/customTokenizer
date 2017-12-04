/*Created by Joshua Lowry*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef unsigned char bool;
#define true 1
#define false 0

const int tokenLength = 100;
void tokenize(char * str, char * tokens[], char * delims);

int main(int argc, char **argv)
{
	char string1[] = "Hello world";
	char * tokens[10];
	memset(&tokens, 0, sizeof(tokens));
	
	tokenize(string1, tokens, " ");
	printf("%s", tokens[0]);
	
	while(true);
	
	return 0;
}

void tokenize(char * str, char * tokens[], char * delims)
{
	//a c string to hold data for the current token
	char tokenBuffer[100];
	memset(&tokenBuffer, 0, sizeof(tokenBuffer));
	
	//the iterator for the tokens
	int tokenNum = 0;
	
	//the current character + a null character
	char currChar[2];
	memset(&currChar, 0, sizeof(currChar));
	
	//for every char in str...
	for (int i = 0; i <= strlen(str); i++)
	{
		//add the current char to the tokenBuffer
		currChar[0] = str[i];
		strcat(tokenBuffer, currChar);
		
		//for every char in delims...
		for (int j = 0; j < strlen(delims); j++)
		{
			//if we have reached the end of a token...
			if (str[i] == delims[j] || str[i] == '\0')
			{
				tokens[tokenNum] = malloc(sizeof(tokenBuffer));
				
				//make the current token equal to the tokenBuffer
				strcpy(tokens[tokenNum], tokenBuffer);
				
				//clear the tokenBuffer
				memset(&tokenBuffer, 0, sizeof(tokenBuffer));
				
				//select the next token
				++tokenNum;
			}
		}
	}
}
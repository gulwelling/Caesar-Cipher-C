#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char encrypt_Char(char character,int key);

int main(int argc, char *args[])
{
	//args[1] = key;args[2] = message
	char character_Set[2] = "26";
	int characters_Alphabet = 26;
	int key = atoi(args[1]);
	if((strncmp(character_Set,args[1],2) > 0) && (key >= 1 && key <= 26))
	{
		int i = 0;
		while(args[2][i] != '\0')
		{
			args[2][i] = encrypt_Char(args[2][i],key);
			i++;
		}
	}
	else
	{
		return -1;
	}
	puts(args[2]);
	return 0;
}


char encrypt_Char(char character, int key)
{
	int characters_Alphabet = 26;
	if(isalpha(character))
	{
		if(tolower(character) + key > 'z')
		{
			return ((character + key) - characters_Alphabet);
		}
		else
		{
			return character + key;
		}
	}
	else
	{
		return character;
	}
}

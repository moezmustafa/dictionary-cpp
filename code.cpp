#include <iostream>
#include <conio.h>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h> 
using namespace std;

const int MAX_SIZE = 2000;
void writingFile(char data[]){
	ofstream file("New Paragraph.txt", ios::app);
	cout << " " << data;
	file << " " << data;
	file.close();
}


void dictionaryReading(char name[], char words[][100], int& index  )
{
	ifstream File(name, ios::in);

	if (!File)								//if file does not open
	{
		cout << "File could not be open" << endl;
		exit(0);
	}
	
	
	while (!File.eof())
	{
		char line[MAX_SIZE] = "";			// Creating Line Array
		File.getline(line, 1000);
		int i = 0;
		
		while (line[i] != '\0')
		{
			words[index][i] = line[i];
			i++;
		}			//Copying Line Array to Text Array
		//cout << line << endl;
		words[index][i] = '\0';
		index++;
	}
	
}
char* FileReading(char name[], bool dictionary = true)
{
	ifstream File(name, ios::in);

	if (!File)								//if file does not open
	{
		cout << "File could not be open" << endl;
		exit(0);
	}

	char TextArray[MAX_SIZE] = "";			// Creating Char Array

	while (!File.eof())
	{
		char line[MAX_SIZE] = "";			// Creating Line Array
		File.getline(line, 1000);
		
		strcat_s(TextArray, line);			//Copying Line Array to Text Array
		//cout << line;
	}
	return TextArray;
}
void tokens(const char para[], char newPara[][100], int& paraIndex, char words[][100], int wordIndex, char meaning[][100], int meanIndex) {
	char str[1000];
	strcpy_s(str, para);
	char separators[] = " ,\t\n.";
	char* token;
	char* next_token;

	// establish a string and get the first token:
	token = strtok_s(str, separators, &next_token);

	// while there are tokens in "string1" or "string2"
	while ((token != NULL))
	{
		// get the next token:
		if (token != NULL)
		{
			int counter = 0;
			for (int i = 0; i < wordIndex; i++)
			{
				if (strcmp(words[i], token) == 0) {
					writingFile(meaning[i]);
					counter++;
				}

			}
			if (counter == 0)
				writingFile(token);
			
			token = strtok_s(NULL, separators, &next_token);
		}
	}

}
int main()
{
	
	char words[1000][100];
	int wordsIndex = 0;
	char wordFile[100] = "Words.txt";
	dictionaryReading(wordFile, words, wordsIndex);
	

	char meanings[1000][100];
	int meanIndex = 0;
	char meaningFile[100] = "dictionary.txt";
	dictionaryReading(meaningFile, meanings, meanIndex);
	
	char name[100] = "paragraph.txt";
	char* Paragraph = FileReading(name);
	char paraCpy[10000];
	
	strcpy_s(paraCpy, Paragraph);
	
	char newPara[1000][100];
	int newParaIndex = 0;
	tokens(paraCpy, newPara, newParaIndex, words, wordsIndex, meanings, meanIndex);
	
	
	return 0;
}
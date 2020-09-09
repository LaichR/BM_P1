// Histogram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

int main()
{
	// Aufgabe 1
	printf("Das Program wurde gestartet\n");





	// Aufgabe 2
	//FILE *stream;
	//errno_t err;
	//int count = 0, ch;
	//// Open for read (will fail if file "crt_fopen_s.c" does not exist)
	//err = fopen_s(&stream, "C:\\Users\\marco\\OneDrive\\Dokumente\\HFIE\\Strukturierte Progammierung\\Histogram\\Alice Adventure in Wonderland.txt", "r");
	//if (stream == NULL)
	//	exit(0);

	//while (1) {
	//	ch = fgetc(stream);
	//	if (ch == EOF)
	//		break;
	//	++count;
	//}
	//printf("Number of characters %i\n", count);

	//fclose(stream);


	// @RLA: How about the part where you give parameters to your program? it would be nice if
	// we could give the file to read as an argument!

	// Aufgabe 3
	FILE* stream = NULL;
	_set_errno(0);

	errno_t err = fopen_s(&stream, "C:\\Users\\marco\\OneDrive\\Dokumente\\HFIE\\Strukturierte Progammierung\\Repo\\BM_P1\\Histogram\\Alice Adventure in Wonderland.txt", "r");
	if (err != 0) {
		printf("Error occured %i", err);
		return 1;
	}

	assert(stream != NULL);
	int ch = getc(stream);
	// @RLA: such large local variables will be a problem on systems with limited memroy resources since the full variable will be allocated
	// on the stack; using the keyword static will make this variable a global variable even if you leave the declaration within the funktion
	// consider using the types from stdint.h instead of int!
	int histogram[256] = { 0 }; 
	
	int maxSizeLetter = 0;

	while (ch > EOF)
	{
		if (ch != EOF) // @RLA: this comparison is not needed if you do the histogram computation and the getc in this order
		{
			histogram[ch]++;
			// this will compute the letter that was used most often for this example.
			// the task was slightly differnt; i asked you to implement a generic funktion that is able 
			// to find the maximum element in an array. For this example the solution is efficient - but it cannot be reused!   
			if (histogram[ch] > histogram[maxSizeLetter])
			{
				maxSizeLetter = ch;
			}
		}
		ch = getc(stream);
	}

	for (int i = 0; i < 256; i++) {
		if (histogram[i] > 0)
		{
			printf("Zeichen \'%c\' = %d\n", i, histogram[i]);
		}
	}
	printf("Grösste Anzahl von Buchstabe \'%c\' = %d\n", maxSizeLetter, histogram[maxSizeLetter]);

	fclose(stream);
}

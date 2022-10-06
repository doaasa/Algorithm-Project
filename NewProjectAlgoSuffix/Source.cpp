#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <bitset>
#include <cstring>
#include <bits.h>
#include <bit>
#include <sstream>
using namespace std;
string filename = "C:\\Users\\Electronica Care\\Downloads\\chrmt.fsa";
string FinalRead = "";

void ReadandSortSuffix(string Genome)
{
	ofstream WriteFile;
	WriteFile.open("Output.txt");
	string* S = new string[Genome.length()]; //»‰⁄„· «—«Ï » ‘Ì· «·”ÿ— «·Ê«Õœ „‰ «·›«Ì·
	int* seqCount = new int[Genome.length()];


	for (int i = 0; i < Genome.length(); i++)
	{
		S[i] = FinalRead.substr(i, (FinalRead.length() - i));
		WriteFile << S[i];
		WriteFile << endl;
		seqCount[i] = i;   //for indexing suffix
	}

	WriteFile << endl;
	WriteFile << endl;
	WriteFile << "=========================================" << endl;
	WriteFile << endl;

	ofstream WriteSuffix;
	WriteSuffix.open("Suffix.txt");
	ofstream FileIndex;
	FileIndex.open("IndexFile.txt");
	int num = 0;
	string temp = "";

	for (int i = 0; i < Genome.length(); i++)
	{
		for (int j = 0; j < Genome.length() - i - 1; j++)  // »Ì⁄„· ”Ê—  ··”«›Ìﬂ” ﬂ·Â„
		{
			if (S[j] > S[j + 1])
			{
				temp = S[j];
				S[j] = S[j + 1];
				S[j + 1] = temp;
				swap(seqCount[j], seqCount[j + 1]);
			}
		}
	}
	for (int i = 0; i < Genome.length(); i++)
	{
		FileIndex << seqCount[i];
		FileIndex << endl;
		WriteSuffix << S[i]; // ﬂ «»… ﬂ· ”«›Ìﬂ” „‰ «·”ÌﬂÊ‰” »⁄œ «·”Ê—  ›Ï «·›«Ì·
		WriteSuffix << endl;
	}
	WriteSuffix << endl;
	WriteSuffix << endl;
}
void  MakeStringGenome() {
	string seqLine = "";
	string header = "";
	int i = 0;
	ifstream OpenFile;
	OpenFile.open(filename);

	getline(OpenFile, header); //»‰ﬁ—√ ”ÿ— «·ÂÌœ— ⁄·‘«‰ „‰Œ“‰ÂÊ
	while (i < 5)
	{
		getline(OpenFile, seqLine); //»‰ﬁ—√ ﬂ· ”ÿ— ›Ï «·›«Ì·

		i++;
		FinalRead += seqLine;
	}
	FinalRead += "$";
	cout << FinalRead << endl;
	cout << FinalRead.length() << endl;
	ReadandSortSuffix(FinalRead);
}
int main(int argc, char* argv[])
{
	MakeStringGenome();
	ifstream OpenTxtFile;
	OpenTxtFile.open("IndexFile.txt");
	int* arr = new int[FinalRead.length()];
	string index="";
	int i = 0;
	int c = 0;
	while (c<301)
	{
		getline(OpenTxtFile, index);
		int x =stoi(index);
		arr[i] = x;
		i++;
		c++;
	}
	ofstream BinaryFile;
	BinaryFile.open("Binary.bin");
	for (int j = 0; j < i; j++)
	{
		BinaryFile <<"the binary is hidden "<< static_cast<byte>(arr[i]);
		BinaryFile << endl;
	}
	
	cout << "End.." << endl;
	system("pause");
	return 0;
}

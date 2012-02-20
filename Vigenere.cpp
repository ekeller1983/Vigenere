/*
	Code file for Vigenere class
	Takes a variety of input and performs a Vigenere encryption 
*/
#include <fstream>
#include <sstream>
#include <cassert>
#include "Vigenere.h"
using namespace std;

// Class constructor
// Must init with a cypher
Vigenere::Vigenere(string cipher)
{
	this->cipher = cipher;
	this->cI = 0;
}

// Single char encrypt
// Takes a char, returns encrypted char
char Vigenere::encrypt(char a)
{
	char r;
	if (int(a) >= 65 && int(a) <= 90) // If uppercase
		r = static_cast<char>(65 + (((int(a) - 65) + 
		(int(toupper(cipher[cI++])) - 65)) % 26));
	else if (int(a) >= 97 && int(a) <= 122) // If lowercase
		r = static_cast<char>(97 + (((int(a) - 97) + 
		(int(toupper(cipher[cI++])) - 65)) % 26));
	else	// If not a letter, pass it
		r = a;

	if (cI >= cipher.length())
		cI = 0;

	return r;
}

// String phrase encrypt
// Takes a string, returns encrypted string
string Vigenere::encrypt(string phrase)
{
	ostringstream encrytpedPhrase;
	int cI = 0;	// Cipher index
	for (int i = 0; i < phrase.length(); i++)
	{
		if (int(phrase[i]) >= 65 && int(phrase[i]) <= 90)	// If uppercase
			encrytpedPhrase << static_cast<char>(65 + 
			(((int(phrase[i]) - 65) + (int(toupper(cipher[cI++])) - 65)) % 26));
		else if (int(phrase[i]) >= 97 && int(phrase[i]) <= 122)	// If lowercase
			encrytpedPhrase << static_cast<char>(97 + 
			(((int(phrase[i]) - 97) + (int(toupper(cipher[cI++])) - 65)) % 26));
		else	// If not a letter, pass it
			encrytpedPhrase << phrase[i];

		if (cI >= cipher.length())
			cI = 0;
	}
	return encrytpedPhrase.str();
}

// Single char decrypt
// Takes a char, returns decrypted char
char Vigenere::decrypt(char a)
{
	char r;
	if (int(a) >= 65 && int(a) <= 90) // If uppercase
		r = static_cast<char>(65 + (((int(a) - 65) - 
		(int(toupper(cipher[cI++])) - 65) + 26) % 26));
	else if (int(a) >= 97 && int(a) <= 122) // If lowercase
		r = static_cast<char>(97 + (((int(a) - 97) - 
		(int(toupper(cipher[cI++])) - 65) + 26) % 26));
	else	// If not a letter, pass it
		r = a;

	if (cI >= cipher.length())
		cI = 0;

	return r;
}

// String phrase decrypt
// Takes a string, returns decrypted string
string Vigenere::decrypt(string phrase)
{
	ostringstream decrytpedPhrase;
	int cI = 0;	// Cipher index
	for (int i = 0; i < phrase.length(); i++)
	{
		if (int(phrase[i]) >= 65 && int(phrase[i]) <= 90)	// If uppercase
			decrytpedPhrase << static_cast<char>(65 + 
			(((int(phrase[i]) - 65) - (int(toupper(cipher[cI++])) - 65) + 26) % 26));
		else if (int(phrase[i]) >= 97 && int(phrase[i]) <= 122)	// If lowercase
			decrytpedPhrase << static_cast<char>(97 + 
			(((int(phrase[i]) - 97) - (int(toupper(cipher[cI++])) - 65) + 26) % 26));
		else	// If not a letter, pass it
			decrytpedPhrase << phrase[i];

		if (cI >= cipher.length())
			cI = 0;
	}
	return decrytpedPhrase.str();
}

// Encrypts a file
// Takes a filename, encrypts file into a new file
void Vigenere::encryptFile(string filename)
{
	// Open files
	ifstream fileR;	// File to read from
	ofstream fileW;	// File to write to
	fileR.open(filename.data());
	assert(fileR.is_open());
	fileW.open(filename.insert(0, "encrypted.").data());

	// Encrypt file
	char r, w;
	while (!fileR.eof())
	{
		fileR.get(r);
		w = Vigenere::encrypt(r);
		fileW.put(w);
	}
	fileR.close();
	fileW.close();
}

// Decrypts a file
// Takes a filename, decrypts file into a new file
void Vigenere::decryptFile(string filename)
{
	// Open files
	ifstream fileR;	// File to read from
	ofstream fileW;	// File to write to
	fileR.open(filename.data());
	assert(fileR.is_open());
	fileW.open(filename.insert(0, "decrypted.").data());

	// Encrypt file
	char r, w;
	while (!fileR.eof())
	{
		fileR.get(r);
		w = Vigenere::decrypt(r);
		fileW.put(w);
	}
	fileR.close();
	fileW.close();
}
/*
	Header file for Vigenere class
*/
#ifndef __VIGENERE_H__
#define __VIGENERE_H__
#include <string>
using namespace std;

class Vigenere
{
private:
	std::string cipher;
	int cI;	// Cipher index
	Vigenere() { }	// Default constructor, private
public:
	Vigenere(string cipher);	// Default constructor
	char encrypt(char a);	// Single char encrypt
	string encrypt(string phrase);	// String phrase encrypt
	char decrypt(char a);	// Single char decrypt
	string decrypt(string phrase);	// String phrase decrypt
	void encryptFile(string filename);	// Encrypt a file
	void decryptFile(string filename);	// Decrypt a file
};

#endif
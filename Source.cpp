#include "Key.h"

void initializeMatrix(Key& key, std::string& prompt, std::vector<std::vector<char>>& matrix)
{
	int rows = 1 + (prompt.size() / key.getOrder().size());
	for (int i = 0; i < rows; i++)
	{
		std::vector<char> vect;
		for (int j = 0; j < key.getOrder().size(); j++)
		{
			vect.push_back('~');
		}
		matrix.push_back(vect);
	}
}

void printMatrix(const std::vector<std::vector<char>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void matrixEncryption(Key& key, std::string& prompt, std::vector<std::vector<char>>& matrix)
{
	// Inserting the prompt
	for (char c : prompt)
	{
		bool inserted = false;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (inserted == true) break;

			for (int j = 0; j < matrix[i].size(); j++)
			{
				if (matrix[i][j] == '~' && !inserted)
				{
					matrix[i][j] = c;
					inserted = true;
					break;
				}
			}
		}
	}

	// Filling the last empty spaces with letters
	while (matrix[matrix.size() - 1][matrix[0].size() - 1] == '~')
	{
		char c = 'a';

		for (int j = 0; j < matrix[matrix.size() - 1].size(); j++)
		{
			if (matrix[matrix.size() - 1][j] == '~')
			{
				matrix[matrix.size() - 1][j] = c;
				++c;
			}
		}
	}

	std::cout << "Encryption Matrix:\n";
	printMatrix(matrix);
}

void messageEncryption(Key& key, std::string& message, std::vector<std::vector<char>>& matrix)
{
	// Iterate from 0 to the size of the key -1
	for (int j = 0; j < key.getOrder().size(); j++)
	{
		// Iterate through the order
		for (int k = 0; k < key.getOrder().size(); k++)
		{
			if (j == key.getOrder()[k])
			{
				for (int i = 0; i < matrix.size(); i++)
				{
					message.push_back(matrix[i][k]);
				}
			}
		}
	}
}

void matrixDecryption(Key& key, std::string& message, std::vector<std::vector<char>>& matrix)
{
	int pos = 0;
	for (int k = 0; k < key.getOrder().size(); k++)
	{
		for (int i = 0; i < key.getOrder().size(); i++)
		{
			if (k == key.getOrder()[i])
			{
				for (int j = 0; j < matrix.size(); j++)
				{
					matrix[j][i] = message[pos];
					++pos;
				}
			}
		}
	}

	std::cout << "Decryption Matrix:\n";
	printMatrix(matrix);
}

void messageDecryption(Key& key, std::string& message, std::vector<std::vector<char>>& matrix)
{
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			message.push_back(matrix[i][j]);
		}
	}
}

std::string encryption(Key& key, std::string& prompt)
{
	std::vector<std::vector<char>> matrix;

	initializeMatrix(key, prompt, matrix);
	matrixEncryption(key, prompt, matrix);

	std::string encryptedMessage;
	messageEncryption(key, encryptedMessage, matrix);

	return encryptedMessage;
}

std::string decryption(Key& key, std::string& prompt, std::string& encryptedMessage)
{
	std::vector<std::vector<char>> decryptionMatrix;
	initializeMatrix(key, prompt, decryptionMatrix);
	matrixDecryption(key, encryptedMessage, decryptionMatrix);

	std::string decryptedMessage;
	messageDecryption(key, decryptedMessage, decryptionMatrix);

	return decryptedMessage;
}

int main()
{
	Key key;
	std::string keyString;
	std::string prompt;

	std::cout << "Enter the key:\n";
	std::cin >> keyString;
	std::cin.ignore();
	key.setWord(keyString);
	key.determineOrder();
	key.printWord();
	key.printOrder();

	std::cout << "Enter the message:\n";
	std::getline(std::cin, prompt);

	std::string encryptedMessage = encryption(key, prompt);
	std::cout << "Encrypted Message:\n" << encryptedMessage << "\n";

	std::string decryptedMessage = decryption(key, prompt, encryptedMessage);
	std::cout << "Decrypted Message:\n" << decryptedMessage << "\n";
	return 0;
}
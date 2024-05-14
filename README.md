Transposition Cipher Encryption and Decryption

Description:

The Transposition Cipher Encryption and Decryption application is a C++ program that encrypts and decrypts text using a transposition cipher with a key composed of distinct letters. The encryption process involves rearranging the letters of the input text based on the order of appearance of letters in the key. Decryption reverses this process to recover the original message.

Features:

1.Key Input: Users input a key composed of distinct letters. The program generates an order based on the alphabetical appearance of each letter in the key.

2.Message Input: Users input the text to be encrypted or decrypted.

3.Encryption Process:

The program constructs a matrix with a fixed number of columns equal to the length of the key.
The input text is arranged into the matrix column by column based on the order generated from the key.
If the input text does not evenly fit into the matrix, it is padded with additional characters.

4.Decryption Process:

The program constructs the decryption matrix based on the order generated from the key.
Each column of the encrypted message is filled into the decryption matrix according to the order.

5.Encryption Output: The encrypted message is displayed, showing the rearranged text based on the transposition cipher.

6.Decryption Output: The decrypted message is displayed, showing the original text recovered from the encrypted message.

Example Usage:

Enter the key:

VIRUS

Enter the message:

I have a bow

Encryption Matrix:

I   h a v

e   a   b

o w a b c

Encrypted Message:

whaavbcabIeo

Decryption Matrix:

I   h a v

e   a   b

o w a b c

Decrypted Message:

I have a bowabc

The Transposition Cipher Encryption and Decryption application provides a simple yet effective method for encrypting and decrypting text using a transposition cipher with a distinct letter key. With its straightforward interface and reliable functionality, the program serves as a valuable tool for secure communication and data privacy.

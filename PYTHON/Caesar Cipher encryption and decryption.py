import random

def caesar_cipher_encrypt(plain_text, key):
    encrypted_text = ""
    for i, char in enumerate(plain_text):
        if char.isalpha():
            shift = key[i % len(key)]
            shifted = ord(char) + shift
            if char.islower():
                if shifted > ord('z'):
                    shifted -= 26
                elif shifted < ord('a'):
                    shifted += 26
            elif char.isupper():
                if shifted > ord('Z'):
                    shifted -= 26
                elif shifted < ord('A'):
                    shifted += 26
            encrypted_text += chr(shifted)
        else:
            encrypted_text += char
    return encrypted_text

def caesar_cipher_decrypt(encrypted_text, key):
    return caesar_cipher_encrypt(encrypted_text, [-shift for shift in key])

# Test the encryption and decryption functions
plain_text = "Hello, World!"
key = [random.randint(1, 25) for _ in range(len(plain_text))]
encrypted_text = caesar_cipher_encrypt(plain_text, key)
decrypted_text = caesar_cipher_decrypt(encrypted_text, key)

print("Plain text:", plain_text)
print("Encrypted text:", encrypted_text)
print("Decrypted text:", decrypted_text)

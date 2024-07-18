def monoalphabetic_cipher(text, cipher_key):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    encrypted_text = ""
    for char in text:
        if char.isalpha():
            if char.isupper():
                shifted_char = cipher_key[alphabet.index(char.lower())].upper()
            else:
                shifted_char = cipher_key[alphabet.index(char)]
            encrypted_text += shifted_char
        else:
            encrypted_text += char
    return encrypted_text
text = input("Enter text to encrypt: ")
cipher_key = input("Enter the cipher key (26 unique letters mapping each letter): ")
encrypted_text = monoalphabetic_cipher(text, cipher_key)
print("Encrypted text:", encrypted_text)

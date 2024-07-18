def caesar_cipher(text, shift):
    encrypted_text = ""
    for char in text:
        if char.isalpha():
            shifted_char = chr((ord(char.lower()) - 97 + shift) % 26 + 97)
            if char.isupper():
                shifted_char = shifted_char.upper()
            encrypted_text += shifted_char
        else:
            encrypted_text += char

    return encrypted_text
text = input("Enter text to encrypt: ")
shift = int(input("Enter the shift value (1-25): "))
encrypted_text = caesar_cipher(text, shift)
print("Encrypted text:", encrypted_text)

def generate_vigenere_table():
    table = []
    for i in range(26):
        row = [(chr((j + i) % 26 + 65)) for j in range(26)]
        table.append(row)
    return table
def vigenere_encrypt(plaintext, key):
    table = generate_vigenere_table()
    key = key.upper()
    plaintext = plaintext.upper()
    encrypted_text = ""
    key_index = 0
    for char in plaintext:
        if char.isalpha():
            row = ord(key[key_index % len(key)]) - 65
            col = ord(char) - 65
            encrypted_text += table[row][col]
            key_index += 1
        else:
            encrypted_text += char

    return encrypted_text
key = input("Enter the key for Vigenère cipher: ")
plaintext = input("Enter the plaintext to encrypt: ")
encrypted_text = vigenere_encrypt(plaintext, key)
print("Encrypted text:", encrypted_text)

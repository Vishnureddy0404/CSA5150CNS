def generate_playfair_matrix(keyword):
    alphabet = "abcdefghiklmnopqrstuvwxyz"  # 'j' is excluded
    keyword = "".join(dict.fromkeys(keyword.lower().replace('j', 'i')))  # Remove duplicates and handle 'j'
    key = keyword + ''.join([char for char in alphabet if char not in keyword])
    matrix = [key[i:i+5] for i in range(0, 25, 5)]
    return matrix

def preprocess_text(text):
    text = text.lower().replace('j', 'i')
    processed_text = []
    i = 0
    while i < len(text):
        if i == len(text) - 1:
            processed_text.append(text[i] + 'x')
            break
        elif text[i] == text[i + 1]:
            processed_text.append(text[i] + 'x')
            i += 1
        else:
            processed_text.append(text[i] + text[i + 1])
            i += 2
    return processed_text

def find_position(matrix, char):
    for row in range(5):
        if char in matrix[row]:
            return row, matrix[row].index(char)
    return None

def encrypt_pair(matrix, pair):
    row1, col1 = find_position(matrix, pair[0])
    row2, col2 = find_position(matrix, pair[1])
    
    if row1 == row2:
        return matrix[row1][(col1 + 1) % 5] + matrix[row2][(col2 + 1) % 5]
    elif col1 == col2:
        return matrix[(row1 + 1) % 5][col1] + matrix[(row2 + 1) % 5][col2]
    else:
        return matrix[row1][col2] + matrix[row2][col1]

def playfair_encrypt(keyword, plaintext):
    matrix = generate_playfair_matrix(keyword)
    processed_text = preprocess_text(plaintext)
    encrypted_text = ''.join(encrypt_pair(matrix, pair) for pair in processed_text)
    return encrypted_text.upper()

# Get user input
keyword = input("Enter the keyword for Playfair cipher (no spaces, 'j' is treated as 'i'): ")
plaintext = input("Enter the plaintext to encrypt (only alphabets, 'j' is treated as 'i'): ")

# Encrypt the plaintext
encrypted_text = playfair_encrypt(keyword, plaintext)
print("Encrypted text:", encrypted_text)

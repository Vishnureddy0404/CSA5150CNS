def mod_inverse(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return -1

def affine_decrypt(ciphertext, a, b):
    result = ""
    a_inv = mod_inverse(a, 26)
    if a_inv == -1:
        raise ValueError("Multiplicative inverse for a does not exist. Decryption is impossible.")
    
    for char in ciphertext:
        if char.isalpha():
            # Apply the decryption formula: p = a_inv(c - b) % 26
            offset = ord('A') if char.isupper() else ord('a')
            decrypted_char = chr(((a_inv * ((ord(char) - offset) - b)) % 26) + offset)
            result += decrypted_char
        else:
            result += char
    return result

def solve_affine_cipher(c1, c2, p1, p2):
    # Solving the system of linear congruences:
    # c1 = (ap1 + b) mod 26
    # c2 = (ap2 + b) mod 26
    m = 26
    a = ((c1 - c2) * mod_inverse((p1 - p2) % m, m)) % m
    b = (c1 - a * p1) % m
    return a, b

# Most frequent letters in ciphertext and their plaintext equivalents
c1, c2 = ord('B') - ord('A'), ord('U') - ord('A')
p1, p2 = ord('E') - ord('A'), ord('T') - ord('A')

# Solving for a and b
a, b = solve_affine_cipher(c1, c2, p1, p2)
print(f"Calculated values: a = {a}, b = {b}")

# Get user input
ciphertext = input("Enter the ciphertext: ")

# Decrypt the ciphertext
try:
    decrypted_text = affine_decrypt(ciphertext, a, b)
    print("Decrypted text:", decrypted_text)
except ValueError as e:
    print(e)

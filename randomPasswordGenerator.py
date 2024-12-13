import random
import string

def generate_password(length):
    if length < 8:
        raise ValueError("Password length must be at least 8 characters.")
    
    # Character pools
    upper_case = string.ascii_uppercase
    lower_case = string.ascii_lowercase
    digits = string.digits
    special_chars = "!@#$%^&*()-_+=<>?"

    # Ensure the password contains at least one of each category
    all_chars = upper_case + lower_case + digits + special_chars
    password = [
        random.choice(upper_case),
        random.choice(lower_case),
        random.choice(digits),
        random.choice(special_chars)
    ]

    # Fill the rest of the password length with random characters
    password += random.choices(all_chars, k=length - 4)

    # Shuffle to make it random
    random.shuffle(password)

    return ''.join(password)

# Example usage
if __name__ == "__main__":
    try:
        length = int(input("Enter desired password length (minimum 8): "))
        print("Generated Password:", generate_password(length))
    except ValueError as e:
        print("Error:", e)

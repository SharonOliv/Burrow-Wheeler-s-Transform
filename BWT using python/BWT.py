def burrows_wheeler_transform(text):
    n = len(text)
    rotations = [text[i:] + text[:i] for i in range(n)]
    sorted_rotations = sorted(enumerate(rotations), key=lambda x: x[1])
    transformed_text = ''.join(rotation[-1] for _, rotation in sorted_rotations)
    return transformed_text

def main():
    choice = int(input("Choose input option:\n1. Enter text manually\n2. Input text from file\n"))
    if choice == 1:
        text = input("Enter the text: ")
    elif choice == 2:
        filename = input("Enter the filename containing the text: ")
        with open(filename, 'r') as file:
            text = ''.join(file.readlines())
    else:
        print("Invalid choice.")
        return

    bwt = burrows_wheeler_transform(text)
    print("Burrows-Wheeler Transform:", bwt)

if __name__ == "__main__":
    main()

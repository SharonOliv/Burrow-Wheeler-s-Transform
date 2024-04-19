def burrows_wheeler_transform(text):
    rotations = [text[i:] + text[:i] for i in range(len(text))]
    sorted_rotations = sorted(rotations)
    transformed_text = ''.join(rotation[-1] for rotation in sorted_rotations)
    return transformed_text

def main():
    choice = int(input("Choose input option:\n1. Enter text manually\n2. Input text from file\n"))

    if choice == 1:
        text = input("Enter the text: ")
    elif choice == 2:
        filename = input("Enter the filename containing the text: ")
        try:
            with open(filename, 'r') as file:
                text = file.read()
        except FileNotFoundError:
            print("File not found. Please check the filename and path.")
            return
        except Exception as e:
            print("An error occurred while reading the file:", e)
            return
    else:
        print("Invalid choice.")
        return

    bwt = burrows_wheeler_transform(text)
    print("Burrows-Wheeler Transform:", bwt)

if __name__ == "__main__":
    main()

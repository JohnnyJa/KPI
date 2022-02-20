import Functions

def main():
    f = int(input("Enter (0) if you want to clear file, enter (1) if you want to append: "))
    if f == 0:
        in_file = open('input.txt', 'wt')
    else:
        in_file = open('input.txt', 'at')

    Functions.write_file(in_file, Functions.get_input())
    in_file.close()

    in_file = open('input.txt', 'rt')
    print("input.txt: ")
    text = Functions.read_file(in_file)
    print('\n'.join(text))
    in_file.close()

    out_file = open('output.txt', 'wt')
    print("output.txt: ")
    print(Functions.process_string(text))
    Functions.write_file(out_file,Functions.process_string(text))
    out_file.close()

if __name__ == '__main__':
    main()



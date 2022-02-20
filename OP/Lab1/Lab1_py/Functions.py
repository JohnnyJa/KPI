import fileinput


def write_file(file, text):
    file.write(text)


def get_input():
    a = []
    for s in fileinput.input():
        a.append(s.strip())
    return '\n'.join(a) + '\n'


def read_file(file):
    return file.readlines()


def process_string(text):
    output_text = []
    for row in text:
        if row[0] != '#':
            output_text.append(row)
    for row in text:
        if row[0] == '#':
            row = row[1:len(row)]
            row = row[0:int(len(row)/2)] + '!' + row[int(len(row)/2):int(len(row))]
            output_text.append(row)
    return ''.join(output_text)
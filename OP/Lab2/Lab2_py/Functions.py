def write_new_data():
    file = open('AllProductList.dat', 'wb')
    num = int(input('Input number of products: '))
    print('\n---------------------------------------------------------------------\n')
    for i in range(num):
        product_name = input('Input product name:\n')
        release_date = input('Input release date:\n')
        expiration_date = input('Input expiration date:\n')
        file.write((product_name + ' ' + release_date + ' ' + expiration_date + '\n').encode())
        print('\n---------------------------------------------------------------------\n')
    file.close()


def add_data():
    file = open('AllProductList.dat', 'ab')
    num = int(input('Input number of products: '))
    print('\n---------------------------------------------------------------------\n')
    for i in range(num):
        product_name = input('Input product name:\n')
        release_date = input('Input release date:\n')
        expiration_date = input('Input expiration date:\n')
        file.write((product_name + ' ' + release_date + ' ' + expiration_date + '\n').encode())
        print('\n---------------------------------------------------------------------\n')
    file.close()


def check_info(path):
    print('\n---------------------------------------------------------------------\n')
    file = open(path, 'rb')
    for line in file:
        info = line.decode().split()
        print('Product name: ' + info[0] + '; Release date: ' + info[1] + '; Expiration date: ' + info[2] + '; \n')
    file.close()
    print('\n---------------------------------------------------------------------\n')


def edit_date():
    file = open('Date.dat', 'wb')
    date = input('\nEnter date: ')
    file.write(date.encode())
    file.close()


def check_date():
    file = open('Date.dat', 'rb')
    date = file.readline().decode()
    print('\nCurrent date is: ' + date + '\n\n')
    file.close()


def STR_to_JDN(date):
    day = int(date[:2])
    month = int(date[3:5])
    year = int(date[6:])
    a = int((14 - month) / 12)
    y = year + 4800 - a
    m = month + 12 * a - 3
    return day + int(((153 * m + 2) / 5)) + 365 * y + int((y / 4)) - int((y / 100)) + int((y / 400)) - 32045

def process_files():
    date_file = open('Date.dat', 'rb')
    date_str = date_file.readline().decode()
    date_file.close()
    curr_date = STR_to_JDN(date_str)

    AllPrFile = open('AllProductList.dat', 'rb')
    LTPrFile = open('Long-termStorageProductsList.dat', 'wb')
    PerPrFile = open('PerishableProductsList.dat', 'wb')

    for line in AllPrFile:
        info = line.decode().split()
        exp_date = STR_to_JDN(info[2])
        rel_date = STR_to_JDN(info[1])
        if(exp_date >= curr_date):
            if(exp_date - rel_date <= 5):
                PerPrFile.write(' '.join(info).encode())
            else:
                LTPrFile.write(' '.join(info).encode())


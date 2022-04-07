import Functions


def main():
   flag = True
   while(flag):
      b = int(input('What do you want to do?\n 1 - Create new data file\n 2 - Edit data file\n 3 - Check info \n 4 - Edit date\n'))
      if(b == 1):
         Functions.write_new_data()
         Functions.process_files()
      elif(b == 2):
         Functions.add_data()
         Functions.process_files()
      elif(b == 3):
         a = int(input('\nWhat info do yu want to check?\n 1 - All product list\n 2 - Perishable products list\n 3 - Long-term storage products list\n 4 - Date\n'))
         if(a == 1):
            print('\nAll Product List: ')
            Functions.check_info('AllProductList.dat')
         elif(a == 2):
            print('\nPerishable Products List: ')
            Functions.check_info('PerishableProductsList.dat')
         elif (a == 3):
            print('\nLong-term Storage Products List: ')
            Functions.check_info('Long-termStorageProductsList.dat')
         elif (a == 4):
            Functions.check_date()
         else:
            print('Error: Wrong input')
      elif(b == 4):
         Functions.edit_date()
         Functions.process_files()
      else:
         print('Work stopped.')
         flag = False

if __name__ == '__main__':
   main()

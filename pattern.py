#Atharva Gujar , Pattern codes 22nd Aug 2022

def pattern1(rows):   
    for i in range(rows):           # *
        for j in range(i):          # **
            print("*",end=" ")      # ***   
        print()                     # ****

#pattern1(7)     

def pattern2(rows,coloumn):         # ****
    for i in range(rows):           # ****
        for j in range(coloumn):    # ****
            print("*",end=' ')      # ****
        print()    

#pattern2(5,6)

def pattern3(rows):                 # ***** 
    for i in range(rows,0,-1):      # ****
        for j in range(i):          # ***
            print("* ",end=' ')     # **
        print()                     # *

#pattern3(7)        

def pattern4(rows):                 # 1
    for i in range(1,rows+1):       # 12
        for j in range(1,i+1):      # 123
            print(j,end=' ')        # 1234
        print()                     # 12345

#pattern4(6)       

def pattern5(n):                    # *
    for i in range(2*n):            # **
        if i > n:                   # ***
            col = 2*n - i           # ****
        else :                      # ***
            col = i                 # **
        for j in range(col):        # *    
            print("*",end=' ')
        print()                       


#pattern5(5)        

def pattern28(rows):                #      *
    for i in range(2*rows):         #     * *
        if i > rows:                #    * * *
            col = 2*rows - i        #   * * * *
        else:                       #  * * * * *
            col = i                 #   * * * *
        space = rows - col          #    * * *
        for x in range(space):      #     * *    
            print(end=' ')          #      *
        for j in range(col):
            print("*",end=' ')
        print()

#pattern28(6)

def pattern10(rows):
    for i in range(rows+1):         #        *
        space = rows - i            #       * *
        for x in range(space,0,-1): #      * * * 
            print(end=' ')          #     * * * *
                                    #    * * * * *
        for j in range(i):
            print("*",end=' ')
        print()
#pattern10(7)

def pattern6(rows):
    for i in range(rows+1):         #       *
        space = rows - i            #      **
        for x in range(space,0,-1): #     ***
            print(end=' ')          #    ****
        col = rows - space          #   *****
        for j in range(col):
            print('*',end='')
        print()        

#pattern6(5)        

def pattern7(rows):
    for i in range(rows):           #  *****
        for x in range(i):          #   ****
            print(end=' ')          #    ***
        col = rows - i              #     **
        for j in range(col):        #      *
            print('*',end='')
        print()        

#pattern7(5)        

def pattern8(rows):
    for i in range(rows+1):         #     *
        space = rows-i              #    ***
        for x in range(space,0,-1): #   *****
            print(end=' ')          #  *******
        for j in range(2*i-1):      # *********
            print('*',end='')   
        print()

#pattern8(5)    

def pattern9(rows):                 # *********
    for i in range(rows):           #  *******
        space = i                   #   *****
        for x in range(space):      #    ***
            print(end=' ')          #     *
        col = 2*rows-(2*i+1)
        for j in range(col):
            print("*",end='')
        print()

#pattern9(4)

def pattern11(rows):
    for i in range(rows):           # * * * * *
        space = i                   #  * * * *
        for x in range(space):      #   * * *
            print(end=' ')          #    * *
        col = rows - i              #     *
        for j in range(col):
            print("*",end=' ')
        print()
#pattern11(5)        

def pattern12(rows):                #  * * * * *
    for i in range(2*rows):         #   * * * *
        if i < rows:                #    * * *
            col = rows-i            #     * *
        else:                       #      *
            col = i - rows+1        #      *
        space = rows - col          #     * *
        for x in range(space):      #    * * *
            print(end=' ')          #   * * * *
        for j in range(col):        #  * * * * *
            print("*",end=' ')        
        print()
#pattern12(7)

#def pattern13(rows):
#    for i in range(rows):           #       *
#        space = rows - i -1         #      * *
#        for x in range(space):      #     *   *
#            print(' ',end='')       #    *     *
#                                    #   *********
#        for j in range(2*i+1):
#            if j == 0 or j==2*i:
#                print('*',end='')
#            else:
#                if i==rows-1:
#                    print('*',end='')
#                else:
#                    print(' ',end='')

#        print()

#pattern13(5)

def pattern14(rows):
    for i in range (0,2*rows+1):        #   * * * * *
        if i >rows:                     #   * * * *
            col = i-rows                #   * * *
        elif i == rows:                 #   * * 
            continue                    #   *
        else:                           #   *
            col = rows-i                #   * *
        for j in range(col):            #   * * * 
                print('*',end=' ')      #   * * * *
        print()                         #   * * * * *

#pattern14(5)        


def pattern15(rows):
    for i in range(rows):
        if i ==rows:
            col = 2*rows
        else:
            col = 2*rows 
              
        for j in  range(col):
            print('*',end=' ')    
        print()    

#pattern15(5)        
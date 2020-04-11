#!/usr/bin/python

def numberOfSteps(number):
    if number < 0:
        return -1;
    
    cnt = 0

    while number != 0:
        if number & 1:
            number -= 1
        else:
            number >>= 1
        cnt += 1
    
    return cnt

def main():
    print('Hello World\n\n')
    for x in range(0, 33, 1):
        print("%d : %d" %(x, numberOfSteps(x)))

if __name__ == '__main__':
    main()
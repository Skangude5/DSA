import os


class Stack:
    def __init__(self):
        self.arr = []
        self.Top = -1

    def push(self, a):
        self.Top += 1
        self.arr.append(a)
        print("Element {} push successful".format(a))

    def pop(self):
        try:
            self.Top -= 1
            return self.arr.pop(self.Top+1)
        except:
            self.Top += 1
            print("Stack underflow!")

    def count(self):
        return len(self.arr)

    def isEmpty(self):
        if len(self.arr) == 0:
            return True
        else:
            return False

    def peek(self, position):
        if len(self.arr) >= position > 0:
            return self.arr[position - 1]
        else:
            print("No element present at {} position in Stack".format(position))

    def change(self, position, value):
        if len(self.arr) >= position > 0:
            self.arr[position - 1] = value
        else:
            print("No element present at {} position in Stack".format(position))

    def display(self):
        if len(self.arr) != 0:
            print("Displaying Stack.....")
            for i in range(self.Top+1):
                print(self.arr[self.Top-i])
        else:
            print("Stack is Empty")


if __name__ == '__main__':
    stack = Stack()
    displaylist = ["1. display stack", "2. push element", "3. pop element", "4. peek element", "5. change element","6. count of stack", "7. isEmpty", "0. exit", "input :"]
    while (True):
        print("\n\n")
        for i in displaylist:
            print(i)
        try:
            choice = int(input())
            os.system("clear")
            if choice == 1:
                stack.display()
            elif choice == 2:
                stack.push(input("Enter Element:"))
            elif choice == 3:
                print("Pop Element is :", stack.pop())
            elif choice == 4:
                inputValue = int(input("Enter Position to peek:"))
                print(stack.peek(inputValue))
            elif choice == 5:
                inputValue1 = int(input("Enter Position to peek:"))
                inputValue2 = input("Enter Element:")
                stack.change(inputValue1, inputValue2)
            elif choice == 6:
                print("Count of Stack is :", stack.count())
            elif choice == 7:
                print("isEmpty :", stack.isEmpty())

            elif choice == 0:
                print("Exiting...")
                break
            else:
                print("Invalid choice")
        except:
            print("Invalid choice: ")

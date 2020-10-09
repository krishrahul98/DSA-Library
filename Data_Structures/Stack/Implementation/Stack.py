# Stack implementation in Python

# Creating a stack
def create_stack():
    stack = []
    return stack


# Creating an empty stack
def check_empty(stack):
    return len(stack) == 0


# Adding element/item into the stack
def push(stack, item):
    stack.append(item)
    print("pushed item: " + item)


# Removing an element from the stack
def pop(stack):
    if (check_empty(stack)):
        return "stack is empty"

    return stack.pop()


stack = create_stack()
push(stack, str(10))
push(stack, str(20))
push(stack, str(30))
push(stack, str(40))
push(stack, str(50))
push(stack, str(60))
push(stack, str(70))
push(stack, str(80))
print("popped item: " + pop(stack))
print("Stack after popping an element: " + str(stack))
print("popped item: " + pop(stack))
print("Stack after popping an element: " + str(stack))
print("popped item: " + pop(stack))
print("Stack after popping an element: " + str(stack))

"""Ouput:
pushed item: 10
pushed item: 20
pushed item: 30
pushed item: 40
pushed item: 50
pushed item: 60
pushed item: 70
pushed item: 80
popped item: 80
Stack after popping an element: ['10', '20', '30', '40', '50', '60', '70']
popped item: 70
Stack after popping an element: ['10', '20', '30', '40', '50', '60']
popped item: 60
Stack after popping an element: ['10', '20', '30', '40', '50'] """



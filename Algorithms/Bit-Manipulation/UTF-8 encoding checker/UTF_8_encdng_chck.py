s=input("Enter the string to check the utf-8 validation for: ")
valid_utf8 = True
try:
    s.encode().decode('utf-8')
except UnicodeDecodeError:
    valid_utf8 = False
if(valid_utf8):
    print("Its a valid UTF-8 string")
else:
    print("Its not a valid UTF-8 string ")
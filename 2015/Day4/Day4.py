import hashlib

hashNum = 0

while(True):
    BHashNum = bytes(str(hashNum), 'utf-8')
    result = hashlib.md5(b"iwrupvqb" + BHashNum)
    DData = result.hexdigest()

    if DData[0:5] == "00000":
        print(hashNum)
        break
    else:
        hashNum += 1
        if (hashNum % 10000 == 0):
            print(hashNum)


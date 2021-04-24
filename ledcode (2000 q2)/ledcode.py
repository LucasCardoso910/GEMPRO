letters = {
    123457: 'A',
    1234567: 'B',
    456: 'C',
    1580: 'D',
    12456: 'E',
    1249: 'F',
    12569: 'G',
    13457: 'H',
    37: 'I',
    3567: 'J',
    13459: 'K',
    156: 'L',
    12357: 'M',
    3579: 'N',
    123567: 'O',
    1458: 'P',
    12347: 'Q',
    123459: 'R',
    12467: 'S',
    278: 'T',
    13567: 'U',
    1379: 'V',
    135790: 'W',
    90: 'X',
    1347: 'Y',
    23456: 'Z',
    0 : ' ',
}

with open("ledcode.in", "r") as in_file:
    number_strings = int(in_file.readline())
    data = in_file.read()

data = data.split('\n')

count = 1
for string in data:
    string_final = []
    number_list = []

    for character in string:
        if character.isalpha() or character == ' ':
            string_final.append(character)
        else:
            number_list.append(character)
            number = ''.join(number_list)

            key = int(number)
            if key in letters:
                letter = letters[key]
                number_list = []

                string_final.append(letter)
    
    with open("ledcode.out", "a") as out_file:
        out_file.write('Phrase ' + str(count) + ': ' + ''.join(string_final))

        if count != number_strings:
            out_file.write('\n')
    
    count += 1

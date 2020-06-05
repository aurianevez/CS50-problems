import csv
from sys import argv, exit


# checking if the commend line argument were correctly entered
if len(argv) != 3:
    print("command line argument should be: csv file followed by text file")
    exit(1)

# opening doc
for i in range(len(argv)):
    csv_input = open(argv[1], 'r')
    txt_input = open(argv[2], 'r')

# Extract the STRs into a list by taking the first row of reader file [1:]
# the nest function allows to substract the first column "name"
str_list = next(csv.reader(csv_input))[1:]


# reading the database into the dictionary
reader = csv.DictReader(csv_input)


# defining dna txt file as a string in order to iterate over is with substring
dna = txt_input.read()


# defining the list that will store the count of the succesive STRs
result = []  # list to store the results


# loop that goes over the different str
for i in range(len(str_list)):
    # counter set to one for every str
    count = 1  # start at one in order to count [j:j+l] (the first str of the sequence)
    countmax = 0
    l = len(str_list[i])

    # loop that iterate over every substring in order to compare with STR[i]
    for j in range(len(dna)):
        if dna[j: j + l] == str_list[i]:  # section on dna string matches an str
            if dna[j + l: j + l + l] == str_list[i]:
                count += 1  # ading one to the actual sequence
                j = j + l
            if dna[j + l: j + l + l] != str_list[i]:
                if count > countmax:
                    countmax = count
                    count = 1
                    j = j + l

    result.append(str(countmax))


# creating a list from csv file in order to compare with the result of the DNA alysis
data_base = list(csv.reader(csv_input))


# creating a list for people's name
people = []

# appending ppl's name to the list
for x in data_base:
    people.append(x[0])


# removing the column name in every list in order to keep only the rulst to compare it to result[]
for x in data_base:
    del x[0]


# setting counter for the loop
# that counts the number of check
# if nmb check = nbr ppl --> no match
count = 0

# checking in the an alement of the list result correspond with a row in the database
for i in range(len(people)):
    if result == data_base[i]:
        print(people[i])

    if result != data_base[i]:
        count += 1
        if count == len(people):
            print("No match")

# closing files
csv_input.close()
txt_input.close()

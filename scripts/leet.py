#!/bin/bash

import os
import sys
import re
import requests


def get_help():
    print("leet: command line tool to manage leetcode programs.")
    print("\t-get [no]: get the number of the question which is not solved.")
    print("\t-new [no]: create a new folder for the code not solved")
    print("\t-glink no: get the link for question number")


def get_list():
    remote_url = 'https://raw.githubusercontent.com/shivanshu-semwal/leetcode/master/leetcode/lists.md'
    local_file = os.path.join(os.getcwd(), 'lists.md')
    data = requests.get(remote_url)
    if data.status_code != 200:
        print("Unable to download list.md file.")
        exit(1)
    with open(local_file, 'wb')as file:
        file.write(data.content)


def get_new(counter: int) -> int:
    folder = os.getcwd()
    for i in range(1, 3000, 100):
        dir = str(i) + "-" + str(i + 100 - 1)
        if not os.path.isdir(dir):
            os.mkdir(dir)
        if os.path.isdir(os.path.join(folder, dir)):
            for j in range(i, i + 100 - 1):
                sdir = os.path.join(dir, str(j))
                if not os.path.isdir(sdir):
                    if counter == 1:
                        return j
                    else:
                        counter -= 1


def get_link(no: int) -> str:
    folder = os.getcwd()
    with open(folder + "/lists.md") as f:
        l = f.readlines()
        if no - 1 < len(l):
            return re.findall("https:[^)]*", l[no - 1])[0]


def create_new(no: int):
    t = ((no - 1) // 100) * 100
    folder = os.getcwd()

    s_dir = str(t + 1) + "-" + str(t + 100)
    s_dir = os.path.join(folder, s_dir)

    dir = os.path.join(s_dir, str(no))
    dir = os.path.join(folder, dir)

    if not os.path.isdir(s_dir):
        os.mkdir(s_dir)

    if not os.path.isdir(dir):
        os.mkdir(dir)

    with open(os.path.join(dir, "1.cpp"), "w") as f:
        link = get_link(no)
        f.write("// " + link + "\n")


if __name__ == "__main__":
    n = len(sys.argv)

    list_file = os.path.join(os.getcwd(), "lists.md")
    if not os.path.isfile(list_file):
        get_list()

    if n == 1:
        get_help()
    elif sys.argv[1] == "-get":

        if n == 2:
            print(get_new(1))
        elif n == 3 and sys.argv[2].isnumeric():
            print(get_new(int(sys.argv[2])))
        else:
            get_help()

    elif sys.argv[1] == "-new":

        if n == 2:
            create_new(get_new(1))
        elif n == 3 and sys.argv[2].isnumeric():
            create_new(int(sys.argv[2]))
        else:
            get_help()

    elif sys.argv[1] == "-glink":

        if n == 3 and sys.argv[2].isnumeric():
            print(get_link(int(sys.argv[2])))
        else:
            get_help()

    else:
        get_help()

import os

file_list = os.listdir("./data")

os.system("rm ./out/*")

for file_name in file_list:
    os.system("./bin/main.out ./data/{} | tee ./out/{}.log".format(file_name, file_name))

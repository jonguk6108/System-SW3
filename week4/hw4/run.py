import os

file_list = os.listdir("./ppm")

if (not os.path.isdir("./out")):
    os.system("mkdir out")

for file_name in file_list:
    print file_name + " : " ,
    cmd = "./bin/main.out ./ppm/%s ./out/%s.pbm ./out/%s.pgm ./out/%s.ppm" % (file_name, file_name[:-4], file_name[:-4], file_name[:-4])
    os.system(cmd)
    print ""

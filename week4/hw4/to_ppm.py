import os
from PIL import Image
import numpy as np

img_list = os.listdir("./png")

if (not os.path.isdir("./ppm")):
    os.system("mkdir ppm")

for file_name in img_list:
    img = Image.open("./png/" + file_name)

    img_array = np.array(img)

    if (".png" in file_name):
        for i in range(3):
            img_array[:,:,i] = (img_array[:,:,i] * (img_array[:,:,-1]/255) + 255 * (1 - img_array[:,:,-1]/255)).astype(np.uint8)
        img_array = img_array[:,:,:-1]

    ppm = open("./ppm/%s.ppm" % (file_name[:-4]), "w")

    ppm.write("P3\n%d %d\n255\n" % (img_array.shape[1], img_array.shape[0]))

    for i in range(img_array.shape[0]):
        if (i != 0):
            ppm.write("\n")
        for j in range(img_array.shape[1]):
            if (j!=0):
                ppm.write(" ")
            ppm.write("%d %d %d" % (img_array[i,j,0], img_array[i,j,1], img_array[i,j,2]))

    if (np.random.binomial(1, 0.5, 1)[0] == 1):
        ppm.write("\n")
    ppm.close()

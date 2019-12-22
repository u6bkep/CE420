#!/usr/bin/python3

from PIL import Image
from PIL import ImageSequence
import sys

im = Image.open(sys.argv[1])

print("const typeDotstarFrame frame[" , im.n_frames , "] = {")
index = 0
for frame in ImageSequence.Iterator(im):
    print("    {{")

    print("//frame number ", index)
    index += 1
    for pixel in list(frame.getdata()):

        print("        {0b11100011,", "0x55,0x00,0x00" if pixel == 1 else "0x00,0x00,0x55","},")
        #print(pixel)

    print("    }},")

print("};")
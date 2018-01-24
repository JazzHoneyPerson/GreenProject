import urllib.request
import numpy as np
import math
from PIL import Image, ImageDraw

def sort(*arr):
    for i in range(1):
        if arr[0+i]>arr[2 + i]:
            t=arr[0+i]
            arr[0+i]=arr[2+i]
            arr[2+i]=t
def download(url, name):
    img = urllib.request.urlopen(url).read()
    out = open(name, "wb")
    out.write(img)
    out.close()
    return Image.open(name)
def diff(col,R,G,B):
    return math.sqrt((col[0]-R)**2+(col[1]-G)**2+(col[2]-B)**2)

Coordinates=np.array([56.854886, 60.573581,56.812489, 60.648804])



step=0.000488
x=-1
for Lat in np.arange(Coordinates[1],  Coordinates[3], step):
    x+=1
    y=-1
    for Long in np.arange(Coordinates[0], Coordinates[2],-step):
        y+=1
        LatLong=str(Long)+","+str(Lat)
        sputnik=download("https://maps.googleapis.com/maps/api/staticmap?center="+LatLong+"&zoom=19&format=png32&size=640x640&maptype=satellite&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4", "sputnik.png")
        #interface=download("https://maps.googleapis.com/maps/api/staticmap?size=640x640&zoom=19&center="+LatLong+"&style=feature:all|element:labels|visibility:off&format=png32&style=feature:all|element:geometry.fill|color:0xffffff&style=feature:all|element:geometry.stroke|color:0x000000&style=feature:road|color:0x857b7b&style=feature:water|color:11689eb&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4","interface.png")
        #map=download("https://maps.googleapis.com/maps/api/staticmap?center="+LatLong+"&zoom=19&size=640x640&style=feature:all|element:labels|visibility:off&format=png32&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4","map.png")
        pixS=sputnik.load()
        #pixM=map.load()
        draw = ImageDraw.Draw(sputnik)
        for i in range(182):
	            for j in range(332):
		            r = pixS[i, j][0]
		            g = pixS[i, j][1]
		            b = pixS[i, j][2]
		            if(r+b-g<75 and g>b and g>r):
		                    draw.point((i, j), (r//2, g,b//2))
		            else:
		                    draw.point((i, j), ((r+g+b)//3, (r+g+b)//3,(r+g+b)//3))
        LatLong=str(x)+","+str(y)
        img3 = sputnik.crop((0,0,182,332))
        img3.save("map("+LatLong+").png", "PNG")
        del draw
        


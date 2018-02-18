import urllib.request
import numpy as np
import math
from PIL import Image, ImageDraw
 
def download(url, name):#downloading the map
    img = urllib.request.urlopen(url).read()
    out = open(name, "wb")
    out.write(img)
    out.close()
    return Image.open(name)
def diff(col,R,G,B):#difference between colors
    return math.sqrt((col[0]-R)**2+(col[1]-G)**2+(col[2]-B)**2)
 
Coordinates=np.array([56.854886, 60.573581,56.812489, 60.648804])#starting and ending coordinates
 
step=0.000488
x=-1#для правильного сохранения названия картинок
for Lat in np.arange(Coordinates[1],  Coordinates[3], step):#получение широты с шагом 0.00048
    x+=1
    y=-1
    for Long in np.arange(Coordinates[0], Coordinates[2],-step):#проход по долготе с шагом
        y+=1
        LatLong=str(Long)+","+str(Lat)
        sputnik=download('https:/maps.googleapis.com/maps/api/staticmap?center='+LatLong+'&zoom=19&format=png32&size=640x640&maptype=satellite&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4', 'sputnik.png')
        pal=download('https:/maps.googleapis.com/maps/api/staticmap?center='+LatLong+'&style=feature:all|element:labels|visibility:off&zoom=19&format=png32&size=640x640&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4', 'pam.png')
        #downloading from sputnik
        pixS=sputnik.load()#массив пикселей со спутника
        pixM=pal.load()
        draw = ImageDraw.Draw(sputnik)
        for i in range(182):#массив пикселей
            for j in range(332):
                r = pixS[i, j][0]
                g = pixS[i, j][1]
                b = pixS[i, j][2]
                if(r+b-g<75 and g>b and g>r):#условие для определения цвета пикселей с полученной со спутника растровой картинки
                        draw.point((i, j), (30, 200,30))#цвет закраски
                else:
                        qdraw.point((i, j), (pixM[i,j][0], pixM[i,j][1],pixM[i,j][2]))#закраска ч/б в случае несоответствия с условием цикла
 
        LatLong=str(x)+","+str(y)
        img3 = sputnik.crop((0,0,182,332))
        img3.save("map("+LatLong+").png", "PNG")
        img3.save("map().png", "PNG")
        del draw#удаляем объект

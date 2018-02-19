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
def condition(col):
    return col[0]+col[2]-col[1]<50 and col[1]>col[2] and col[1]>col[0]
def diff(col,R,G,B):#difference between colors
    return math.sqrt((col[0]-R)**2+(col[1]-G)**2+(col[2]-B)**2)
def getColors(url, name):
    picture=download(url, name)
    return picture.load()
Coordinates=np.array([56.854886, 60.573581,56.812489, 60.648804])#starting and ending coordinates
 
step=0.000488
x=-1#для правильного сохранения названия картинок
for Lat in np.arange(Coordinates[1],  Coordinates[3], step):#получение широты с шагом 0.00048
    x+=1
    y=-1
    for Long in np.arange(Coordinates[0], Coordinates[2],-step):#проход по долготе с шагом
        y+=1
        LatLong=str(Long)+","+str(Lat)
        sputnik=getColors('https://maps.googleapis.com/maps/api/staticmap?center='+LatLong+'&zoom=19&format=png32&size=450x450&maptype=satellite&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4', 'may.png')
        sputnikya=getColors('https://static-maps.yandex.ru/1.x/?ll='+str(Lat)+','+str(Long)+'&size=450,450&z=19&l=sat', 'AySat')
        pal=getColors('https://maps.googleapis.com/maps/api/staticmap?center='+LatLong+'&style=feature:all|element:labels|visibility:off&zoom=19&format=png32&size=450x450&key=AIzaSyBd7DMOTTilre43iTilXMGru34D15yHxO4', 'pam.png')
        #downloading from sputnik
        img = Image.open('Amap.png')
        draw = ImageDraw.Draw(img)
        for i in range(450):#массив пикселей
            for j in range(450):
                if (condition(sputnik[i, j]) or condition(sputnikya[i, j])) and  pal[i, j][0]==223 and pal[i, j][1]==223 and pal[i, j][2]==223:#условие для определения цвета пикселей с полученной со спутника растровой картинки
                        draw.point((i, j), (0, 255,0))#цвет закраски
                else:
                    draw.point((i, j), sputnik[i, j])
                        #draw.point((i, j), (pixM[i, j][0], pixM[i, j][1],pixM[i, j][2]))
        LatLong=str(x)+","+str(y)
        img3 = img.crop((0,0,182,332))
        img3.save("map("+LatLong+").png", "PNG")
        img3.save("map().png", "PNG")
        del draw#удаляем объект

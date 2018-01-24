from PIL import Image

def Paste(img, x, y):
    try:
        Pimg = Image.open("testideas/testideas/map("+str(x)+","+str(y)+").png")
        Minimg= Pimg.resize((36, 66), Image.ANTIALIAS)
        img.paste(Minimg, (x*36, y*66))
    except FileNotFoundError:
        pass
    return img
    
img = Image.new('RGB', (2088, 5610))

for x in range(57):
    for y in range(86):
        img=Paste(img, x, y)
im = "map.png"
img.save(im,"PNG")

 
# im.show()

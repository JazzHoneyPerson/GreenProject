from PIL import Image, ImageDraw

for step in range(1,17):
    pallete = Image.open("PresentForPython/pallete("+str(step)+").jpg")
    interface=Image.open("PresentForPython/GMap("+str(step)+").jpg")
    draw = ImageDraw.Draw(interface)
    pix = pallete.load()
    pix1 = interface.load()
    for i in range(256):
		    for j in range(256):
			    a = pix[i, j][0]
			    b = pix[i, j][1]
			    c = pix[i, j][2]
			    if (a!=220 or b!=220 or c!=220):
				    draw.point((i, j), (23, 134, 54))
    interface.save("map("+str(step)+").jpg", "JPEG")
    del draw

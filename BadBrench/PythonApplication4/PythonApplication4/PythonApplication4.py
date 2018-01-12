from PIL import Image, ImageDraw

for step in range(1,228):
    pallete = Image.open("PresentForPython/pallete("+str(step)+").jpg")
    interface=Image.open("PresentForPython/GInterface("+str(step)+").jpg")
    map=Image.open("PresentForPython/GMap("+str(step)+").jpg")
    draw = ImageDraw.Draw(interface)
    pix = pallete.load()
    pix1 = map.load()
    for i in range(256):
		    for j in range(256):
			    a = pix[i, j][0]
			    b = pix[i, j][1]
			    c = pix[i, j][2]
			    re = pix1[i, j][0]
			    gr = pix1[i, j][1]
			    bl = pix1[i, j][2]
			    if ( (a!=220 or b!=220 or c!=220) and ((re==222 and gr==222 and bl==222) or (re==223 and gr==223 and bl==223) or (re==203 and gr==230 and bl==163))):
				        draw.point((i, j), (23, 134, 54))
    img3 = interface.crop((0,0,255,512))
    img3.save("map("+str(step)+").jpg", "JPEG")
    del draw


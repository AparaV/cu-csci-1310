import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

imgWhite = mpimg.imread('white_2.jpg')
#print white.shape
imgBlack = mpimg.imread('hello.jpg')

width = 500
height = 500

size = 50
something = True
x = 0
alternate = False

while x <= 500 - size:
	if alternate:
		y = 0
		while y <= 500 - size:
			endC = x + size
			endR = y + size
			imgBlack[y:endR, x:endC] = imgWhite[y:endR, x:endC]
			y += 2*size
	else:
		y = size
		while y <= 500 - size:
			endC = x + size
			endR = y + size
			imgBlack[y:endR, x:endC] = imgWhite[y:endR, x:endC]
			y += 2*size			
	#imgPlot = plt.imshow(imgBlack)
	#plt.show()
	alternate = not alternate
	x += size
	

imgPlot = plt.imshow(imgBlack)
plt.show()

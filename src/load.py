import cv2 as cv

file = cv.imread(r"C:\Users\drpre\OneDrive\Pictures\Camera Roll\WIN_20240817_17_02_12_Pro.jpg",
                 cv.IMREAD_GRAYSCALE)

height = file.shape[0]
width = file.shape[1]

with open('text1.txt', 'w') as f:
    f.write(f"{height} {width}\n")
    for i in range(height):
        for j in range(width):
            
            f.write(f"{file[i, j]} ")
       
        f.write("\n")

cv.imshow('Image', file)
print("Grayscale values have been written to text1.txt.")

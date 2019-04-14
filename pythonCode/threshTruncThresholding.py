import cv2

thresholdValue = 150
maxValue = 255

#callback method for trackbar value change
def onTrackbarValueChange(*args):
    global thresholdValue
    thresholdValue = args[0]
    print(thresholdValue)
    th, result = cv2.threshold(image, thresholdValue, maxValue, cv2.THRESH_TRUNC)
    cv2.imshow("image", result)

#Read image
image = cv2.imread("../assets/putin.jpg", cv2.IMREAD_GRAYSCALE)

#create window
cv2.namedWindow("image", cv2.WINDOW_NORMAL)

#create trackbar
cv2.createTrackbar("Value", "image", thresholdValue, maxValue, onTrackbarValueChange)

#call method to initialize first time
onTrackbarValueChange(thresholdValue)

while True:
    k = cv2.waitKey(10)
    
    #press esc on keyboard to exit
    if k == 27:
        break

#close all the opened windows
cv2.destroyAllWindows()
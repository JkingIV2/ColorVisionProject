# RBG Color Blindness Checker

## User inputs colors or color values for two colors and the program attempts to distinguish simple color blindness.

**version 1.0**

The end user is guided to one of two resources to derive the colors they are having trouble seeing on their device. The end user will then enter the RBG values for those two colors and the program will describe if the end user may have trouble with common types of red-green (Deuteranopia/Protanopia) color blindess.

Future iterations are intended to check more color blind RBG values than just the above and require less technical inputs
like RBG values, from the end user and perhaps asking them to only enter a URL or something that can be copy and pasted easily.

**version 2.0**

Updates:

Checks more different types of color blindness using Euclidean Color Distance "colorDistance():" & "evaluateColor():"
1) Red-Green Blindness (Protanopia / Deuteranopia)
2) Red-Green Weakness (Protanomaly / Deuteranomaly)
3) Blue-Yellow Blindness (Tritanopia)

Checks for low contrast color issues (Achromatopsia) or connfirms high contrast.

Allows user to enter Hex codes, RGB values, or color names (these are later broken down in to RGB values)
parseColorInput():

Logs and Exports Session infomration to "color_safety_log.txt"

Future iterations still aim to make the program easier for end users to use with less inputs or moments for inputs and then recommendations the user should consider to implement so that they can see more colors when using their web browser or web sites. This would require the program to check more types of color blindness or record more data about the end user and have a better "scoring" of the user to better define their color blindness/weaknesses.

Bug:
1st prompt response = color
2nd prompt response = (0-255 number)
3rd prompt response = abc
loop occurs :(




## Developer

John King
CSCI 111

```

Here is an example of the V1.1 program running:

```
Do you have an image or a website that you're having trouble seeing certain colors or do you
already know the color values you need to compare?
Please type image, website or colors based on what you're using then press enter.
(Tip: You can type 'quit' or 'exit' at any color prompt to leave).

blue
Proceeding to color comparison mode.

Enter the 1st color (or type 'quit' to exit): yellow 
Enter the 2nd color (or type 'quit' to exit): blue

-Results-
Color 1: Yellow (RGB: 255,255,0)
Color 2: Blue (RGB: 0,0,255)
Euclidean Color Distance: 441.67
Potential Blue-Yellow color blindness (Tritanopia).

Would you like to check more colors?
1: Yes
2: No
Enter choice: 1
Lets go again!

Do you have an image or a website that you're having trouble seeing certain colors or do you
already know the color values you need to compare?
Please type image, website or colors based on what you're using then press enter.
(Tip: You can type 'quit' or 'exit' at any color prompt to leave).

color
Proceeding to color comparison mode.

Enter the 1st color (or type 'quit' to exit): green
Enter the 2nd color (or type 'quit' to exit): blue

-Results-
Color 1: Green (RGB: 0,255,0)
Color 2: Blue (RGB: 0,0,255)
Euclidean Color Distance: 360.62
These colors have high contrast and are distinguishable across major color vision categories.

Would you like to check more colors?
1: Yes
2: No
Enter choice: 2
Ending Program

Session history successfully exported to 'color_safety_log.txt'.
Ending Program
```

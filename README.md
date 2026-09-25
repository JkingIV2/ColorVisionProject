# RBG Color Blindness Checker

## User inputs RGB values for two colors and the program attempts to distuingish simple color blindness.

**version 1.0**

The end user is guided to one of two resources to derive the colors they are having trouble seeing on their device. The end user will then enter the RBG values for those two colors and the program will describe if the end user may have trouble with common types of red-green (Deuteranopia/Protanopia) color blindess.

Future iterations are intended to check more color blind RBG values than just the above and require less technical inputs
like RBG values, from the end user and perhaps asking them to only enter a URL or something that can be copy and pasted easily.


## Developer

John King
CSCI 111

## Example

To run the program, give the following commands:

```
When the user RBG or image or website

RGB color value: 000 000 000

1 or 2
```

Here is an example of the program running:

```
Do you have an image or a website that you're having trouble seeing certain colors or do you
already know the RBG values for the colors you need to compare?
Please type image, website or RBG based on what you're using then press enter.

RBG
We can compare two colors at time, please enter the first color's RBG values below without any symbols.
Example: Blue's RBG value is (0, 0, 255) and the correct format to enter is: 0 0 255
Enter the 1st color's RGB values separated by spaces (Example for blue: 0 0 255): 152 55 55
Enter 2nd color's RGB values separated by spaces: 55 152 55
Hey Listen!: Based on these two colors, it's common to have Red-Green color blindness issues (Deuteranopia/Protanopia).
These colors may look identical to some users. It might be a good idea to adjust these.

Would you like to check more colors?
1: Yes
2: No
Enter choice: 2
Ending Program
```

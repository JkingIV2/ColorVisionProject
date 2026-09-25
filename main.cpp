#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
//Provided a palette of colors, 
//evaluate to what degree its color combinations can be 
//perceived and differentiated from each other, 
//while especially accounting for people with color blindness
//cout << "\n";
//https://xlork.com/tools/palette-from-website
//https://htmlcolorcodes.com/image-color-picker/

int main()
{
string response1;
bool colorcheck = true;
int r1, g1, b1; // Red, Green, Blue for color 1
int r2, g2, b2; // Red, Green, Blue for color 2
bool color1IsRed;
bool color2IsGreen;
bool color1IsGreen;
bool color2IsRed;
int choice;

do
  {
  cout << "Do you have an image or a website that you're having trouble seeing certain colors or do you\n";
  cout << "already know the RBG values for the colors you need to compare?\n";
  cout << "Please type image, website or RBG based on what you're using then press enter.\n";

  cin >> response1;
  
  if(response1 == "image")
  {
  cout << "We need to know the RBG Values of which colors you're having trouble seeing so,\n.";
  cout << "you will need to use the below website to retrieve those RBG values.\n";
  cout << "https://htmlcolorcodes.com/image-color-picker/\n";
  cout << "After opening the HTML Color Codes website look for the Upload button\n";
  cout << "and select the colors you want to get the RBG values from.\n";
  cout << "\n";
  cout << "The website will provide you the color's used and their respective color values\n";
  cout << "represented in a couple different ways via a drop down box to the right but,\n";
  cout << "We just need the RBG values.\n";
  cout << "\n";
  cout << "By copying those RBG values from the website we can compare two colors at time.\n";
  cout << "\n";
  cout << "Example: Blue's RBG value is (0, 0, 255) and the correct format to enter is: 0 0 255\n";
  }
  else if(response1 == "website")
  {
  cout << "We need to know the RBG Values of which colors you're having trouble seeing so,\n.";
  cout << "you will need to use the below website to retrieve those RBG values.\n";
  cout << "https://xlork.com/tools/palette-from-website\n";
  cout << "\n";
  cout << "After opening the Xlork website look for the Search Bar\n";
  cout << "and enter the exact URL you want to extract the RBG values from then press Extract\n";
  cout << "\n";
  cout << "The website will provide you the color's used and their respective color values\n";
  cout << "represented in a couple different ways but, we just need the RBG values.\n";
  cout << "By copying those values from the website we can compare two colors at time.\n";
  cout << "\n";
  cout << "Example: Blue's RBG value is (0, 0, 255) and the correct format to enter is: 0 0 255\n";
  }
  else if(response1 == "RBG")
  {
  cout << "We can compare two colors at time, please enter the first color's RBG values below without any symbols.\n";
  cout << "Example: Blue's RBG value is (0, 0, 255) and the correct format to enter is: 0 0 255\n";
  }
  else
  {
  cout << "You've entered an invalid entry.\n";
  cout << "Please Try Again.\n";
  }

  cout << "Enter the 1st color's RGB values separated by spaces (Example for blue: 0 0 255): ";
  cin >> r1 >> g1 >> b1;
          
  cout << "Enter 2nd color's RGB values separated by spaces: ";
  cin >> r2 >> g2 >> b2;

  color1IsRed = (r1 > 150 && g1 < 100 && b1 < 100);
  color1IsGreen = (r1 < 100 && g1 > 150 && b1 < 100);
  color2IsGreen = (r2 < 100 && g2 > 150 && b2 < 100);
  color2IsRed = (r2 > 150 && g2 < 100 && b2 < 100);

  if ((color1IsRed && color2IsGreen) || (color1IsGreen && color2IsRed)) 
  {
  cout << "WARNING: Based on these two colors, it's common to have Red-Green color blindness issues (Deuteranopia/Protanopia).\n";
  cout << "These colors may look identical to some users. It might be a good idea to adjust these.\n";
  } 
  else 
  {
  cout << "These two colors should be distinguishable for most common types of color blindness.\n";
  }
  cout << "\n";
  cout << "Would you like to check more colors?\n";
  cout << "1: Yes\n";
  cout << "2: No\n";
  cout << "Enter choice: ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    colorcheck = true;
    cout << "\n";
    break;

  case 2:
    colorcheck = false;
    cout << "Ending Program\n";
    break;

  default:
    colorcheck = false;
    cout << "Invalid choice. Program ending, please restart to check more colors.\n";
    break;
  }
} while (colorcheck == true);

return 0;
}

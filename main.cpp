#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;


double colorDistance(int r1, int g1, int b1, int r2, int g2, int b2);
void evaluateColor(int r1, int g1, int b1, int r2, int g2, int b2, string &report);
bool parseColorInput(int &r, int &g, int &b, string &colorId);
string toLowerCase(string str);

int main()
{
    string response1;
    bool colorcheck = true;
    int r1, g1, b1; // Red, Green, Blue for color 1
    int r2, g2, b2; // Red, Green, Blue for color 2
    string id1, id2; //IDs for history log
    int choice;
    
    // store session history
    vector<string> colorHistory;

    do
    {
        cout << "Do you have an image or a website that you're having trouble seeing certain colors or do you\n";
        cout << "already know the color values you need to compare?\n";
        cout << "Please type image, website or colors based on what you're using then press enter.\n";
        cout << "(Tip: You can type 'quit' or 'exit' at any color prompt to leave).\n\n";
        cin >> response1;

        if (response1 == "image")
        {
            cout << "We need to know the color values you're having trouble seeing so,\n";
            cout << "you can use the below website to retrieve Hex or RGB values:\n";
            cout << "https://htmlcolorcodes.com/image-color-picker/\n\n";
        }
        else if (response1 == "website")
        {
            cout << "We need to know the color values you're having trouble seeing so,\n";
            cout << "you can use the below website to retrieve color values:\n";
            cout << "https://xlork.com/tools/palette-from-website\n\n";
        }
        else
        {
            cout << "Proceeding to color comparison mode.\n\n";
        }

        //1st color (Supports Hex, RGB, Name, or Quit)
        do {
            cout << "Enter the 1st color (or type 'quit' to exit): ";
            if (parseColorInput(r1, g1, b1, id1)) {
                break;
            }
            cout << "Invalid input format or unknown color name. Please try again.\n";
        } while (true);
              
        // 2nd color (Supports Hex, RGB, Name, or Quit)
        do {
            cout << "Enter the 2nd color (or type 'quit' to exit): ";
            if (parseColorInput(r2, g2, b2, id2)) {
                break;
            }
            cout << "Invalid input format or unknown color name. Please try again.\n";
        } while (true);

        string safetyReport = "";
        evaluateColor(r1, g1, b1, r2, g2, b2, safetyReport);
        
        double distance = colorDistance(r1, g1, b1, r2, g2, b2);
        cout << fixed << setprecision(2);
        cout << "\n-Results-\n";
        cout << "Color 1: " << id1 << " (RGB: " << r1 << "," << g1 << "," << b1 << ")\n";
        cout << "Color 2: " << id2 << " (RGB: " << r2 << "," << g2 << "," << b2 << ")\n";
        cout << "Euclidean Color Distance: " << distance << "\n";
        cout << safetyReport << "\n";

        // Store result as vector "colorHistory"
        string record = "Color 1: " + id1 + " vs Color 2: " + id2 + " | Distance: " + to_string(distance);
        colorHistory.push_back(record);

        cout << "\nWould you like to check more colors?\n";
        cout << "1: Yes\n";
        cout << "2: No\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            colorcheck = true;
            cout << "Lets go again!\n\n";
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

    //export fstream
    ofstream outFile("color_safety_log.txt");
    if (outFile.is_open())
    {
        outFile << "Color Blindness Session Log\n";
        for (size_t i = 0; i < colorHistory.size(); ++i)
        {
            outFile << "Check " << (i + 1) << ": " << colorHistory[i] << "\n";
        }
        outFile.close();
        cout << "\nSession history successfully exported to 'color_safety_log.txt'.\n";
    }
    else
    {
        cout << "\nError: Could not open file for writing session log.\n";
    }

    return 0;
}

//function defs
string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool parseColorInput(int &r, int &g, int &b, string &colorId)
{
    string token;
    if (!(cin >> token)) return false;

    //quit option
    string name = toLowerCase(token);
    if (name == "quit" || name == "exit") {
        cout << "\nExiting program session. Goodbye!\n";
        exit(0);
    }

    bool isNumeric = true;
    for (char c : token) {
        if (!isdigit(c)) {
            isNumeric = false;
            break;
        }
    }

    if (isNumeric && token.length() <= 3 && token[0] != '#') 
    {
        int rVal = stoi(token);
        int gVal, bVal;
        if (cin >> gVal >> bVal) {
            if (rVal >= 0 && rVal <= 255 && gVal >= 0 && gVal <= 255 && bVal >= 0 && bVal <= 255) {
                r = rVal;
                g = gVal;
                b = bVal;
                colorId = "RGB(" + to_string(r) + "," + to_string(g) + "," + to_string(b) + ")";
                return true;
            }
        }
        return false;
    }

    string hexStr = token;
    if (hexStr[0] == '#') {
        hexStr = hexStr.substr(1);
    }

    if (hexStr.length() == 6) 
    {
        unsigned int rgbVal;
        stringstream ss;
        ss << hex;
        ss << hexStr;
        if (ss >> rgbVal) {
            r = (rgbVal >> 16) & 0xFF;
            g = (rgbVal >> 8) & 0xFF;
            b = rgbVal & 0xFF;
            colorId = "#" + hexStr;
            return true;
        }
    }

    if (name == "red") { r = 255; g = 0; b = 0; colorId = "Red"; return true; }
    if (name == "green") { r = 0; g = 255; b = 0; colorId = "Green"; return true; }
    if (name == "blue") { r = 0; g = 0; b = 255; colorId = "Blue"; return true; }
    if (name == "yellow") { r = 255; g = 255; b = 0; colorId = "Yellow"; return true; }
    if (name == "cyan") { r = 0; g = 255; b = 255; colorId = "Cyan"; return true; }
    if (name == "magenta") { r = 255; g = 0; b = 255; colorId = "Magenta"; return true; }
    if (name == "white") { r = 255; g = 255; b = 255; colorId = "White"; return true; }
    if (name == "black") { r = 0; g = 0; b = 0; colorId = "Black"; return true; }
    if (name == "orange") { r = 255; g = 165; b = 0; colorId = "Orange"; return true; }
    if (name == "purple") { r = 128; g = 0; b = 128; colorId = "Purple"; return true; }
    if (name == "brown") { r = 165; g = 42; b = 42; colorId = "Brown"; return true; }
    if (name == "pink") { r = 255; g = 192; b = 203; colorId = "Pink"; return true; }

    return false;
}

double colorDistance(int r1, int g1, int b1, int r2, int g2, int b2)
{
    double dr = r1 - r2;
    double dg = g1 - g2;
    double db = b1 - b2;
    return sqrt(dr * dr + dg * dg + db * db);
}

void evaluateColor(int r1, int g1, int b1, int r2, int g2, int b2, string &report)
{
    //Red-Green Blindness (Protanopia / Deuteranopia)
    bool color1IsRed = (r1 > 150 && g1 < 100 && b1 < 100);
    bool color1IsGreen = (r1 < 100 && g1 > 150 && b1 < 100);
    bool color2IsGreen = (r2 < 100 && g2 > 150 && b2 < 100);
    bool color2IsRed = (r2 > 150 && g2 < 100 && b2 < 100);

    //Red-Green Weakness (Protanomaly / Deuteranomaly)
    bool color1IsMutedRedOrBrown = (r1 >= 100 && r1 <= 180 && g1 < 100 && b1 < 100);
    bool color2IsMutedGreenOrOlive = (r2 < 120 && g2 >= 100 && g2 <= 180 && b2 < 100);
    bool color2IsMutedRedOrBrown = (r2 >= 100 && r2 <= 180 && g2 < 100 && b2 < 100);
    bool color1IsMutedGreenOrOlive = (r1 < 120 && g1 >= 100 && g1 <= 180 && b1 < 100);

    //Blue-Yellow Blindness (Tritanopia)
    bool color1IsBlue = (r1 < 100 && g1 < 100 && b1 > 150);
    bool color1IsYellow = (r1 > 150 && g1 > 150 && b1 < 100);
    bool color2IsYellow = (r2 > 150 && g2 > 150 && b2 < 100);
    bool color2IsBlue = (r2 < 100 && g2 < 100 && b2 > 150);

    double dist = colorDistance(r1, g1, b1, r2, g2, b2);

    if ((color1IsRed && color2IsGreen) || (color1IsGreen && color2IsRed)) 
    {
        report = "Potential complete Red-Green color blindness (Protanopia / Deuteranopia).";
    } 
    else if ((color1IsMutedRedOrBrown && color2IsMutedGreenOrOlive) || (color2IsMutedRedOrBrown && color1IsMutedGreenOrOlive))
    {
        report = "Potential Red-Green color blindness(Protanomaly / Deuteranomaly detected between reds/browns and greens).";
    }
    else if ((color1IsBlue && color2IsYellow) || (color1IsYellow && color2IsBlue))
    {
        report = "Potential Blue-Yellow color blindness (Tritanopia).";
    }
    else if (dist < 45.0)
    {
        report = "Low contrast, vulnerable to Achromatopsia (Total Monochromacy / Complete Color Blindness).";
    }
    else if (dist < 75.0)
    {
        report = "Moderate contrast. May be difficult to distinguish with poor lighting.";
    }
    else 
    {
        report = "These colors have high contrast and are distinguishable across major color vision categories.";
    }
}

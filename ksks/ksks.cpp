#include <cstdint>
#include <vector>
#include <iostream>
#include <cstring>

enum class CommandID : uint8_t {
    CLEAR_DISPLAY = 0x01,
    DRAW_PIXEL = 0x02,
    DRAW_LINE = 0x03,
    DRAW_RECTANGLE = 0x04,
    FILL_RECTANGLE = 0x05,
    DRAW_ELLIPSE = 0x06,
    FILL_ELLIPSE = 0x07,
    DRAW_CIRCLE = 0x08,
    FILL_CIRCLE = 0x09,
    DRAW_ROUNDED_RECTANGLE = 0x0A,
    FILL_ROUNDED_RECTANGLE = 0x0B,
    DRAW_TEXT = 0x0C,
    DRAW_IMAGE = 0x0D
};

struct Command {
    CommandID id;
    std::vector<uint8_t> params;
};

class CommandParser {
public:
    Command parse(const std::vector<uint8_t>& data) {
        Command command;
        command.id = static_cast<CommandID>(data[0]);
        command.params = std::vector<uint8_t>(data.begin() + 1, data.end());
        return command;
    }
};

void handleCommand(const Command& command) {
    switch (command.id) {
    case CommandID::CLEAR_DISPLAY: {
        uint16_t color;
        std::memcpy(&color, &command.params[0], sizeof(color));
        std::cout << "Clear display with color: " << color << std::endl;
        break;
    }
    case CommandID::DRAW_PIXEL: {
        int16_t x0, y0;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&color, &command.params[4], sizeof(color));
        std::cout << "Draw pixel at (" << x0 << ", " << y0 << ") with color: " << color << std::endl;
        break;
    }
    case CommandID::DRAW_LINE: {
        int16_t x0, y0, x1, y1;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&x1, &command.params[4], sizeof(x1));
        std::memcpy(&y1, &command.params[6], sizeof(y1));
        std::memcpy(&color, &command.params[8], sizeof(color));
        std::cout << "Draw line from (" << x0 << ", " << y0 << ") to (" << x1 << ", " << y1 << ") with color: " << color << std::endl;
        break;
    }
    case CommandID::DRAW_RECTANGLE: {
        int16_t x0, y0, w, h;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&w, &command.params[4], sizeof(w));
        std::memcpy(&h, &command.params[6], sizeof(h));
        std::memcpy(&color, &command.params[8], sizeof(color));
        std::cout << "Draw rectangle at (" << x0 << ", " << y0 << ") with width " << w << " and height " << h << " and color: " << color << std::endl;
        break;
    }
    case CommandID::FILL_RECTANGLE: {
        int16_t x0, y0, w, h;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&w, &command.params[4], sizeof(w));
        std::memcpy(&h, &command.params[6], sizeof(h));
        std::memcpy(&color, &command.params[8], sizeof(color));
        std::cout << "Fill rectangle at (" << x0 << ", " << y0 << ") with width " << w << " and height " << h << " and color: " << color << std::endl;
        break;
    }
    case CommandID::DRAW_ELLIPSE: {
        int16_t x0, y0, radius_x, radius_y;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&radius_x, &command.params[4], sizeof(radius_x));
        std::memcpy(&radius_y, &command.params[6], sizeof(radius_y));
        std::memcpy(&color, &command.params[8], sizeof(color));
        std::cout << "Draw ellipse at (" << x0 << ", " << y0 << ") with radius_x " << radius_x << " and radius_y " << radius_y << " and color: " << color << std::endl;
        break;
    }
    case CommandID::FILL_ELLIPSE: {
        int16_t x0, y0, radius_x, radius_y;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&radius_x, &command.params[4], sizeof(radius_x));
        std::memcpy(&radius_y, &command.params[6], sizeof(radius_y));
        std::memcpy(&color, &command.params[8], sizeof(color));
        std::cout << "Fill ellipse at (" << x0 << ", " << y0 << ") with radius_x " << radius_x << " and radius_y " << radius_y << " and color: " << color << std::endl;
        break;
    }
    case CommandID::DRAW_CIRCLE: {
        int16_t x0, y0, radius;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&radius, &command.params[4], sizeof(radius));
        std::memcpy(&color, &command.params[6], sizeof(color));
        std::cout << "Draw circle at (" << x0 << ", " << y0 << ") with radius " << radius << " and color: " << color << std::endl;
        break;
    }
    case CommandID::FILL_CIRCLE: {
        int16_t x0, y0, radius;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&radius, &command.params[4], sizeof(radius));
        std::memcpy(&color, &command.params[6], sizeof(color));
        std::cout << "Fill circle at (" << x0 << ", " << y0 << ") with radius " << radius << " and color: " << color << std::endl;
        break;
    }
    case CommandID::DRAW_ROUNDED_RECTANGLE: {
        int16_t x0, y0, w, h, radius;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&w, &command.params[4], sizeof(w));
        std::memcpy(&h, &command.params[6], sizeof(h));
        std::memcpy(&radius, &command.params[8], sizeof(radius));
        std::memcpy(&color, &command.params[10], sizeof(color));
        std::cout << "Draw rounded rectangle at (" << x0 << ", " << y0 << ") with width " << w << ", height " << h << ", radius " << radius << " and color: " << color << std::endl;
        break;
    }
    case CommandID::FILL_ROUNDED_RECTANGLE: {
        int16_t x0, y0, w, h, radius;
        uint16_t color;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&w, &command.params[4], sizeof(w));
        std::memcpy(&h, &command.params[6], sizeof(h));
        std::memcpy(&radius, &command.params[8], sizeof(radius));
        std::memcpy(&color, &command.params[10], sizeof(color));
        std::cout << "Fill rounded rectangle at (" << x0 << ", " << y0 << ") with width " << w << ", height " << h << ", radius " << radius << " and color: " << color << std::endl;
        break;
    }
    case CommandID::DRAW_TEXT: {
        int16_t x0, y0;
        uint16_t color;
        uint8_t font_number, length;
        char text[100];
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&color, &command.params[4], sizeof(color));
        std::memcpy(&font_number, &command.params[6], sizeof(font_number));
        std::memcpy(&length, &command.params[7], sizeof(length));
        std::memcpy(&text, &command.params[8], length);
        text[length] = '\0';
        std::cout << "Draw text '" << text << "' at (" << x0 << ", " << y0 << ") with color: " << color << ", font: " << (int)font_number << std::endl;
        break;
    }
    case CommandID::DRAW_IMAGE: {
   
        int16_t x0, y0, w, h;
        std::memcpy(&x0, &command.params[0], sizeof(x0));
        std::memcpy(&y0, &command.params[2], sizeof(y0));
        std::memcpy(&w, &command.params[4], sizeof(w));
        std::memcpy(&h, &command.params[6], sizeof(h));

        std::cout << "Draw image at (" << x0 << ", " << y0 << ") with width " << w << " and height " << h << std::endl;

      
        size_t pixelCount = w * h;
        std::cout << "Pixel data (RGB565 format):\n";
        for (size_t i = 0; i < pixelCount; ++i) {
            uint16_t pixel;
            std::memcpy(&pixel, &command.params[8 + i * 2], sizeof(pixel));
            std::cout << std::hex << pixel << " ";
            if ((i + 1) % w == 0) {
                std::cout << std::endl;  
            }
        }
        break;
    }
    default:
        std::cout << "Unknown command" << std::endl;
        break;
    }
}

void displayAvailableCommands() {
    std::cout << "\nAvailable commands:\n";
    std::cout << "1 - Clear display: color\n";
    std::cout << "2 - Draw pixel: x0, y0, color\n";
    std::cout << "3 - Draw line: x0, y0, x1, y1, color\n";
    std::cout << "4 - Draw rectangle: x0, y0, w, h, color\n";
    std::cout << "5 - Fill rectangle: x0, y0, w, h, color\n";
    std::cout << "6 - Draw ellipse: x0, y0, radius_x, radius_y, color\n";
    std::cout << "7 - Fill ellipse: x0, y0, radius_x, radius_y, color\n";
    std::cout << "8 - Draw circle: x0, y0, radius, color\n";
    std::cout << "9 - Fill circle: x0, y0, radius, color\n";
    std::cout << "10 - Draw rounded rectangle: x0, y0, w, h, radius, color\n";
    std::cout << "11 - Fill rounded rectangle: x0, y0, w, h, radius, color\n";
    std::cout << "12 - Draw text: x0, y0, color, font_number, length, text\n";
    std::cout << "13 - Draw image: x0, y0, w, h, data\n";
    std::cout << "Enter command ID (1-13): ";
}

std::vector<uint8_t> getCommandParameters(CommandID commandID) {
    std::vector<uint8_t> params;
    switch (commandID) {
    case CommandID::CLEAR_DISPLAY: {
        uint16_t color;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(2);
        std::memcpy(&params[0], &color, sizeof(color));
        break;
    }
    case CommandID::DRAW_PIXEL: {
        int16_t x0, y0;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(6);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &color, sizeof(color));
        break;
    }
    case CommandID::DRAW_LINE: {
        int16_t x0, y0, x1, y1;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter x1: ";
        std::cin >> x1;
        std::cout << "Enter y1: ";
        std::cin >> y1;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(10);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &x1, sizeof(x1));
        std::memcpy(&params[6], &y1, sizeof(y1));
        std::memcpy(&params[8], &color, sizeof(color));
        break;
    }
    case CommandID::DRAW_ELLIPSE: {
        int16_t x0, y0, radius_x, radius_y;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter radius_x: ";
        std::cin >> radius_x;
        std::cout << "Enter radius_y: ";
        std::cin >> radius_y;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(10);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &radius_x, sizeof(radius_x));
        std::memcpy(&params[6], &radius_y, sizeof(radius_y));
        std::memcpy(&params[8], &color, sizeof(color));
        break;
    }
    case CommandID::FILL_ELLIPSE: {
        int16_t x0, y0, radius_x, radius_y;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter radius_x: ";
        std::cin >> radius_x;
        std::cout << "Enter radius_y: ";
        std::cin >> radius_y;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(10);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &radius_x, sizeof(radius_x));
        std::memcpy(&params[6], &radius_y, sizeof(radius_y));
        std::memcpy(&params[8], &color, sizeof(color));
        break;
    }
    case CommandID::DRAW_RECTANGLE: {
        int16_t x0, y0, w, h;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter width (w): ";
        std::cin >> w;
        std::cout << "Enter height (h): ";
        std::cin >> h;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(10);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &w, sizeof(w));
        std::memcpy(&params[6], &h, sizeof(h));
        std::memcpy(&params[8], &color, sizeof(color));
        break;
    }
    case CommandID::FILL_RECTANGLE: {
        int16_t x0, y0, w, h;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter width (w): ";
        std::cin >> w;
        std::cout << "Enter height (h): ";
        std::cin >> h;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(10);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &w, sizeof(w));
        std::memcpy(&params[6], &h, sizeof(h));
        std::memcpy(&params[8], &color, sizeof(color));
        break;
    }
    case CommandID::DRAW_CIRCLE: {
        int16_t x0, y0, radius;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(8);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &radius, sizeof(radius));
        std::memcpy(&params[6], &color, sizeof(color));
        break;
    }
    case CommandID::FILL_CIRCLE: {
        int16_t x0, y0, radius;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(8);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &radius, sizeof(radius));
        std::memcpy(&params[6], &color, sizeof(color));
        break;
    }
    case CommandID::DRAW_ROUNDED_RECTANGLE: {
        int16_t x0, y0, w, h, radius;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter width (w): ";
        std::cin >> w;
        std::cout << "Enter height (h): ";
        std::cin >> h;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(12);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &w, sizeof(w));
        std::memcpy(&params[6], &h, sizeof(h));
        std::memcpy(&params[8], &radius, sizeof(radius));
        std::memcpy(&params[10], &color, sizeof(color));
        break;
    }
    case CommandID::FILL_ROUNDED_RECTANGLE: {
        int16_t x0, y0, w, h, radius;
        uint16_t color;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter width (w): ";
        std::cin >> w;
        std::cout << "Enter height (h): ";
        std::cin >> h;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        params.resize(12);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &w, sizeof(w));
        std::memcpy(&params[6], &h, sizeof(h));
        std::memcpy(&params[8], &radius, sizeof(radius));
        std::memcpy(&params[10], &color, sizeof(color));
        break;
    }
    case CommandID::DRAW_TEXT: {
        int16_t x0, y0;
        uint16_t color;
        uint8_t font_number, length;
        std::string text;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter color (RGB565): ";
        std::cin >> color;
        std::cout << "Enter font number: ";
        std::cin >> font_number;
        std::cout << "Enter text: ";
        std::cin >> text;
        length = text.size();
        params.resize(8 + length);
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &color, sizeof(color));
        std::memcpy(&params[6], &font_number, sizeof(font_number));
        params[7] = length;
        std::memcpy(&params[8], text.c_str(), length);
        break;
    }
    case CommandID::DRAW_IMAGE: {
        int16_t x0, y0, w, h;
        std::cout << "Enter x0: ";
        std::cin >> x0;
        std::cout << "Enter y0: ";
        std::cin >> y0;
        std::cout << "Enter width (w): ";
        std::cin >> w;
        std::cout << "Enter height (h): ";
        std::cin >> h;

        params.resize(8 + w * h * 2);  // 8 bytes for position and dimensions, 2 bytes per pixel
        std::memcpy(&params[0], &x0, sizeof(x0));
        std::memcpy(&params[2], &y0, sizeof(y0));
        std::memcpy(&params[4], &w, sizeof(w));
        std::memcpy(&params[6], &h, sizeof(h));

        std::cout << "Enter pixel data (RGB565 format):\n";
        for (int i = 0; i < w * h; ++i) {
            uint16_t pixel;
            std::cout << "Pixel " << i + 1 << ": ";
            std::cin >> pixel;
            std::memcpy(&params[8 + i * 2], &pixel, sizeof(pixel));
        }
        break;
    }
    default:
        std::cout << "Unknown command!" << std::endl;
        break;
    }
    return params;
}
int main() {
    while (true) {
        displayAvailableCommands();
        std::cout << "Enter command ID (1-13) or 0 to exit: ";

        int commandID;
        std::cin >> commandID;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
           
            continue;
        }

        if (commandID == 0) {
            std::cout << "Exiting program..." << std::endl;
            break; 
        }

        CommandParser parser;
        Command command;

        switch (commandID) {
        case 1:
            command.id = CommandID::CLEAR_DISPLAY;
            break;
        case 2:
            command.id = CommandID::DRAW_PIXEL;
            break;
        case 3:
            command.id = CommandID::DRAW_LINE;
            break;
        case 4:
            command.id = CommandID::DRAW_RECTANGLE;
            break;
        case 5:
            command.id = CommandID::FILL_RECTANGLE;
            break;
        case 6:
            command.id = CommandID::DRAW_ELLIPSE;
            break;
        case 7:
            command.id = CommandID::FILL_ELLIPSE;
            break;
        case 8:
            command.id = CommandID::DRAW_CIRCLE;
            break;
        case 9:
            command.id = CommandID::FILL_CIRCLE;
            break;
        case 10:
            command.id = CommandID::DRAW_ROUNDED_RECTANGLE;
            break;
        case 11:
            command.id = CommandID::FILL_ROUNDED_RECTANGLE;
            break;
        case 12:
            command.id = CommandID::DRAW_TEXT;
            break;
        case 13:
            command.id = CommandID::DRAW_IMAGE;
            break;
        default:
            std::cout << "Invalid command ID! Please enter a number between 1 and 13.\n";
            continue; 
        }

        command.params = getCommandParameters(command.id);
        handleCommand(command);
    }

    return 0;
}
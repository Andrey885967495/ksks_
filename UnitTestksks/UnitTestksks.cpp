#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <cstdint>
#include <cstring>
#include "../ksks/ksks.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestksks
{
    TEST_CLASS(UnitTestksks)
    {
    public:

        Command createCommand(CommandID id, const std::vector<uint8_t>& params) {
            Command command;
            command.id = id;
            command.params = params;
            return command;
        }

        TEST_METHOD(TestClearDisplay)
        {
          
            uint16_t color = 0x1234;
            std::vector<uint8_t> params(2);
            std::memcpy(&params[0], &color, sizeof(color));
            Command command = createCommand(CommandID::CLEAR_DISPLAY, params);

      
            Assert::IsTrue(command.id == CommandID::CLEAR_DISPLAY);
      
            uint16_t receivedColor;
            std::memcpy(&receivedColor, &command.params[0], sizeof(receivedColor));
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestDrawPixel)
        {
            int16_t x0 = 100, y0 = 50;
            uint16_t color = 0x5678;
            std::vector<uint8_t> params(6);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &color, sizeof(color));
            Command command = createCommand(CommandID::DRAW_PIXEL, params);

            Assert::IsTrue(command.id == CommandID::DRAW_PIXEL);

            int16_t receivedX0, receivedY0;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedColor, &command.params[4], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestDrawLine)
        {
            int16_t x0 = 10, y0 = 20, x1 = 100, y1 = 120;
            uint16_t color = 0xAAAA;
            std::vector<uint8_t> params(10);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &x1, sizeof(x1));
            std::memcpy(&params[6], &y1, sizeof(y1));
            std::memcpy(&params[8], &color, sizeof(color));
            Command command = createCommand(CommandID::DRAW_LINE, params);

            Assert::IsTrue(command.id == CommandID::DRAW_LINE);

            int16_t receivedX0, receivedY0, receivedX1, receivedY1;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedX1, &command.params[4], sizeof(receivedX1));
            std::memcpy(&receivedY1, &command.params[6], sizeof(receivedY1));
            std::memcpy(&receivedColor, &command.params[8], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(x1, receivedX1);
            Assert::AreEqual(y1, receivedY1);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestDrawRectangle)
        {
            int16_t x0 = 30, y0 = 40, w = 50, h = 60;
            uint16_t color = 0xFFFF;
            std::vector<uint8_t> params(10);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &w, sizeof(w));
            std::memcpy(&params[6], &h, sizeof(h));
            std::memcpy(&params[8], &color, sizeof(color));
            Command command = createCommand(CommandID::DRAW_RECTANGLE, params);

            Assert::IsTrue(command.id == CommandID::DRAW_RECTANGLE);

            int16_t receivedX0, receivedY0, receivedW, receivedH;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedW, &command.params[4], sizeof(receivedW));
            std::memcpy(&receivedH, &command.params[6], sizeof(receivedH));
            std::memcpy(&receivedColor, &command.params[8], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(w, receivedW);
            Assert::AreEqual(h, receivedH);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestFillRectangle)
        {
            int16_t x0 = 70, y0 = 80, w = 90, h = 100;
            uint16_t color = 0x4321;
            std::vector<uint8_t> params(10);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &w, sizeof(w));
            std::memcpy(&params[6], &h, sizeof(h));
            std::memcpy(&params[8], &color, sizeof(color));
            Command command = createCommand(CommandID::FILL_RECTANGLE, params);

            Assert::IsTrue(command.id == CommandID::FILL_RECTANGLE);

            int16_t receivedX0, receivedY0, receivedW, receivedH;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedW, &command.params[4], sizeof(receivedW));
            std::memcpy(&receivedH, &command.params[6], sizeof(receivedH));
            std::memcpy(&receivedColor, &command.params[8], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(w, receivedW);
            Assert::AreEqual(h, receivedH);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestDrawEllipse)
        {
            int16_t x0 = 10, y0 = 20, radius_x = 15, radius_y = 25;
            uint16_t color = 0x8888;
            std::vector<uint8_t> params(10);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &radius_x, sizeof(radius_x));
            std::memcpy(&params[6], &radius_y, sizeof(radius_y));
            std::memcpy(&params[8], &color, sizeof(color));
            Command command = createCommand(CommandID::DRAW_ELLIPSE, params);

            Assert::IsTrue(command.id == CommandID::DRAW_ELLIPSE);

            int16_t receivedX0, receivedY0, receivedRadiusX, receivedRadiusY;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedRadiusX, &command.params[4], sizeof(receivedRadiusX));
            std::memcpy(&receivedRadiusY, &command.params[6], sizeof(receivedRadiusY));
            std::memcpy(&receivedColor, &command.params[8], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(radius_x, receivedRadiusX);
            Assert::AreEqual(radius_y, receivedRadiusY);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestFillEllipse)
        {
            int16_t x0 = 10, y0 = 20, radius_x = 15, radius_y = 25;
            uint16_t color = 0x9999;
            std::vector<uint8_t> params(10);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &radius_x, sizeof(radius_x));
            std::memcpy(&params[6], &radius_y, sizeof(radius_y));
            std::memcpy(&params[8], &color, sizeof(color));
            Command command = createCommand(CommandID::FILL_ELLIPSE, params);

            Assert::IsTrue(command.id == CommandID::FILL_ELLIPSE);

            int16_t receivedX0, receivedY0, receivedRadiusX, receivedRadiusY;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedRadiusX, &command.params[4], sizeof(receivedRadiusX));
            std::memcpy(&receivedRadiusY, &command.params[6], sizeof(receivedRadiusY));
            std::memcpy(&receivedColor, &command.params[8], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(radius_x, receivedRadiusX);
            Assert::AreEqual(radius_y, receivedRadiusY);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestDrawCircle)
        {
            int16_t x0 = 30, y0 = 40, radius = 50;
            uint16_t color = 0xAAAA;
            std::vector<uint8_t> params(8);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &radius, sizeof(radius));
            std::memcpy(&params[6], &color, sizeof(color));
            Command command = createCommand(CommandID::DRAW_CIRCLE, params);

            Assert::IsTrue(command.id == CommandID::DRAW_CIRCLE);

            int16_t receivedX0, receivedY0, receivedRadius;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedRadius, &command.params[4], sizeof(receivedRadius));
            std::memcpy(&receivedColor, &command.params[6], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(radius, receivedRadius);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestFillCircle)
        {
            int16_t x0 = 30, y0 = 40, radius = 50;
            uint16_t color = 0xBBBB;
            std::vector<uint8_t> params(8);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &radius, sizeof(radius));
            std::memcpy(&params[6], &color, sizeof(color));
            Command command = createCommand(CommandID::FILL_CIRCLE, params);

            Assert::IsTrue(command.id == CommandID::FILL_CIRCLE);

            int16_t receivedX0, receivedY0, receivedRadius;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedRadius, &command.params[4], sizeof(receivedRadius));
            std::memcpy(&receivedColor, &command.params[6], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(radius, receivedRadius);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestDrawRoundedRectangle)
        {
            int16_t x0 = 30, y0 = 40, w = 50, h = 60, radius = 10;
            uint16_t color = 0xCCCC;
            std::vector<uint8_t> params(12);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &w, sizeof(w));
            std::memcpy(&params[6], &h, sizeof(h));
            std::memcpy(&params[8], &radius, sizeof(radius));
            std::memcpy(&params[10], &color, sizeof(color));
            Command command = createCommand(CommandID::DRAW_ROUNDED_RECTANGLE, params);

            Assert::IsTrue(command.id == CommandID::DRAW_ROUNDED_RECTANGLE);

            int16_t receivedX0, receivedY0, receivedW, receivedH, receivedRadius;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedW, &command.params[4], sizeof(receivedW));
            std::memcpy(&receivedH, &command.params[6], sizeof(receivedH));
            std::memcpy(&receivedRadius, &command.params[8], sizeof(receivedRadius));
            std::memcpy(&receivedColor, &command.params[10], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(w, receivedW);
            Assert::AreEqual(h, receivedH);
            Assert::AreEqual(radius, receivedRadius);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestFillRoundedRectangle)
        {
            int16_t x0 = 30, y0 = 40, w = 50, h = 60, radius = 10;
            uint16_t color = 0xDDDD;
            std::vector<uint8_t> params(12);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &w, sizeof(w));
            std::memcpy(&params[6], &h, sizeof(h));
            std::memcpy(&params[8], &radius, sizeof(radius));
            std::memcpy(&params[10], &color, sizeof(color));
            Command command = createCommand(CommandID::FILL_ROUNDED_RECTANGLE, params);

            Assert::IsTrue(command.id == CommandID::FILL_ROUNDED_RECTANGLE);

            int16_t receivedX0, receivedY0, receivedW, receivedH, receivedRadius;
            uint16_t receivedColor;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedW, &command.params[4], sizeof(receivedW));
            std::memcpy(&receivedH, &command.params[6], sizeof(receivedH));
            std::memcpy(&receivedRadius, &command.params[8], sizeof(receivedRadius));
            std::memcpy(&receivedColor, &command.params[10], sizeof(receivedColor));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(w, receivedW);
            Assert::AreEqual(h, receivedH);
            Assert::AreEqual(radius, receivedRadius);
            Assert::AreEqual(color, receivedColor);
        }

        TEST_METHOD(TestDrawText)
        {
            int16_t x0 = 10, y0 = 20;
            uint16_t color = 0xEEEE;
            uint8_t font_number = 2;
            std::string text = "Hello";
            uint8_t length = text.size();
            std::vector<uint8_t> params(8 + length);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &color, sizeof(color));
            std::memcpy(&params[6], &font_number, sizeof(font_number));
            params[7] = length;
            std::memcpy(&params[8], text.c_str(), length);
            Command command = createCommand(CommandID::DRAW_TEXT, params);

            Assert::IsTrue(command.id == CommandID::DRAW_TEXT);

            int16_t receivedX0, receivedY0;
            uint16_t receivedColor;
            uint8_t receivedFontNumber, receivedLength;
            char receivedText[100];
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedColor, &command.params[4], sizeof(receivedColor));
            std::memcpy(&receivedFontNumber, &command.params[6], sizeof(receivedFontNumber));
            std::memcpy(&receivedLength, &command.params[7], sizeof(receivedLength));
            std::memcpy(&receivedText, &command.params[8], receivedLength);
            receivedText[receivedLength] = '\0';

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(color, receivedColor);
            Assert::AreEqual(font_number, receivedFontNumber);
            Assert::AreEqual(length, receivedLength);
            Assert::AreEqual(text, std::string(receivedText));
        }

        TEST_METHOD(TestDrawImage)
        {
            int16_t x0 = 20, y0 = 30, w = 100, h = 200;
            std::vector<uint16_t> pixelData(w * h, 0xFFFF);

            
            std::vector<uint8_t> params(8 + w * h * 2);
            std::memcpy(&params[0], &x0, sizeof(x0));
            std::memcpy(&params[2], &y0, sizeof(y0));
            std::memcpy(&params[4], &w, sizeof(w));
            std::memcpy(&params[6], &h, sizeof(h));

            for (size_t i = 0; i < pixelData.size(); ++i) {
                std::memcpy(&params[8 + i * 2], &pixelData[i], sizeof(pixelData[i]));
            }

            Command command = createCommand(CommandID::DRAW_IMAGE, params);

            Assert::IsTrue(command.id == CommandID::DRAW_IMAGE);

            
            int16_t receivedX0, receivedY0, receivedW, receivedH;
            std::memcpy(&receivedX0, &command.params[0], sizeof(receivedX0));
            std::memcpy(&receivedY0, &command.params[2], sizeof(receivedY0));
            std::memcpy(&receivedW, &command.params[4], sizeof(receivedW));
            std::memcpy(&receivedH, &command.params[6], sizeof(receivedH));

            Assert::AreEqual(x0, receivedX0);
            Assert::AreEqual(y0, receivedY0);
            Assert::AreEqual(w, receivedW);
            Assert::AreEqual(h, receivedH);

            for (size_t i = 0; i < pixelData.size(); ++i) {
                uint16_t receivedPixel;
                std::memcpy(&receivedPixel, &command.params[8 + i * 2], sizeof(receivedPixel));
                Assert::AreEqual(pixelData[i], receivedPixel);
            }
        }
    };
}

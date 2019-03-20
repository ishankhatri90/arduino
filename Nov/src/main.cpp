#include <Arduino.h>
// TODO:
// Give the buffer names - Done
// Add recipe for which buffer to use
// Put baud and delay as constants - Done




byte msg[][28] = {{0x71, 0x19, 0x0e, 0x3f, 0xa5, 0xc9, 0x7e, 0x3f, 0xcb, 0x57, 0x11, 0x41, 0x1c, 0x3e, 0xf1, 0xc0, 0x44, 0x09, 0x52, 0xbd, 0xad, 0xfa, 0x85, 0xc0, 0x31, 0xdb, 0xa8, 0xf3}, //example data 1
                    {0x71, 0x19, 0x0e, 0x3f, 0xb6, 0xdd, 0xa9, 0x3f, 0x9f, 0xe5, 0xae, 0x41, 0x33, 0x15, 0x50, 0xc0, 0x46, 0x8a, 0x91, 0xbe, 0x41, 0x92, 0x1a, 0xc0, 0x30, 0xad, 0x53, 0x8f},// 2
{ 0x71, 0x19, 0x0e, 0x3d, 0x0d, 0x39, 0x84, 0x3e, 0xc8, 0xc1, 0xd9, 0x40, 0xcf, 0xef, 0x27, 0xc0, 0x44, 0xef, 0x92, 0xbe, 0x1b, 0xc8, 0x74, 0xc0, 0x2f, 0xee, 0x8c, 0xdd },// 3
{ 0x71, 0x19, 0x0e, 0x3e, 0xd4, 0x58, 0x66, 0x3f, 0xeb, 0x0e, 0x51, 0x41, 0x39, 0x11, 0x12, 0xc0, 0x45, 0x22, 0xc0, 0xbe, 0x15, 0x44, 0xfe, 0xc0, 0x30, 0x25, 0xa0, 0xb5 },// 4
{ 0x71, 0x19, 0x0e, 0x3f, 0xad, 0xca, 0x77, 0x3f, 0xb8, 0x74, 0xe3, 0x41, 0x02, 0xcc, 0xf1, 0xc0, 0x43, 0x04, 0x69, 0xbd, 0xf5, 0x65, 0x97, 0xc0, 0x32, 0x21, 0xed, 0xa7 },// 5
{ 0x71, 0x19, 0x0e, 0x3f, 0xa3, 0x91, 0xf6, 0x3f, 0xcb, 0x1f, 0x19, 0x40, 0xf1, 0xe2, 0x5d, 0xc0, 0x3e, 0x04, 0xa2, 0xbd, 0x0f, 0xc0, 0xb6, 0xc0, 0x34, 0x09, 0xcf, 0xdb },// 6
{ 0x71, 0x19, 0x0e, 0x3f, 0xcc, 0x96, 0x5e, 0x40, 0x2b, 0xe1, 0x71, 0x41, 0x28, 0x71, 0xe3, 0xc0, 0x38, 0xe1, 0xe9, 0x3d, 0xb7, 0x1c, 0x89, 0xc0, 0x33, 0x96, 0x83, 0xee },// 7
{ 0x71, 0x19, 0x0e, 0x40, 0x1c, 0x0f, 0xde, 0x40, 0x45, 0x32, 0x40, 0x41, 0x2d, 0xe3, 0x5d, 0xc0, 0x37, 0x0d, 0xed, 0x3e, 0x08, 0x3e, 0xb6, 0xc0, 0x31, 0xf6, 0xe2, 0xf0 },// 8
{ 0x51, 0x19, 0x0e, 0x40, 0x3f, 0xe5, 0x16, 0x40, 0x42, 0x93, 0xc9, 0x41, 0x1a, 0x7e, 0x94, 0xc0, 0x36, 0xe7, 0xd3, 0x3e, 0x1a, 0x82, 0x01, 0xc0, 0x30, 0x2f, 0x87, 0x4 },// 9
{ 0x51, 0x19, 0x0e, 0x40, 0x54, 0xeb, 0xca, 0x40, 0x3c, 0xd5, 0xd1, 0x41, 0x0b, 0x3c, 0x24, 0xc0, 0x36, 0xdf, 0x03, 0x3e, 0x32, 0x6e, 0x03, 0xc0, 0x2e, 0x84, 0x69, 0xb9 },// 10
{ 0x51, 0x19, 0x0e, 0x40, 0x69, 0x2d, 0x9f, 0x40, 0x4b, 0x28, 0xab, 0x41, 0x07, 0xab, 0x35, 0xc0, 0x36, 0x63, 0x5e, 0x3e, 0x4d, 0x61, 0x6f, 0xc0, 0x2d, 0x38, 0x4b, 0x8b },// 11
{ 0x51, 0x19, 0x0e, 0x40, 0x6a, 0xbf, 0x7c, 0x40, 0x5f, 0xf5, 0x34, 0x41, 0x06, 0xe2, 0xbb, 0xc0, 0x35, 0x88, 0xce, 0x3e, 0x6a, 0xd1, 0xa7, 0xc0, 0x2b, 0xf2, 0x86, 0x6d },// 12
{ 0x51, 0x19, 0x0e, 0x40, 0x88, 0xc3, 0x19, 0x40, 0x76, 0xad, 0x24, 0x41, 0x09, 0xc5, 0x4d, 0xc0, 0x34, 0x5e, 0xf5, 0x3e, 0x8c, 0xc7, 0xde, 0xc0, 0x2a, 0xcc, 0x75, 0x76 },// 13
{ 0x51, 0x19, 0x0e, 0x40, 0x9f, 0x23, 0xc7, 0x40, 0x5d, 0xeb, 0x72, 0x41, 0x04, 0xb7, 0x5c, 0xc0, 0x35, 0x1e, 0xa4, 0x3e, 0x90, 0xa2, 0x95, 0xc0, 0x2c, 0x8e, 0x46, 0xa5 },// 14
{ 0x51, 0x19, 0x0e, 0x40, 0x7a, 0x46, 0xbf, 0x40, 0x54, 0x57, 0x04, 0x41, 0x00, 0x5f, 0xf9, 0xc0, 0x33, 0xcd, 0xb1, 0x3e, 0x64, 0xe9, 0xd4, 0xc0, 0x2c, 0x98, 0x9b, 0x44 },// 15
{ 0x44, 0x10, 0xda, 0xaa, 0xda, 0x14, 0xc8, 0x50, 0x54, 0xeb, 0x3, 0x58, 0xad , 0x2b, 0xf1, 0xb6, 0xca, 0x9f, 0xd4, 0xcf, 0xdd, 0x0d, 0x4d, 0xcc, 0xcb, 0x3e, 0xd1, 0x55 }, //bad value // 16
{ 0x78, 0x19, 0xda, 0x14, 0xc8, 0x50, 0x54, 0xeb, 0x9f, 0xd4, 0xcf, 0xdd, 0xde, 0x40, 0x45, 0x32, 0x40, 0x41, 0x2d, 0xe3, 0x5d, 0xc0, 0xeb, 0x3, 0x58, 0xad, 0x2b, 0xf1 }, //bad value // 17
{ 0x21, 0x3f, 0xcc, 0x96, 0xc3, 0xd1, 0x41, 0x0b, 0x3c, 0x24, 0xc0, 0x36, 0xdf, 0x3, 0x3e, 0x32, 0x6e, 0x3, 0xdd, 0xa9, 0x3f, 0x9f, 0xe5, 0xae, 0x41, 0x40, 0xf1, 0xe2 },// 18
{ 0x71, 0x19, 0x0e, 0x3f, 0xa5, 0xc9, 0x7e, 0x3f, 0xcb, 0x57, 0x11, 0x41, 0x1c, 0x3e, 0xf1, 0xc0, 0x44, 0x09, 0x52, 0xbd, 0xad, 0xfa, 0x85, 0xc0, 0x31, 0xdb, 0xa8, 0xf3}, //example data // 19
{ 0x71, 0x19, 0x0e, 0x3f, 0xb6, 0xdd, 0xa9, 0x3f, 0x9f, 0xe5, 0xae, 0x41, 0x33, 0x15, 0x50, 0xc0, 0x46, 0x8a, 0x91, 0xbe, 0x41, 0x92, 0x1a, 0xc0, 0x30, 0xad, 0x53, 0x8f},// 20
{ 0x71, 0x19, 0x0e, 0x3d, 0x0d, 0x39, 0x84, 0x3e, 0xc8, 0xc1, 0xd9, 0x40, 0xcf, 0xef, 0x27, 0xc0, 0x44, 0xef, 0x92, 0xbe, 0x1b, 0xc8, 0x74, 0xc0, 0x2f, 0xee, 0x8c, 0xdd },// 21
{ 0x71, 0x19, 0x0e, 0x3e, 0xd4, 0x58, 0x66, 0x3f, 0xeb, 0x0e, 0x51, 0x41, 0x39, 0x11, 0x12, 0xc0, 0x45, 0x22, 0xc0, 0xbe, 0x15, 0x44, 0xfe, 0xc0, 0x30, 0x25, 0xa0, 0xb5 },// 22
{ 0x71, 0x19, 0x0e, 0x3f, 0xad, 0xca, 0x77, 0x3f, 0xb8, 0x74, 0xe3, 0x41, 0x02, 0xcc, 0xf1, 0xc0, 0x43, 0x04, 0x69, 0xbd, 0xf5, 0x65, 0x97, 0xc0, 0x32, 0x21, 0xed, 0xa7 },// 23
{ 0x71, 0x19, 0x0e, 0x3f, 0xa3, 0x91, 0xf6, 0x3f, 0xcb, 0x1f, 0x19, 0x40, 0xf1, 0xe2, 0x5d, 0xc0, 0x3e, 0x04, 0xa2, 0xbd, 0x0f, 0xc0, 0xb6, 0xc0, 0x34, 0x09, 0xcf, 0xdb },// 24
{ 0x71, 0x19, 0x0e, 0x3f, 0xcc, 0x96, 0x5e, 0x40, 0x2b, 0xe1, 0x71, 0x41, 0x28, 0x71, 0xe3, 0xc0, 0x38, 0xe1, 0xe9, 0x3d, 0xb7, 0x1c, 0x89, 0xc0, 0x33, 0x96, 0x83, 0xee },// 25
{ 0x71, 0x19, 0x0e, 0x40, 0x1c, 0x0f, 0xde, 0x40, 0x45, 0x32, 0x40, 0x41, 0x2d, 0xe3, 0x5d, 0xc0, 0x37, 0x0d, 0xed, 0x3e, 0x08, 0x3e, 0xb6, 0xc0, 0x31, 0xf6, 0xe2, 0xf0 },// 26
{ 0x51, 0x19, 0x0e, 0x40, 0x3f, 0xe5, 0x16, 0x40, 0x42, 0x93, 0xc9, 0x41, 0x1a, 0x7e, 0x94, 0xc0, 0x36, 0xe7, 0xd3, 0x3e, 0x1a, 0x82, 0x01, 0xc0, 0x30, 0x2f, 0x87, 0x4 },// 27
{ 0x51, 0x19, 0x0e, 0x40, 0x54, 0xeb, 0xca, 0x40, 0x3c, 0xd5, 0xd1, 0x41, 0x0b, 0x3c, 0x24, 0xc0, 0x36, 0xdf, 0x03, 0x3e, 0x32, 0x6e, 0x03, 0xc0, 0x2e, 0x84, 0x69, 0xb9 }};// 28};//bad value

void setup()
{
  Serial.begin(9600);
  for (int row = 0; row < 28; row++)
  {
      for (int col = 0; col < 28; col++)
          {
              Serial.print(msg[row][col], HEX);
              // Serial.write(msg[row][col]);
              // Serial.print("\t");
          }
          // Serial.println(F("\nDone!"));
      Serial.println();
  }
}
void loop() {
}

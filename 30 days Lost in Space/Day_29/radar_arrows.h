const byte ARROW_SIZE_X = 11;
const byte ARROW_SIZE_Y = 11;

// 'RIGHT', 11x11px
const unsigned char ARROW_RIGHT [] PROGMEM = {
  0x00, 0x00, 0x40, 0x00, 0xc0, 0x00, 0xff, 0x01, 0xff, 0x03, 0xff, 0x07, 0xff, 0x03, 0xff, 0x01, 
  0xc0, 0x00, 0x40, 0x00, 0x00, 0x00
};

// 'UP', 11x11px
const unsigned char ARROW_UP [] PROGMEM = {
  0x20, 0x00, 0x70, 0x00, 0xf8, 0x00, 0xfc, 0x01, 0xfe, 0x03, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0x00, 
  0xf8, 0x00, 0xf8, 0x00, 0xf8, 0x00
};

// 'UP_RIGHT', 11x11px
const unsigned char ARROW_UP_RIGHT [] PROGMEM = {
  0x00, 0x00, 0xf8, 0x03, 0xf0, 0x03, 0xf0, 0x03, 0xf8, 0x03, 0xfc, 0x03, 0xfe, 0x03, 0x7c, 0x02, 
  0x38, 0x00, 0x10, 0x00, 0x00, 0x00
};

// 'UP_LEFT', 11x11px
const unsigned char ARROW_UP_LEFT [] PROGMEM = {
  0x00, 0x00, 0xfe, 0x00, 0x7e, 0x00, 0x7e, 0x00, 0xfe, 0x00, 0xfe, 0x01, 0xfe, 0x03, 0xf2, 0x01, 
  0xe0, 0x00, 0x40, 0x00, 0x00, 0x00
};

// 'DOWN', 11x11px
const unsigned char ARROW_DOWN [] PROGMEM = {
  0xf8, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0xf8, 0x00, 0xfe, 0x03, 0xfc, 0x01, 
  0xf8, 0x00, 0x70, 0x00, 0x20, 0x00
};

// 'DOWN_RIGHT', 11x11px
const unsigned char ARROW_DOWN_RIGHT [] PROGMEM = {
  0x00, 0x00, 0x18, 0x00, 0x3c, 0x00, 0x7e, 0x02, 0xfe, 0x03, 0xfc, 0x03, 0xf8, 0x03, 0xf0, 0x03, 
  0xf0, 0x03, 0xf8, 0x03, 0x00, 0x00
};

// 'DOWN_LEFT', 11x11px
const unsigned char ARROW_DOWN_LEFT [] PROGMEM = {
  0x00, 0x00, 0x40, 0x00, 0xe0, 0x00, 0xf2, 0x01, 0xfe, 0x03, 0xfe, 0x03, 0xfe, 0x01, 0xfe, 0x00, 
  0x7e, 0x00, 0xfe, 0x00, 0x00, 0x00
};

// 'LEFT', 11x11px
const unsigned char ARROW_LEFT [] PROGMEM = {
  0x00, 0x00, 0x10, 0x00, 0x18, 0x00, 0xfc, 0x07, 0xfe, 0x07, 0xff, 0x07, 0xfe, 0x07, 0xfc, 0x07, 
  0x18, 0x00, 0x10, 0x00, 0x00, 0x00
};

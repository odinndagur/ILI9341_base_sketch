word color( byte R, byte G, byte B) {
  return ( ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | (B >> 3) );
}

void ellipse(int16_t x, int16_t y, float r, word col){
    tft.fillCircle(x,y,r,col);
}

void background(word col){
    tft.fillScreen(col);
}

void point(int16_t x, int16_t y, word col){
    tft.fillCircle(x,y,1,col);
}

void rect(){
  
}

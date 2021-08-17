#pragma once

struct color {
  unsigned char r, g, b, a;
  color(unsigned char _r = 0, unsigned char _g = 0, unsigned char _b = 0, unsigned char _a = 0) {
    r = _r; g = _g; b = _b; a = _a;
  }
};

#define WHITE color(255, 255, 255, 255)
#define BLACK color(  0,   0,   0, 255)
#define RED   color(255,   0,   0, 255)
#define GREEN color(  0, 255,   0, 255)
#define BLUE  color(  0,   0, 255, 255)

class renderer {

public:
  static renderer& getInstance() {
    static renderer instance;
    return instance;
  }

private:
  renderer();
  ~renderer();

public:
  void init(int win_w = 1280 , int win_h = 720, std::string win_title = "Demo App");
  void term();

  void prerender();
  void render();

  bool shouldCloseWindow();

  void setBackgroundcolor(color col);
  void drawCircle(double x, double y, double r, double lw = 1, color col = BLACK);
  void fillCircle(double x, double y, double r, color col = BLACK);
  void drawRectangle(double x, double y, double w, double h, double theta = 0, double lw = 1, color col = BLACK);
  void fillRectangle(double x, double y, double w, double h, double theta = 0, color col = BLACK);
  void drawLine(double x1, double y1, double x2, double y2, double lw = 1, color col = BLACK);

private:
  Size2D winSize;
  color background;
};

#define GetGM() renderer::getInstance()
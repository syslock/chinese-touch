class DrawingPad
{
public:
    DrawingPad();
    void clear();
    void render_buttons();
    void draw( int x, int y, u8* buffer, int widht, int height, int layer=-1 );
    void draw_point( int x, int y );
    void draw_line( int x1, int y1, int x2, int y2 );
public:
    int bg2, bg3;
    int res_x, res_y;
};


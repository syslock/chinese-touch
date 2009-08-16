class DrawingPad
{
public:
    DrawingPad();
    void clear();
    void draw( int x, int y );
    void draw_line( int x1, int y1, int x2, int y2 );
public:
    int bg3;
    int res_x, res_y;
};


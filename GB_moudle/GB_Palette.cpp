#include"GB_palette.h"

Palette::Palette(int x, int y)
{
    RECT rec;
    srand((unsigned)time(NULL));

    this->x = x;
    this->y = y;
    this->pen = CreatePen(PS_SOLID, 2, RGB(192, 192, 192));
    for (int i = 0; i < BTNS; i++)
    {
        BTN btn;
        btn.rect.left = x;
        btn.rect.top = y;
        btn.rect.right = x + BTN_size;
        btn.rect.bottom = y + BTN_size;

        x += BTN_size + BTN_gap;

        btn.brsh = CreateSolidBrush(cols[i]);
        btn.col = cols[i];
        btns.push_back(btn);
    }
    this->boundary_x = x + BTN_size;
    this->boundary_y = y + BTN_size;


    // 랜덤 색상을 저장 할 버튼 생성
    rec.left = x;
    rec.top = y;
    rec.right = x + BTN_size;
    rec.bottom = y + BTN_size;

    this->btn_ran.rect = rec;
    x += BTN_size + BTN_gap;
    this->ChangeRand();

    // 바운더리 영역 확장
    this->boundary_x += x + BTN_size;
}

Palette::~Palette()
{
    for (auto i :btns)
    {
        DeleteObject(i.brsh);
        DeleteObject(i.pen);
    }
    
    btns.clear();
}


void Palette::paint(HWND hWnd, HDC hdc)
{
    RECT temp;
    HBRUSH obrush;

    obrush = (HBRUSH)SelectObject(hdc, btns[0].brsh);
    SelectObject(hdc, this->pen);
    for (auto i : btns)
    {
        SelectObject(hdc, i.brsh);
        Rectangle(hdc, i.rect.left, i.rect.top, i.rect.right, i.rect.bottom);
    }

    // 랜덤 팔레트 출력
    temp = btn_ran.rect;
    SelectObject(hdc, this->btn_ran.brsh);
    Rectangle(hdc, temp.left, temp.top, temp.right, temp.bottom);
    
    
    SelectObject(hdc, obrush);
}


COLORREF Palette::is_press(LPARAM lParam)
{
    POINT po;
    po.x = LOWORD(lParam);
    po.y = HIWORD(lParam);
    
    for (size_t i = 0; i < this->btns.size(); i++)
        if (PtInRect(&this->btns[i].rect, po))
            return btns[i].col;
    if (PtInRect(&this->btn_ran.rect, po))
        return btn_ran.col;

    return -1;
}

// 색상을 랜덤값으로 읽어와 저장하는 함수
COLORREF Palette::ChangeRand() {

    int rr = rand() % 256;
    int gg = rand() % 256;
    int bb = rand() % 256;

    this->btn_ran.col = RGB(rr, gg, bb);
    if (this->btn_ran.brsh != NULL)
        DeleteObject(this->btn_ran.brsh);
    this->btn_ran.brsh = CreateSolidBrush(this->btn_ran.col);

    return this->btn_ran.col;
}


GB_Pen::GB_Pen(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->col = RGB(0, 0, 0);
    this->size = 10;
    this->area = RECT{ x, y, x + width, y + height };
}
void GB_Pen::set_color(COLORREF col) 
{
    this->col = col;
}
COLORREF GB_Pen::get_color()
{
    return this->col;
}
void GB_Pen::set_size(int size)
{
    this->size = size;
}
void GB_Pen::set_size_up()
{
    if (this->size < 10)
        this->size += 1;
    else if (this->size < 30)
        this->size += 2;
    else if (this->size < 48)
        this->size += 3;
    else
        this->size = 50;
    return;
}
void GB_Pen::set_size_down()
{
    if (this->size > 48)
        this->size = 48;
    else if (this->size > 30)
        this->size -= 3;
    else if (this->size > 10)
        this->size -= 2;
    else if (this->size > 0)
        this->size -= 1;
    return;
}
int GB_Pen::get_size()
{
    return this->size;
}
void GB_Pen::paint(HWND hWnd, HDC hdc)
{
    HPEN npen, open;
    HBRUSH nbrush, obrush;
    WCHAR pen_size[5];
    int x_start,x_end, y;
    
    nbrush = CreateSolidBrush(RGB(240,240,240));        //WINDOW_COLOR
    obrush = (HBRUSH)SelectObject(hdc, nbrush);

    y = this->area.top + (this->area.bottom - this->area.top) / 2;
    x_start = this->area.left + this->width / 10;
    x_end = this->area.right - this->width / 10;
    
    Rectangle(hdc, this->area.left, this->area.top, this->area.right, this->area.bottom);
    
    npen = npen = CreatePen(PS_SOLID, this->size, this->col);
    open = (HPEN)SelectObject(hdc, npen);

    MoveToEx(hdc, x_start, y, NULL);
    LineTo(hdc, x_end, y);


    SelectObject(hdc, obrush);
    DeleteObject(nbrush);
    SelectObject(hdc, open);
    DeleteObject(npen);
}
#include <windows.h>

class Common
{
public :
    // static methos có thể truy cập trực tiếp mà không cần khởi tạo đối tượng (object)
    // vd: Common::gotoXY();
    // và static methods chỉ có thể truy cập các biến tĩnh

    // static variables có thể truy cập trực tiếp mà không cần khởi tạo đối tượng (object)
    // các đối tượng (objects) truy cập static variable sẽ có giá trị như nhau 
    // vd: int Commom::count = 0;
    // s1.count++; s2.count++; => lúc này s1.count = s2.count = 2;

    // hiện và ẩn con trỏ chuột 
    void showCur();
    void hideCur();
	// Cố định màn hình Console
	static void fixConsoleWindow();
	// Di chuyển đến tọa độ (x,y) trong màn hình Console
	static void gotoXY(int, int);
	// Chỉnh size của màn hình Console 
	static void setConsoleWindow(int wide, int high);
    // xóa màn hình
    static void clearConsole();
    // chỉnh màu sắc chữ và nền 
    static void color(int color);
    // chỉnh nhạc
    // ý tưởng cho nhạc trong một mảng khi cần xài thì gọi đó và chạy 
    static void playSound(int i);
    // tương tác từ bàn phím
    static int getConsoleInput();
public:
	Common();
	~Common();
};
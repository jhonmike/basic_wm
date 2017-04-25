extern "C" {
#include <X11/Xlib.h>
}
#include <memory>

class WindowManager {
    public:
        static ::std::unique_ptr<WindowManager> Create();
        ~WindowManager();
        void Run();

    private:
        WindowManager(Display* display);
        Display* display_;
        const Window root_;

    static int OnXError(Display* display, XErrorEvent* e);

    static int OnWMDetected(Dispaly* display, XErrorEvent* e);

    static bool wm_detected_;
};

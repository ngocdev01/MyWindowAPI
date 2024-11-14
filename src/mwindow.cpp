//
// Created by ericg on 11/7/2024.
//
#include <mwindow/mwindow.h>
#include <memory>
#include <mwindow/logger.h>

namespace mwindow::window
{
    LRESULT MWindowApp::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        auto* targetWindow = reinterpret_cast<MWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        if(msg == WM_CREATE)
        {
            const auto lpCreateStruct = reinterpret_cast<LPCREATESTRUCT>(lParam);
            targetWindow = static_cast<MWindow*>(lpCreateStruct->lpCreateParams);
            SetWindowLongPtr(hwnd,GWLP_USERDATA,reinterpret_cast<LONG_PTR>(targetWindow));
        }
        if(msg==WM_DESTROY)
        {
            PostQuitMessage(0);
            return 0;
        }

        return DefWindowProc(hwnd,msg,wParam,lParam);
    }

    bool MWindowApp::Initialize(HINSTANCE hInstance)
    {
        this->hInstance = hInstance;
        WNDCLASS wc {};
        wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wc.lpszClassName = className.c_str();
        wc.hInstance = hInstance;
        wc.lpfnWndProc = WindowProc;


        RegisterClass(&wc);


#if defined(USE_LOGGER)
        mwindow::debug::Logger::Initialize();
#endif
        return true;
    }

    bool MWindowApp::Update()
    {
        MSG msg {};
        if(PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if(msg.message == WM_QUIT) return false;
        }
        return true;

    }

    void MWindowApp::UnInitialize()
    {
        UnregisterClass(className.c_str(), hInstance);
#if defined(USE_LOGGER)
        mwindow::debug::Logger::UnInitialize();
#endif
    }

    std::shared_ptr<MWindow> MWindowApp::CreateNewWindow(const int x, const int y, const std::string &name) const
    {
        auto window = std::make_shared<MWindow>();
        window->width = x;
        window->height = y;
        window->title = name;
        window->handle = CreateWindowEx(0,
            window->className.c_str(),
            window->title.c_str(),
            WS_OVERLAPPEDWINDOW,
            window->x,
            window->y,
            window->width,
            window->height,
            nullptr,
            nullptr,
            hInstance,
            &window);
        return window;
    }
}

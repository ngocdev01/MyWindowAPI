//
// Created by ericg on 11/7/2024.
//

#ifndef MWINDOW_H
#define MWINDOW_H
#include <memory>
#include <windows.h>
#include <string>

namespace mwindow::window
{
    class MWindow
    {
    public:
        HWND handle;
        int width = CW_USEDEFAULT;
        int height =  CW_USEDEFAULT;
        int x = CW_USEDEFAULT;
        int y = CW_USEDEFAULT;
        std::string title = "MWindow";
        std::string className  = "MCLass";
    };

    class MWindowApp
    {
    public:
        static LRESULT WindowProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
        bool Initialize(HINSTANCE hInstance);
        bool Update();
        [[nodiscard]]
        std::shared_ptr<MWindow> CreateNewWindow(int x, int y, const std::string &name) const;
        std::string className  = "MCLass";
    private:
        HINSTANCE hInstance = nullptr;
    };



}
#endif //MWINDOW_H

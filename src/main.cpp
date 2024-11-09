//
// Created by ericg on 11/7/2024.
//

#include <iostream>
#include <mwindow/mwindow.h>
#include <mwindow/logger.h>
using namespace  mwindow::window;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR pCmdLine,int nCmdShow)
{
    MWindowApp windowApp;

    windowApp.Initialize(hInstance);

    auto window = windowApp.CreateNewWindow(800,600,"MyWindow");

    LOG_INFO("Create window");
    if(!window->handle) return 0;
    ShowWindow(window->handle,nCmdShow);

    while(windowApp.Update());
    windowApp.UnInitialize();
    return 0;
}
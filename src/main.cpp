//
// Created by ericg on 11/7/2024.
//

#include <iostream>
#include <mwindow/mwindow.h>
#include <mwindow/logging.h>
using namespace  mwindow::window;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR pCmdLine,int nCmdShow)
{
    MWindowApp windowApp;
    mwindow::debug::DebugConsole debugConsole;

    windowApp.Initialize(hInstance);
    debugConsole.Initalize();
    debugConsole.LogInfo("Start create window");
    auto window = windowApp.CreateNewWindow(800,600,"MyWindow");


    if(!window->handle) return 0;
    ShowWindow(window->handle,nCmdShow);
    debugConsole.LogInfo("Create window completed");
    while(windowApp.Update())
    {

    }
    return 0;
}
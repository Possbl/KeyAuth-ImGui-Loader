#include "Main.h"
#include "ui/ui.h"
#include "globals.h"
#include "ui/icons.h"
#include "ui/fonts.h"
#include "Auth/Auth.hpp"

std::string name = ""; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = ""; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = ""; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0";
std::string url = "https://keyauth.win/api/1.2/";

KeyAuth::api KeyAuthApp(name, ownerid, secret, version, url);



ImVec4 blueColor = ImVec4(0.00f, 0.40f, 0.75f, 1.00f); 


void ApplyImGuiTheme()
{
    ImGuiStyle& style = ImGui::GetStyle();

    // Enable dark theme colors
    ImGui::StyleColorsDark();

    // Customize colors
    style.Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.80f, 1.00f);         // Text color
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f); // Disabled text color
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.90f);     // Window background color
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.90f);      // Blue child window background color with reduced alpha
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);      // Popup background color
    style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 0.40f, 0.75f, 1.00f);        // Blue window border color
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);  // Window border shadow color
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);       // Frame background color
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.00f, 0.40f, 0.75f, 0.60f);// Blue frame background color when hovered
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.35f, 0.35f, 0.35f, 0.70f); // Frame background color when active
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.70f);       // Title background color
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.12f, 0.12f, 0.12f, 0.70f); // Title background color when active
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f); // Title background color when collapsed
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.70f);     // Menu bar background color
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.12f, 0.12f, 0.12f, 0.70f);   // Scrollbar background color
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.45f, 0.45f, 0.45f, 0.60f); // Scrollbar grab color
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.60f, 0.60f, 0.60f, 0.70f); // Scrollbar grab color when hovered
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.80f, 0.80f, 0.80f, 0.70f);  // Scrollbar grab color when active
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.78f, 0.78f, 0.78f, 1.00f);    // Checkbox checkmark color
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);   // Slider grab color
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.90f, 0.90f, 0.90f, 0.70f);  // Slider grab color when active
    style.Colors[ImGuiCol_Button] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);        // Button color
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.00f, 0.40f, 0.75f, 0.70f); // Blue button color when hovered
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);  // Button color when active
    style.Colors[ImGuiCol_Header] = ImVec4(0.30f, 0.30f, 0.30f, 0.70f);        // Header color
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.80f); // Header color when hovered
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.50f, 0.50f, 0.50f, 0.80f);  // Header color when active
    style.Colors[ImGuiCol_Separator] = ImVec4(0.50f, 0.50f, 0.50f, 0.70f);     // Separator color
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.60f, 0.60f, 0.60f, 0.70f); // Separator color when hovered
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);// Separator color when active
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.50f, 0.50f, 0.50f, 0.50f);     // Resize grip color
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.60f, 0.60f, 0.60f, 0.70f); // Resize grip color when hovered
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.70f, 0.70f, 0.70f, 0.70f);// Resize grip color when active
    style.Colors[ImGuiCol_Tab] = ImVec4(0.15f, 0.15f, 0.15f, 0.86f);           // Tab color
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.00f, 0.40f, 0.75f, 0.80f);    // Blue tab color when hovered
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.23f, 0.23f, 0.23f, 0.85f);     // Tab color when active
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.08f, 0.08f, 0.08f, 0.97f);   // Tab color when unfocused
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.13f, 0.13f, 0.13f, 0.97f); // Tab color when unfocused and active
    style.Colors[ImGuiCol_DockingPreview] = ImVec4(0.26f, 0.59f, 0.98f, 0.70f); // Docking preview color
    style.Colors[ImGuiCol_DockingEmptyBg] = ImVec4(0.20f, 0.20f, 0.20f, 0.70f); // Docking empty background color
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);     // Plot lines color
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 0.40f, 0.75f, 1.00f); // Blue plot lines color when hovered
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f); // Plot histogram color
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 0.40f, 0.75f, 1.00f); // Blue plot histogram color when hovered
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f); // Selected text background color
    style.Colors[ImGuiCol_PlotHistogram] = blueColor;
    style.Colors[ImGuiCol_PlotHistogramHovered] = blueColor;

    // Adjust button text alignment
    style.ButtonTextAlign = ImVec2(0.5f, 0.5f);

    // Disable anti-aliasing for lines and shapes
    style.AntiAliasedLines = false;
    style.AntiAliasedFill = false;


}

void clearItems()
{
    globals.pass_word[0] = '\0';
    globals.user_name[0] = '\0';
    globals.license[0] = '\0';
}

bool mainwind = false;
bool loginwind = true;

int selectedItem = 0;

float progress = 0.0f;
bool loadingbar = false;


void UpdateProgress() {
    progress = 0.0f;

    loadingbar = !loadingbar;

    const float increment = 0.01f;
    const std::chrono::milliseconds duration(5000);

    auto start = std::chrono::steady_clock::now();
    while (progress < 1.0f) {
        auto current = std::chrono::steady_clock::now();
        float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current - start).count();
        progress = elapsed / duration.count();

        // Render the UI and update the window
        // ...

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    loadingbar = !loadingbar;
}

void ui::render() {
    ApplyImGuiTheme();
    ImGui::SetNextWindowPos(ImVec2(window_pos.x, window_pos.y), ImGuiCond_Once);
    ImGui::SetNextWindowSize(ImVec2(window_size.x, window_size.y));
    ImGui::SetNextWindowBgAlpha(1.0f);

    static int tab = 0;

    if (loginwind)
    {
        ImGui::Begin(window_title, &globals.active, window_flags);
        {
            ImGui::BeginChild("##Left", ImVec2(ImGui::GetContentRegionAvail().x, 100), true);
            {
                ImGui::SetCursorPos(ImVec2(100, 30));
                if (ImGui::Button(ICON_FA_USER, ImVec2(80, 30)))
                {
                    tab = 0;
                    clearItems();
                }
                ImGui::SetCursorPos(ImVec2(200, 30));
                if (ImGui::Button(ICON_FA_KEY, ImVec2(80, 30)))
                {
                    tab = 1;
                    clearItems();
                }

                ImGui::SetCursorPos(ImVec2(300, 30));
                if (ImGui::Button(ICON_FA_GEAR, ImVec2(80, 30)))
                {
                    tab = 2;
                    clearItems();
                }
            }
            ImGui::EndChild();


            ImGui::BeginChild("##Right", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true);
            {

                if (tab == 0)
                {

                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2 - 12);
                    ImGui::Text("Login");
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2.5 - 100);
                    ImGui::InputTextWithHint("##username", "Username", globals.user_name, sizeof(globals.user_name));
                    ImGui::Spacing();
                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2.5 - 100);
                    ImGui::InputTextWithHint("##password", "Password", globals.pass_word, sizeof(globals.pass_word), ImGuiInputTextFlags_Password);

                    ImGui::Spacing();
                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2.5 + 15);

                    if (ImGui::Button("Login", ImVec2(80, 30)))
                    {
                        KeyAuthApp.login(globals.user_name, globals.pass_word);
                        if (!KeyAuthApp.data.success)
                        {
                            MessageBox(NULL, KeyAuthApp.data.message.c_str(), "Auth Error", NULL);
                            Sleep(1500);
                            exit(0);
                        }
                        else {
                            Beep(250, 300);
                            loginwind = false;
                            mainwind = true;
                        }
                    }
                }

                if (tab == 1)
                {
                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2 - 20);
                    ImGui::Text("Register");

                    ImGui::Spacing();
                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2.5 - 100);
                    ImGui::InputTextWithHint("##username", "Username", globals.user_name, IM_ARRAYSIZE(globals.user_name));
                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2.5 - 100);
                    ImGui::InputTextWithHint("##password", "Password", globals.pass_word, IM_ARRAYSIZE(globals.pass_word), ImGuiInputTextFlags_Password);
                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2.5 - 100);
                    ImGui::InputTextWithHint("##license", "License", globals.license, IM_ARRAYSIZE(globals.license));


                    ImGui::Spacing();
                    ImGui::SetCursorPosX(ImGui::GetContentRegionAvail().x / 2.5 + 15);

                    if (ImGui::Button("Register", ImVec2(80, 30)))
                    {
                        KeyAuthApp.regstr(globals.user_name, globals.pass_word, globals.license);
                        if (!KeyAuthApp.data.success)
                        {
                            MessageBox(NULL, KeyAuthApp.data.message.c_str(), "Auth Error", NULL);
                            Sleep(1500);
                            exit(0);
                        }
                        else {
                            Beep(250, 300);
                            loginwind = false;
                            mainwind = !mainwind;
                            // continue to next window

                        }
                    }

                }

                if (tab == 2)
                {

                    ImGui::SetCursorPos(ImVec2(ImGui::GetContentRegionAvail().x / 2 - 25, 25));
                    ImGui::Text("Build");
                    ImGui::SameLine();
                    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 1.0f, 0.0f, 1.0f));
                    ImGui::Text(globals.version.c_str());
                    ImGui::PopStyleColor(); // Restore the original text color



                }

            }
            ImGui::EndChild();
        }
        ImGui::End();
    }
    

    if (mainwind)
    {
        const char* products[] = { "Rainbow Six" , "Valorant", "Fortnite", "EFT", "Apex Legends"};
        ImGui::Begin(window_title, &globals.active, window_flags);

        ImGui::BeginChild("##main", ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), true, window_flags);

        ImGui::Text("Product: %s", products[selectedItem]);
        ImGui::SetNextItemWidth(150);

        ImGui::ListBox("##cheat", &selectedItem, products, IM_ARRAYSIZE(products), 10);

        ImGui::SameLine();
        ImGui::SetCursorPosX(265);

        // setup subscription levels on keyauth dashboard and make sure the product array matches the names
        if (ImGui::Button("Load Cheat", ImVec2(130, 30)))
        {

            for (std::string subs : KeyAuthApp.data.subscriptions)
            {
                if (subs == products[selectedItem])
                {
                    // load cheat in here
                    if (!loadingbar)
                    {
                        std::thread loadingThread(UpdateProgress);
                        loadingThread.detach();
                    }
                }
                else {
                    MessageBox(NULL, "Subscription not found", "Subscription Error", NULL);
                }
            }
        }

        if (loadingbar) {
            ImGui::ProgressBar(progress);
        }


        ImGui::EndChild();
        
        ImGui::End();
    }
     
}




void ui::init(LPDIRECT3DDEVICE9 device) {
    dev = device;


    if (window_pos.x == 0) {
        RECT screen_rect{};
        GetWindowRect(GetDesktopWindow(), &screen_rect);
        screen_res = ImVec2(float(screen_rect.right), float(screen_rect.bottom));


    }
}

int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    KeyAuthApp.init();
    if (!KeyAuthApp.data.success)
    {
        std::cout << "\n Status: " << KeyAuthApp.data.message;
        Sleep(1500);
        exit(0);
    }	
    KeyAuthApp.check();


    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, ui::window_title, NULL};
    RegisterClassEx(&wc);
    main_hwnd = CreateWindow(wc.lpszClassName, ui::window_title, WS_POPUP, 0, 0, 5, 5, NULL, NULL, wc.hInstance, NULL);

    if (!CreateDeviceD3D(main_hwnd)) {
        CleanupDeviceD3D();
        UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }

    ShowWindow(main_hwnd, SW_HIDE);
    UpdateWindow(main_hwnd);

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
    io.IniFilename = nullptr; 
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(main_hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //IM_ASSERT(font != NULL);


    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);
    io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Verdana.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);
    static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_16_FA, 0 };
    ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
    ImFont* FontAwesome = io.Fonts->AddFontFromMemoryCompressedTTF(fa6_solid_compressed_data, fa6_solid_compressed_size, 14.f, &icons_config, icons_ranges);
    ImFont* FontAwesomeBig = io.Fonts->AddFontFromMemoryCompressedTTF(fa6_solid_compressed_data, fa6_solid_compressed_size, 19.f, nullptr, icons_ranges);
    ImFont* TitleFont = io.Fonts->AddFontFromMemoryCompressedTTF(trebucbd_compressed_data, trebucbd_compressed_size, 30, nullptr, io.Fonts->GetGlyphRangesDefault());



    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            continue;
        }

        // Start the Dear ImGui frame
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            static int init = false;
            if (!init) {
                ui::init(g_pd3dDevice);
                init = true;
            }
            else {
                ui::render();
            }
        }
        ImGui::EndFrame();

        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }

        // Update and Render additional Platform Windows
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
        }

        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
            ResetDevice();
        }
        if (!globals.active) {
            msg.message = WM_QUIT;
        }
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    DestroyWindow(main_hwnd);
    UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

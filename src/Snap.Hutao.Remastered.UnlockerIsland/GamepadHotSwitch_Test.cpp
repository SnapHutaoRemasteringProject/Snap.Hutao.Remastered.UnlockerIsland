// 手柄热切换测试文件
// 这个文件展示了如何使用GamepadHotSwitch API

#include "GamepadHotSwitch.h"
#include <iostream>

void TestGamepadHotSwitch()
{
    std::cout << "=== Gamepad Hot Switch Test ===\n";
    
    // 获取单例实例
    GamepadHotSwitch& hotSwitch = GamepadHotSwitch::GetInstance();
    
    // 测试初始化
    std::cout << "1. Testing initialization...\n";
    bool initResult = hotSwitch.Initialize();
    if (initResult)
    {
        std::cout << "   Initialization successful\n";
    }
    else
    {
        std::cout << "   Initialization failed (XInput可能不可用)\n";
    }
    
    // 测试启用/禁用
    std::cout << "2. Testing enable/disable...\n";
    hotSwitch.SetEnabled(true);
    std::cout << "   Enabled: " << (hotSwitch.IsEnabled() ? "true" : "false") << "\n";
    
    // 测试模式切换
    std::cout << "3. Testing mode switching...\n";
    std::cout << "   Current mode: " << (hotSwitch.IsGamepadMode() ? "Gamepad" : "Keyboard/Mouse") << "\n";
    
    // 手动切换模式
    hotSwitch.SwitchToGamepadMode(true);
    std::cout << "   After switching to gamepad mode: " << (hotSwitch.IsGamepadMode() ? "Gamepad" : "Keyboard/Mouse") << "\n";
    
    hotSwitch.SwitchToGamepadMode(false);
    std::cout << "   After switching to keyboard/mouse mode: " << (hotSwitch.IsGamepadMode() ? "Gamepad" : "Keyboard/Mouse") << "\n";
    
    // 测试窗口消息处理
    std::cout << "4. Testing window message processing...\n";
    hotSwitch.ProcessWindowMessage(WM_MOUSEMOVE, 0, 0);
    std::cout << "   Mouse activity registered\n";
    
    // 清理
    std::cout << "5. Cleaning up...\n";
    hotSwitch.SetEnabled(false);
    hotSwitch.Shutdown();
    
    std::cout << "=== Test completed ===\n";
}

// 主函数（仅用于测试）
int main()
{
    TestGamepadHotSwitch();
    return 0;
}

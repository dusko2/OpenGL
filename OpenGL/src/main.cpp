#include "GLFWController/GLFWController.h"
#include "Window/UIWindow.h"
#include "GLADController/GLADController.h"
#include "GLObject/ShaderLoader/ShaderLoader.h"

int main(void) {
    GLFWController::GetInstance().Initialize();
    UIWindow::GetInstance().Initialize();
    GLADController::GetInstance().Initialize();

    ShaderLoader::GetInstance().Load();
    UIWindow::GetInstance().StartLoop();

	return 0;
}

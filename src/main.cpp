#include "scene/scene.h"

int main(void)
{
    int w = 800;
    int h = 600;

    Scene scene{ Camera{ 0.5f,
                         M_PI_2,
                         { 0.f, 0.f, 0.f },
                         { 0.f, 0.f, -1.f },
                         { 0.f, 1.f, 0.f } } };
    scene.add_object(Sphere{ { 0.f, 0.f, -5.f }, 2.f });
    scene.add_object(Sphere{ { 0.f, -3.f, -3.f }, 2.f });
    scene.draw_scene(w, h);

    return 0;
}

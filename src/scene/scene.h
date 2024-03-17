#pragma once

#include <vector>

#include "camera.h"
#include "geometry/sphere.h"
#include "light.h"

class Scene
{
public:
    Scene(const Camera camera)
        : camera_(camera)
    {}

    template <typename... Ts>
    Scene(const Camera camera, Ts... lights)
        : camera_(camera)
        , lights_(std::forward(lights...))
    {}

    void add_light(const Light& light)
    {
        this->lights_.push_back(light);
    }

    void add_object(const Sphere& object)
    {
        this->objects_.push_back(object);
    }

private:
    Camera camera_;
    std::vector<Light> lights_;
    // TODO: Change this to a vector of objects
    std::vector<Sphere> objects_;
};
